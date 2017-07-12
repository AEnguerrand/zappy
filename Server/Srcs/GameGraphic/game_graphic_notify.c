/*
** game_graphic_notify.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_graphic_notify.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Jun 27 23:31:03 2017 Enguerrand Allamel
** Last update Tue Jun 27 23:31:03 2017 Enguerrand Allamel
*/

#include "zappy.h"

int 		game_graphic_notify_all(const char *format, ...)
{
  va_list 	args;
  char 		cmd[512];
  int 		i;

  if (format)
    {
      bzero(cmd, 512);
      va_start(args, format);
      if (vsnprintf(cmd, 512, format, args) <= 0)
	return (-1);
      va_end(args);
      i = 0;
      while (i < ZAPPY_FD_MAX)
	{
	  if (g_zappy.tunnels[i].type == Z_CLIENT &&
	      g_zappy.tunnels[i].client.type == Z_CLIENT_GRAPHIC)
	    cir_buf_add_cmd(&g_zappy.tunnels[i].cir_buf_out, cmd);
	  i += 1;
	}
      return (0);
    }
  return (0);
}

int 		game_graphic_notify_all_n_eol(const char *format, ...)
{
  va_list 	args;
  char 		cmd[512];
  int 		i;

  if (format)
    {
      bzero(cmd, 512);
      va_start(args, format);
      if (vsnprintf(cmd, 512, format, args) <= 0)
	return (-1);
      va_end(args);
      i = 0;
      while (i < ZAPPY_FD_MAX)
	{
	  if (g_zappy.tunnels[i].type == Z_CLIENT &&
	      g_zappy.tunnels[i].client.type == Z_CLIENT_GRAPHIC)
	    cir_buf_add_cmd_no_eol(&g_zappy.tunnels[i].cir_buf_out, cmd);
	  i += 1;
	}
      return (0);
    }
  return (0);
}