/*
** my_tab.c for my_tab in /home/mar_b/rendu/MUL_2013_fdf
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Fri May  2 17:08:14 2014 Fabien Martinez
** Last update Fri May  9 11:26:47 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "my_tab.h"

t_my_tab	*my_append_elt(t_my_tab *tab, char **data)
{
  t_my_tab	*elt;
  t_my_tab	*head;

  if ((elt = malloc(sizeof(*elt))) == NULL)
    return (NULL);
  elt->data = data;
  elt->next = NULL;
  if (tab == NULL)
    return (elt);
  head = tab;
  while (head->next)
    head = head->next;
  head->next = elt;
  free(data);
  return (tab);
}

int		my_size_tab(t_my_tab *tab)
{
  t_my_tab	*tmp;
  int		size;

  tmp = tab;
  size = 0;
  while (tmp)
    {
      size += 1;
      tmp = tmp->next;
    }
  return (size);
}
char		**my_convert_tab(t_my_tab *tab)
{
  char		**arr;
  int		i;
  int		size;

  size = my_size_tab(tab);
}
