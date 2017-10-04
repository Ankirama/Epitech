/*
** label.c for label in /home/mar_b/rendu/CPE_2014_corewar/asm
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Aug 29 16:27:19 2014 mar_b mar_b
** Last update Sun Aug 31 20:45:29 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "asm_utils.h"
#include "utils.h"

/*
** i'm lazy
*/
static int	_count_bef_label(t_asm *lst, const int line)
{
  int		size;

  size = 0;
  while (lst != NULL && lst->line < line)
    {
      size += lst->bytes;
      lst = lst->next;
    }
  return (size);
}

/*
** i'm lazy.
*/
int	my_label(t_asm *head, const int line, const char *label)
{
  t_asm	*tmp;
  int	size;

  tmp = head;
  while (tmp != NULL && tmp->line < line)
    {
      if (tmp->type == 0 && my_strcmp(label, tmp->data[0]))
	return (_count_bef_label(tmp, line) * -1);
      tmp = tmp->next;
    }
  if (tmp != NULL && tmp->type == 0 && my_strcmp(label, tmp->data[0]))
    return (0);
  size = 0;
  while (tmp->next != NULL)
    {
      size += tmp->bytes;
      tmp = tmp->next;
      if (tmp->type == 0 && my_strcmp(label, tmp->data[0]))
	return (size);
    }
  return (0);
}
