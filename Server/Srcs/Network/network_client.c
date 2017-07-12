/*
** network_client.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/network_client.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Jun 21 15:09:03 2017 Enguerrand Allamel
** Last update Wed Jun 21 15:09:03 2017 Enguerrand Allamel
*/

#include "zappy.h"

static int 	client_close(int fd)
{
  shutdown(fd, SHUT_RDWR);
  close(fd);
  tunnel_close_client(fd);
  return (0);
}

int 		client_read(int fd)
{
  ssize_t 	r;
  ssize_t 	i;
  char 		buf[2048];

  bzero(buf, 2048);
  if ((r = read(fd, buf, 2048)) <= 0)
    {
      log_server(fd, "Connection closed. (READ)");
      return (client_close(fd));
    }
  i = 0;
  while (i < r)
    {
      if (cir_buf_push(&g_zappy.tunnels[fd].cir_buf_in, buf[i]) != 0)
	{
	  log_server(fd, "Fail push to circular buffer");
	  return (client_close(fd));

	}
      i += 1;
    }
  return (0);
}

int 		client_write(int fd)
{
  char 		cmd[2048];

  if (g_zappy.tunnels[fd].type == Z_TYPE_NOT_SET)
    return (-1);
  while (cir_buf_has_cmd(&g_zappy.tunnels[fd].cir_buf_out) == 1)
    {
      if ((cir_buf_get_cmd_eol(&g_zappy.tunnels[fd].cir_buf_out, cmd))
	  == false)
	return (0);
      log_server(fd, "Write for client: [%s]", cmd);
      if (send(fd, cmd, strlen(cmd), MSG_NOSIGNAL) <= 0 ||
	  strcmp("dead\n", cmd) == 0)
	{
	  log_server(fd, "Connection closed. (WRITE)");
	  return (client_close(fd));
	}
    }
  return (0);
}