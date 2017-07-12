/*
** game_map.h for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_map.h
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Jun 20 16:11:43 2017 Enguerrand Allamel
** Last update Tue Jun 20 16:11:43 2017 Enguerrand Allamel
*/

#ifndef PSU_2016_ZAPPY_GAME_MAP_H
# define PSU_2016_ZAPPY_GAME_MAP_H

typedef struct		s_game_map_case
{
  size_t		resources[ZAPPY_RESSOURCES_MAX];
}			t_game_map_case;

typedef struct 		s_game_map
{
  int 			width;
  int 			height;
  t_game_map_case	*ressources;
  size_t 		all_ressources[ZAPPY_RESSOURCES_MAX];
}			t_game_map;

/*
 * GAME MAP
 */
int 	game_map_init();

int	game_map_get_case(t_pos pos, t_game_map_case *map_case);

void	game_map_debug();

/*
 * GAME MAP RESSOURCES
 */

bool	game_map_ressouces_has_this_ressources_ignore_food(t_pos 	pos,
							       size_t	*tab);

/*
 * GAME MAP GENERATION
 */
void	game_map_case_generation_init();

void	game_map_case_generation_update(size_t tab[ZAPPY_RESSOURCES_MAX]);

int 	game_map_case_generation_ressource(int x, int y);

int 	game_map_case_generation_re(t_zappy_resource resource);

#endif //PSU_2016_ZAPPY_GAME_MAP_H
