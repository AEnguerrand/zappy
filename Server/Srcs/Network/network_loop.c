/*
** network_loop.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/network_loop.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Fri Jun 30 09:59:46 2017 Enguerrand Allamel
** Last update Fri Jun 30 09:59:46 2017 Enguerrand Allamel
*/

#include "zappy.h"

int 			network_loop_read(fd_set 		*fd_read,
					     struct timeval 	*tv,
					     long long 		*time_sub)
{
  int			fd_max;
  struct timespec	time_av;
  struct timespec	time_ap;

  FD_ZERO(fd_read);
  fd_max = network_init_fds(fd_read, NULL);
  tv->tv_sec = 0;
  tv->tv_usec = network_time_convert_nsec_to_usec(network_time_get_min());
  log_server(-1, "D: %ld\n", (long int)tv->tv_usec);
  if (clock_gettime(CLOCK_MONOTONIC, &time_av) == -1)
    exit_error("Clock get time fail (AV)");
  if (select(fd_max + 1, fd_read, NULL, NULL, (tv->tv_usec != -1) ? tv :
					      NULL) == -1)
    exit_error("Select fail (READ)");
  if (clock_gettime(CLOCK_MONOTONIC, &time_ap) == -1)
    exit_error("Clock get time fail (AP)");
  *time_sub = ((time_ap.tv_sec - time_av.tv_sec) * 1000000000)
	      + (time_ap.tv_nsec - time_av.tv_nsec);
  return (0);
}

int 	network_loop_exec(fd_set *fd_read, long long time_sub)
{
  int 	i;

  i = 0;
  game_queue_check(time_sub);
  while (i < ZAPPY_FD_MAX)
    {
      network_handle_data(i, fd_read, NULL);
      if (g_zappy.tunnels[i].type == Z_CLIENT)
	network_run_turn(i, time_sub);
      i += 1;
    }
  return (0);
}

int 	network_loop_write(fd_set 		*fd_write,
			      struct timeval 	*tv)
{
  int 	fd_max;
  int 	i;

  FD_ZERO(fd_write);
  fd_max = network_init_fds(NULL, fd_write);
  tv->tv_sec = 1;
  tv->tv_usec = 0;
  if (select(fd_max + 1, NULL, fd_write, NULL, tv) == -1)
    exit_error("Select fail (WRITE)");
  i = 0;
  while (i < ZAPPY_FD_MAX)
    {
      network_handle_data(i, NULL, fd_write);
      i += 1;
    }
  return (0);
}