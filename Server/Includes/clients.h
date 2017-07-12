/*
** clients.h for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/clients.h
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Jun 20 15:31:26 2017 Enguerrand Allamel
** Last update Tue Jun 20 15:31:26 2017 Enguerrand Allamel
*/

#ifndef PSU_2016_ZAPPY_CLIENTS_H
# define PSU_2016_ZAPPY_CLIENTS_H

typedef enum 	e_zappy_client_type
{
  Z_CLIENT_DEFAULT = 0,
  Z_CLIENT_PLAYER = 1,
  Z_CLIENT_GRAPHIC = 2
}		t_zappy_client_type;

typedef struct 		s_zappy_client
{
  bool			is_log;
  t_zappy_client_type	type;
  t_game_player		player;
  t_game_graphic	graphic;
}			t_zappy_client;

/*
 * CLIENTS
 */
int 	client_add(int fd);

int 	client_login(int fd, const char *cmd);

#endif //PSU_2016_ZAPPY_CLIENTS_H
