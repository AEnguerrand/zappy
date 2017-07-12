/*
** game_player.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_player.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Jun 21 19:47:12 2017 Enguerrand Allamel
** Last update Wed Jun 21 19:47:12 2017 Enguerrand Allamel
*/

#include "zappy.h"

size_t 		game_player_nb_in_case_on_level(t_pos 			pos,
						      t_zappy_level	level)
{
  int 		i;
  size_t	nb;

  i = 0;
  nb = 0;
  while (i < ZAPPY_FD_MAX)
    {
      if (g_zappy.tunnels[i].type == Z_CLIENT &&
	  g_zappy.tunnels[i].client.type == Z_CLIENT_PLAYER &&
	  g_zappy.tunnels[i].client.player.level == level &&
	  g_zappy.tunnels[i].client.player.pos.x == pos.x &&
	  g_zappy.tunnels[i].client.player.pos.y == pos.y)
	nb += 1;
      i += 1;
    }
  return (nb);
}

size_t 		game_player_nb_in_case(t_pos pos)
{
  int 		i;
  size_t	nb;

  i = 0;
  nb = 0;
  while (i < ZAPPY_FD_MAX)
    {
      if (g_zappy.tunnels[i].type == Z_CLIENT &&
	  g_zappy.tunnels[i].client.type == Z_CLIENT_PLAYER &&
	  g_zappy.tunnels[i].client.player.pos.x == pos.x &&
	  g_zappy.tunnels[i].client.player.pos.y == pos.y)
	nb += 1;
      i += 1;
    }
  return (nb);
}

int 		game_player_in_case_upgrade_level(t_pos 		pos,
						     t_zappy_level 	level)
{
  int 		i;

  i = 0;
  game_graphic_notify_all("pie %d %d %d", pos.x, pos.y, 1);
  while (i < ZAPPY_FD_MAX)
    {
      if (g_zappy.tunnels[i].type == Z_CLIENT &&
	  g_zappy.tunnels[i].client.type == Z_CLIENT_PLAYER &&
	  g_zappy.tunnels[i].client.player.level == level &&
	  g_zappy.tunnels[i].client.player.pos.x == pos.x &&
	  g_zappy.tunnels[i].client.player.pos.y == pos.y)
	{
	  g_zappy.tunnels[i].client.player.level += 1;
	  if (g_zappy.tunnels[i].client.player.level > 8)
	    return (-1);
	  game_graphic_notify_all("plv %d %d",
				  g_zappy.tunnels[i].client.player.id,
				  g_zappy.tunnels[i].client.player.level);
	  cir_buf_add_cmd_v(&g_zappy.tunnels[i].cir_buf_out,
			    "Current level: %d",
			    g_zappy.tunnels[i].client.player.level);
	}
      i += 1;
    }
  return (0);
}

int 		game_player_in_case_start_up_level(t_pos 		pos,
						      t_zappy_level 	level)
{
  int 		i;

  i = 0;
  while (i < ZAPPY_FD_MAX)
    {
      if (g_zappy.tunnels[i].type == Z_CLIENT &&
	  g_zappy.tunnels[i].client.type == Z_CLIENT_PLAYER &&
	  g_zappy.tunnels[i].client.player.level == level &&
	  g_zappy.tunnels[i].client.player.pos.x == pos.x &&
	  g_zappy.tunnels[i].client.player.pos.y == pos.y)
	{
	  cir_buf_add_cmd(&g_zappy.tunnels[i].cir_buf_out,
			  "Elevation underway");
	}
      i += 1;
    }
  return (0);
}