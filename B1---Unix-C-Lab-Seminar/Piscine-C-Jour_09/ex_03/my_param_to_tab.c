/*
** my_param_to_tab.c for my_param_to_tab in /home/mar_b/rendu/Piscine-C-Jour_09/ex_03
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu Mar 13 10:36:48 2014 Fabien Martinez
** Last update Fri Mar 14 19:18:20 2014 Fabien Martinez
*/

#include <stdlib.h>
#include "my.h"

int	my_real_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i += 1;
  return (i);
}

char	*my_real_strdup(char *str)
{
  char  *ptr;
  int   i;

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

struct s_stock_par	*my_param_to_tab(int ac, char **av)
{
  struct s_stock_par	*ptr;
  int			i;

  i = 0;
  ptr = malloc((ac + 1) * sizeof(struct s_stock_par));
  if (ptr == NULL)
    return (NULL);
  while (i < ac)
    {
      ptr[i].size_param = my_real_strlen(av[i]);
      ptr[i].str = av[i];
      ptr[i].copy = my_real_strdup(av[i]);
      ptr[i].tab = my_str_to_wordtab(av[i]);
      i += 1;
    }
  ptr[i].str = 0;
  return (ptr);
}
