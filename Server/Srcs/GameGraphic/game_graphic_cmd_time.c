/*
** game_graphic_cmd_time.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_graphic_cmd_time.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Sun Jul 02 03:31:22 2017 Enguerrand Allamel
** Last update Sun Jul 02 03:31:22 2017 Enguerrand Allamel
*/

#include "zappy.h"

int 		game_graphic_cmd_time_sgt(int fd, const char *cmd)
{
  (void)cmd;
  cir_buf_add_cmd_v(&g_zappy.tunnels[fd].cir_buf_out, "sgt %ld",
		    g_zappy.arguments.freq);
  return (0);
}

int 		game_graphic_cmd_time_sst(int fd, const char *cmd)
{
  int 		freq;
  const char 	*arg;

  if (!(arg = get_pos_args(cmd)) || (freq = atoi(arg)) <= 0 || freq > 10000)
    {
      cir_buf_add_cmd_v(&g_zappy.tunnels[fd].cir_buf_out, "freq only number"
	      " and > 0 and <= 10000");
      return (-1);
    }
  g_zappy.arguments.freq = (size_t)freq;
  cir_buf_add_cmd_v(&g_zappy.tunnels[fd].cir_buf_out, "sgt %ld",
		    g_zappy.arguments.freq);
  return (0);
}