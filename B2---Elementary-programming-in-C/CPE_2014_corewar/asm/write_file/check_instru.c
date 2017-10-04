/*
** checkInstru.c for write_file in /home/mar_b/rendu/CPE_2014_corewar/asm
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Aug 21 13:20:47 2014 mar_b mar_b
** Last update Sun Aug 31 20:21:58 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "asm_utils.h"
#include "utils.h"
#include "parsing.h"
#include "op.h"
#include "write_file.h"

/*
** brief: it will check the type of instruction like Register, direct etc...
** @str: the current param
** @i : the position in our op_tab (like live, ld, ...)
** @j: the type position (like first argument etc...
** @lst: our asm list with instructions
** return: return the good size, or -1
*/
static char	_type_instru(t_asm *lst, int i, int j, t_asm *head)
{
  if ((op_tab[i].type[j] & T_DIR) == T_DIR &&
      check_dir(lst->data[j + 1], head, lst->line))
    return (DIR_SIZE);
  else if ((op_tab[i].type[j] & T_REG) == T_REG &&
	   check_reg(lst->data[j + 1], lst->line))
    return (1);
  else if ((op_tab[i].type[j] & T_IND) == T_IND &&
	   check_ind(lst->data[j + 1], head, lst->line))
    return (IND_SIZE);
  else
    my_error_line(lst->line);
  return (0);
}

/*
** brief: it will caclulate the size if it's a special instru like live etc...
** @lst: our current element
** @head: our entire list
** @head_size: our header_size with the program's size
** @code: the code in op_tab to know the instruction like live..
** @return: return 1 if it's not a special code, 0 else
*/
static char	_calc_size(t_asm *lst, t_asm *head, int *head_size, int code)
{
  int		j;
  char		size;

  j = 0;
  if (code == 0 || code == 8 || code == 11 || code == 14)
    lst->bytes = (code == 0) ? 5 : IND_SIZE + 1;
  else if (code == 9 || code == 10)
    {
      lst->bytes = 2;
      while (lst->data[++j] != NULL)
	{
	  size = _type_instru(lst, code, j - 1, head);
	  lst->bytes = (size == 1) ? lst->bytes + 1 : lst->bytes + IND_SIZE;
	}
    }
  else
    return (1);
  *head_size += lst->bytes;
  return (0);
}

/*
** brief: it will check if there is any error like it's not a valid instruction
** @lst: our current element
** return: return -1 if any error, else the code (like 0 for live etc...)
*/
static int	_pre_check(t_asm *lst)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (i < 16 && !my_strcmp(lst->data[0], op_tab[i].mnemonique))
    ++i;
  if (i == 16)
    return (-1);
  while (lst->data[j] != NULL && lst->data[j + 1] != NULL)
    ++j;
  if (j != op_tab[i].nbr_args)
    return (-1);
  return (i);
}

/*
** brief: the main fun to check instru AND calculate the prog's size
** @lst: the current struct's "maillon" with instruction/label
** @head: the struct with all instructions/labels
** @head_size: the prog's size
** return: return -1 if any error, else 0
*/
void	check_instru(t_asm *lst, t_asm *head, int *head_size)
{
  int	i;
  int	j;
  int	size;

  if ((i = _pre_check(lst)) == -1)
    my_error_line(lst->line);
  j = 0;
  if (_calc_size(lst, head, head_size, i) == 1)
    {
      lst->bytes = 2;
      while (lst->data[++j] != NULL)
	{
	  size = _type_instru(lst, i, j - 1, head);
	  lst->bytes += size;
	}
      *head_size += lst->bytes;
    }
}
