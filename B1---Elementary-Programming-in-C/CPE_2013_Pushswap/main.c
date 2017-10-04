/*
** main.c for main in /home/mar_b/rendu/CPE_2013_Pushswap
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sat May 17 19:54:27 2014 mar_b mar_b
** Last update Sat Jun  7 14:35:49 2014 mar_b mar_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_fun.h"
#include "my_list.h"
#include "my_swap.h"
#include "my_changelist.h"
#include "my_rotate.h"
#include "my_sort.h"

static void	my_write(char c)
{
  (void)write(2, &c, 1);
}

static void	my_putinterr(int nbr)
{
  if (nbr >= 0 && nbr < 10)
    my_write(nbr + '0');
  else if (nbr < 0 && nbr > -10)
    {
      my_write('-');
      my_write((nbr * -1) + '0');
    }
  else
    {
      my_putinterr(nbr / 10);
      my_write((nbr >= 0 ? nbr % 10 : (nbr % 10) * -1) + '0');
    }
}

static	void	my_check_d(t_list *lst)
{
  t_list	*curr;
  t_list	*tmp;

  curr = lst->next;
  while (curr != lst)
    {
      tmp = curr->next;
      while (tmp != lst)
	{
	  if (tmp->data == curr->data)
	    {
	      write(2, "error: ", 7);
	      my_putinterr(tmp->data);
	      my_puterror(" is not alone, my god !!\n", 25);
	    }
	  tmp = tmp->next;
	}
      curr = curr->next;
    }
}

int		main(int argc, char **argv)
{
  t_list	*l_a;
  t_list	*l_b;
  char		verbose;

  verbose = argc > 1 && argv[1][0] == '-' && argv[1][1] == 'v' ? 1 : 0;
  if ((verbose && argc == 2) || argc == 1)
    return (0);
  l_a = my_create_list(verbose ? argc - 1 : argc, verbose ? &argv[1] : argv);
  l_b = my_create_list(0, NULL);
  my_check_d(l_a);
  my_sort(l_a, l_b, verbose);
  return (0);
}
