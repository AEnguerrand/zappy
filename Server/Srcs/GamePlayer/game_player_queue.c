/*
** game_player_queue.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_player_queue.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Mon Jun 26 11:56:50 2017 Enguerrand Allamel
** Last update Mon Jun 26 11:56:50 2017 Enguerrand Allamel
*/

#include "zappy.h"

int 				game_player_queue_push(int		fd,
							  const char	*cmd,
							  size_t	t_u)
{
  t_game_player_cmd_queue	*item;
  t_game_player_cmd_queue	*last;

  if (!(item = malloc(sizeof(t_game_player_cmd_queue))) ||
      !(item->cmd = strdup(cmd)))
    return (-1);
  item->is_start = false;
  item->time_unit = t_u;
  item->next = NULL;
  last = g_zappy.tunnels[fd].client.player.first;
  while (last && last->next)
    last = last->next;
  if (last)
    last->next = item;
  else
    g_zappy.tunnels[fd].client.player.first = item;
  return (0);
}

int				game_player_queue_pop(int fd)
{
  t_game_player_cmd_queue	*last;

  if (!g_zappy.tunnels[fd].client.player.first)
    return (-1);
  last = g_zappy.tunnels[fd].client.player.first;
  g_zappy.tunnels[fd].client.player.first = last->next;
  free(last->cmd);
  free(last);
  return (0);
}

int 				game_player_queue_size(int fd)
{
  t_game_player_cmd_queue	*item;
  int 				size;

  size = 0;
  item = g_zappy.tunnels[fd].client.player.first;
  while (item)
    {
      size += 1;
      item = item->next;
    }
  return (size);
}

int 	game_player_queue_start(int fd, t_game_player_cmd_queue *item)
{
  (void)fd;
  item->time_interval = network_time_convert_unit_time_to_nsec(
	  item->time_unit);
  item->is_start = true;
  return (0);
}

int			game_player_queue_check(int fd, long long time_sub)
{
  if (g_zappy.tunnels[fd].client.player.first &&
      game_player_queue_size(fd) > 0 && g_zappy.tunnels[fd].client.player.
	  first->is_start == true)
    g_zappy.tunnels[fd].client.player.first->time_interval -= time_sub;
  if (!g_zappy.tunnels[fd].client.player.first ||
      game_player_queue_size(fd) <= 0)
    return (0);

  else if (g_zappy.tunnels[fd].client.player.first->is_start == false)
    return (game_player_queue_start(fd,
				    g_zappy.tunnels[fd].client.player.first));
  else if (g_zappy.tunnels[fd].client.player.first->time_interval
	   <= 0)
    {
      log_server(fd, "Q Check EXEC (%s)",
		 g_zappy.tunnels[fd].client.player.first->cmd);
      game_player_cmd_exec(fd, g_zappy.tunnels[fd].client.player.first->cmd);
      game_player_queue_pop(fd);
    }
  return (0);
}