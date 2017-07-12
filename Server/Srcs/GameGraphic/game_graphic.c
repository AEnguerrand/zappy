/*
** game_graphic.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_graphic.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Jun 21 23:44:48 2017 Enguerrand Allamel
** Last update Wed Jun 21 23:44:48 2017 Enguerrand Allamel
*/

#include "zappy.h"

static void	display_all_player(int fd)
{
  int 		i;

  i = 0;
  while (i < ZAPPY_FD_MAX)
    {
      if (g_zappy.tunnels[i].type == Z_CLIENT &&
	  g_zappy.tunnels[i].client.type == Z_CLIENT_PLAYER)
	cir_buf_add_cmd_v(&g_zappy.tunnels[fd].cir_buf_out, "pnw %d %d %d %d"
				  " %d %s",
			  g_zappy.tunnels[i].client.player.id,
			  g_zappy.tunnels[i].client.player.pos.x,
			  g_zappy.tunnels[i].client.player.pos.y,
			  g_zappy.tunnels[i].client.player.dir,
			  g_zappy.tunnels[i].client.player.level,
			  game_player_teams_get_name(
				  g_zappy.tunnels[i].client.player.team_id));
      i += 1;
    }
}

int 	game_graphic_login_display(int fd)
{
  cir_buf_add_cmd_v(&g_zappy.tunnels[fd].cir_buf_out, "msz %d %d",
		    g_zappy.map.width,
		    g_zappy.map.height);
  cir_buf_add_cmd_v(&g_zappy.tunnels[fd].cir_buf_out, "sgt %ld",
		    g_zappy.arguments.freq);
  game_graphic_map_display_all(fd);
  game_graphic_player_teams(fd);
  display_all_player(fd);
  return (0);
}