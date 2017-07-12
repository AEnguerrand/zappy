/*
** game_graphic_cmd.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_graphic_cmd.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Sun Jul 02 02:53:39 2017 Enguerrand Allamel
** Last update Sun Jul 02 02:53:39 2017 Enguerrand Allamel
*/

#include "zappy.h"

static t_game_graphic_cmd g_graphic_cmd[] =
	{
		{"ppo", &game_graphic_cmd_player_ppo, true},
		{"pin", &game_graphic_cmd_player_inv, true},
		{"sgt", &game_graphic_cmd_time_sgt, false},
		{"sst", &game_graphic_cmd_time_sst, true},
		{NULL, NULL, false}
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

int 	game_graphic_cmd_exec(int fd, const char *cmd)
{
  int 	i;

  i = 0;
  while (g_graphic_cmd[i].cmd &&
	 ((!g_graphic_cmd[i].args &&
	   strcmp(cmd, g_graphic_cmd[i].cmd) != 0)
	  || (g_graphic_cmd[i].args &&
	      compare_cmd(g_graphic_cmd[i].cmd, cmd) == 0)))
    i += 1;
  if (g_graphic_cmd[i].cmd && g_graphic_cmd[i].ptr_func)
    {
      log_server(fd, "graphic exec: [%s]", cmd);
      return (g_graphic_cmd[i].ptr_func(fd, cmd));
    }
  cir_buf_add_cmd_v(&g_zappy.tunnels[fd].cir_buf_out, "Command not found"
			    " [%s]", cmd);
  return (0);
}
