/*
** game_player_cmd_player.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_player_cmd_player.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Fri Jun 30 14:56:10 2017 Enguerrand Allamel
** Last update Fri Jun 30 14:56:10 2017 Enguerrand Allamel
*/

#include "zappy.h"

int 	game_player_cmd_player_connect_nbr(int fd, const char *cmd)
{
  (void)cmd;
  if (g_zappy.tunnels[fd].client.player.team_id < 0 ||
      g_zappy.tunnels[fd].client.player.team_id >= g_zappy.arguments.teams_nb)
    return (-1);
  cir_buf_add_cmd_v(&g_zappy.tunnels[fd].cir_buf_out, "%d",
		    g_zappy.arguments.solt_free_by_team[
			    g_zappy.tunnels[fd].client.player.team_id]);
  return (0);
}

int 	game_player_cmd_player_fork_start(int fd, const char *cmd)
{
  (void)cmd;
  game_player_queue_push(fd, "ForkFinish", 41);
  game_graphic_notify_all("pfk %d",
			  g_zappy.tunnels[fd].client.player.id);
  return (0);
}

int 		game_player_cmd_player_fork(int fd, const char *cmd)
{
  static int	l_id = 0;

  (void)cmd;
  if (g_zappy.tunnels[fd].client.player.team_id < 0 ||
      g_zappy.tunnels[fd].client.player.team_id >= g_zappy.arguments.teams_nb)
    return (-1);
  l_id += 1;
  if (l_id < 0)
    l_id = 0;
  game_action_queue_push(ZAPPY_G_ACT_FORK_END, 600, l_id,
			 g_zappy.tunnels[fd].client.player.team_id);
  game_graphic_notify_all("enw %d %d %d %d",
			  l_id,
			  g_zappy.tunnels[fd].client.player.id,
			  g_zappy.tunnels[fd].client.player.pos.x,
			  g_zappy.tunnels[fd].client.player.pos.y);
  g_zappy.arguments.solt_free_by_team[
	  g_zappy.tunnels[fd].client.player.team_id] += 1;
  cir_buf_add_cmd(&g_zappy.tunnels[fd].cir_buf_out, "ok");
  return (0);
}