/*
** game_player_cmd_look.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_player_cmd_look.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Mon Jun 26 15:14:24 2017 Enguerrand Allamel
** Last update Mon Jun 26 15:14:24 2017 Enguerrand Allamel
*/

#include "zappy.h"

static t_zappy_resource_to_name g_zappy_resource_to_name[] =
	{
		{"food", FOOD},
		{"linemate", LINEMATE},
		{"deraumere", DERAUMERE},
		{"sibur", SIBUR},
		{"mendiane", MENDIANE},
		{"phiras", PHIRAS},
		{"thystame", THYSTAME},
		{NULL, RESSOURCE_DEFAULT}
	};

static void	print_info_case_player(int fd, t_pos pos, bool *is_first)
{
  size_t 	i;

  i = 0;
  while (i < game_player_nb_in_case(pos))
    {
      if (!*is_first)
	cir_buf_add_cmd_no_eol(&g_zappy.tunnels[fd].cir_buf_out, " ");
      *is_first = false;
      cir_buf_add_cmd_no_eol(&g_zappy.tunnels[fd].cir_buf_out, "player");
      i += 1;
    }
}

static void	print_info_case_ressources(int fd, t_pos pos, bool *is_first)
{
  int 		i;
  size_t 	a;
  size_t 	b;

  i = 0;
  while (g_zappy_resource_to_name[i].name)
    {
      a = g_zappy.map.ressources[(pos.y * g_zappy.map.width) + pos.x].
	      resources[i + 1];
      b = 0;
      while (b < a)
	{
	  if (!*is_first)
	    cir_buf_add_cmd_no_eol(&g_zappy.tunnels[fd].cir_buf_out, " ");
	  cir_buf_add_cmd_no_eol(&g_zappy.tunnels[fd].cir_buf_out,
				 g_zappy_resource_to_name[i].name);
	  *is_first = false;
	  b += 1;
	}
      i += 1;
    }
}

int		game_player_cmd_look_case(int fd, t_pos pos, bool *is_first)
{
  bool		is_first_case;

  if (pos.x < 0 || pos.x >= g_zappy.map.width ||
      pos.y < 0 || pos.y >= g_zappy.map.height)
    return (-1);
  if (!*is_first)
    cir_buf_add_cmd_no_eol(&g_zappy.tunnels[fd].cir_buf_out, ",");
  *is_first = false;
  is_first_case = true;
  print_info_case_player(fd, pos, &is_first_case);
  print_info_case_ressources(fd, pos, &is_first_case);
  return (0);
}

int 		game_player_cmd_look(int fd, const char *cmd)
{
  t_zappy_level level;
  bool		is_first;

  (void)cmd;
  is_first = true;
  level = Z_LEVEL_DEFAULT;
  cir_buf_add_cmd_no_eol(&g_zappy.tunnels[fd].cir_buf_out, "[");
  while (level <= g_zappy.tunnels[fd].client.player.level)
    {
      game_player_cmd_look_line(fd, level,
				g_zappy.tunnels[fd].client.player.dir,
				&is_first);
      level += 1;
    }
  cir_buf_add_cmd(&g_zappy.tunnels[fd].cir_buf_out, "]");
  return (0);
}