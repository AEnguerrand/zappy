/*
** game_player_dead.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_player_dead.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Sun Jul 02 15:01:09 2017 Enguerrand Allamel
** Last update Sun Jul 02 15:01:09 2017 Enguerrand Allamel
*/

#include "zappy.h"

int 	game_player_dead(int fd)
{
  if (fd < 0 || fd >= ZAPPY_FD_MAX ||
      g_zappy.tunnels[fd].type != Z_CLIENT ||
      g_zappy.tunnels[fd].client.type != Z_CLIENT_PLAYER)
    return (-1);
  cir_buf_add_cmd(&g_zappy.tunnels[fd].cir_buf_out, "dead");
  return (0);
}