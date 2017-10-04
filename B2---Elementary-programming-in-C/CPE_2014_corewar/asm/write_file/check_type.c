/*
** checkInstru.c for write_file in /home/mar_b/rendu/CPE_2014_corewar/asm
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Aug 21 13:20:47 2014 mar_b mar_b
** Last update Sun Aug 31 20:44:36 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "op.h"
#include "asm_utils.h"
#include "utils.h"
#include "parsing.h"

/*
** brief: check it's a direct param like %42 or %:label
** @str: our current param
** @lst: our asm list with instructions
** return: return 0 if it's not a direct param, else return 1
*/
char	check_dir(char *str, t_asm *lst, const int line)
{
  int	i;
  t_asm	*tmp;

  if (str[0] != DIRECT_CHAR)
    return (0);
  if (str[1] == LABEL_CHAR)
    {
      tmp = lst;
      while (tmp != NULL)
	{
	  if (tmp->type == 0 && my_strcmp(&str[2], tmp->data[0]))
	    return (1);
	  tmp = tmp->next;
	}
      error_label(&str[2], line, str);
    }
  else
    {
      i = (str[1] == '-') ? 2 : 1;
      while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	++i;
    }
  return (i > 1 && str[i] == '\0');
}

/*
** brief: check if it's a register param
** @str: our current param
** return: return 0 if it's not a register, else 1
*/
char	check_reg(char *str, const int line)
{
  char	err;
  int	nbr;

  if (str[0] == 'r')
    {
      nbr = my_getnbr_asm(&str[1], &err);
      if (err == 1 || nbr > REG_NUMBER || nbr < 1)
	my_error_register(line, str);
      return (1);
    }
  return (0);
}

/*
** brief: check if it's an indirect param
** @str: our current param
** @lst: our asm list with instructions
** return: return 0 if it's not an indirect param, else 1
*/
char	check_ind(char *str, t_asm *lst, const int line)
{
  int	i;
  t_asm	*tmp;

  if (str[0] == LABEL_CHAR)
    {
      tmp = lst;
      while (tmp != NULL)
	{
	  if (tmp->type == 0 && my_strcmp(&str[1], tmp->data[0]))
	    return (1);
	  tmp = tmp->next;
	}
      error_label(&str[1], line, str);
    }
  else
    {
      i = (str[0] == '-') ? 1 : 0;
      while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	++i;
    }
  return (str[i] == '\0');
}
