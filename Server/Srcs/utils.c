/*
** utils.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/utils.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Mon Jun 26 16:35:51 2017 Enguerrand Allamel
** Last update Mon Jun 26 16:35:51 2017 Enguerrand Allamel
*/

#include "zappy.h"

const char	*get_pos_args(const char *cmd)
{
  const char	*pos;

  if (!cmd)
    return (NULL);
  else if (!(pos = strstr(cmd, " ")))
    return (NULL);
  else if (pos && (*pos != '\0')  && (*(pos + 1) != '\0'))
    return (pos + 1);
  return (NULL);
}

int	free_double(char **str)
{
  int 	i;

  if (!str)
    return (-1);
  i = 0;
  while (str && str[i])
    {
      free(str[i]);
      i += 1;
    }
  free(str);
  return (0);
}

int		null_double(char **str, size_t size)
{
  size_t 	i;

  if (!str)
    return (-1);
  i = 0;
  while (i < size)
    {
      str[i] = NULL;
      i += 1;
    }
  return (0);
}

int 	pos_cirular(int a, int b)
{
  int 	res;

  res = a % b;
  if (res < 0)
    return (res + b);
  else
  return (res);
}