/*
** game_player_teams.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_player_teams.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Thu Jun 22 11:51:54 2017 Enguerrand Allamel
** Last update Thu Jun 22 11:51:54 2017 Enguerrand Allamel
*/

#include "zappy.h"

int 	game_player_teams_is_exist(const char *team_name)
{
  int 	i;

  i = 0;
  while (g_zappy.arguments.teams_name && g_zappy.arguments.teams_name[i] &&
	 strcmp(team_name, g_zappy.arguments.teams_name[i]) != 0)
    i += 1;
  if (g_zappy.arguments.teams_name && g_zappy.arguments.teams_name[i] &&
      strcmp(team_name, g_zappy.arguments.teams_name[i]) == 0)
    return (1);
  return (0);
}

int 	game_player_teams_get_id(const char *team_name)
{
  int 	i;

  i = 0;
  while (g_zappy.arguments.teams_name && g_zappy.arguments.teams_name[i] &&
	 strcmp(team_name, g_zappy.arguments.teams_name[i]) != 0)
    i += 1;
  if (g_zappy.arguments.teams_name && g_zappy.arguments.teams_name[i] &&
      strcmp(team_name, g_zappy.arguments.teams_name[i]) == 0)
    return (i);
  return (-1);
}

const char 	*game_player_teams_get_name(int team_id)
{
  if (team_id < 0 || team_id >= g_zappy.arguments.teams_nb)
    return (NULL);
  return (g_zappy.arguments.teams_name[team_id]);
}

int 	game_player_teams_init()
{
  int 	i;

  i = 0;
  if (!(g_zappy.arguments.solt_free_by_team =
		malloc(g_zappy.arguments.teams_nb * sizeof(int))))
    return (-1);
  while (i < g_zappy.arguments.teams_nb)
    {
      g_zappy.arguments.solt_free_by_team[i] =
	      g_zappy.arguments.teams_clients;
      i += 1;
    }
  return (0);
}