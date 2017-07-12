/*
** network_start.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/network_start.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Jun 20 20:51:17 2017 Enguerrand Allamel
** Last update Tue Jun 20 20:51:17 2017 Enguerrand Allamel
*/

#include "zappy.h"

int		network_init_fds(fd_set *fd_read, fd_set *fd_write)
{
  int 		i;
  int 		res;

  i = 0;
  res = 0;
  while (i < ZAPPY_FD_MAX)
    {
      if (g_zappy.tunnels[i].type != Z_TYPE_NOT_SET)
	{
	  if (fd_read)
	    FD_SET(i, fd_read);
	  else if (fd_write)
	    FD_SET(i, fd_write);
	  res = i;
	}
      i += 1;
    }
  return (res);
}

int 		network_handle_data(int i, fd_set *fd_read, fd_set *fd_write)
{
  if (fd_read && FD_ISSET(i, fd_read) && g_zappy.tunnels[i].ptr_func_read)
    {
      g_zappy.tunnels[i].ptr_func_read(i);
    }
  if (fd_write && FD_ISSET(i, fd_write) && g_zappy.tunnels[i].ptr_func_write)
    {
      g_zappy.tunnels[i].ptr_func_write(i);
    }
  return (0);
}

void		network_run_turn(int fd, long long time_sub)
{
  char 		last_cmd[2048];
  bool		has_cmd;

  has_cmd = cir_buf_get_cmd(&g_zappy.tunnels[fd].cir_buf_in, last_cmd);
  if (has_cmd && !g_zappy.tunnels[fd].client.is_log)
    client_login(fd, last_cmd);
  else if (has_cmd && g_zappy.tunnels[fd].client.is_log &&
	  g_zappy.tunnels[fd].client.type == Z_CLIENT_PLAYER)
    game_player_cmd_read(fd, last_cmd);
  else if (has_cmd && g_zappy.tunnels[fd].client.is_log &&
	  g_zappy.tunnels[fd].client.type == Z_CLIENT_GRAPHIC)
    game_graphic_cmd_exec(fd, last_cmd);
  if (g_zappy.tunnels[fd].client.is_log &&
      g_zappy.tunnels[fd].client.type == Z_CLIENT_PLAYER)
    game_player_queue_check(fd, time_sub);
}

int		network_handle_loop(fd_set 		*fd_read,
				       fd_set 		*fd_write,
				       struct timeval 	*tv)
{
  long long 	time_sub;

  network_loop_read(fd_read, tv, &time_sub);
  network_loop_exec(fd_read, time_sub);
  network_loop_write(fd_write, tv);
  return (0);
}

int 			network_init()
{
  struct timeval	tv;
  fd_set  		fd_read;
  fd_set		fd_write;

  tunnel_init();
  tunnel_add_server(g_zappy.arguments.port);
  tv.tv_sec = 20;
  tv.tv_usec = 0;
  while (g_zappy.end == false)
    network_handle_loop(&fd_read, &fd_write, &tv);
  game_end();
  log_server(-1, "Good bye");
  return (0);
}