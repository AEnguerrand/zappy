/*
** game_graphic_player.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_graphic_player.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Jun 27 23:59:28 2017 Enguerrand Allamel
** Last update Tue Jun 27 23:59:28 2017 Enguerrand Allamel
*/

#include "zappy.h"

int 	game_graphic_player_teams(int fd)
{
  int 	i;

  i = 0;
  while (g_zappy.arguments.teams_name && g_zappy.arguments.teams_name[i])
    {
      cir_buf_add_cmd_v(&g_zappy.tunnels[fd].cir_buf_out, "tna %s",
			g_zappy.arguments.teams_name[i]);
      i += 1;
    }
  return (0);
}

int 	game_graphic_player_send_inv_all(int fd)
{
  game_graphic_notify_all("pin %d %d %d %d %d %d %d %d %d %d",
			  g_zappy.tunnels[fd].client.player.id,
			  g_zappy.tunnels[fd].client.player.pos.x,
			  g_zappy.tunnels[fd].client.player.pos.y,
			  g_zappy.tunnels[fd].client.player.inventory[1],
			  g_zappy.tunnels[fd].client.player.inventory[2],
			  g_zappy.tunnels[fd].client.player.inventory[3],
			  g_zappy.tunnels[fd].client.player.inventory[4],
			  g_zappy.tunnels[fd].client.player.inventory[5],
			  g_zappy.tunnels[fd].client.player.inventory[6],
			  g_zappy.tunnels[fd].client.player.inventory[7]);
  return (0);
}