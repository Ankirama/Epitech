/*
** my_strdup.c for my_strdup in /home/mar_b/rendu/Piscine-C-Jour_08/ex_01
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Mar 12 08:59:25 2014 Fabien Martinez
** Last update Thu Mar 13 19:17:14 2014 Fabien Martinez
*/

#include <stdlib.h>

char	*my_strdup(char *str)
{
  char	*ptr;
  int	i;

  ptr = malloc(sizeof(*str));
  i = 0;
  while (str[i] != '\0')
    {
      ptr[i] = str[i];
      i += 1;
    }
  ptr[i] = '\0';
  return (ptr);
}
