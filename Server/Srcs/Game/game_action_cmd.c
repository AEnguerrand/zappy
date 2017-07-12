/*
** game_action_cmd.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_action_cmd.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Fri Jun 30 15:40:28 2017 Enguerrand Allamel
** Last update Fri Jun 30 15:40:28 2017 Enguerrand Allamel
*/

#include "zappy.h"

static t_game_action_cmd g_game_action_cmd[] =
	{
		{ZAPPY_G_ACT_FORK_END, &game_action_fork_remove},
		{ZAPPY_G_ACT_PLAYER_EAT, &game_action_eat},
		{ZAPPY_G_ACT_DEFAULT, NULL}
	};

int 	game_action_cmd_exec(int id, int team_id, t_game_action_type cmd)
{
  int 	i;

  i = 0;
  while (g_game_action_cmd[i].type != ZAPPY_G_ACT_DEFAULT &&
	  cmd != g_game_action_cmd[i].type)
    i += 1;
  if (g_game_action_cmd[i].type != ZAPPY_G_ACT_DEFAULT &&
      g_game_action_cmd[i].ptr_func)
    {
      log_server(id, "command action exec: [%d]", cmd);
      return (g_game_action_cmd[i].ptr_func(id, team_id, cmd));
    }
  return (0);
}