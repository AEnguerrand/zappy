/*
** elevation.h for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/elevation.h
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Jun 20 14:27:21 2017 Enguerrand Allamel
** Last update Tue Jun 20 14:27:21 2017 Enguerrand Allamel
*/

#ifndef PSU_2016_ZAPPY_ELEVATION_H
# define PSU_2016_ZAPPY_ELEVATION_H

typedef enum 	e_zappy_level
{
  Z_LEVEL_DEFAULT = 0,
  Z_LEVEL_1 = 1,
  Z_LEVEL_2 = 2,
  Z_LEVEL_3 = 3,
  Z_LEVEL_4 = 4,
  Z_LEVEL_5 = 5,
  Z_LEVEL_6 = 6,
  Z_LEVEL_7 = 7,
  Z_LEVEL_8 = 8
}		t_zappy_level;

typedef struct		s_zappy_elevation_rule
{
  t_zappy_level		level_current;
  t_zappy_level		level_elevation;
  size_t 		player_nb;
  size_t		resources[ZAPPY_RESSOURCES_MAX];
}			t_zappy_elevation_rule;

#endif //PSU_2016_ZAPPY_ELEVATION_H
