/*
** game_player_sound.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_player_sound.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Sat Jul 01 11:28:56 2017 Enguerrand Allamel
** Last update Sat Jul 01 11:28:56 2017 Enguerrand Allamel
*/

#include "zappy.h"

static int	get_min_dist(int a, int b, int dist)
{
  if (abs(a - b) > abs(a - (-dist + 1 + b)))
    return (-dist + 1 + b);
  else if (abs(a - b) > abs(a - (dist - 1 + b)))
    return (dist - 1 + b);
  else
    return (b);
}

static int 	calc_x1(int fd_rec)
{
  if (g_zappy.tunnels[fd_rec].client.player.dir == Z_PLAYER_DIR_EAST)
    return (g_zappy.tunnels[fd_rec].client.player.pos.x + 1);
  else if (g_zappy.tunnels[fd_rec].client.player.dir == Z_PLAYER_DIR_WEST)
    return (g_zappy.tunnels[fd_rec].client.player.pos.x - 1);
  else
    return (g_zappy.tunnels[fd_rec].client.player.pos.x);
}

static int 	calc_y1(int fd_rec)
{
  if (g_zappy.tunnels[fd_rec].client.player.dir == Z_PLAYER_DIR_SOUTH)
    return (g_zappy.tunnels[fd_rec].client.player.pos.y - 1);
  else if (g_zappy.tunnels[fd_rec].client.player.dir == Z_PLAYER_DIR_NORTH)
    return (g_zappy.tunnels[fd_rec].client.player.pos.y + 1);
  else
    return (g_zappy.tunnels[fd_rec].client.player.pos.y);
}

static void	init_pos_s(t_pos *pos, int fd_send, int fd_rec)
{
  pos->x = get_min_dist(g_zappy.tunnels[fd_rec].client.player.pos.x,
		       g_zappy.tunnels[fd_send].client.player.pos.x,
		       g_zappy.map.width);
  pos->y = get_min_dist(g_zappy.tunnels[fd_rec].client.player.pos.y,
		       g_zappy.tunnels[fd_send].client.player.pos.y,
		       g_zappy.map.height);
}

int		game_player_sound_get_sound_pos(int fd_send, int fd_rec)
{
  t_pos		pos;
  double	an;
  double	ux;
  double	uy;
  double	vx;
  double	vy;

  if (g_zappy.tunnels[fd_rec].client.player.pos.x ==
      g_zappy.tunnels[fd_send].client.player.pos.x &&
      g_zappy.tunnels[fd_rec].client.player.pos.y ==
      g_zappy.tunnels[fd_send].client.player.pos.y)
    return (0);
  init_pos_s(&pos, fd_send, fd_rec);
  ux = (double)pos.x - g_zappy.tunnels[fd_rec].client.player.pos.x;
  uy = (double)pos.y - g_zappy.tunnels[fd_rec].client.player.pos.y;
  vx = (double)calc_x1(fd_rec) - g_zappy.tunnels[fd_rec].client.player.pos.x;
  vy = (double)calc_y1(fd_rec) - g_zappy.tunnels[fd_rec].client.player.pos.y;
  an = (double)((ux * vx + uy * vy) /
	  (sqrt(fabs(ux * ux + uy * uy)) * sqrt(fabs(vx * vx + vy * vy))));
  return (game_player_sound_check_sound(
	  an, ((ux * vy - uy * vx) > 0) ? (1) : (-1)));
}
