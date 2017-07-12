/*
** game_player_cmd_obj.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_player_cmd_obj.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Mon Jun 26 15:42:41 2017 Enguerrand Allamel
** Last update Mon Jun 26 15:42:41 2017 Enguerrand Allamel
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

static t_zappy_resource	get_ressource_id_by_name(const char *name)
{
  int 			i;

  i = 0;
  if (!name)
    return (RESSOURCE_DEFAULT);
  while (g_zappy_resource_to_name[i].name &&
	 strcmp(g_zappy_resource_to_name[i].name, name) != 0)
    i += 1;
  if (g_zappy_resource_to_name[i].name)
    return (g_zappy_resource_to_name[i].id);
  return (RESSOURCE_DEFAULT);
}

int 			game_player_cmd_obj_take(int fd, const char *cmd)
{
  t_zappy_resource	resource;

  if ((resource = get_ressource_id_by_name(get_pos_args(cmd)))
      == RESSOURCE_DEFAULT)
    cir_buf_add_cmd(&g_zappy.tunnels[fd].cir_buf_out, "ko");
  else if (g_zappy.map.ressources[(g_zappy.tunnels[fd].client.player.pos.y *
	  g_zappy.map.width) +
	  g_zappy.tunnels[fd].client.player.pos.x].resources[resource] >= 1)
    {
      g_zappy.map.ressources[(g_zappy.tunnels[fd].client.player.pos.y *
	      g_zappy.map.width) +
	      g_zappy.tunnels[fd].client.player.pos.x].resources[resource]
	      -= 1;
      g_zappy.tunnels[fd].client.player.inventory[resource] += 1;
      game_graphic_notify_all("pgt %d %d",
			      g_zappy.tunnels[fd].client.player.id,
			      resource);
      game_graphic_player_send_inv_all(fd);
      game_map_case_generation_re(resource);
      cir_buf_add_cmd(&g_zappy.tunnels[fd].cir_buf_out, "ok");
    }
  else
    cir_buf_add_cmd(&g_zappy.tunnels[fd].cir_buf_out, "ko");
  return (0);
}

int 	game_player_cmd_obj_set(int fd, const char *cmd)
{
  t_zappy_resource	resource;

  if ((resource = get_ressource_id_by_name(get_pos_args(cmd)))
      == RESSOURCE_DEFAULT)
    cir_buf_add_cmd(&g_zappy.tunnels[fd].cir_buf_out, "ko");
  else if (g_zappy.tunnels[fd].client.player.inventory[resource] >= 1)
    {
      g_zappy.map.ressources[(g_zappy.tunnels[fd].client.player.pos.y *
	      g_zappy.map.width) +
	      g_zappy.tunnels[fd].client.player.pos.x].resources[resource]
	      += 1;
      g_zappy.tunnels[fd].client.player.inventory[resource] -= 1;
      game_graphic_notify_all("pdr %d %d",
			      g_zappy.tunnels[fd].client.player.id,
			      resource);
      game_graphic_player_send_inv_all(fd);
      game_graphic_send_map_pos_all(g_zappy.tunnels[fd].client.player.pos);
      cir_buf_add_cmd(&g_zappy.tunnels[fd].cir_buf_out, "ok");
    }
  else
    cir_buf_add_cmd(&g_zappy.tunnels[fd].cir_buf_out, "ko");
  return (0);
}