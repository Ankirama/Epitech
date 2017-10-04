/*
** do-op.c for do-op in /home/mar_b/rendu/Piscine-C-Jour_11/do-op
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Mar 24 09:21:43 2014 Fabien Martinez
** Last update Mon Mar 24 20:48:51 2014 Fabien Martinez
*/

#include "my_fun.h"
#include "my_nbr.h"
#include "operations.h"

int	doop(int nb1, int nb2, char op)
{
  int	(*my_tab_fun[5])(int, int);
  int	nbr;

  my_tab_fun[0] = my_add;
  my_tab_fun[1] = my_sub;
  my_tab_fun[2] = my_div;
  my_tab_fun[3] = my_mul;
  my_tab_fun[4] = my_mod;
  nbr = 0;
  if (op == '+')
    nbr = my_tab_fun[0](nb1, nb2);
  else if (op == '-')
    nbr = my_tab_fun[1](nb1, nb2);
  else if (op == '/')
    nbr = my_tab_fun[2](nb1, nb2);
  else if (op == '*')
    nbr = my_tab_fun[3](nb1, nb2);
  else
    nbr = my_tab_fun[4](nb1, nb2);
  return (nbr);
}

int	main(int argc, char **argv)
{
  char	op;
  int	nbr;

  if (argc == 4)
    {
      op = argv[2][0];
      if (op != '-' && op != '+' && op != '/' && op != '*' && op != '%')
	my_putstr("0\n");
      else
	{
	  if (op == '/' && my_getnbr(argv[3]) == 0)
	    my_putstr("Stop: division by zero\n");
	  else if (op == '%' && my_getnbr(argv[3]) == 0)
	    my_putstr("Stop: modulo by zero\n");
	  else
	    {
	      nbr = doop(my_getnbr(argv[1]), my_getnbr(argv[3]), op);
	      my_put_nbr(nbr);
	      my_putchar('\n');
	    }
	}
    }
  return (0);
}
