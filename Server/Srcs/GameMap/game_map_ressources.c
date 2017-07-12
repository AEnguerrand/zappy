/*
** game_map_ressources.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_map_ressources.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Jun 27 12:22:47 2017 Enguerrand Allamel
** Last update Tue Jun 27 12:22:47 2017 Enguerrand Allamel
*/

#include "zappy.h"

bool	game_map_ressouces_has_this_ressources_ignore_food(t_pos 	pos,
							       size_t	*tab)
{
  int 	i;

  i = LINEMATE;
  if (pos.x < 0 || pos.x >= g_zappy.map.width ||
      pos.y < 0 || pos.y >= g_zappy.map.height)
    return (false);
  while (i < ZAPPY_RESSOURCES_MAX)
    {
      if (g_zappy.map.ressources[(pos.y * g_zappy.map.width) + pos.x].
	      resources[i] != tab[i])
	return (false);
      i += 1;
    }
  return (true);
}