/*
** game_player_sound_b.c for PSU_2016_zappy in /home/enguerrand/delivery/PSU_2016_zappy/game_player_sound_b.c
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Sun Jul 02 17:22:57 2017 Enguerrand Allamel
** Last update Sun Jul 02 17:22:57 2017 Enguerrand Allamel
*/

#include "zappy.h"

static int 	check_sound_dia(double b)
{
  if (b == -135)
    return (4);
  else if (b == -45)
    return (2);
  if (b == 45)
    return (8);
  else if (b == 135)
    return (6);
  return (1);
}

int		game_player_sound_check_sound(double an, int sig_s)
{
  double	b;

  b = (int)((180 / M_PI) * acos(an));
  b = b * sig_s;
  if (b > -45 && b < 45)
    return (1);
  else if (b > 45 && b < 135)
    return (7);
  else if (b > 135 && b < -135)
    return (5);
  else if (b < -45 && b > -135)
    return (3);
  return (check_sound_dia(b));
}