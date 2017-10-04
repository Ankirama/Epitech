/*
** my_check.c for my_check in /home/mar_b/rendu/PSU_2013_my_ls
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Sun Apr 27 12:53:45 2014 Fabien Martinez
** Last update Fri May  2 16:56:15 2014 Fabien Martinez
*/

#include "my_ls.h"

static char	my_create_tab_optls(char c)
{
  char		tab[14];
  char		i;

  tab[RECURSIVE] = 'R';
  tab[REVERSE] = 'r';
  tab[DIRC] = 'd';
  tab[LONG] = 'l';
  tab[TIME] = 't';
  tab[GROUP] = 'G';
  tab[NOTSORT] = 'f';
  tab[OWNER] = 'g';
  tab[INDICATOR] = 'F';
  tab[ALL] = 'a';
  tab[INFGRP] = 'o';
  tab[BACKUP] = 'B';
  tab[SIZE] = 'S';
  tab[QUOTE] = 'Q';
  i = 0;
  while (tab[i] && tab[i] != c)
    i += 1;
  return (i);
}

char	my_check_options(char *opt, char *str)
{
  int	i;
  char	c;

  i = 1;
  while (str[i])
    {
      if ((c = my_create_tab_optls(str[i])) < 14)
	opt[c] = 1;
      else
	return (1);
      i += 1;
    }
  opt[LONG] = opt[INFGRP] || opt[OWNER] ? 1 : opt[LONG];
  opt[ALL] = opt[NOTSORT] ? 1 : opt[ALL];
  return (0);
}

char	my_check_dir(char *file)
{
  if (file[0] == '.' && (file[1] == '\0' ||
			 (file[1] == '.' && file[2] == '\0')))
    return (1);
  return (0);
}
