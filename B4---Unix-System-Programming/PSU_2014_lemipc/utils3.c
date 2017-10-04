/*
** main.c<2> for main in /home/ankirama
** 
** Made by 
** Login   <ankirama@ubuntu>
** 
** Started on  Thu Feb 19 21:38:01 2015 
** Last update Fri Feb 20 04:34:38 2015 
*/

#include "lemipc.h"

char	check_inf(t_game *game)
{
  int	i;
  int	enough;

  i = -1;
  enough = 0;
  while (++i < MAX_TEAMS && !enough)
    enough = game->teams[i] >= 2 ? 1 : 0;
  return (enough);
}

