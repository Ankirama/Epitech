/*
** mainparser.c for mainparser in /home/chenev_d/rendu/CPE_2014_corewar
**
** Made by chenev_d chenev_d
** Login   <chenev_d@epitech.net>
**
** Started on  Mon Jul 21 13:37:54 2014 chenev_d chenev_d
** Last update Sun Aug 31 23:26:04 2014 chenev_d chenev_d
*/

#include <stdlib.h>
#include "parse.h"
#include "parser.h"

/*
** brief: Transform int to char*
** @nbr: Our int number
** return: Our int now transform into char*
*/
char	*int_to_array(int nbr)
{
  int	i;
  int	count;
  int	tmp;
  char	*arr;

  count = 1;
  tmp = nbr;
  while (tmp > 9)
    {
      tmp /= 10;
      ++count;
    }
  arr = my_malloc(sizeof(char) * (count + 1));
  i = count;
  while (nbr > 9)
    {
      arr[--i] = nbr % 10 + '0';
      nbr /= 10;
    }
  arr[--i] = nbr + '0';
  arr[count] = '\0';
  return (arr);
}

/*
** brief: init some usefull values
** @opt: struc contains our values
*/
void	my_init(t_option *opt)
{
  opt->n_number = 0;
  opt->a_adress = 0;
  opt->option = 0;
  opt->number_of_n = 0;
  opt->aid_adress = 0;
  opt->aid_number = 0;
}

/*
** brief: free all tab that we malloc
** @opt: struc contains our values
*/
void	freeparser(t_option *opt)
{
  free(opt->my_a_adress);
  free(opt->my_n_number);
  free(opt->my_cor);
}

/*
** brief: Will check all option & start vm
** @ac: number argument
** @av: argument
** return: 0
*/
t_list		*parser_option(int ac, char **av,
			       unsigned char *vm_memory)
{
  t_option	opt;
  t_list	*root;

  if (ac == 1)
    my_puterror(ERR_BASE);
  else
    {
      my_init(&opt);
      my_precheck(av);
      check_my_cor(av, &opt);
      my_second_check_number(av, &opt);
      check_my_dump(av, &opt);
      check_my_number(av, &opt);
      check_my_adress(av, &opt);
    }
  root = parse_vm(&opt, vm_memory);
  freeparser(&opt);
  return (root);
}
