/*
** log.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/log.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Sun Jun 25 16:58:17 2017 Enguerrand Allamel
** Last update Sun Jun 25 16:58:17 2017 Enguerrand Allamel
*/

#include "zappy.h"

void		log_server(int fd, const char *format_data, ...)
{
  va_list 	args;

  if (DEBUG)
    {
      printf("%s[Zappy Server][Client %d]%s ",
	     ANSI_COLOR_GREEN,
	     fd,
	     ANSI_COLOR_RESET);
      if (format_data)
	{
	  va_start(args, format_data);
	  vprintf(format_data, args);
	  va_end(args);
	}
      printf("\n");
    }
}