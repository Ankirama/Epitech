/*
** my_params_in_list.c for day12 in /home/mar_b/rendu/Piscine-C-Jour_12/ex_01
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Tue Mar 25 09:07:09 2014 Fabien Martinez
** Last update Tue Mar 25 10:12:08 2014 Fabien Martinez
*/

#include <stdlib.h>
#include "mylist.h"

t_list		*rec_params(int i, int ac, char **av, t_list *list)
{
  t_list	*tmp;

  tmp = malloc(sizeof(*tmp));
  if (tmp == NULL)
    return (NULL);
  if (i == ac - 1)
    {
      tmp->data = av[i];
      tmp->next = list;
      return (tmp);
    }
  else
    {
      tmp->data = av[i];
      tmp->next = list;
      rec_params(i + 1, ac, av, tmp);
    }
}

t_list		*my_params_in_list(int ac, char **av)
{
  if (ac == 0 || av == NULL || (*av) == NULL)
    return (NULL);
  return (rec_params(0, ac, av, NULL));
}
