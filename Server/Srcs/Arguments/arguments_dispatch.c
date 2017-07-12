/*
** arguments_dispatch.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/arguments_dispatch.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Jun 20 18:25:28 2017 Enguerrand Allamel
** Last update Tue Jun 20 18:25:28 2017 Enguerrand Allamel
*/

#include "zappy.h"

int 	arguments_list_port(int *i, const char **av, const char opt)
{
  (void)opt;
  if (!av[*i] || (g_zappy.arguments.port = atoi(av[*i])) <= 0)
    {
      fprintf(stderr, "port only interger (> 0).\n");
      return (-1);
    }
  *i += 1;
  return (0);
}
int 	arguments_list_map(int *i, const char **av, const char opt)
{
  if (opt == 'x')
    {
      if (!av[*i] || (g_zappy.arguments.map_width = atoi(av[*i])) <= 0 ||
	  g_zappy.arguments.map_width > 30 ||
	  g_zappy.arguments.map_height < 10)
	{
	  fprintf(stderr, "map_width only interger between 10 and 30.\n");
	  return (-1);
	}
    }
  else
    {
      if (!av[*i] || (g_zappy.arguments.map_height = atoi(av[*i])) <= 0 ||
	  g_zappy.arguments.map_height > 30 ||
	  g_zappy.arguments.map_height < 10)
	{
	  fprintf(stderr, "map_height only interger between 10 and 30.\n");
	  return (-1);
	}
    }
  *i += 1;
  return (0);
}
int 		arguments_list_teams(int *i, const char **av, const char opt)
{
  size_t 	a;

  (void)opt;
  a = 0;
  while (av[*i + a] && av[*i + a][0] != '-')
    a += 1;
  if (!(g_zappy.arguments.teams_name = malloc((a + 1) * sizeof(char *))) ||
      null_double(g_zappy.arguments.teams_name, a + 1) != 0)
    return (-1);
  a = 0;
  while (av[*i] && av[*i][0] != '-')
    {
      if (game_player_teams_is_exist(av[*i]) == 1 ||
	  !(g_zappy.arguments.teams_name[a] = strdup(av[*i])))
	{
	  fprintf(stderr, "Teams is not unique / alerady exist.\n");
	  return (-1);
	}
      *i += 1;
      a += 1;
    }
  g_zappy.arguments.teams_nb = a;
  g_zappy.arguments.teams_name[a] = NULL;
  return (0);
}
int 	arguments_list_clients_nb(int *i, const char **av, const char opt)
{
  (void)opt;
  if (!av[*i] || (g_zappy.arguments.teams_clients = atoi(av[*i])) <= 0 ||
	  g_zappy.arguments.teams_clients > ZAPPY_FD_MAX - 10)
    {
      fprintf(stderr, "map_height only interger between 1 and %d.\n",
	      ZAPPY_FD_MAX - 10);
      return (-1);
    }
  *i += 1;
  return (0);
}
int 	arguments_list_freq(int *i, const char **av, const char opt)
{
  (void)opt;
  if (!av[*i] || (g_zappy.arguments.freq = (size_t)atoi(av[*i])) <= 0 ||
	  g_zappy.arguments.freq > 10000)
    {
      fprintf(stderr, "freq only interger (> 0 and <= 10000).\n");
      return (-1);
    }
  *i += 1;
  return (0);
}