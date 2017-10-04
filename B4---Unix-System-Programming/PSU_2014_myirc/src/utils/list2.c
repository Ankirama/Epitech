/*
** main.c<2> for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Wed Apr  1 10:32:07 2015 Fabien Martinez
*/

#include "utils.h"

void		remove_element(t_list **root, void *elt_data)
{
  t_list	*tmp;
  t_list	*elt;

  tmp = (*root);
  while (tmp->next != *root && strcmp(tmp->next->data, elt_data) != 0)
    tmp = tmp->next;
  if (tmp->next != *root)
    {
      elt = tmp->next;
      tmp->next = elt->next;
      (*root)->size -= elt->size;
      free(elt->data);
      free(elt);
    }
}

int		nb_elements(t_list *root)
{
  t_list	*tmp;
  int		nb;

 nb = 0;
  tmp = root->next;
  while (tmp != root)
    {
      ++nb;
      tmp = tmp->next;
    }
  return (nb);
}

void		change_element(t_list **root, void *old_data, void *new_data)
{
  t_list	*tmp;

  tmp = (*root)->next;
  while (tmp != *root && strcmp(tmp->data, old_data) != 0)
    tmp = tmp->next;
  if (tmp != *root)
    {
      free(tmp->data);
      tmp->data = strdup(new_data);
    }
}

t_list		*get_list(t_list *root, void *data)
{
  t_list	*tmp;

  tmp = root->next;
  while (tmp != root && strcmp(data, tmp->data) != 0)
    tmp = tmp->next;
  return (tmp);
}
