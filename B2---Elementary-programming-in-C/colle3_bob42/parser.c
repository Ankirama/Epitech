/*
** parser.c for parser in /home/mar_b/rendu/colle3_bob42
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Sep  9 19:17:03 2014 mar_b mar_b
** Last update Tue Sep  9 22:52:06 2014 mar_b mar_b
*/

#include "calc.h"
#include "utils.h"

static int	_find_par_open(const char *str, const int end)
{
  int		i;

  i = end;
  while (i >= 0 && str[i] != ID_PARENT_OPEN)
    --i;
  if (i < 0)
    my_puterror(ERR_PARENT_OPEN);
  return (i);
}

static int	_check_my_oper(int nbr1, int nbr2, char my_op)
{
  char		op[5];
  int		(*oper[5]) (int, int);
  int		i;

  op[0] = ID_ADD;
  op[1] = ID_SUB;
  op[2] = ID_MULT;
  op[3] = ID_DIV;
  op[4] = ID_MOD;
  oper[0] = my_add;
  oper[1] = my_sub;
  oper[2] = my_mul;
  oper[3] = my_div;
  oper[4] = my_mod;
  i = 0;
  while (i < 5 && op[i] != my_op)
    ++i;
  if (i == 5)
    my_puterror(ERR_OPE);
  return (oper[i](nbr1, nbr2));
}

static char	*_my_operation(char *str, int begin, int *end, int op)
{
  int		i;
  int		j;
  int		nbr1;
  int		nbr2;
  int		res;
  char		*new_str;

  if (op == 0 || str[op + 1] == '\0')
    my_puterror(ERR_OPE);
  i = op - 1;
  while (i >= begin && i != 0 && str[i] != ID_MULT && str[i] != ID_DIV &&
	 str[i] != ID_ADD && str[i] != ID_SUB && str[i] != ID_MOD &&
	 str[i] != ID_PARENT_OPEN && str[i] != ID_PARENT_CLOSE)
    --i;
  nbr1 = my_getnbr(&str[i], op - i);
  j = op + 1;
  while (j < *end && str[j] != '\0' && str[j] != ID_MULT && str[j] != ID_DIV &&
	 str[j] != ID_ADD && str[j] != ID_SUB && str[j] != ID_MOD &&
	 str[i] != ID_PARENT_OPEN && str[i] != ID_PARENT_CLOSE)
    ++j;
  nbr2 = my_getnbr(&str[op + 1], j - op);
  res = _check_my_oper(nbr1, nbr2, str[op]);
  new_str = my_new_str(str, res, i, j - 1);
  *end = *end - (j - i + 1) + size_nbr(res);
  return (new_str);
}

static char	*_my_priority(char *str, int start, int end)
{
  int		i;
  char		op_found;

  i = start;
  op_found = 0;
  while (i < end && str[i] != ID_MULT && str[i] != ID_DIV && str[i] != ID_MOD)
    {
      if (str[i] == ID_ADD || str[i] == ID_SUB)
	op_found = 1;
      ++i;
    }
  if (i != end)
    str = _my_operation(str, start, &end, i);
  else if (!op_found)
    return (str);
  else
    {
      i = start;
      while (i < end && str[i] != ID_ADD && str[i] != ID_SUB)
	++i;
      str = _my_operation(str, start, &end, i);
    }
  return (_my_priority(str, start, end));
}

char	*main_parser(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    {
      while (str[i] != '\0' && str[i] != ID_PARENT_CLOSE)
	++i;
      if (str[i] == '\0')
	return (_my_priority(str, 0, i));
      else
	{
	  str = _my_priority(str, _find_par_open(str, i), i);
	  i = -1;
	}
    }
  return (str);
}
