/*
** arguments.h for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/arguments.h
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Jun 20 14:46:54 2017 Enguerrand Allamel
** Last update Tue Jun 20 14:46:54 2017 Enguerrand Allamel
*/

#ifndef PSU_2016_ZAPPY_ARGUMENTS_H
# define PSU_2016_ZAPPY_ARGUMENTS_H

typedef struct 	s_zappy_arguments_func
{
  const char 	opt;
  int 		(*ptr_func)(int *i, const char **av, const char opt);
}		t_zappy_arguments_func;

typedef struct		s_zappy_arguments
{
  unsigned short 	port;
  int 			map_width;
  int 			map_height;
  int 			teams_nb;
  char 			**teams_name;
  int 			*solt_free_by_team;
  int 			teams_clients;
  size_t 		freq;
}			t_zappy_arguments;

int 	arguments_get_all(int ac, const char **av);

int 	arguments_list_map(int *i, const char **av, const char opt);
int 	arguments_list_port(int *i, const char **av, const char opt);
int 	arguments_list_teams(int *i, const char **av, const char opt);
int 	arguments_list_clients_nb(int *i, const char **av, const char opt);
int 	arguments_list_freq(int *i, const char **av, const char opt);

#endif //PSU_2016_ZAPPY_ARGUMENTS_H
