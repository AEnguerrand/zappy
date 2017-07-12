/*
** game_graphic_init.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_graphic_init.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Jun 21 23:45:02 2017 Enguerrand Allamel
** Last update Wed Jun 21 23:45:02 2017 Enguerrand Allamel
*/

#include "zappy.h"

int	game_graphic_add(int fd)
{
  g_zappy.tunnels[fd].client.type = Z_CLIENT_GRAPHIC;
  log_server(fd, "%s", "New graphic init");
  return (0);
}