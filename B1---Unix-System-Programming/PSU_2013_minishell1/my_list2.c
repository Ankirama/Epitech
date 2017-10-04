/*
** my_list2.c for my_list2 in /home/mar_b/rendu/PSU_2013_minishell1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Jun 19 11:39:26 2014 mar_b mar_b
** Last update Sun Jun 22 19:50:08 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "my_list.h"
#include "my_str.h"

/*
** brief: we will try to find our value into our list
** @lst: our list
** @value: we will try to find this one
** return: return the line without the value (like PATH=ext we will return ext)
*/
char		*my_find_element(t_list *lst, char *value)
{
  t_list	*tmp;

  tmp = lst->next;
  while (tmp != lst && !my_strcmp(tmp->data, value, 1))
    tmp = tmp->next;
  if (tmp == lst)
    return (NULL);
  return (&tmp->data[my_strlen(value) + 1]);
}

/*
** brief: this function will set / add our new value into your env list
** @var: we will try to find this variable (like PATH, PWD etc..)
** @value: we will add this value
** @lst: we will check into this env list
*/
void	my_setenv_lst(t_list *lst, char *var, char *value)
{
  my_remove_elt(&lst, var);
  my_add_elt(&lst, value, var);
}
