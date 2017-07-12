/*
** game_player_cmd_incantation.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_player_cmd_incantation.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Mon Jun 26 18:44:56 2017 Enguerrand Allamel
** Last update Mon Jun 26 18:44:56 2017 Enguerrand Allamel
*/

#include "zappy.h"

static t_zappy_elevation_rule g_zappy_elevation_rule[] =
	{
		{Z_LEVEL_1, Z_LEVEL_2, 1, {0, 0, 1, 0, 0, 0, 0, 0}},
		{Z_LEVEL_2, Z_LEVEL_3, 2, {0, 0, 1, 1, 1, 0, 0, 0}},
		{Z_LEVEL_3, Z_LEVEL_4, 2, {0, 0, 2, 0, 1, 0, 2, 0}},
		{Z_LEVEL_4, Z_LEVEL_5, 4, {0, 0, 1, 1, 2, 0, 1, 0}},
		{Z_LEVEL_5, Z_LEVEL_6, 4, {0, 0, 1, 2, 1, 3, 0, 0}},
		{Z_LEVEL_6, Z_LEVEL_7, 6, {0, 0, 1, 2, 3, 0, 1, 0}},
		{Z_LEVEL_7, Z_LEVEL_8, 6, {0, 0, 2, 2, 2, 2, 2, 1}},
		{Z_LEVEL_DEFAULT, Z_LEVEL_DEFAULT, 0,
			{0, 0, 0, 0, 0, 0, 0, 0}},
	};

static int 	get_index_of_rule(t_zappy_level current_level)
{
  int 		i;

  i = 0;
  while (g_zappy_elevation_rule[i].level_current != Z_LEVEL_DEFAULT &&
	 g_zappy_elevation_rule[i].level_current != current_level)
    i += 1;
  if (g_zappy_elevation_rule[i].level_current == current_level)
    return (i);
  return (-1);
}

int 	game_player_cmd_incantation_start(int fd, const char *cmd)
{
  int 	idx_rule;

  (void)cmd;
  game_player_queue_push(fd, "IncantationFinish", 299);
  if ((idx_rule = get_index_of_rule(g_zappy.tunnels[fd].client.player.level))
      == -1)
    return (-1);
  if (game_player_nb_in_case_on_level(g_zappy.tunnels[fd].client.player.pos,
				      g_zappy_elevation_rule[idx_rule].
					      level_current)
      == g_zappy_elevation_rule[idx_rule].player_nb &&
	  game_map_ressouces_has_this_ressources_ignore_food(
		  g_zappy.tunnels[fd].client.player.pos,
		  g_zappy_elevation_rule[idx_rule].resources) == true)
    {
      game_graphic_player_send_inc_start_all(fd);
      game_player_in_case_start_up_level(
	      g_zappy.tunnels[fd].client.player.pos,
	      g_zappy.tunnels[fd].client.player.level);
      return (0);
    }
  cir_buf_add_cmd(&g_zappy.tunnels[fd].cir_buf_out, "ko");
  return (0);
}

int 	game_player_cmd_incantation_end(int fd, const char *cmd)
{
  int 	idx_rule;

  (void)cmd;
  if ((idx_rule = get_index_of_rule(g_zappy.tunnels[fd].client.player.level))
      == -1)
    return (-1);
  if (game_player_nb_in_case_on_level(g_zappy.tunnels[fd].client.player.pos,
				      g_zappy_elevation_rule[idx_rule].
					      level_current)
      == g_zappy_elevation_rule[idx_rule].player_nb &&
      game_map_ressouces_has_this_ressources_ignore_food(
	      g_zappy.tunnels[fd].client.player.pos,
	      g_zappy_elevation_rule[idx_rule].resources))
    {
      game_player_in_case_upgrade_level(g_zappy.tunnels[fd].client.player.pos,
					g_zappy_elevation_rule[idx_rule].
						level_current);
      return (0);
    }
  game_graphic_notify_all("pie %d %d %d",
			  g_zappy.tunnels[fd].client.player.pos.x,
			  g_zappy.tunnels[fd].client.player.pos.y, 0);
  cir_buf_add_cmd(&g_zappy.tunnels[fd].cir_buf_out, "ko");
  return (0);
}