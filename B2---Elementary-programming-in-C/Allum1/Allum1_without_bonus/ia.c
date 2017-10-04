/*
** ia.c for ia in /home/mar_b/rendu/Allum1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Wed Jul  2 09:40:43 2014 mar_b mar_b
** Last update Thu Jul  3 15:58:34 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "list.h"
#include "utils.h"

/*
** brief: if we can't find the good position we will try to remove 1 by 1
** the longer line
** @lst: our list
** @my_bin_p: the first 1 in our result (binary)
** @pos: we will set it with the good position
** return: return the nbr
*/
static int	_fill_hole(t_list *lst, int my_bin_p, int *pos)
{
  int		nbr_tmp;
  int		nbr;
  t_list	*tmp;

  tmp = lst->next;
  *pos = 1;
  while (tmp != NULL && !tmp->bin[my_bin_p])
    {
      (*pos) = (*pos) + 1;
      tmp = tmp->next;
    }
  nbr_tmp = tmp->nbr_ele;
  while (bin_to_int(lst->bin) != 0 && tmp->nbr_ele > 0)
    {
      tmp->nbr_ele -= 1;
      free(tmp->bin);
      tmp->bin = int_to_bin(tmp->nbr_ele);
      free(lst->bin);
      lst->bin = operation_xor(lst);
    }
  nbr = (tmp->nbr_ele == 0) ? 1 : nbr_tmp - tmp->nbr_ele;
  tmp->nbr_ele = nbr_tmp;
  free(tmp->bin);
  tmp->bin = int_to_bin(tmp->nbr_ele);
  return (nbr);
}

/*
** brief: it will search the good line to stay with the good strategy
** @lst: our list
** @nbr: our number (we will set it in this function)
** return: return the position found
*/
static int	_find_position(t_list *lst, int *nbr)
{
  int		i;
  int		find;
  int		pos;
  t_list	*tmp;

  *nbr = bin_to_int(lst->bin);
  tmp = lst->next;
  i = -1;
  while (++i < ID_OCTET && !lst->bin[i]);
  if (i == 8)
    return (1);
  find = 0;
  pos = 0;
  while (tmp != NULL && !find)
    {
      ++pos;
      find = same_binary(lst, tmp, i - 1);
      tmp = tmp->next;
    }
  if (!find)
    *nbr = _fill_hole(lst, i, &pos);
  return (pos);
}

/*
** brief: it will substract the number of lucifers in line pos (if 0 remove)
** @lst: our list
** @pos: our line
** @nbr: number of lucifers
*/
static void	_my_sub_nbr(t_list *lst, const int pos, const int nbr)
{
  t_list	*tmp;
  int		i;

  tmp = lst;
  i = -1;
  while (tmp != NULL && ++i < pos)
    tmp = tmp->next;
  tmp->nbr_ele -= nbr;
  if (tmp->nbr_ele <= 0)
    remove_ele(lst, pos);
  else
    {
      free(tmp->bin);
      tmp->bin = int_to_bin(tmp->nbr_ele);
    }
  free(lst->bin);
  lst->bin = operation_xor(lst->next);
}

static void	_one_big_size(t_list *lst, int par)
{
  t_list	*tmp;
  int		pos;

  pos = 0;
  tmp = lst->next;
  while (tmp != NULL && tmp->nbr_ele == 1)
    {
      ++pos;
      tmp = tmp->next;
    }
  if (par % 2 == 0)
    tmp->nbr_ele = 1;
  else
    remove_ele(lst, pos);
}

/*
** brief: main function for IA, it will check if she already won
** @lst: our list
** @more_one: used to check number of line with more 1 lucifer
** @pos: the pos choosed by AI
** @nbr: the number of lucifers
*/
void		ia_game(t_list *lst, int more_one, int pos, int nbr)
{
  t_list	*tmp;

  tmp = lst->next;
  while (tmp != NULL)
    {
      more_one = (tmp->nbr_ele > 1) ? more_one + 1 : more_one;
      tmp = tmp->next;
    }
  if (lst->nbr_ele == 1)
    lst->next->nbr_ele = 1;
  else if (lst->nbr_ele == 2 && more_one <= 1)
    {
      if (lst->next->nbr_ele == 1)
	remove_ele(lst, 2);
      else
	remove_ele(lst, 1);
    }
  else if (more_one == 1)
    _one_big_size(lst, lst->nbr_ele - 1);
  else
    {
      pos = _find_position(lst, &nbr);
      _my_sub_nbr(lst, pos, nbr);
    }
}
