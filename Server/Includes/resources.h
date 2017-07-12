/*
** resources.h for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/resources.h
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Jun 20 14:22:53 2017 Enguerrand Allamel
** Last update Tue Jun 20 14:22:53 2017 Enguerrand Allamel
*/

#ifndef PSU_2016_ZAPPY_RESOURCES_H
# define PSU_2016_ZAPPY_RESOURCES_H

# ifndef ZAPPY_RESSOURCES_MAX
#  define ZAPPY_RESSOURCES_MAX 8
# endif

typedef enum 	e_zappy_resource
{
  RESSOURCE_DEFAULT = 0,
  FOOD = 1,
  LINEMATE = 2,
  DERAUMERE = 3,
  SIBUR = 4,
  MENDIANE = 5,
  PHIRAS = 6,
  THYSTAME = 7
}		t_zappy_resource;

typedef struct 		s_zappy_resource_to_name
{
  const char 		*name;
  t_zappy_resource	id;
}			t_zappy_resource_to_name;

#endif //PSU_2016_ZAPPY_RESOURCES_H
