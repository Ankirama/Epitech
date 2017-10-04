/*
** my_show_tab.c for my_show_tab in /home/mar_b/rendu/Piscine-C-Jour_09/ex_04
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu Mar 13 11:28:58 2014 Fabien Martinez
** Last update Fri Mar 14 19:17:29 2014 Fabien Martinez
*/

#include <stdlib.h>

long    rec_my_real_put_nbr(long nbr)
{
  if (nbr <= 9)
    {
      my_putchar('0' + nbr);
    }
  else
    {
      rec_my_real_put_nbr(nbr / 10);
      my_putchar ('0' + (nbr % 10));
    }
}

int     my_real_put_nbr(int nbr)
{
  long  nb;

  nb = nbr;
  if (nbr < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  rec_my_real_put_nbr(nb);
}

void	my_real_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i += 1;
    }
}

int     my_real_show_wordtab(char **tab)
{
  int   i;

  i = 0;
  while (tab[i] != 0)
    {
      my_real_putstr(tab[i]);
      my_putchar('\n');
      i += 1;
    }
}

int	my_show_tab(struct s_stock_par *par)
{
  int	i;

  i = 0;
  if (par != NULL)
    {
      while (par[i].str != 0)
	{
	  my_real_putstr(par[i].str);
	  my_putchar('\n');
	  my_real_put_nbr(par[i].size_param);
	  my_putchar('\n');
	  my_real_show_wordtab(par[i].tab);
	  my_putchar('\n');
	  i += 1;
	}
    }
}
