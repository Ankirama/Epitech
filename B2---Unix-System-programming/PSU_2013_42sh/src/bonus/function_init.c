/*
** function_init.c for  in /home/teyssa_r/rendu/PSU_2013_42sh/src/bonus
** 
** Made by teyssa_r teyssa_r
** Login   <teyssa_r@epitech.net>
** 
** Started on  Sun Sep 21 17:36:14 2014 teyssa_r teyssa_r
** Last update Sun Sep 21 18:11:52 2014 teyssa_r teyssa_r
*/

#include "mini.h"

void	init_buff(char *buff, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      buff[i] = 0;
      i++;
    }
}

void	init_realloc(char *str, int size)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  while (i < size)
    str[i++] = 0;
}
