/*
** arguments.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/arguments.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Jun 20 17:05:32 2017 Enguerrand Allamel
** Last update Tue Jun 20 17:05:32 2017 Enguerrand Allamel
*/

#include "zappy.h"

static t_zappy_arguments_func g_arguments_func[] =
	{
		{'p', &arguments_list_port},
		{'x', &arguments_list_map},
		{'y', &arguments_list_map},
		{'n', &arguments_list_teams},
		{'c', &arguments_list_clients_nb},
		{'f', &arguments_list_freq},
		{0, NULL}
	};

static void	arguments_print_debug()
{
  size_t 	i;

  printf("[ARGUMENTS] :\n");
  printf("port: %d\n", g_zappy.arguments.port);
  printf("map_width: %d\n", g_zappy.arguments.map_width);
  printf("map_height: %d\n", g_zappy.arguments.map_height);
  i = 0;
  while (g_zappy.arguments.teams_name && g_zappy.arguments.teams_name[i])
    {
      printf("Teams [ID: %ld] [Slot free: %d] : %s\n", i,
	     g_zappy.arguments.solt_free_by_team[i],
	     g_zappy.arguments.teams_name[i]);
      i += 1;
    }
  printf("freq: %ld\n", g_zappy.arguments.freq);
  printf("----------\n");
}

static void	arguments_print_usage(const char *bin_name)
{
  fprintf(stderr, "USAGE : %s -p port -x width -y height -n name1 name2 ..."
	  " -c clientsNb -f freq\n", bin_name);
  fprintf(stderr, "\tport\t\tis the port number\n");
  fprintf(stderr, "\twidth\t\tis the width of the world\n");
  fprintf(stderr, "\theight\t\tis the width of the world\n");
  fprintf(stderr, "\tnameX\t\tis the name of the team X\n");
  fprintf(stderr, "\tclientsNb\tis the number of authorized clients per"
	  " team\n");
  fprintf(stderr, "\tfreq\t\tis the reciprocal of time unit for execution of"
	  " actions\n");
}

static int 	arguments_dispatch(const char **av, int *idx, const char opt)
{
  int 		i;

  i = 0;
  while (g_arguments_func[i].opt != 0 && g_arguments_func[i].opt != opt)
    i += 1;
  if (g_arguments_func[i].opt != 0)
    {
      *idx += 1;
      return (g_arguments_func[i].ptr_func(idx, av, opt));
    }
  arguments_print_usage(av[0]);
  return (-1);
}

static void	arguments_init()
{
  g_zappy.arguments.port = 4242;
  g_zappy.arguments.map_width = 10;
  g_zappy.arguments.map_height = 10;
  g_zappy.arguments.teams_name = NULL;
  g_zappy.arguments.teams_clients = 3;
  g_zappy.arguments.freq = 100;
}

int 	arguments_get_all(int ac, const char **av)
{
  int 	i;

  i = 1;
  arguments_init();
  while (i < ac && av[i])
    {
      if (av[i][0] == '-' && av[i][1] && !av[i][2] && av[i + 1])
	{
	  if (arguments_dispatch(av, &i, av[i][1]) == -1)
	    {
	      arguments_print_usage(av[0]);
	      return (-1);
	    }
	}
      else
	{
	  arguments_print_usage(av[0]);
	  return (-1);
	}
    }
  if (game_player_teams_init() == -1)
    return (-1);
  arguments_print_debug();
  return (0);
}