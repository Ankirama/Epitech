/*
** my_number.c for my_number in /home/chenev_d/rendu/test/corewar
**
** Made by chenev_d chenev_d
** Login   <chenev_d@epitech.net>
**
** Started on  Sat Aug 16 12:34:59 2014 chenev_d chenev_d
** Last update Sun Aug 31 23:26:17 2014 chenev_d chenev_d
*/

#include <stdlib.h>
#include "utils.h"
#include "parser.h"

/*
** brief: check if the values -n is good
** @a: values to look over our values
** @c: number max of values
** @number: values convert in char*
*/
void	loop_number(int a, int c, char *number)
{
  char	tmp;
  int	b;

  b = 0;
  while (a < c)
    {
      tmp = number[a];
      b = a + 1;
      while (b < c)
        {
          if (tmp == number[b] && tmp != '5')
	    my_puterror(ERR_NAU);
          b++;
        }
      a++;
    }
}

/*
** brief: complete our -n 0 values
** @opt: Our struct which contains our values
** @c: number max of values
*/
void	change_number(t_option *opt, int c)
{
  int	a;
  int	d;
  int	b;

  a = 0;
  while (a < c)
    {
      if (opt->my_n_number[a] == 5)
	{
	  b = 0;
	  d = 1;
	  while (b < c)
	    {
	      if (opt->my_n_number[b] == d && b != a)
		{
		  b = 0;
		  d++;
		}
	      else
		b++;
	    }
	  opt->my_n_number[a] = d;
	}
      a++;
    }
}

/*
** brief: filled our int* with -n values
** @nb: our all -n values in one int
** @opt: Our struct which contains our values
*/
void	check_the_n_number(int nb, t_option *opt)
{
  int	a;
  char	*number;
  int	c;
  int	b;

  a = 0;
  b = 0;
  number = int_to_array(nb);
  if ((c = my_strlen(number)) > 4)
    my_puterror(ERR_NAU);
  opt->my_n_number = my_malloc(sizeof(int) * (c + 1));
  while (b < c)
    {
      opt->my_n_number[b] = number[b] - '0';
      b++;
    }
  opt->my_n_number[b] = -1;
  change_number(opt, c);
  loop_number(a, c, number);
  free(number);
}

/*
** brief: check & filled our -n values
** @str1: char* whom checked -n
** @str2: char* whom checked the number
** @strp: char* whom checked .cor
** @opt: Our struct which contains our values
*/
void	check_my_number2(char *str1, char *str2, t_option *opt, char *strp)
{
  int	nb;

  if (my_strcmp("-n", str1) != 0 && my_cor(strp) == 1)
    {
      nb = my_getnbr(str2);
      if (nb < 1 || nb > 4)
	my_puterror(ERR_N2);
      if (opt->aid_number == 0)
        opt->n_number = nb;
      else
        opt->n_number = opt->n_number * 10 + nb;
      opt->aid_number = opt->aid_number + 1;
    }
  else
    my_puterror(ERR_COR);
}

/*
** brief: redir the different checking for filled -n values
** @av: contains all our arguments
** @opt: Our struct which contains our values
*/
void	check_my_number(char **av, t_option *opt)
{
  int	a;

  a = 1;
  while (av[a] != NULL)
    {
      if (my_cor(av[a]) == 1)
        {
          if (a - 2 > 0 && av[a - 2] != NULL && my_strcmp("-n", av[a - 2]) != 0)
	    check_my_number2(av[a - 2], av[a - 1], opt, av[a]);
	  else if (a - 4 > 0 && av[a - 4] != NULL && my_strcmp("-n", av[a - 4]) != 0
		   && my_cor(av[a - 2]) != 1)
	    check_my_number2(av[a - 4], av[a - 3], opt, av[a]);
          else
            {
              if (opt->aid_number == 0)
                opt->n_number = 5;
	      else
		 opt->n_number = opt->n_number * 10 + 5;
	      opt->aid_number = opt->aid_number + 1;
            }
	}
      a++;
    }
  check_the_n_number(opt->n_number, opt);
}
