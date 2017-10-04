/*
** my_strcmp.c for my_strcmp in /home/lefebv_1/rendu/colle5_mar_b
** 
** Made by lefebv_1 lefebv_1
** Login   <lefebv_1@epitech.net>
** 
** Started on  Tue Sep 23 19:06:09 2014 lefebv_1 lefebv_1
** Last update Tue Sep 23 21:53:17 2014 lefebv_1 lefebv_1
*/

#include "utils.h"

int	my_strcmp(const char *s1, const char *s2)
{
  int	i;

  i = 0;
  if (my_strlen(s1) != my_strlen(s2))
    return (-1);
  while (s1[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (-1);
      i = i + 1;
    }
  return (0);
}
