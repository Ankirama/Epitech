/*
** my_word.c for my_word in /home/lefebv_1/rendu/colle5_mar_b
** 
** Made by lefebv_1 lefebv_1
** Login   <lefebv_1@epitech.net>
** 
** Started on  Tue Sep 23 21:11:12 2014 lefebv_1 lefebv_1
** Last update Tue Sep 23 22:31:51 2014 lefebv_1 lefebv_1
*/

#include "utils.h"

static int	_my_check_word(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 'a' || str[i] > 'z')
	{
	  my_putstr(ERR_WORD, 2);
	  return (-1);
	}
      i = i + 1;
    }
  return (0);
}

void	my_word(char *str, t_option *option)
{
  if (_my_check_word(str) == 0)
    option->word = str;
  else
    my_puterror(ERR_ARG);
}
