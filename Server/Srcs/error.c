/*
** error.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/error.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Jun 21 11:05:40 2017 Enguerrand Allamel
** Last update Wed Jun 21 11:05:40 2017 Enguerrand Allamel
*/

#include "zappy.h"

int 	exit_error(const char *text)
{
  fprintf(stderr, "ERROR IRC SERVER: [%s] [%s]\n", text, strerror(errno));
  exit(EXIT_FAILURE);
}