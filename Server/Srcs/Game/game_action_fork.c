/*
** game_action_fork.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_action_fork.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Fri Jun 30 15:46:13 2017 Enguerrand Allamel
** Last update Fri Jun 30 15:46:13 2017 Enguerrand Allamel
*/

#include "zappy.h"

int 		game_action_fork_remove(int 			id,
					int 			team_id,
					t_game_action_type 	cmd)
{
  (void)id;
  (void)team_id;
  (void)cmd;
  log_server(id, "End of fork");
  game_graphic_notify_all("edi %d", id);
  g_zappy.arguments.solt_free_by_team[team_id] -= 1;
  return (0);
}

bool			game_action_fork_free(int team_id)
{
  t_game_cmd_queue	*tmp;

  tmp = g_zappy.action_game;
  while (tmp)
    {
      if (tmp->type == ZAPPY_G_ACT_FORK_END && tmp->team_id == team_id)
	return (true);
      tmp = tmp->next;
    }
  return (false);
}

int 			game_action_fork_use(int team_id)
{
  t_game_cmd_queue	*tmp;

  tmp = g_zappy.action_game;
  while (tmp)
    {
      if (tmp->type == ZAPPY_G_ACT_FORK_END && tmp->team_id == team_id)
	{
	  game_graphic_notify_all("eht %d", tmp->id);
	  game_graphic_notify_all("ebo %d", tmp->id);
	  if (team_id < 0 || team_id >= g_zappy.arguments.teams_nb)
	    return (-1);
	  g_zappy.arguments.solt_free_by_team[team_id] -= 1;
	  game_queue_remove(tmp);
	  return (0);
	}
      tmp = tmp->next;
    }
  return (-1);
}