/*
** main.c for let it go in /home/mar_b/colle_06_HBX_mar_b
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Sep 30 19:06:48 2014 mar_b mar_b
** Last update Tue Sep 30 22:36:31 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "list.h"
#include "utils.h"

static void	_init_values(char *opt, int *position)
{
  int		i;

  i = -1;
  while (++i < 5)
    opt[i] = 0;
  i = -1;
  while (++i < 2)
    position[i] = 0;
}

static char	my_tab_option(char *str, char *opt)
{
  char		*tab[5];
  char		type;
  int		i;

  i = 0;
  tab[ID_OPT_T] = OPT_T;
  tab[ID_OPT_R] = OPT_R;
  tab[ID_OPT_REV] = OPT_REV;
  tab[ID_OPT_STAT] = OPT_STAT;
  tab[ID_OPT_FLY] = OPT_FLY;
  while (i < 5 && (type = my_strcmp(str, tab[i])) == -1)
    i++;
  if (i < 5)
    {
      if (type)
	opt[i] = 1;
      else
	opt[i] = 0;
      return (1);
    }
  else
    return (0);
}

static void	_check_opt(char *opt, char *str1, char *str2, t_list *lst)
{
  if (str2 == NULL)
    lst = travel_str(str1);
  else
    {
      str1 = my_sort_char(str1);
      str2 = my_sort_char(str2);
      lst = travel_cmp(str1, str2, lst, -1);
    }
  if (opt[ID_OPT_T] && !opt[ID_OPT_R])
    my_sort_int(&lst, cmp_inf);
  if (opt[ID_OPT_R] && !opt[ID_OPT_STAT])
    travel_range(lst, opt[ID_OPT_REV], 0);
  else
    travel_lst(lst, opt[ID_OPT_REV]);
}

static void	_create_tab_opt(int argc, char **argv, char *opt, int *position)
{
  int		i;
  int		pos;

  i = 0;
  pos = 0;
  while (++i < argc)
    {
      if (my_tab_option(argv[i], opt) == 0)
	{
	  if (pos > 1)
	    my_puterror(ERR_USAGE);
	  position[pos] = i;
	  ++pos;
	}
    }
}

int		main(int argc, char **argv)
{
  t_list	*lst;
  int		position[2];
  char		opt[5];

  if (argc > 1)
    {
      lst = NULL;
      _init_values(opt, position);
      _create_tab_opt(argc, argv, opt, position);
      if (position[0] == 0)
	my_puterror(ERR_USAGE);
      _check_opt(opt, argv[position[0]],
		 position[1] == 0 ? NULL : argv[position[1]], lst);
      let_it_go(lst);
    }
  else
    my_putchar('\n');
  return (0);
}
