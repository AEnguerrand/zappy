/*
** main.c for  in /home/cauvin_m/Rendu/PSU_2016_zappy/Server/Srcs/
**
** Made by Maxime Cauvin
** Login   <maxime.cauvin@epitech.eu>
**
** Started on  Sun Jun 18 05:34:57 2017 Maxime Cauvin
** Last update Sun Jun 18 05:35:20 2017 Maxime Cauvin
*/

#include "zappy.h"

t_zappy	g_zappy;

void	stop_server(int sig)
{
  (void)sig;
  game_end();
  log_server(-1, "Good bye");
  exit(0);
}

int   main(int ac, const char **av)
{
  signal(SIGINT, &stop_server);
  if (arguments_get_all(ac, av) == -1)
    return (EXIT_FAILURE);
  g_zappy.action_game = NULL;
  g_zappy.end = false;
  game_map_init();
  network_init();
  return (EXIT_SUCCESS);
}
