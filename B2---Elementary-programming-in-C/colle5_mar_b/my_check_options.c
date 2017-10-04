/*
** my_check_options.c for my_check_options in /home/lefebv_1/rendu/colle5_mar_b
** 
** Made by lefebv_1 lefebv_1
** Login   <lefebv_1@epitech.net>
** 
** Started on  Tue Sep 23 20:30:17 2014 lefebv_1 lefebv_1
** Last update Tue Sep 23 22:43:58 2014 lefebv_1 lefebv_1
*/

#include <stdlib.h>
#include "utils.h"

static char	**_my_arg_tab()
{
  char	**arg_tab;

  if ((arg_tab = malloc(sizeof(char *) * 4)) == NULL)
    my_puterror(ERR_MALLOC);
  arg_tab[0] = ARG_SIZE;
  arg_tab[1] = ARG_GRID;
  arg_tab[2] = ARG_WORD;
  arg_tab[3] = ARG_COLOR;
  return (arg_tab);
}

static void	_my_options(const int i, char *str, t_option *option)
{
  if (i == 0)
    my_size(str, option);
  else if (i == 1)
    my_grid(str, option);
  else if (i == 2)
    my_word(str, option);
  else if (i == 3)
    my_color(option);
}

static void	_my_check_grid_befor_size(t_option *option)
{
  if (option->grid != NULL
      && my_strlen(option->grid) < option->size * option->size)
    {
      my_putstr(ERR_GRID_LITTLE, 2);
      my_puterror(ERR_GRID);
    }
  if (option->grid != NULL
      && my_strlen(option->grid) > option->size * option->size)
    {
      my_putstr(ERR_GRID_BIG, 2);
      my_puterror(ERR_GRID);
    }
}

void	my_check_option(int argc, char **argv, t_option *option)
{
  char	**arg_tab;
  int	nbr_arg;
  int	i;

  i = 0;
  if (argc > 8)
    my_puterror(ERR_ARG);
  if ((arg_tab = _my_arg_tab()) == NULL)
    my_puterror(ERR_ARG_TAB);
  while (nbr_arg < argc)
    {
      i = 0;
      while (i < 4)
	{
	  if (my_strcmp(arg_tab[i], argv[nbr_arg]) == 0)
	    {
	      if (nbr_arg + 1 == argc)
		my_puterror(ERR_ARG);
	      _my_options(i, argv[nbr_arg + 1], option);
	    }
	  i = i + 1;
	}
      nbr_arg = nbr_arg + 1;
    }
  _my_check_grid_befor_size(option);
}
