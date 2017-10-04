/*
** my_advanced_sort_wordtab.c for my_advanced_sort_wordtab in /home/mar_b/rendu/Piscine-C-Jour_11/ex_04
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Mar 24 11:15:08 2014 Fabien Martinez
** Last update Mon Mar 24 11:35:32 2014 Fabien Martinez
*/

#include <stdlib.h>

int	my_advanced_sort_wordtab(char **tab, int(*cmp)(char *, char *))
{
  if (tab != NULL)
    my_fun_advanced(tab, cmp);
  return (0);
}

int	my_fun_advanced(char **tab, int(*cmp)(char *, char *))
{
  int	i;
  char *tmp;
  char done;

  done = 1;
  if (tab[0] != 0 && tab[1] != 0)
    {
      while (done)
	{
	  done = 0;
	  i = 0;
	  while (tab[i + 1] != 0)
	    {
	      if (cmp(tab[i], tab[i + 1]) > 0)
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
