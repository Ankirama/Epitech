/*
** list.c for utils in /home/mar_b/rendu/CPE_2014_corewar/asm
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Aug 21 13:20:01 2014 mar_b mar_b
** Last update Fri Aug 29 15:47:27 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "op.h"
#include "asm_utils.h"
#include "utils.h"

/*
** brief: it will add a label in our list
** @lst: our structure
** @data: our line like add r1,r2,r3
** @line: our line for error
*/
void	add_label(t_asm **lst, char *data, int line)
{
  t_asm	*tmp;
  t_asm	*elt;

  elt = my_malloc(sizeof(*elt));
  elt->data = my_str_to_wordtab(data, SEPARATOR_CHAR, LABEL_CHAR);
  elt->type = 0;
  elt->line = line;
  elt->bytes = 0;
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
** brief: it will add an instruction in our list
** @lst: our structure
** @data: our line like add r1,r2,r3
** @line: our line for error
*/
void	add_instru(t_asm **lst, char *data, int line)
{
  t_asm *tmp;
  t_asm	*elt;

  elt = my_malloc(sizeof(*elt));
  elt->data = my_str_to_wordtab(data, SEPARATOR_CHAR, COMMENT_CHAR);
  elt->type = 1;
  elt->line = line;
  elt->bytes = 0;
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
** brief: it will display our list
** @lst: our list
*/
void	display_list(t_asm *lst)
{
  int	i;
  t_asm	*tmp;

  tmp = lst;
  while (tmp != NULL)
    {
      i = -1;
      while (tmp->data[++i] != NULL)
	{
	  my_write(1, tmp->data[i], my_strlen(tmp->data[i]));
	  if (tmp->data[i + 1] != NULL)
	    my_write(1, " ", 1);
	}
      my_write(1, "\n", 1);
      tmp = tmp->next;
    }
}

/*
** brief: it will free our list
** @lst: our list
*/
void	let_it_go(t_asm *lst)
{
  t_asm	*tmp;
  int	i;

  while (lst != NULL)
    {
      i = -1;
      while (lst->data[++i] != NULL)
	free(lst->data[i]);
      free(lst->data);
      tmp = lst;
      lst = lst->next;
      free(tmp);
    }
}
