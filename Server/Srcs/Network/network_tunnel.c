/*
** network_tunnel.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/network_tunnel.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Jun 21 11:02:44 2017 Enguerrand Allamel
** Last update Wed Jun 21 11:02:44 2017 Enguerrand Allamel
*/

#include "zappy.h"

void		tunnel_init()
{
  size_t 	i;

  i = 0;
  while (i < ZAPPY_FD_MAX)
    {
      g_zappy.tunnels->type = Z_TYPE_NOT_SET;
      i += 1;
    }
}

int 	tunnel_close_client(int fd)
{
  if (g_zappy.tunnels[fd].type == Z_CLIENT)
    {
      if (g_zappy.tunnels[fd].client.type == Z_CLIENT_PLAYER)
	{
	  game_graphic_notify_all("pdi %d",
				  g_zappy.tunnels[fd].client.player.id);
	  g_zappy.arguments.solt_free_by_team[
		  g_zappy.tunnels[fd].client.player.team_id] += 1;
	}
      g_zappy.tunnels[fd].type = Z_TYPE_NOT_SET;
      g_zappy.tunnels[fd].ptr_func_write = NULL;
      g_zappy.tunnels[fd].ptr_func_read = NULL;
      if (g_zappy.tunnels[fd].cir_buf_in.buf)
	{
	  free(g_zappy.tunnels[fd].cir_buf_in.buf);
	  g_zappy.tunnels[fd].cir_buf_in.buf = NULL;
	}
      if (g_zappy.tunnels[fd].cir_buf_out.buf)
	{
	  free(g_zappy.tunnels[fd].cir_buf_out.buf);
	  g_zappy.tunnels[fd].cir_buf_out.buf = NULL;
	}
      g_zappy.tunnels[fd].client.type = Z_CLIENT_DEFAULT;
    }
  return (0);
}

int 			tunnel_add_client(int fd_server)
{
  int   		fd;
  struct sockaddr_in 	client_sin;
  socklen_t 		client_sin_len;

  client_sin_len = sizeof(client_sin);
  if ((fd = accept(fd_server, (struct sockaddr *)&client_sin,
		   &client_sin_len)) < 0)
    exit_error("Accept new client");
  if (cir_buf_init(&g_zappy.tunnels[fd].cir_buf_in, 4096) != 0 ||
      cir_buf_init(&g_zappy.tunnels[fd].cir_buf_out, 4096) != 0)
    exit_error("Fail init circular buffer or client");
  client_add(fd);
  g_zappy.tunnels[fd].type = Z_CLIENT;
  g_zappy.tunnels[fd].ptr_func_read = &client_read;
  g_zappy.tunnels[fd].ptr_func_write= &client_write;
  return (0);
}

int 			tunnel_add_server(unsigned short 	port)
{
  int 			fd;
  struct sockaddr_in 	sin;
  int 			i;

  if ((fd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
    return (-1);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = INADDR_ANY;
  i = 1;
  if (setsockopt(fd, SOL_SOCKET,
		 SO_REUSEPORT, &i,
		 sizeof(int)) < 0)
    return (-1);
  if (bind(fd, (struct sockaddr*)&sin, sizeof(sin)) < 0
      || listen(fd, 100) < 0)
    exit_error("Bind / Listen new server");
  g_zappy.tunnels[fd].type = Z_SERVER;
  g_zappy.tunnels[fd].ptr_func_read = &server_read;
  return (0);
}