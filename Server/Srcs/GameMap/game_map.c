/*
** game_map.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_map.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Jun 21 17:49:47 2017 Enguerrand Allamel
** Last update Wed Jun 21 17:49:47 2017 Enguerrand Allamel
*/

#include "zappy.h"

int 		game_map_init()
{
  int 		x;
  int 		y;

  g_zappy.map.width = g_zappy.arguments.map_width;
  g_zappy.map.height = g_zappy.arguments.map_height;
  if (!(g_zappy.map.ressources
		= malloc((g_zappy.map.height * g_zappy.map.width) *
			 sizeof(t_game_map_case))))
    return (-1);
  game_map_case_generation_init();
  y = 0;
  while (y < g_zappy.map.height)
    {
      x = 0;
      while (x < g_zappy.map.width)
	{
	  game_map_case_generation_ressource(x, y);
	  x += 1;
	}
      y += 1;
    }
  if (DEBUG)
    game_map_debug();
  return (0);
}

void			game_map_debug()
{
  t_pos			pos;
  t_game_map_case	map_case;

  pos.x = 0;
  pos.y = 0;
  while (pos.y < g_zappy.map.height)
    {
      pos.x = 0;
      printf("%c%d:", (pos.y == 0 ? 0 : '\n'), pos.y);
      while (pos.x < g_zappy.map.width)
	{
	  if (game_map_get_case(pos, &map_case) != 0)
	    {
	      fprintf(stderr, "Error in map debug (case error)\n");
	      return;
	    }
	  printf(" [%ld,%ld,%ld,%ld,%ld,%ld,%ld]", map_case.resources[FOOD],
		 map_case.resources[LINEMATE], map_case.resources[DERAUMERE],
		 map_case.resources[SIBUR], map_case.resources[MENDIANE],
		 map_case.resources[PHIRAS], map_case.resources[THYSTAME]);
	  pos.x += 1;
	}
      pos.y += 1;
    }
  printf("\n----------\n");
}

int	game_map_get_case(t_pos pos, t_game_map_case *map_case)
{
  if (pos.x >= g_zappy.map.width || pos.y >= g_zappy.map.height)
    return (-1);
  *map_case = g_zappy.map.ressources[pos.y + (g_zappy.map.width * pos.x)];
  return (0);
}