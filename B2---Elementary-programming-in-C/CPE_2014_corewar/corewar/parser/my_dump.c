/*
** my_dump.c for my_dump in /home/chenev_d/rendu/test/corewar
**
** Made by chenev_d chenev_d
** Login   <chenev_d@epitech.net>
**
** Started on  Sat Aug 16 12:34:04 2014 chenev_d chenev_d
** Last update Sun Aug 31 23:25:59 2014 chenev_d chenev_d
** Last update Mon Aug 25 15:28:21 2014 teyssa_r teyssa_r
*/

#include <stdlib.h>
#include "utils.h"
#include "parser.h"

/*
** brief: check the option -dump and get the value of dump
** @av: contain all our arguments
** @opt: struct wich contains our values
** return: return 0
*/
int		check_my_dump(char **av, t_option *opt)
{
  int		a;
  int		dump;
  static int	d = 0;

  a = 0;
  while (av[a] != NULL)
    {
      if (my_strcmp("-dump", av[a]) != 0 && d == 0 && av[a + 1] != NULL)
        {
          dump = my_getnbr(av[a + 1]);
	  if (dump <= 0)
	    dump = 0;
	  opt->dump = dump;
	  d = 2;
        }
      else if (d == 0)
	opt->dump = -1;
      a++;
    }
  return (0);
}
