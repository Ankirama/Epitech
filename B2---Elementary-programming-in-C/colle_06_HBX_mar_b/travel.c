/*
** travel.c for travel in /home/mar_b/colle_06_HBX_mar_b
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Sep 30 19:20:27 2014 mar_b mar_b
** Last update Tue Sep 30 22:35:00 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "utils.h"
#include "list.h"

t_list		*travel_str(char *str)
{
  int		i;
  char		cur;
  unsigned int	nbr;
  t_list	*lst;

  lst = NULL;
  str = my_sort_char(str);
  i = -1;
  while (str[++i] != '\0')
    {
      nbr = 0;
      cur = str[i];
      while (str[i] != '\0' && cur == str[i])
	{
	  ++i;
	  ++nbr;
	}
      --i;
      add_element(&lst, cur, nbr);
    }
  return (lst);
}

static void	_good_one(char *str, char *cmp, int *i, int *j)
{
  while (str[*i] != '\0' && cmp[*j] != '\0' && str[*i] > cmp[*j])
    *j = *j + 1;
  while (str[*i] != '\0' && cmp[*j] != '\0' && str[*i] < cmp[*j])
    *i = *i + 1;
}

t_list		*travel_cmp(char *str, char *cmp, t_list *lst, int i)
{
  int		j;
  unsigned int	nbr;
  char		cur;

  j = -1;
  while (str[++i] != '\0' && cmp[++j] != '\0')
    {
      _good_one(str, cmp, &i, &j);
      cur = str[i];
      nbr = 0;
      while (str[i] != '\0' && cur == str[i] && cur == cmp[j])
	{
	  ++i;
	  ++nbr;
	}
      while (cmp[j] != '\0' && cur == cmp[j])
	++j;
      --i;
      --j;
      if (cmp[j] == cur)
	add_element(&lst, cur, nbr);
    }
  return (lst);
}
