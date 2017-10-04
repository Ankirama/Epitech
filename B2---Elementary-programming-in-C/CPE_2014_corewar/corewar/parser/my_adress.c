/*
** my_adress.c for my_adress in /home/chenev_d/rendu/test/corewar
**
** Made by chenev_d chenev_d
** Login   <chenev_d@epitech.net>
**
** Started on  Sat Aug 16 12:35:56 2014 chenev_d chenev_d
** Last update Sun Aug 31 23:25:46 2014 chenev_d chenev_d
** Last update Sat Aug 30 00:15:45 2014 charles viterbo
** Last update Fri Aug 29 20:05:28 2014 chenev_d chenev_d
** Last update Mon Aug 25 15:45:39 2014 teyssa_r teyssa_r
*/

#include <stdlib.h>
#include "utils.h"
#include "parser.h"

/*
** brief: check our adress values & add them in our int*
** @nb: Our adress values
** @c: our number max adress values
** @number: our number in char * of adress
*/
void	check_the_a_adress(t_option *opt)
{
  opt->my_a_adress[opt->aid_adress] = -1;
}

/*
** brief: filled my tab adress
** @str1: contain my option
** @str2: contain my number
** @opt: struct which contains my values
*/
void	check_my_adress2(char *str1, char *str2, t_option *opt)
{
  int	nb;

  if (my_strcmp("-a", str1) != 0)
    {
      nb = my_getnbr(str2);
      if (nb < 0)
	my_puterror(ERR_NB);
      else
	opt->my_a_adress[opt->aid_adress] = nb % MEM_SIZE;
      opt->aid_adress = opt->aid_adress + 1;
    }
  else
    my_puterror(ERR_COR);
}

/*
** brief: redir the different checking for filled -a values
** @av: contains all our arguments
** @opt: Our struct which contains our values
*/
void	check_my_adress(char **av, t_option *opt)
{
  int	i;

  i = 0;
  opt->my_a_adress = my_malloc(sizeof(int) * (opt->number_cor + 1));
  while (av[++i] != NULL)
    {
      if (my_cor(av[i]) == 1)
	{
	  if (((i - 2) > 0) && av[i - 2] != NULL &&
	      my_strcmp("-a", av[i - 2]) != 0)
	    check_my_adress2(av[i - 2], av[i - 1], opt);
	  else if (i - 4 > 0 && av[i - 4] != NULL &&
		   my_strcmp("-a", av[i - 4]) != 0 && my_cor(av[i - 2]) != 1)
	    check_my_adress2(av[i - 4], av[i - 3], opt);
          else
            {
	      if (opt->aid_adress > 0)
                my_puterror(ERR_A);
	    }
	}
    }
  if (opt->aid_adress > 0)
    check_the_a_adress(opt);
  else
    opt->my_a_adress = NULL;
}
