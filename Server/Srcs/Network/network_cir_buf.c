/*
** network_cir_buf.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/network_cir_buf.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Jun 20 20:53:23 2017 Enguerrand Allamel
** Last update Tue Jun 20 20:53:23 2017 Enguerrand Allamel
*/

#include "zappy.h"

int		cir_buf_init(t_zappy_cir_buf *cir_buf, size_t size)
{
  cir_buf->lenght = size;
  cir_buf->head = 0;
  cir_buf->tail = 0;
  if ((cir_buf->buf = malloc((sizeof(char) * (cir_buf->lenght + 1)))) == NULL)
    return (-1);
  bzero(cir_buf->buf, cir_buf->lenght + 1);
  return (0);
}

int 		cir_buf_push(t_zappy_cir_buf *cir_buf, const char data)
{
  size_t 	next_head;

  next_head = cir_buf->head + 1;
  if (next_head >= cir_buf->lenght)
    next_head = 0;
  if (next_head == cir_buf->tail)
    return (-1);
  cir_buf->buf[cir_buf->head] = data;
  cir_buf->head = next_head;
  return (0);
}

int 		cir_buf_pop(t_zappy_cir_buf *cir_buf, char *data)
{
  size_t 	next_tail;

  if (cir_buf->head == cir_buf->tail)
    return (-1);
  next_tail = cir_buf->tail + 1;
  if (next_tail >= cir_buf->lenght)
    next_tail = 0;
  *data = cir_buf->buf[cir_buf->tail];
  cir_buf->buf[cir_buf->tail] = 0;
  cir_buf->tail = next_tail;
  return (0);
}

static int 	cir_buf_pop_no_reset(t_zappy_cir_buf *cir_buf, char *data)
{
  size_t 	next_tail;

  if (cir_buf->head == cir_buf->tail)
    return (-1);
  next_tail = cir_buf->tail + 1;
  if (next_tail >= cir_buf->lenght)
    next_tail = 0;
  *data = cir_buf->buf[cir_buf->tail];
  cir_buf->tail = next_tail;
  return (0);
}

int 		cir_buf_has_cmd(t_zappy_cir_buf *cir_buf)
{
  size_t 	tmp_tail;
  char 		data;

  tmp_tail = cir_buf->tail;
  data = 0;
  while (cir_buf_pop_no_reset(cir_buf, &data) == 0 && data != '\n')
    data = 0;
  cir_buf->tail = tmp_tail;
  if (data == '\n')
    return (1);
  return (0);
}