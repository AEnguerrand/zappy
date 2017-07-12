/*
** game_graphic_incantation.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_graphic_incantation.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Sat Jul 01 23:39:39 2017 Enguerrand Allamel
** Last update Sat Jul 01 23:39:39 2017 Enguerrand Allamel
*/

#include "zappy.h"

static void	check_turn_start(size_t *a, size_t max, size_t i, int fd)
{
  if (g_zappy.tunnels[i].type == Z_CLIENT &&
      g_zappy.tunnels[i].client.type == Z_CLIENT_PLAYER &&
      g_zappy.tunnels[i].client.player.level ==
      g_zappy.tunnels[fd].client.player.level &&
      g_zappy.tunnels[i].client.player.pos.x ==
      g_zappy.tunnels[fd].client.player.pos.x &&
      g_zappy.tunnels[i].client.player.pos.y ==
      g_zappy.tunnels[fd].client.player.pos.y)
    {
      if (*a + 1 >= max)
	game_graphic_notify_all(" %d",
				g_zappy.tunnels[i].client.player.id);
      else
	game_graphic_notify_all_n_eol(" %d",
				      g_zappy.tunnels[i].client.player.id);
      *a += 1;
    }
}

int 		game_graphic_player_send_inc_start_all(int fd)
{
  size_t 	i;
  size_t 	a;
  size_t 	max;

  game_graphic_notify_all_n_eol("pic %d %d %d",
				g_zappy.tunnels[fd].client.player.pos.x,
				g_zappy.tunnels[fd].client.player.pos.y,
				(int)g_zappy.tunnels[fd].client.player.level);
  max = game_player_nb_in_case_on_level(g_zappy.tunnels[fd].client.player.pos,
					g_zappy.tunnels[fd].client.player.
						level);
  i = 0;
  a = 0;
  while (i < ZAPPY_FD_MAX)
    {
      check_turn_start(&a, max, i, fd);
      i += 1;
    }
  return (0);
}