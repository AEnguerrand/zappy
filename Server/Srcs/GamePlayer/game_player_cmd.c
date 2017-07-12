/*
** game_player_cmd.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_player_cmd.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Sun Jun 25 20:11:25 2017 Enguerrand Allamel
** Last update Sun Jun 25 20:11:25 2017 Enguerrand Allamel
*/

#include "zappy.h"

static t_game_player_cmd g_player_cmd[] =
	{
		{"Forward", 7, &game_player_cmd_move_forward, false},
		{"Right", 7, &game_player_cmd_move_right, false},
		{"Left", 7, &game_player_cmd_move_left, false},
		{"Look", 7, &game_player_cmd_look, false},
		{"Inventory", 1, &game_player_cmd_inventory, false},
		{"Broadcast", 7, &game_player_cmd_broadcast, true},
		{"Connect_nbr", 1, &game_player_cmd_player_connect_nbr,
			false},
		{"Fork", 1, &game_player_cmd_player_fork_start, false},
		{"Eject", 7, &game_player_cmd_eject, false},
		{"Take", 7, &game_player_cmd_obj_take, true},
		{"Set", 7, &game_player_cmd_obj_set, true},
		{"Incantation", 1, &game_player_cmd_incantation_start, false},
		{NULL, 0, NULL, false}
	};

static t_game_player_cmd g_player_cmd_srv[] =
	{
		{"Forward", 7, &game_player_cmd_move_forward, false},
		{"Right", 7, &game_player_cmd_move_right, false},
		{"Left", 7, &game_player_cmd_move_left, false},
		{"Look", 7, &game_player_cmd_look, false},
		{"Inventory", 1, &game_player_cmd_inventory, false},
		{"Broadcast", 7, &game_player_cmd_broadcast, true},
		{"Connect_nbr", 1, &game_player_cmd_player_connect_nbr,
			false},
		{"Fork", 1, &game_player_cmd_player_fork_start, false},
		{"ForkFinish", 41, &game_player_cmd_player_fork, false},
		{"Eject", 7, &game_player_cmd_eject, false},
		{"Take", 7, &game_player_cmd_obj_take, true},
		{"Set", 7, &game_player_cmd_obj_set, true},
		{"Incantation", 1, &game_player_cmd_incantation_start, false},
		{"IncantationFinish", 299, &game_player_cmd_incantation_end,
			false},
		{NULL, 0, NULL, false}
	};

static int 	compare_cmd(const char *cmd, const char *cmd_user)
{
  int		i;

  i = 0;
  while (cmd && cmd_user && cmd[i] && cmd_user[i] && cmd[i] == cmd_user[i])
    i += 1;
  if (cmd && cmd[i] == '\0')
    return (1);
  return (0);
}

int 	game_player_cmd_exec(int fd, const char *cmd)
{
  int 	i;

  i = 0;
  while (g_player_cmd_srv[i].cmd &&
	  ((!g_player_cmd_srv[i].args &&
	    strcmp(cmd, g_player_cmd_srv[i].cmd) != 0)
	   || (g_player_cmd_srv[i].args &&
	       compare_cmd(g_player_cmd_srv[i].cmd, cmd) == 0)))
    i += 1;
  if (g_player_cmd_srv[i].cmd && g_player_cmd_srv[i].ptr_func)
    {
      log_server(fd, "command exec: [%s]", cmd);
      return (g_player_cmd_srv[i].ptr_func(fd, cmd));
    }
  cir_buf_add_cmd(&g_zappy.tunnels[fd].cir_buf_out, "ko");
  return (0);
}

int 	game_player_cmd_read(int fd, const char *cmd)
{
  int 	i;

  i = 0;
  while (g_player_cmd[i].cmd &&
	 ((!g_player_cmd[i].args && strcmp(cmd, g_player_cmd[i].cmd) != 0)
	  || (g_player_cmd[i].args &&
	      compare_cmd(g_player_cmd[i].cmd, cmd) == 0)))
    i += 1;
  if (g_player_cmd[i].cmd)
    {
      log_server(fd, "command push: [%s]", cmd);
      game_player_queue_push(fd, cmd, g_player_cmd[i].time_unit);
      return (0);
    }
  cir_buf_add_cmd(&g_zappy.tunnels[fd].cir_buf_out, "ko");
  return (0);
}

