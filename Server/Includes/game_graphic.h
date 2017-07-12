/*
** protocol_graphic.h for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/protocol_graphic.h
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Jun 20 15:30:00 2017 Enguerrand Allamel
** Last update Tue Jun 20 15:30:00 2017 Enguerrand Allamel
*/

#ifndef PSU_2016_ZAPPY_GAME_GRAPHIC_H
# define PSU_2016_ZAPPY_GAME_GRAPHIC_H

typedef struct	t_game_graphic_cmd
{
  const char	*cmd;
  int 		(*ptr_func)(int fd, const char *cmd);
  bool		args;
}		t_game_graphic_cmd;

typedef struct 	s_game_graphic
{
}		t_game_graphic;

/*
 * GAME GRAPHIC INIT
 */
int	game_graphic_add(int fd);

int 	game_graphic_login_display(int fd);

/*
 * GAME GRAPHIC NOTIFY
 */
int 	game_graphic_notify_all(const char *format, ...);

int 	game_graphic_notify_all_n_eol(const char *format, ...);

/*
 * GAME GRAPHIC MAP
 */
int 	game_graphic_map_display_case(int fd, t_pos pos);

int 	game_graphic_map_display_all(int fd);

int 	game_graphic_send_map_pos_all(t_pos pos);

int 	game_graphic_send_map_all();

/*
 * GAME GRAPHIC PLAYER
 */
int 	game_graphic_player_teams(int fd);

int 	game_graphic_player_send_inv_all(int fd);

/*
 * GAME GRAPHIC INCANTATION
 */
int 	game_graphic_player_send_inc_start_all(int fd);

/*
 * GAME GRAPHIC CMD
 */
int 	game_graphic_cmd_exec(int fd, const char *cmd);

/*
 * GAME GRAPHIC CMD PLAYER
 */
int 	game_graphic_cmd_player_ppo(int fd, const char *cmd);

int 	game_graphic_cmd_player_inv(int fd, const char *cmd);

/*
 * GAME GRAPHIC CMD TIME
 */
int 	game_graphic_cmd_time_sgt(int fd, const char *cmd);

int 	game_graphic_cmd_time_sst(int fd, const char *cmd);

#endif //PSU_2016_ZAPPY_GAME_GRAPHIC_H
