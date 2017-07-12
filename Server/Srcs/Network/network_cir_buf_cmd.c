/*
** network_cir_buf_cmd.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/network_cir_buf_cmd.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Jun 21 20:19:22 2017 Enguerrand Allamel
** Last update Wed Jun 21 20:19:22 2017 Enguerrand Allamel
*/

#include "zappy.h"

bool 		cir_buf_get_cmd(t_zappy_cir_buf	*cir_buf,
				    char 	cmd[2048])
{
  char 		data;
  size_t	i;

  if (!cir_buf || cir_buf_has_cmd(cir_buf) != 1 ||
      !memset(cmd, 0, 2048))
    return (false);
  i = 0;
  while (cir_buf_pop(cir_buf, &data) == 0 && i < 2048)
    {
      cmd[i] = data;
      if (data == '\n')
	{
	  cmd[i] = '\0';
	  return (true);
	}
      i += 1;
    }
  return (false);
}

bool 		cir_buf_get_cmd_eol(t_zappy_cir_buf	*cir_buf,
					 char 		cmd[2048])
{
  char 		data;
  size_t	i;

  if (!cir_buf || cir_buf_has_cmd(cir_buf) != 1 ||
      !memset(cmd, 0, 2048))
    return (false);
  i = 0;
  while (cir_buf_pop(cir_buf, &data) == 0 && i < 2048)
    {
      cmd[i] = data;
      if (data == '\n')
	{
	  cmd[i + 1] = '\0';
	  return (true);
	}
      i += 1;
    }
  return (false);
}

int 		cir_buf_add_cmd(t_zappy_cir_buf *cir_buf, const char *cmd)
{
  size_t 	i;

  if (!cmd)
    return (-1);
  i = 0;
  while (i < strlen(cmd))
    {
      if (cir_buf_push(cir_buf, cmd[i]) != 0)
	log_server(-1, "FAIL PUSH");
      i += 1;
    }
  if (cir_buf_push(cir_buf, '\n') != 0)
    log_server(-1, "FAIL PUSH");
  return (0);
}

int 		cir_buf_add_cmd_no_eol(t_zappy_cir_buf	*cir_buf,
					  const char	*cmd)
{
  size_t 	i;

  if (!cmd)
    return (-1);
  i = 0;
  while (i < strlen(cmd))
    {
      cir_buf_push(cir_buf, cmd[i]);
      i += 1;
    }
  return (0);
}

int 		cir_buf_add_cmd_v(t_zappy_cir_buf	*cir_buf,
				     const char		*format,
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
      cir_buf_add_cmd(cir_buf, cmd);
      return (0);
    }
  return (-1);
}