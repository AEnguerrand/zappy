/*
** game_player_cmd_look_line.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_player_cmd_look_line.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Thu Jun 29 10:52:17 2017 Enguerrand Allamel
** Last update Thu Jun 29 10:52:17 2017 Enguerrand Allamel
*/

#include "zappy.h"

static void	look_line_north(int fd, int dist, int lenght, bool *is_first)
{
  int 		i;
  t_pos		pos;

  i = 0;
  pos = g_zappy.tunnels[fd].client.player.pos;
  pos.y = pos_cirular(pos.y + dist, g_zappy.map.height);
  pos.x = pos_cirular(pos.x - dist, g_zappy.map.width);
  while (i < lenght)
    {
      game_player_cmd_look_case(fd, pos, is_first);
      pos.x = pos_cirular(pos.x + 1, g_zappy.map.width);
      i += 1;
    }
}

static void	look_line_east(int fd, int dist, int lenght, bool *is_first)
{
  int 		i;
  t_pos		pos;

  i = 0;
  pos = g_zappy.tunnels[fd].client.player.pos;
  pos.x = pos_cirular(pos.x + dist, g_zappy.map.width);
  pos.y = pos_cirular(pos.y + dist, g_zappy.map.height);
  while (i < lenght)
    {
      game_player_cmd_look_case(fd, pos, is_first);
      pos.y = pos_cirular(pos.y - 1, g_zappy.map.height);
      i += 1;
    }
}

static void	look_line_south(int fd, int dist, int lenght, bool *is_first)
{
  int 		i;
  t_pos		pos;

  i = 0;
  pos = g_zappy.tunnels[fd].client.player.pos;
  pos.y = pos_cirular(pos.y - dist, g_zappy.map.height);
  pos.x = pos_cirular(pos.x + dist, g_zappy.map.width);
  while (i < lenght)
    {
      game_player_cmd_look_case(fd, pos, is_first);
      pos.x = pos_cirular(pos.x - 1, g_zappy.map.width);
      i += 1;
    }
}

static void	look_line_west(int fd, int dist, int lenght, bool *is_first)
{
  int 		i;
  t_pos		pos;

  i = 0;
  pos = g_zappy.tunnels[fd].client.player.pos;
  pos.x = pos_cirular(pos.x - dist, g_zappy.map.width);
  pos.y = pos_cirular(pos.y - dist, g_zappy.map.height);
  while (i < lenght)
    {
      game_player_cmd_look_case(fd, pos, is_first);
      pos.y = pos_cirular(pos.y + 1, g_zappy.map.height);
      i += 1;
    }
}

int 	game_player_cmd_look_line(int			fd,
				     int 		dist,
				     t_game_player_dir 	dir,
				     bool 		*is_first)
{
  int 	lenght;

  if (dist < 0)
    return (-1);
  lenght = (dist * 2) + 1;
  if (dir == Z_PLAYER_DIR_NORTH)
    look_line_north(fd, dist, lenght, is_first);
  else if (dir == Z_PLAYER_DIR_EAST)
    look_line_east(fd, dist, lenght, is_first);
  else if (dir == Z_PLAYER_DIR_SOUTH)
    look_line_south(fd, dist, lenght, is_first);
  else if (dir == Z_PLAYER_DIR_WEST)
    look_line_west(fd, dist, lenght, is_first);
  return (0);
}