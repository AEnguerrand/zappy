/*
** game_player_cmd_inventory.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_player_cmd_inventory.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Mon Jun 26 15:41:06 2017 Enguerrand Allamel
** Last update Mon Jun 26 15:41:06 2017 Enguerrand Allamel
*/

#include "zappy.h"

int 	game_player_cmd_inventory(int fd, const char *cmd)
{
  (void)cmd;
  cir_buf_add_cmd_v(&g_zappy.tunnels[fd].cir_buf_out,
		    "[ food %d, linemate %d, deraumere %d, sibur %d,"
			    " mendiane %d, phiras %d, thystame %d ]",
		    g_zappy.tunnels[fd].client.player.inventory[1],
		    g_zappy.tunnels[fd].client.player.inventory[2],
		    g_zappy.tunnels[fd].client.player.inventory[3],
		    g_zappy.tunnels[fd].client.player.inventory[4],
		    g_zappy.tunnels[fd].client.player.inventory[5],
		    g_zappy.tunnels[fd].client.player.inventory[6],
		    g_zappy.tunnels[fd].client.player.inventory[7]);
  return (0);
}