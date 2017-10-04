/*
** my_list.c for my_list in /home/user/rendu/PSU_2013_my_select
**
** Made by 
** Login   
**
** Started on  Thu May 15 11:19:21 2014 
** Last update Wed May 28 14:32:21 2014 
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_list.h"
#include "my_error.h"
#include "my_fun.h"

/*
** It will add the elt
*/
void		my_add_elt(t_list **list, char *val)
{
  t_list	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    my_puterror("error: problem to malloc the t_list!\n", 37);
  new->data = val;
  new->size = my_strlen(val);
  new->active = 0;
  new->prec = (*list)->prec;
  new->next = (*list);
  (*list)->prec->next = new;
  (*list)->prec = new;
}

/*
** It will create our root
*/
t_list		*my_create_list(char **argv, int argc)
{
  t_list	*root;
  int		i;

  if ((root = malloc(sizeof(*root))) == NULL)
    my_puterror("error: problem to malloc the t_list!\n", 37);
  root->next = root;
  root->prec = root;
  root->active = 0;
  root->size = argc - 2;
  i = 1;
  while (i < argc)
    {
      my_add_elt(&root, argv[i]);
      i += 1;
    }
  return (root);
}

/*
** This one will create our list and print it
*/
void		my_display_list(t_list *list)
{
  t_list	*head;

  head = list->next;
  while (head != list)
    {
      my_putstr(head->data, head->size);
      my_putstr("\n", 1);
      head = head->next;
    }
}

/*
** It will free our list
*/
void		my_let_it_go(t_list *list)
{
  t_list	*tmp;
  t_list	*next;

  tmp = list->next;
  while (tmp != list)
    {
      next = tmp->next;
      free(tmp);
      tmp = next;
    }
  free(list);
}

/*
** it will return the element at position y
*/
t_list		*my_ret_elt(t_list *lst, int pos)
{
  t_list	*tmp;

  tmp = lst->next;
  while (pos > 0)
    {
      tmp = tmp->next;
      pos -= 1;
    }
  return (tmp);
}
