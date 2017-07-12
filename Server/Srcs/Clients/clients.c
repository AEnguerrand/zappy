/*
** clients.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/clients.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Jun 21 20:12:26 2017 Enguerrand Allamel
** Last update Wed Jun 21 20:12:26 2017 Enguerrand Allamel
*/

#include "zappy.h"

int 	client_add(int fd)
{
  g_zappy.tunnels[fd].client.type = Z_CLIENT_DEFAULT;
  g_zappy.tunnels[fd].client.is_log = false;
  cir_buf_add_cmd(&g_zappy.tunnels[fd].cir_buf_out, "WELCOME");
  return (0);
}

int 	client_login(int fd, const char *cmd)
{
  if (!cmd)
    return (-1);
  if (strcmp(cmd, "GRAPHIC") == 0)
    {
      if (game_graphic_add(fd) == -1 ||
	  game_graphic_login_display(fd) == -1)
	cir_buf_add_cmd(&g_zappy.tunnels[fd].cir_buf_out, "ko");
      else
	g_zappy.tunnels[fd].client.is_log = true;
    }
  else if (game_player_teams_is_exist(cmd) == 1)
    {
      if (game_player_add(fd, cmd) == -1)
	cir_buf_add_cmd(&g_zappy.tunnels[fd].cir_buf_out, "ko");
      else
	g_zappy.tunnels[fd].client.is_log = true;
    }
  else
    {
      cir_buf_add_cmd(&g_zappy.tunnels[fd].cir_buf_out, "ko");
    }
  return (0);
}