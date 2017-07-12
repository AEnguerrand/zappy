/*
** game_player_cmd_broadcast.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_player_cmd_broadcast.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Fri Jun 30 23:35:09 2017 Enguerrand Allamel
** Last update Fri Jun 30 23:35:09 2017 Enguerrand Allamel
*/

#include "zappy.h"

static int 	send_broadcast_to(int fd_send, int fd_rec, const char *msg)
{
  cir_buf_add_cmd_v(&g_zappy.tunnels[fd_rec].cir_buf_out, "message %d, %s",
		    game_player_sound_get_sound_pos(fd_send, fd_rec), msg);
  return (0);
}

int 		game_player_cmd_broadcast(int fd, const char *cmd)
{
  int 		i;
  const char	*msg;

  if (!cmd || !(msg = get_pos_args(cmd)))
    {
      cir_buf_add_cmd(&g_zappy.tunnels[fd].cir_buf_out, "ko");
      return (-1);
    }
  i = 0;
  while (i < ZAPPY_FD_MAX)
    {
      if (i != fd && g_zappy.tunnels[i].type == Z_CLIENT &&
	  g_zappy.tunnels[i].client.type == Z_CLIENT_PLAYER)
	send_broadcast_to(fd, i, msg);
      i += 1;
    }
  game_graphic_notify_all("pbc %d %s",
			  g_zappy.tunnels[fd].client.player.id,
			  msg);
  cir_buf_add_cmd(&g_zappy.tunnels[fd].cir_buf_out, "ok");
  return (0);
}