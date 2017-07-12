/*
** game_map_generation.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_map_generation.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Sun Jul 02 11:19:00 2017 Enguerrand Allamel
** Last update Sun Jul 02 11:19:00 2017 Enguerrand Allamel
*/

#include "zappy.h"

void	game_map_case_generation_init()
{
  int 	i;

  i = 0;
  while (i < ZAPPY_RESSOURCES_MAX)
    {
      g_zappy.map.all_ressources[i] = 0;
      i += 1;
    }
}

void	game_map_case_generation_update(size_t tab[ZAPPY_RESSOURCES_MAX])
{
  int 	i;

  i = 0;
  while (i < ZAPPY_RESSOURCES_MAX)
    {
      g_zappy.map.all_ressources[i] = tab[i];
      i += 1;
    }
}

int 		game_map_case_generation_ressource(int x, int y)
{
  int 		idx;
  time_t	t;

  if (x < 0 || x >= g_zappy.map.width ||
      y < 0 || y >= g_zappy.map.height)
    return (-1);
  idx = (y * g_zappy.map.width) + x;
  srand(((unsigned)time(&t)) + ((unsigned)clock()));
  g_zappy.map.ressources[idx].resources[FOOD] =
	  (size_t)(rand() % 4) + 3;
  g_zappy.map.ressources[idx].resources[LINEMATE] =
	  (size_t)(rand() % 2) == 1 ? 2 : 0;
  g_zappy.map.ressources[idx].resources[DERAUMERE] =
	  (size_t)(rand() % 4) == 3 ? 1 : 0;
  g_zappy.map.ressources[idx].resources[SIBUR] =
	  (size_t)(rand() % 4) == 3 ? 1 : 0;
  g_zappy.map.ressources[idx].resources[MENDIANE] =
	  (size_t)(rand() % 7) == 6 ? 2 : 0;
  g_zappy.map.ressources[idx].resources[PHIRAS] =
	  (size_t)(rand() % 10) == 9 ? 3 : 0;
  g_zappy.map.ressources[idx].resources[THYSTAME] =
	  (size_t)(rand() % 20) == 19 ? 1 : 0;
  game_map_case_generation_update(g_zappy.map.ressources[idx].resources);
  return (0);
}

int 		game_map_case_generation_re(t_zappy_resource resource)
{
  int 		idx;
  time_t	t;
  t_pos		pos;

  if ((int)resource < 0 || (int)resource >= ZAPPY_RESSOURCES_MAX)
    return (-1);
  srand(((unsigned)time(&t)) + ((unsigned)clock()));
  pos.x = rand() % g_zappy.map.width;
  pos.y = rand() % g_zappy.map.height;
  idx = (pos.y * g_zappy.map.width) + pos.x;
  g_zappy.map.ressources[idx].resources[resource] += 1;
  game_map_case_generation_update(g_zappy.map.ressources[idx].resources);
  game_graphic_send_map_pos_all(pos);
  return (0);
}