/*
** my_sort.c for my_sort in /home/lefebv_1/colle_06_HBX_mar_b
**
** Made by lefebv_1 lefebv_1
** Login   <lefebv_1@epitech.net>
**
** Started on  Tue Sep 30 18:56:39 2014 lefebv_1 lefebv_1
** Last update Tue Sep 30 20:53:14 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "utils.h"
#include "list.h"

char	cmp_sup(unsigned int n1, unsigned int n2)
{
  return (n1 > n2);
}

char	cmp_inf(unsigned int n1, unsigned int n2)
{
  return (n1 < n2);
}

char	*my_sort_char(char *str)
{
  char	tmp;
  int	i;
  int	sort;

  i = 1;
  sort = 0;
  while (sort == 0)
    {
      i = 1;
      sort = 1;
      while (str[i] != '\0')
	{
	  if (str[i] < str[i - 1])
	    {
	      tmp = str[i];
	      str[i] = str[i - 1];
	      str[i - 1] = tmp;
	      sort = 0;
	    }
	  i = i + 1;
	}
    }
  return (str);
}

void		my_sort_int(t_list **lst,
			    char (*cmp)(unsigned int, unsigned int))
{
  t_list	*tmp_lst;
  unsigned int	tmp;
  char		carac;
  int		sort;

  sort = 0;
  while (sort == 0)
    {
      tmp_lst = *lst;
      sort = 1;
      while (tmp_lst != NULL && tmp_lst->next != NULL)
	{
	  if (cmp(tmp_lst->nbr, tmp_lst->next->nbr))
	    {
	      tmp = tmp_lst->nbr;
	      carac = tmp_lst->carac;
              tmp_lst->nbr = tmp_lst->next->nbr;
	      tmp_lst->carac = tmp_lst->next->carac;
              tmp_lst->next->nbr = tmp;
	      tmp_lst->next->carac = carac;
              sort = 0;
	    }
	  tmp_lst = tmp_lst->next;
	}
    }
}
