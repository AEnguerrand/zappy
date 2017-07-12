/*
** protocol_player.h for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/protocol_player.h
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Jun 20 14:59:30 2017 Enguerrand Allamel
** Last update Tue Jun 20 14:59:30 2017 Enguerrand Allamel
*/

#ifndef PSU_2016_ZAPPY_GAME_PLAYER_H
# define PSU_2016_ZAPPY_GAME_PLAYER_H

typedef enum 	e_game_player_dir
{
  Z_PLAYER_DIR_DEFAULT = 0,
  Z_PLAYER_DIR_NORTH = 1,
  Z_PLAYER_DIR_EAST = 2,
  Z_PLAYER_DIR_SOUTH = 3,
  Z_PLAYER_DIR_WEST = 4
}		t_game_player_dir;

typedef struct	s_game_player_cmd
{
  const char	*cmd;
  size_t 	time_unit;
  int 		(*ptr_func)(int fd, const char *cmd);
  bool		args;
}		t_game_player_cmd;

typedef struct 				s_game_player_cmd_queue
{
  char	 				*cmd;
  bool					is_start;
  long long 				time_interval;
  size_t 				time_unit;
  struct s_game_player_cmd_queue	*next;
}					t_game_player_cmd_queue;

typedef struct 			s_game_player
{
  size_t 			id;
  t_pos				pos;
  t_game_player_dir		dir;
  t_zappy_level			level;
  int 				team_id;
  t_game_player_cmd_queue	*first;
  int				inventory[ZAPPY_RESSOURCES_MAX];
}				t_game_player;

/*
 * GAME PLAYER INIT
 */
int	game_player_add(int fd, const char *team_name);

/*
 * GAME PLAYER
 */
size_t 	game_player_nb_in_case_on_level(t_pos pos, t_zappy_level level);

size_t 	game_player_nb_in_case(t_pos pos);

int 	game_player_in_case_upgrade_level(t_pos pos, t_zappy_level level);

int 	game_player_in_case_start_up_level(t_pos pos, t_zappy_level level);

/*
 * GAME PLAYER TEAMS
 */
int 	game_player_teams_is_exist(const char *team_name);

int 	game_player_teams_get_id(const char *team_name);

const char 	*game_player_teams_get_name(int team_id);

int 	game_player_teams_init();

/*
 * GAME PLAYER CMD
 */
int 	game_player_cmd_exec(int fd, const char *cmd);

int 	game_player_cmd_read(int fd, const char *cmd);

/*
 * GAME PLAYER CMD MOVE
 */
int 	game_player_cmd_move_forward(int fd, const char *cmd);

int 	game_player_cmd_move_right(int fd, const char *cmd);

int 	game_player_cmd_move_left(int fd, const char *cmd);

/*
 * GAME PLAYER CMD LOOK
 */
int 	game_player_cmd_look(int fd, const char *cmd);

int	game_player_cmd_look_case(int fd, t_pos pos, bool *is_first);

/*
 * GAME PLAYER CMD LOOK LINE
 */
int 	game_player_cmd_look_line(int 			fd,
				     int 		dist,
				     t_game_player_dir 	dir,
				     bool 		*is_first);

/*
 * GAME PLAYER CMD INVENTORY
 */
int 	game_player_cmd_inventory(int fd, const char *cmd);

/*
 * GAME PLAYER CMD OBJ
 */
int 	game_player_cmd_obj_take(int fd, const char *cmd);

int 	game_player_cmd_obj_set(int fd, const char *cmd);

/*
 * GAME PLAYER CMD INCANTATION
 */
int 	game_player_cmd_incantation_start(int fd, const char *cmd);

int 	game_player_cmd_incantation_end(int fd, const char *cmd);

/*
 * GAME PLAYER CMD PLAYER
 */
int 	game_player_cmd_player_connect_nbr(int fd, const char *cmd);

int 	game_player_cmd_player_fork(int fd, const char *cmd);

int 	game_player_cmd_player_fork_start(int fd, const char *cmd);

/*
 * GAME PLAYER CMD BROADCAST
 */
int 	game_player_cmd_broadcast(int fd, const char *cmd);

/*
 * GAME PLAYER CMD EJECT
 */
int 	game_player_cmd_eject(int fd, const char *cmd);

/*
 * GAME PLAYER SOUND
 */
int	game_player_sound_get_sound_pos(int fd_send, int fd_rec);

int	game_player_sound_check_sound(double a, int sig_s);

/*
 * GAME PLAYER QUEUE
 */
int 	game_player_queue_push(int fd, const char *cmd, size_t t_u);

int	game_player_queue_pop(int fd);

int 	game_player_queue_size(int fd);

int 	game_player_queue_check(int fd, long long time_sub);

int 	game_player_queue_start(int fd, t_game_player_cmd_queue *item);

/*
 * GAME PLAYER DEAD
 */
int 	game_player_dead(int fd);

#endif //PSU_2016_ZAPPY_GAME_PLAYER_H
