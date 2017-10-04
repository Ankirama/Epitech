/*
** my_precheck.c for my_precheck in /home/chenev_d/rendu/CPE_2014_corewar/CPE_2014_corewar/parser
**
** Made by chenev_d chenev_d
** Login   <chenev_d@epitech.net>
**
** Started on  Sat Aug 16 18:21:40 2014 chenev_d chenev_d
** Last update Sun Aug 31 23:25:52 2014 chenev_d chenev_d
*/

#include <stdlib.h>
#include "utils.h"
#include "parser.h"

/*
** brief: Like ATOI with an error for parser
** @str: we will convert this string to an integer
** return: it will return the new integer
*/
int	my_getnbr_p(const char *str)
{
  int	i;
  int	nbr;

  i = -1;
  while (str[++i])
    {
      if (str[i] < '0' || str[i] > '9')
	my_puterror(ERR_BASE);
    }
  i = -1;
  nbr = 0;
  while (str[++i] && nbr >= 0)
    nbr = nbr * 10 + (str[i] - '0');
  return (nbr);
}

/*
** brief: precheking of all values contents in av
** @av: all our arguments
*/
void	my_precheck(char **av)
{
  int	a;
  int	d;

  a = 1;
  d = 0;
  while (av[a] != NULL)
    {
      if ((my_cor(av[a])) == 1)
	a++;
      else if (av[a + 1] != NULL && my_strcmp("-n", av[a]) != 0
	       && my_getnbr_p(av[a + 1]))
	a += 2;
      else if (av[a + 1] != NULL && my_strcmp("-dump", av[a]) != 0 && d++ == 0
	       && my_getnbr_p(av[a + 1]) >= 0)
	a += 2;
      else if (av[a + 1] != NULL && my_strcmp("-a", av[a]) != 0
	       && my_getnbr_p(av[a + 1]) >= 0)
	a += 2;
      else
	my_puterror(ERR_BASE);
    }
}

/*
** brief: check if we have the good number of -a relative .cor
** @av: all our arguments
*/
void	my_second_check_adress(char **av, t_option *opt)
{
  int	a;
  int	a_option;

  a_option = 0;
  a = 1;
  while (av[a] != NULL)
    {
      if (av[a + 2] != NULL && my_strcmp("-a", av[a]) != 0 && my_cor(av[a + 2]) == 1)
	a_option++;
      else if (av[a + 4] != NULL && my_strcmp("-a", av[a]) != 0
	       && my_cor(av[a + 4]) == 1 && my_strcmp("-a", av[a + 2]) == 0)
	a_option++;
      else
	if (my_strcmp("-a", av[a]) != 0)
	  my_puterror(ERR_TOOA);
      a++;
    }
  if (a_option != opt->number_cor && a_option != 0)
    my_puterror(ERR_A);
}

/*
** brief: check if we have the good number of -n relative .cor
** @av: all our arguments
*/
void	my_second_check_number(char **av, t_option *opt)
{
  int	a;
  int	n_option;

  n_option = 0;
  a = 1;
  while (av[a] != NULL)
    {
      if (av[a + 2] != NULL && my_strcmp("-n", av[a]) != 0 && my_cor(av[a + 2]) == 1)
	n_option++;
      else if (av[a + 4] != NULL && my_strcmp("-n", av[a]) != 0
	       && my_cor(av[a + 4]) == 1 && my_strcmp("-n", av[a + 2]) == 0)
	n_option++;
      else
	if (my_strcmp("-n", av[a]) != 0)
	  my_puterror(ERR_TOON);
      a++;
    }
  my_second_check_adress(av, opt);
}
