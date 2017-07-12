/*
** game_player_cmd_move.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_player_cmd_move.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Mon Jun 26 10:51:01 2017 Enguerrand Allamel
** Last update Mon Jun 26 10:51:01 2017 Enguerrand Allamel
*/

#include "zappy.h"

int 	game_player_cmd_move_forward(int fd, const char *cmd)
{
  (void)cmd;
  if (g_zappy.tunnels[fd].client.player.dir == Z_PLAYER_DIR_NORTH)
    g_zappy.tunnels[fd].client.player.pos.y =
	    pos_cirular(g_zappy.tunnels[fd].client.player.pos.y + 1,
			g_zappy.map.height);
  else if (g_zappy.tunnels[fd].client.player.dir == Z_PLAYER_DIR_EAST)
    g_zappy.tunnels[fd].client.player.pos.x =
	    pos_cirular(g_zappy.tunnels[fd].client.player.pos.x + 1,
			g_zappy.map.width);
  else if (g_zappy.tunnels[fd].client.player.dir == Z_PLAYER_DIR_SOUTH)
    g_zappy.tunnels[fd].client.player.pos.y =
	    pos_cirular(g_zappy.tunnels[fd].client.player.pos.y - 1,
			g_zappy.map.height);
  else
    g_zappy.tunnels[fd].client.player.pos.x =
	    pos_cirular(g_zappy.tunnels[fd].client.player.pos.x - 1,
		      g_zappy.map.width);
  game_graphic_notify_all("ppo %d %d %d %d",
			  g_zappy.tunnels[fd].client.player.id,
			  g_zappy.tunnels[fd].client.player.pos.x,
			  g_zappy.tunnels[fd].client.player.pos.y,
			  g_zappy.tunnels[fd].client.player.dir);
  cir_buf_add_cmd(&g_zappy.tunnels[fd].cir_buf_out, "ok");
  return (0);
}

int 	game_player_cmd_move_right(int fd, const char *cmd)
{
  (void)cmd;
  if (g_zappy.tunnels[fd].client.player.dir >= 4)
    g_zappy.tunnels[fd].client.player.dir = (t_game_player_dir)1;
  else
    g_zappy.tunnels[fd].client.player.dir += 1;
  game_graphic_notify_all("ppo %d %d %d %d",
			  g_zappy.tunnels[fd].client.player.id,
			  g_zappy.tunnels[fd].client.player.pos.x,
			  g_zappy.tunnels[fd].client.player.pos.y,
			  g_zappy.tunnels[fd].client.player.dir);
  cir_buf_add_cmd(&g_zappy.tunnels[fd].cir_buf_out, "ok");
  return (0);
}

int 	game_player_cmd_move_left(int fd, const char *cmd)
{
  (void)cmd;
  if (g_zappy.tunnels[fd].client.player.dir <= 1)
    g_zappy.tunnels[fd].client.player.dir = (t_game_player_dir)4;
  else
    g_zappy.tunnels[fd].client.player.dir -= 1;
  game_graphic_notify_all("ppo %d %d %d %d",
			  g_zappy.tunnels[fd].client.player.id,
			  g_zappy.tunnels[fd].client.player.pos.x,
			  g_zappy.tunnels[fd].client.player.pos.y,
			  g_zappy.tunnels[fd].client.player.dir);
  cir_buf_add_cmd(&g_zappy.tunnels[fd].cir_buf_out, "ok");
  return (0);
}