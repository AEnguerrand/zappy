/*
** game_graphic_cmd_player.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_graphic_cmd_player.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Sun Jul 02 03:09:28 2017 Enguerrand Allamel
** Last update Sun Jul 02 03:09:28 2017 Enguerrand Allamel
*/

#include "zappy.h"

static int 	ppo_turn(int fd, int i, int id)
{
  if (g_zappy.tunnels[i].type == Z_CLIENT &&
      g_zappy.tunnels[i].client.type == Z_CLIENT_PLAYER &&
      g_zappy.tunnels[i].client.player.id == (size_t)id)
    {
      cir_buf_add_cmd_v(&g_zappy.tunnels[fd].cir_buf_out,
			"ppo %d %d %d %d",
			g_zappy.tunnels[i].client.player.id,
			g_zappy.tunnels[i].client.player.pos.x,
			g_zappy.tunnels[i].client.player.pos.y,
			g_zappy.tunnels[i].client.player.dir);
      return (1);
    }
  return (0);
}

int 		game_graphic_cmd_player_ppo(int fd, const char *cmd)
{
  int 		i;
  int 		id;
  const char 	*arg;

  if (!(arg = get_pos_args(cmd)) || (id = atoi(arg)) < 0)
    {
      cir_buf_add_cmd_v(&g_zappy.tunnels[fd].cir_buf_out, "id only number");
      return (-1);
    }
  i = 0;
  while (i < ZAPPY_FD_MAX)
    {
      if (ppo_turn(fd, i, id) == 1)
	return (0);
      i += 1;
    }
  cir_buf_add_cmd_v(&g_zappy.tunnels[fd].cir_buf_out, "id player not found");
  return (-1);
}

static int 	pin_turn(int fd, int i, int id)
{
  if (g_zappy.tunnels[i].type == Z_CLIENT &&
      g_zappy.tunnels[i].client.type == Z_CLIENT_PLAYER &&
      g_zappy.tunnels[i].client.player.id == (size_t)id)
    {
      cir_buf_add_cmd_v(&g_zappy.tunnels[fd].cir_buf_out,
			"pin %d %d %d %d %d %d %d %d %d %d",
			g_zappy.tunnels[i].client.player.id,
			g_zappy.tunnels[i].client.player.pos.x,
			g_zappy.tunnels[i].client.player.pos.y,
			g_zappy.tunnels[i].client.player.inventory[1],
			g_zappy.tunnels[i].client.player.inventory[2],
			g_zappy.tunnels[i].client.player.inventory[3],
			g_zappy.tunnels[i].client.player.inventory[4],
			g_zappy.tunnels[i].client.player.inventory[5],
			g_zappy.tunnels[i].client.player.inventory[6],
			g_zappy.tunnels[i].client.player.inventory[7]);
      return (1);
    }
  return (0);
}

int 		game_graphic_cmd_player_inv(int fd, const char *cmd)
{
  int 		i;
  int 		id;
  const char 	*arg;

  if (!(arg = get_pos_args(cmd)) || (id = atoi(arg)) < 0)
    {
      cir_buf_add_cmd_v(&g_zappy.tunnels[fd].cir_buf_out, "id only number");
      return (-1);
    }
  i = 0;
  while (i < ZAPPY_FD_MAX)
    {
      if (pin_turn(fd, i, id) == 1)
	return (0);
      i += 1;
    }
  cir_buf_add_cmd_v(&g_zappy.tunnels[fd].cir_buf_out, "id player not found");
  return (-1);
}