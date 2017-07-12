/*
** utils.h for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/utils.h
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Jun 20 16:19:55 2017 Enguerrand Allamel
** Last update Tue Jun 20 16:19:55 2017 Enguerrand Allamel
*/

#ifndef PSU_2016_ZAPPY_UTILS_H
# define PSU_2016_ZAPPY_UTILS_H

# ifndef ANSI_COLOR_RED
#  define ANSI_COLOR_RED     "\x1b[31m"
# endif

# ifndef ANSI_COLOR_GREEN
#  define ANSI_COLOR_GREEN   "\x1b[32m"
# endif

# ifndef ANSI_COLOR_YELLOW
#  define ANSI_COLOR_YELLOW  "\x1b[33m"
# endif

# ifndef ANSI_COLOR_BLUE
#  define ANSI_COLOR_BLUE    "\x1b[34m"
# endif

# ifndef ANSI_COLOR_MAGENTA
#  define ANSI_COLOR_MAGENTA "\x1b[35m"
# endif

# ifndef ANSI_COLOR_CYAN
#  define ANSI_COLOR_CYAN    "\x1b[36m"
# endif

# ifndef ANSI_COLOR_RESET
#  define ANSI_COLOR_RESET   "\x1b[0m"
# endif

typedef struct	s_pos
{
  int 		x;
  int 		y;
}		t_pos;

/*
 * UTILS
 */
const char	*get_pos_args(const char *cmd);

int	free_double(char **str);

int	null_double(char **str, size_t size);

int 	pos_cirular(int a, int b);

#endif //PSU_2016_ZAPPY_UTILS_H
