/*
** game_action_eat.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_action_eat.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Fri Jun 30 20:35:06 2017 Enguerrand Allamel
** Last update Fri Jun 30 20:35:06 2017 Enguerrand Allamel
*/

#include "zappy.h"

int 		game_action_eat(int 			id,
				   int 			team_id,
				   t_game_action_type 	cmd)
{
  if (id < 0 || id >= ZAPPY_FD_MAX || g_zappy.tunnels[id].type != Z_CLIENT
      || g_zappy.tunnels[id].client.type != Z_CLIENT_PLAYER)
    return (-1);
  g_zappy.tunnels[id].client.player.inventory[FOOD] -= 1;
  if (g_zappy.tunnels[id].client.player.inventory[FOOD] <= 0)
    {
      log_server(id, "!!! DEAD !!!");
      game_player_dead(id);
      return (-2);
    }
  game_action_queue_push(cmd, 126, id, team_id);
  return (0);
}