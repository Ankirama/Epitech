/*
** my_list.c for my_list in /home/mar_b/rendu/PSU_2013_minishell1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sat May 17 20:08:25 2014 mar_b mar_b
** Last update Sat Jun 21 03:18:38 2014 mar_b mar_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_str.h"
#include "my_list.h"
#include "my_list2.h"
#include "my_error.h"

/*
** brief: It will add the elt
** @list: we will add an elt into this list
** @val: this is the value
** @start: this is the variable like PATH etc...
*/
void	my_add_elt(t_list **list, char *val, char *start)
{
  t_list	*new;
  int		i;
  int		j;
  int		size;

  if ((new = malloc(sizeof(*new))) == NULL)
    my_puterror("error: problem to malloc the t_list in my_list.c: l30!\n");
  size = (start != NULL) ? my_strlen(start) : 0;
  if ((new->data = malloc(size + my_strlen(val) + 1)) == NULL)
    my_puterror("error: problem to malloc in my_list.c: l33!\n");
  j = -1;
  i = -1;
  while (start != NULL && start[++i])
    new->data[++j] = start[i];
  i = -1;
  if (j != -1)
    new->data[++j] = '=';
  while (val[++i])
    new->data[++j] = val[i];
  new->data[++j] = '\0';
  new->prec = (*list)->prec;
  new->next = (*list);
  (*list)->prec->next = new;
  (*list)->prec = new;
}

/*
** brief: It will create our list
** @env: we will create a list about our env
*/
t_list		*my_create_list(char **env)
{
  t_list	*root;
  int		i;

  if ((root = malloc(sizeof(*root))) == NULL)
    my_puterror("error: problem to malloc the t_list in my_list.c: l60!\n");
  root->next = root;
  root->prec = root;
  i = -1;
  while (env[++i])
    my_add_elt(&root, env[i], NULL);
  return (root);
}

/*
** brief: we will remove the first element
*/
void		my_remove_elt(t_list **lst, char *value)
{
  t_list	*tmp;

  tmp = (*lst)->next;
  while (tmp != (*lst) && !my_strcmp(tmp->data, value, 1))
    tmp = tmp->next;
  if (tmp != (*lst))
    {
      tmp->prec->next = tmp->next;
      tmp->next->prec = tmp->prec;
      free(tmp);
    }
}

/*
** brief: it will display our list
** @lst: our list
** @type: type == 0 -> normal, type == 1: env -0 type
*/
void		my_display_lst(t_list *lst, char type)
{
  t_list	*tmp;

  tmp = lst->next;
  while (tmp != lst)
    {
      (void)write(1, tmp->data, my_strlen(tmp->data));
      if ((type != 1 && tmp->next != lst) || type == 0)
	(void)write(1, "\n", 1);
      tmp = tmp->next;
    }
}
