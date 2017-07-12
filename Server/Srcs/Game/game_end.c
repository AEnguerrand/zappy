/*
** game_end.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_end.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Sun Jul 02 16:07:09 2017 Enguerrand Allamel
** Last update Sun Jul 02 16:07:09 2017 Enguerrand Allamel
*/

#include "zappy.h"

static const char 	*game_end_get_winner()
{
  int 			i;

  i = 0;
  while (i < ZAPPY_FD_MAX)
    {
      if (g_zappy.tunnels[i].type == Z_CLIENT &&
	  g_zappy.tunnels[i].client.type == Z_CLIENT_PLAYER &&
	  g_zappy.tunnels[i].client.player.level == Z_LEVEL_8)
	{
	  return (game_player_teams_get_name(
		  g_zappy.tunnels[i].client.player.team_id));
	}
      i += 1;
    }
  return ("Michel");
}

static void	clean_all_tunnels()
{
  int 		i;

  i = 0;
  while (i < ZAPPY_FD_MAX)
    {
      if (g_zappy.tunnels[i].type == Z_CLIENT)
	tunnel_close_client(i);
      i += 1;
    }
}

static void	clean_args()
{
  free_double(g_zappy.arguments.teams_name);
  if (g_zappy.arguments.solt_free_by_team)
    free(g_zappy.arguments.solt_free_by_team);
  if (g_zappy.map.ressources)
    free(g_zappy.map.ressources);
}

int 			game_end()
{
  fd_set		fd_write;
  struct timeval	tv;

  game_graphic_notify_all("seg %s", game_end_get_winner());
  network_loop_write(&fd_write, &tv);
  clean_all_tunnels();
  clean_args();
  return (0);
}