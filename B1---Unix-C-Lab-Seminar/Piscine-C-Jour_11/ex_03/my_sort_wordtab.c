/*
** my_sort_wordtab.c for my_sort_wordtab in /home/user/rendu/Piscine-C-Jour_11/ex_03
**
** Made by 
** Login   
**
** Started on  Mon Mar 24 10:12:26 2014 
** Last update Mon Mar 24 11:43:57 2014 
*/

#include <stdlib.h>

int	my_sort_wordtab(char **tab)
{
  if (tab != NULL)
    my_fun_sort_wordtab(tab);
  return (0);
}

int	my_fun_sort_wordtab(char **tab)
{
  int	i;
  char	*tmp;
  char	done;

  done = 1;
  if (tab[0] != 0 && tab[1] != 0)
    {
      while (done)
	{
	  done = 0;
	  i = 0;
	  while (tab[i + 1] != 0)
	    {
	      if (my_strcmp(tab[i], tab[i + 1]) > 0)
		{
		  tmp = tab[i];
		  tab[i] = tab[i + 1];
		  tab[i + 1] = tmp;
		  done = 1;
		}
	      i += 1;
	    }
	}
    }
}
