/*
** network_time.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/network_time.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Jun 28 10:10:17 2017 Enguerrand Allamel
** Last update Wed Jun 28 10:10:17 2017 Enguerrand Allamel
*/

#include "zappy.h"

long long 	network_time_get_min()
{
  long long 	min;
  int 		i;

  i = 0;
  min = game_action_queue_min_time();
  while (i < ZAPPY_FD_MAX)
    {
      if (g_zappy.tunnels[i].type == Z_CLIENT &&
	  g_zappy.tunnels[i].client.type == Z_CLIENT_PLAYER)
	{
	  if (g_zappy.tunnels[i].client.player.first &&
	      g_zappy.tunnels[i].client.player.first->is_start == true &&
		  (g_zappy.tunnels[i].client.player.first->time_interval
		   < min || min == -1))
	    min = g_zappy.tunnels[i].client.player.first->time_interval;
	}
      i += 1;
    }
  return (min);
}

long long	network_time_convert_unit_time_to_nsec(size_t unit_time)
{
  long long 	nsec;

  nsec = (long long)(((double)unit_time / g_zappy.arguments.freq) *
	  1000000000.0);
  return (nsec);
}

long int	network_time_convert_nsec_to_usec(long int nsec)
{
  long int 	usec;

  if (-1 == nsec)
    return (-1);
  usec = nsec / 1000;
  return (usec);
}