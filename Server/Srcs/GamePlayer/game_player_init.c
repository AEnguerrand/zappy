/*
** game_player_init.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_player_init.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Jun 21 19:56:09 2017 Enguerrand Allamel
** Last update Wed Jun 21 19:56:09 2017 Enguerrand Allamel
*/

#include "zappy.h"

static void	game_player_init_define_pos(int fd)
{
  g_zappy.tunnels[fd].client.player.pos.x = rand() % (g_zappy.map.width -1);
  g_zappy.tunnels[fd].client.player.pos.y = rand() % (g_zappy.map.height - 1);
}

static void 	game_player_init_inventory(int fd)
{
  g_zappy.tunnels[fd].client.player.inventory[1] = 30;
  g_zappy.tunnels[fd].client.player.inventory[2] = 0;
  g_zappy.tunnels[fd].client.player.inventory[3] = 0;
  g_zappy.tunnels[fd].client.player.inventory[4] = 0;
  g_zappy.tunnels[fd].client.player.inventory[5] = 0;
  g_zappy.tunnels[fd].client.player.inventory[6] = 0;
  g_zappy.tunnels[fd].client.player.inventory[7] = 0;
}

static int 	game_player_send_init(int fd)
{
  cir_buf_add_cmd_v(&g_zappy.tunnels[fd].cir_buf_out, "%ld",
		    g_zappy.arguments.solt_free_by_team[
			    g_zappy.tunnels[fd].client.player.team_id]);
  cir_buf_add_cmd_v(&g_zappy.tunnels[fd].cir_buf_out, "%d %d",
		    g_zappy.map.width,
		    g_zappy.map.height);
  game_graphic_notify_all("pnw %d %d %d %d %d %s",
			  g_zappy.tunnels[fd].client.player.id,
			  g_zappy.tunnels[fd].client.player.pos.x,
			  g_zappy.tunnels[fd].client.player.pos.y,
			  g_zappy.tunnels[fd].client.player.dir,
			  g_zappy.tunnels[fd].client.player.level,
			  game_player_teams_get_name(
				  g_zappy.tunnels[fd].client.player.team_id));
  return (0);
}

static int 	game_player_add_b(int fd)
{
  game_player_init_inventory(fd);
  game_action_queue_push(ZAPPY_G_ACT_PLAYER_EAT, 126, fd,
			 g_zappy.tunnels[fd].client.player.team_id);
  if (game_player_send_init(fd) != 0)
    return (-1);
  log_server(fd, "ID: %ld, Team: [%s], Pos[X:%d - Y:%d], Dir: %d, Level: %d",
	     g_zappy.tunnels[fd].client.player.id,
	     game_player_teams_get_name(
		     g_zappy.tunnels[fd].client.player.team_id),
	     g_zappy.tunnels[fd].client.player.pos.x,
	     g_zappy.tunnels[fd].client.player.pos.y,
	     g_zappy.tunnels[fd].client.player.dir,
	     g_zappy.tunnels[fd].client.player.level);
  return (0);
}

int		game_player_add(int fd, const char *team_name)
{
  static size_t last_id = 0;

  g_zappy.tunnels[fd].client.player.id = last_id + 1;
  last_id += 1;
  g_zappy.tunnels[fd].client.type = Z_CLIENT_PLAYER;
  g_zappy.tunnels[fd].client.player.dir = Z_PLAYER_DIR_EAST;
  g_zappy.tunnels[fd].client.player.level = Z_LEVEL_1;
  g_zappy.tunnels[fd].client.player.first = NULL;
  game_player_init_define_pos(fd);
  if ((g_zappy.tunnels[fd].client.player.team_id =
	       game_player_teams_get_id(team_name)) == -1)
    return (-1);
  if (game_action_fork_free(g_zappy.tunnels[fd].client.player.team_id)
      == true)
    game_action_fork_use(g_zappy.tunnels[fd].client.player.team_id);
  else if (g_zappy.arguments.solt_free_by_team[
		   g_zappy.tunnels[fd].client.player.team_id] > 0)
    {
      g_zappy.arguments.solt_free_by_team[
	      g_zappy.tunnels[fd].client.player.team_id] -= 1;
    }
  else
    return (-1);
  return (game_player_add_b(fd));
}