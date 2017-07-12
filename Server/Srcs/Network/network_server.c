/*
** network_server.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/network_server.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Jun 21 11:46:49 2017 Enguerrand Allamel
** Last update Wed Jun 21 11:46:49 2017 Enguerrand Allamel
*/

#include "zappy.h"

int 	server_read(int fd)
{
  log_server(fd, "[Server] New client connect.\n");
  tunnel_add_client(fd);
  return (0);
}