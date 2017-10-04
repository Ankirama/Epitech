/*
** my_strcmp.c for my_strcmp in /home/lefebv_1/colle_06_HBX_mar_b
**
** Made by lefebv_1 lefebv_1
** Login   <lefebv_1@epitech.net>
**
** Started on  Tue Sep 30 20:31:26 2014 lefebv_1 lefebv_1
** Last update Tue Sep 30 22:14:46 2014 mar_b mar_b
*/

#include "utils.h"

static char	_my_optcmp(const char *s1, const char *s2)
{
  int		i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
    ++i;
  if (s1[i] != s2[i])
    return (1);
  else
    return (0);
}

static char	_my_checkopt(const char *str)
{
  if (_my_optcmp(str, "=on") == 0)
    return (1);
  else if (_my_optcmp(str, "=off") == 0)
    return (0);
  else
    return (-1);
}

char	my_strcmp(const char *s1, const char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && s1[i] != '=')
    {
      if (s1[i] != s2[i])
	return (-1);
      i++;
    }
  if (s1[i] == '=')
    return (_my_checkopt(&s1[i]));
  else if (s1[i] != '\0' || s2[i] != '\0')
    return (-1);
  return (1);
}
