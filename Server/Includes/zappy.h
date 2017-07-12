/*
** zappy.h for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/zappy.h
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Jun 20 14:26:32 2017 Enguerrand Allamel
** Last update Tue Jun 20 14:26:32 2017 Enguerrand Allamel
*/

#ifndef PSU_2016_ZAPPY_ZAPPY_H
# define PSU_2016_ZAPPY_ZAPPY_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <signal.h>
# include <arpa/inet.h>
# include <sys/socket.h>
# include <stdbool.h>
# include <time.h>
# include <errno.h>
# include <math.h>
# include "utils.h"
# include "resources.h"
# include "elevation.h"
# include "arguments.h"
# include "game_graphic.h"
# include "game_player.h"
# include "game_time.h"
# include "game_map.h"
# include "clients.h"
# include "game_action.h"
# include "network.h"

# ifndef ZAPPY_FD_MAX
#  define ZAPPY_FD_MAX 255
# endif

# ifndef DEBUG
#  define DEBUG 0
# endif

# ifndef MSG_NOSIGNAL
#  define MSG_NOSIGNAL 0
# endif

typedef struct			s_zappy
{
  t_zappy_arguments		arguments;
  t_zappy_tunnel		tunnels[ZAPPY_FD_MAX];
  t_game_map			map;
  t_game_cmd_queue		*action_game;
  bool				end;
}				t_zappy;

extern t_zappy g_zappy;

/*
 * ERROR
 */
int 	exit_error(const char *text);

/*
 * LOG
 */
void	log_server(int fd, const char *format_data, ...);

/*
 * SIGNAL
 */
void	stop_server(int sig);

#endif //PSU_2016_ZAPPY_ZAPPY_H
