/*
** game_action.h for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_action.h
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Fri Jun 30 15:54:47 2017 Enguerrand Allamel
** Last update Fri Jun 30 15:54:47 2017 Enguerrand Allamel
*/

#ifndef PSU_2016_ZAPPY_GAME_ACTION_H
# define PSU_2016_ZAPPY_GAME_ACTION_H

typedef enum		e_game_action_type
{
  ZAPPY_G_ACT_DEFAULT = 0,
  ZAPPY_G_ACT_FORK_END = 1,
  ZAPPY_G_ACT_PLAYER_EAT = 2
}			t_game_action_type;

typedef struct		s_game_action_cmd
{
  t_game_action_type	 type;
  int 			(*ptr_func)(int 			id,
					 int 			team_id,
					 t_game_action_type 	cmd);
}			t_game_action_cmd;

typedef struct 				s_game_cmd_queue
{
  t_game_action_type	 		type;
  int 					id;
  int 					team_id;
  long long 				time_interval;
  struct s_game_cmd_queue		*next;
}					t_game_cmd_queue;

/*
 * GAME ACTION CMD
 */
int 	game_action_cmd_exec(int id, int team_id, t_game_action_type cmd);

/*
 * GAME ACTION QUEUE
 */
int 			game_action_queue_push(t_game_action_type	cmd,
						  size_t		t_u,
						  int 			id,
						  int 			t_id);

int		game_queue_check(long long time_sub);

int 		game_queue_remove(t_game_cmd_queue *item);

long long 	game_action_queue_min_time();

/*
 * GAME ACTION FORK
 */
int 		game_action_fork_remove(int 			id,
					   int 			team_id,
					   t_game_action_type 	cmd);

bool		game_action_fork_free(int team_id);

int		game_action_fork_use(int team_id);

/*
 * GAME ACTION EAT
 */
int 		game_action_eat(int 			id,
				   int 			team_id,
				   t_game_action_type 	cmd);

/*
 * GAME END
 */
int 		game_end();

#endif //PSU_2016_ZAPPY_GAME_ACTION_H
