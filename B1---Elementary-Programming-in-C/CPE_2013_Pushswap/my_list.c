/*
** my_list.c for my_list in /home/mar_b/rendu/CPE_2013_Pushswap
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sat May 17 20:08:25 2014 mar_b mar_b
** Last update Sun Jun  8 20:03:38 2014 mar_b mar_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_list.h"
#include "my_fun.h"
#include "my_changelist.h"

/*
** It will add the elt
*/
static void	my_add_elt(t_list **list, char *val)
{
  t_list	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    my_puterror("error: problem to malloc the t_list!\n", 37);
  new->data = my_getnbr(val);
  new->prec = (*list)->prec;
  new->next = (*list);
  (*list)->prec->next = new;
  (*list)->prec = new;
}

/*
** It will create our list
*/
t_list		*my_create_list(int argc, char **argv)
{
  t_list	*root;
  int		i;

  if ((root = malloc(sizeof(*root))) == NULL)
    my_puterror("error: problem to malloc the t_list!\n", 37);
  root->next = root;
  root->prec = root;
  i = 0;
  root->size = argc == 0 ? 0 : argc - 1;
  while (++i < argc)
    my_add_elt(&root, argv[i]);
  return (root);
}

/*
** This one will print the list
*/
void		my_display_list(t_list *list)
{
  t_list	*head;

  head = list->next;
  while (head != list)
    {
      my_putstr(head->data);
      (void)write(1, " ", 1);
      head = head->next;
    }
}

void		my_remove_elt(t_list *lst, int pos)
{
  t_list	*tmp;

  tmp = lst->next;
  while (pos > 0)
    {
      tmp = tmp->next;
      pos -= 1;
    }
  lst->size -= 1;
  tmp->prec->next = tmp->next;
  tmp->next->prec = tmp->prec;
  free(tmp);
}

/*
** This function will empty l_b
*/

void		my_empty_lb(t_list **l_a, t_list **l_b)
{
  while ((*l_b)->size > 0)
    (void)write(1, pa(l_a, l_b), 2);
}
