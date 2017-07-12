/*
** network.h for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/network.h
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Jun 20 15:36:01 2017 Enguerrand Allamel
** Last update Tue Jun 20 15:36:01 2017 Enguerrand Allamel
*/

#ifndef PSU_2016_ZAPPY_NETWORK_H
# define PSU_2016_ZAPPY_NETWORK_H

typedef enum		e_zappy_tunnel_type
{
  Z_TYPE_NOT_SET = 0,
  Z_SERVER = 1,
  Z_CLIENT = 2
}			t_zappy_tunnel_type;

typedef struct 		s_zappy_cir_buf
{
  char 			*buf;
  size_t 		head;
  size_t 		tail;
  size_t 		lenght;
}			t_zappy_cir_buf;

typedef struct		s_zappy_tunnel
{
  t_zappy_tunnel_type	type;
  int			(*ptr_func_write)(int fd);
  int			(*ptr_func_read)(int fd);
  t_zappy_cir_buf	cir_buf_in;
  t_zappy_cir_buf	cir_buf_out;
  t_zappy_client	client;
}			t_zappy_tunnel;

/*
 * CIR_BUF
 */
int		cir_buf_init(t_zappy_cir_buf *cir_buf, size_t size);

int 		cir_buf_push(t_zappy_cir_buf *cir_buf, const char data);

int 		cir_buf_pop(t_zappy_cir_buf *cir_buf, char *data);

int 		cir_buf_has_cmd(t_zappy_cir_buf *cir_buf);

/*
 * CIR BUF CMD
 */
bool 	cir_buf_get_cmd(t_zappy_cir_buf	*cir_buf,
			     char 	cmd[512]);

bool 	cir_buf_get_cmd_eol(t_zappy_cir_buf	*cir_buf,
				 char 		cmd[512]);

int 	cir_buf_add_cmd(t_zappy_cir_buf *cir_buf, const char *cmd);

int 	cir_buf_add_cmd_no_eol(t_zappy_cir_buf *cir_buf, const char *cmd);

int 	cir_buf_add_cmd_v(t_zappy_cir_buf		*cir_buf,
				     const char		*format,
				     ...);

int 		cir_buf_add_cmd_v_n_eol(t_zappy_cir_buf	*cir_buf,
					   const char	*format,
					   ...);

/*
 * TUNNEL
 */
void		tunnel_init();

int 		tunnel_close_client(int fd);

int		tunnel_add_server(unsigned short port);

int		tunnel_add_client(int fd_server);

/*
 * NETWORK START
 */
int 	network_init();

int	network_init_fds(fd_set *fd_read, fd_set *fd_write);

int 	network_handle_data(int i, fd_set *fd_read, fd_set *fd_write);

void	network_run_turn(int fd, long long time_sub);

int	network_handle_loop(fd_set 		*fd_read,
			       fd_set 		*fd_write,
			       struct timeval 	*tv);

/*
 * NETWORK EXEC
 */
int 	network_loop_exec(fd_set *fd_read, long long time_sub);

int 	network_loop_read(fd_set 		*fd_read,
			     struct timeval 	*tv,
			     long long 		*time_sub);

int 	network_loop_write(fd_set 		*fd_write,
			      struct timeval 	*tv);

/*
 * SERVER
 */
int 	server_read(int fd);

/*
 * CLIENT
 */
int	client_read(int fd);

int 	client_write(int fd);

#endif //PSU_2016_ZAPPY_NETWORK_H
