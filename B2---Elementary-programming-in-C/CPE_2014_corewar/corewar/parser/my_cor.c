/*
** my_cor.c for my_cor.c in /home/chenev_d/rendu/test/corewar
** 
** Made by chenev_d chenev_d
** Login   <chenev_d@epitech.net>
** 
** Started on  Sat Aug 16 12:33:18 2014 chenev_d chenev_d
** Last update Sun Aug 31 23:26:11 2014 chenev_d chenev_d
*/

#include <stdlib.h>
#include "utils.h"
#include "parser.h"

/*
** brief: check if the arg is .cor or not
** @str: Our arg to be checked
** return: 1 if it's .cor 0 if it's not
*/
int	my_cor(char *str)
{
  int	l;

  l = my_strlen(str);
  if (l - 4 > 0)
    {
      if (my_strcmp(".cor", &str[l - 4]) != 0)
        return (1);
    }
  return (0);
}

/*
** brief: Count number of .cor in our arguments
** @av: all our arguments
** return: return the number of .cor
*/
int	count_my_cor(char **av)
{
  int	a;
  int	b;

  a = 0;
  b = 0;
  while (av[a] != NULL)
    {
      if ((my_cor(av[a])) == 1)
	b++;
      a++;
    }
  if (b < 1 || b > 4)
    my_puterror(ERR_CCOR);
  return (b);
}

/*
** brief: check all .cor and put them on char *
** @av: all our arguments
** @opt: our struct which contains all our values
** return: return 0
*/
int	check_my_cor(char **av, t_option *opt)
{
  int	a;
  int	b;
  int	d;
  int	e;

  a = 0;
  b = 0;
  d = 0;
  e = count_my_cor(av);
  opt->my_cor = my_malloc(sizeof(char*) * (e + 1));
  while (av[a] != NULL)
    {
      if ((my_cor(av[a])) == 1)
        {
          opt->my_cor[d++] = av[a];
          b++;
        }
      a++;
    }
  opt->my_cor[d] = NULL;
  opt->number_cor = b;
  if (opt->number_cor < 1 || opt->number_cor > 4)
    my_puterror(ERR_CCOR);
  return (0);
}
