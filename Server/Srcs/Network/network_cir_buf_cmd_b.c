/*
** network_cir_buf_cmd_b.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/network_cir_buf_cmd_b.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Sat Jul 01 23:36:24 2017 Enguerrand Allamel
** Last update Sat Jul 01 23:36:24 2017 Enguerrand Allamel
*/

#include "zappy.h"

int 		cir_buf_add_cmd_v_n_eol(t_zappy_cir_buf	*cir_buf,
					  const char	*format,
					  ...)
{
  va_list 	args;
  char 		cmd[2048];

  if (format)
    {
      bzero(cmd, 2048);
      va_start(args, format);
      if (vsnprintf(cmd, 2048, format, args) <= 0)
	return (-1);
      va_end(args);
      cir_buf_add_cmd_no_eol(cir_buf, cmd);
      return (0);
    }
  return (-1);
}