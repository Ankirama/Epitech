/*
** my_width_height.c for my_width_height in /home/mar_b/rendu/Piscine-C-colles-Semaine_03
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Sat Mar 29 17:12:22 2014 Fabien Martinez
** Last update Sat Mar 29 22:18:44 2014 Fabien Martinez
*/

#include "my_proto.h"

void	my_init(char *str)
{
  int	i;

  i = 0;
  while (i < BUFF_SIZE + 1)
    {
      str[i] = 0;
      i += 1;
    }
}

int	init_variables(int *height, int *width, char *width_done, char *first)
{
  *height = 0;
  *width = 0;
  *width_done = 0;
  *first = 0;
  return (1);
}
