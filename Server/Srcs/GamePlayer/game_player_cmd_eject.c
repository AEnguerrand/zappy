/*
** game_player_cmd_eject.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_player_cmd_eject.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Sat Jul 01 15:35:08 2017 Enguerrand Allamel
** Last update Sat Jul 01 15:35:08 2017 Enguerrand Allamel
*/

#include "zappy.h"

static void	move_player(int i, bool *alone)
{
  if (g_zappy.tunnels[i].client.player.dir == Z_PLAYER_DIR_NORTH)
    g_zappy.tunnels[i].client.player.pos.y =
	    pos_cirular(g_zappy.tunnels[i].client.player.pos.y + 1,
			g_zappy.map.height);
  else if (g_zappy.tunnels[i].client.player.dir == Z_PLAYER_DIR_SOUTH)
    g_zappy.tunnels[i].client.player.pos.y =
	    pos_cirular(g_zappy.tunnels[i].client.player.pos.y - 1,
			g_zappy.map.height);
  else if (g_zappy.tunnels[i].client.player.dir == Z_PLAYER_DIR_WEST)
    g_zappy.tunnels[i].client.player.pos.y =
	    pos_cirular(g_zappy.tunnels[i].client.player.pos.x + 1,
			g_zappy.map.width);
  else
    g_zappy.tunnels[i].client.player.pos.y =
	    pos_cirular(g_zappy.tunnels[i].client.player.pos.x - 1,
			g_zappy.map.width);

  *alone = false;
  game_graphic_notify_all("ppo %d %d %d %d",
			  g_zappy.tunnels[i].client.player.id,
			  g_zappy.tunnels[i].client.player.pos.x,
			  g_zappy.tunnels[i].client.player.pos.y,
			  g_zappy.tunnels[i].client.player.dir);
}

static void	check_player(int fd, int i, t_pos pos, bool *alone)
{
  if (i != fd &&
      g_zappy.tunnels[i].type == Z_CLIENT &&
      g_zappy.tunnels[i].client.type == Z_CLIENT_PLAYER &&
      g_zappy.tunnels[i].client.player.pos.x == pos.x &&
      g_zappy.tunnels[i].client.player.pos.y == pos.y)
    {
      if (alone == false)
	{
	  game_graphic_notify_all("pex %d",
				  g_zappy.tunnels[fd].client.player.id);
	}
      move_player(i, alone);
    }
}

int 		game_player_cmd_eject(int fd, const char *cmd)
{
  int 		i;
  t_pos		pos;
  bool		alone;

  (void)cmd;
  i = 0;
  alone = true;
  pos = g_zappy.tunnels[fd].client.player.pos;
  while (i < ZAPPY_FD_MAX)
    {
      check_player(fd, i, pos, &alone);
      i += 1;
    }
  if (alone == true)
    cir_buf_add_cmd(&g_zappy.tunnels[fd].cir_buf_out, "ko");
  else
    cir_buf_add_cmd(&g_zappy.tunnels[fd].cir_buf_out, "ok");
  return (0);
}