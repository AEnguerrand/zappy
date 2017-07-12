/*
** time.h for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_time.h
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Jun 20 15:01:20 2017 Enguerrand Allamel
** Last update Tue Jun 20 15:01:20 2017 Enguerrand Allamel
*/

#ifndef PSU_2016_ZAPPY_GAMETIME_H
# define PSU_2016_ZAPPY_GAMETIME_H

/*
 * NETWORK TIME
 */
long long 	network_time_get_min();

long long	network_time_convert_unit_time_to_nsec(size_t unit_time);

long int	network_time_convert_nsec_to_usec(long int nsec);

#endif //PSU_2016_ZAPPY_GAMETIME_H
