/*
** main.c for main in /home/lefebv_1/rendu/colle1
**
** Made by lefebv_1 lefebv_1
** Login   <lefebv_1@epitech.net>
**
** Started on  Tue Aug 26 22:19:59 2014 lefebv_1 lefebv_1
** Last update Tue Aug 26 22:24:13 2014 mar_b mar_b
*/

#include "utils.h"

static void	_my_error(const int verif)
{
  if (verif == 1)
    my_putstr(ERR_SECARG, 2);
  else if (verif == 2)
    my_putstr(ERR_THIRARG, 2);
  else if (verif == 3)
    my_putstr(ERR_SECTHI_ARG, 2);
  my_puterror(ERR_USAGE);
}

int	main(int argc, char **argv)
{
  int	nbr;
  int	verif;

  if (argc == 4)
    {
      nbr = my_getnbr(argv[1]);
      if (nbr == 0)
	{
	  my_putstr(DEFAULT_SHARP, 1);
	  return (0);
	}
      if ((verif = my_check_arg(argv[2], argv[3])) != 0)
	_my_error(verif);
      else
	my_putstr(NORMAL_USAGE, 1);
    }
  else
    my_puterror(ERR_NTARGS);
  return (0);
}
