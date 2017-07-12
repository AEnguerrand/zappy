/*
** game_graphic_map.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_graphic_map.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Jun 27 23:47:17 2017 Enguerrand Allamel
** Last update Tue Jun 27 23:47:17 2017 Enguerrand Allamel
*/

#include "zappy.h"

int	game_graphic_map_display_case(int fd, t_pos pos)
{
  if (pos.x < 0 || pos.x >= g_zappy.map.width ||
      pos.y < 0 || pos.y >= g_zappy.map.height)
    return (-1);
  cir_buf_add_cmd_v(&g_zappy.tunnels[fd].cir_buf_out,
		    "bct %d %d %d %d %d %d %d %d %d", pos.x,
		    pos.y,
		    g_zappy.map.ressources[(pos.y * g_zappy.map.width)
					   + pos.x].resources[1],
		    g_zappy.map.ressources[(pos.y * g_zappy.map.width)
					   + pos.x].resources[2],
		    g_zappy.map.ressources[(pos.y * g_zappy.map.width)
					   + pos.x].resources[3],
		    g_zappy.map.ressources[(pos.y * g_zappy.map.width)
					   + pos.x].resources[4],
		    g_zappy.map.ressources[(pos.y * g_zappy.map.width)
					   + pos.x].resources[5],
		    g_zappy.map.ressources[(pos.y * g_zappy.map.width)
					   + pos.x].resources[6],
		    g_zappy.map.ressources[(pos.y * g_zappy.map.width)
					   + pos.x].resources[7]);
  return (0);
}

int	game_graphic_map_display_all(int fd)
{
  t_pos	pos;

  pos.x = 0;
  pos.y = 0;
  while (pos.y < g_zappy.map.height)
    {
      pos.x = 0;
      while (pos.x < g_zappy.map.width)
	{
	  game_graphic_map_display_case(fd, pos);
	  pos.x += 1;
	}
      pos.y += 1;
    }
  return (0);
}

int 	game_graphic_send_map_pos_all(t_pos pos)
{

  int 		i;

  i = 0;
  while (i < ZAPPY_FD_MAX)
    {
      if (g_zappy.tunnels[i].type == Z_CLIENT &&
	  g_zappy.tunnels[i].client.type == Z_CLIENT_GRAPHIC)
	game_graphic_map_display_case(i, pos);
      i += 1;
    }
  return (0);
}

int 	game_graphic_send_map_all()
{

  int 		i;

  i = 0;
  while (i < ZAPPY_FD_MAX)
    {
      if (g_zappy.tunnels[i].type == Z_CLIENT &&
	  g_zappy.tunnels[i].client.type == Z_CLIENT_GRAPHIC)
	game_graphic_map_display_all(i);
      i += 1;
    }
  return (0);
}