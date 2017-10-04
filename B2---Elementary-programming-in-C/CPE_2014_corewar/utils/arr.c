/*
** arr.c for  in /home/teyssa_r/rendu/CPE_2014_corewar/utils
**
** Made by teyssa_r teyssa_r
** Login   <teyssa_r@epitech.net>
**
** Started on  Sat Aug 16 15:57:13 2014 teyssa_r teyssa_r
** Last update Sun Aug 24 13:21:55 2014
*/

#include <stdlib.h>
#include "utils.h"

int	my_strlen_arr(char **dbtab)
{
  int	i;

  i = 0;
  while (dbtab[i] != NULL)
    i++;
  return (i);
}

void	my_display_arr(char **arr, const int fd)
{
  int		i;

  i = -1;
  while (arr[++i] != NULL)
    {
      my_write(fd, arr[i], my_strlen(arr[i]));
      if (arr[i + 1] != NULL)
	my_putchar(fd, ' ');
    }
  my_putchar(fd, '\n');
}
