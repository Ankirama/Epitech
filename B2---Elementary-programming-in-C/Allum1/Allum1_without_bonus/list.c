/*
** list.c for list in /home/mar_b/rendu/Allum1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Jul  1 13:56:52 2014 mar_b mar_b
** Last update Tue Jul  1 16:26:56 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "list.h"
#include "utils.h"

/*
** brief: it will add an element with our nbr_ele and the binary
** @lst: our list
** @nbr_ele: our number of lucifers
** @bin_nbr: nbr_ele converted in binary
*/
static void     _add_element(t_list **lst, int nbr_ele, char *bin_nbr)
{
  t_list        *tmp;
  t_list        *elt;

  if ((elt = malloc(sizeof(*elt))) == NULL)
    my_puterror("error: problem to malloc in list.c\n");
  elt->nbr_ele = nbr_ele;
  elt->bin = bin_nbr;
  elt->next = NULL;
  if ((*lst) == NULL)
    (*lst) = elt;
  else
    {
      tmp = (*lst);
      while (tmp != NULL && tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = elt;
    }
}

/*
** brief: create our list
** @length: the size of our list
** return: return our new list
*/
t_list          *create_list(int length)
{
  t_list	*lst;
  int		i;

  if ((lst = malloc(sizeof(*lst))) == NULL)
    my_puterror("error: problem to malloc in list.c\n");
  lst->nbr_ele = length;
  lst->next = NULL;
  i = -1;
  while (++i < length)
    _add_element(&(lst->next), i * 2 + 1, int_to_bin(i * 2 + 1));
  lst->bin = operation_xor(lst->next);
  return (lst);
}

/*
** brief: remove an element in our list
** @lst: our list
** @pos: we will travel until this position
*/
void		remove_ele(t_list *lst, int pos)
{
  t_list	*tmp;
  t_list	*tmp2;

  tmp = lst;
  lst->nbr_ele -= 1;
  while (--pos > 0)
    tmp = tmp->next;
  tmp2 = tmp->next;
  tmp->next = tmp2->next;
  free(tmp2->bin);
  free(tmp2);
}

/*
** LET IT GO ! (FR version --> better than US version)
** url : https://www.youtube.com/watch?v=wQP9XZc2Y_c
** you have to like it <3
*/
void		free_lst(t_list *lst)
{
  t_list	*tmp;

  while (lst != NULL)
    {
      tmp = lst;
      lst = lst->next;
      free(tmp->bin);
      free(tmp);
    }
}
