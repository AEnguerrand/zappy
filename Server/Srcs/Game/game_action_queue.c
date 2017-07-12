/*
** game_action_queue.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_action_queue.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Fri Jun 30 15:21:29 2017 Enguerrand Allamel
** Last update Fri Jun 30 15:21:29 2017 Enguerrand Allamel
*/

#include "zappy.h"

int 			game_action_queue_push(t_game_action_type	cmd,
						  size_t		t_u,
						  int 			id,
						  int 			t_id)
{
  t_game_cmd_queue	*item;
  t_game_cmd_queue	*last;

  if (!(item = malloc(sizeof(t_game_cmd_queue))))
    return (-1);
  item->id = id;
  item->type = cmd;
  item->team_id = t_id;
  item->time_interval = network_time_convert_unit_time_to_nsec(t_u);
  item->next = NULL;
  last = g_zappy.action_game;
  while (last && last->next)
    last = last->next;
  if (last)
    last->next = item;
  else
    g_zappy.action_game = item;
  log_server(id, "command action push: [%d]", cmd);
  return (0);
}

int 			game_queue_remove(t_game_cmd_queue *item)
{
  t_game_cmd_queue	*tmp;
  t_game_cmd_queue	*tmp_b;

  tmp = g_zappy.action_game;
  if (tmp && tmp != item)
    {
      while (tmp && tmp->next && tmp->next != item)
	tmp = tmp->next;
      if (tmp && tmp->next && tmp->next == item)
	{
	  tmp_b = tmp->next;
	  tmp->next = tmp->next->next;
	  free(tmp_b);
	}
    }
  else if (tmp && tmp == item)
    {
      g_zappy.action_game = tmp->next;
      free(tmp);
    }
  return (0);
}

long long 		game_action_queue_min_time()
{
  t_game_cmd_queue	*tmp;
  long long		min;

  tmp = g_zappy.action_game;
  min = -1;
  while (tmp)
    {
      if (min == -1 || min > tmp->time_interval)
	min = tmp->time_interval;
      tmp = tmp->next;
    }
  return (min);
}

int			game_queue_check(long long time_sub)
{
  t_game_cmd_queue	*tmp;
  t_game_cmd_queue	*tmp_n;

  log_server(-1, "command action check");
  tmp = g_zappy.action_game;
  while (tmp)
    {
      tmp->time_interval -= time_sub;
      tmp = tmp->next;
    }
  tmp = g_zappy.action_game;
  while (tmp)
    {
      tmp_n = tmp->next;
      if (tmp->time_interval <= 0)
	{
	  log_server(-1, "EXEC Action game");
	  game_action_cmd_exec(tmp->id, tmp->team_id, tmp->type);
	  game_queue_remove(tmp);
	}
      tmp = tmp_n;
    }
  return (0);
}