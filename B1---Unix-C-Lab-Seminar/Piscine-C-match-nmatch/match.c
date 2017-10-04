/*
** match.c for match in /home/mar_b/rendu/Piscine-C-match-nmatch
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Fri Mar 14 11:09:28 2014 Fabien Martinez
** Last update Sun Mar 16 15:18:21 2014 Fabien Martinez
*/

#include <stdlib.h>

char	*my_check_letter(char *str, char c)
{
  int	i;
  int	pos;

  i = 0;
  pos = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	{
	  pos = i;
	}
      i += 1;
    }
  return (&str[pos]);
}

char	match(char *s1, char *s2)
{
  if (s1 == NULL || s2 == NULL)
    return (0);
  if (s2[0] == '*')
    {
      while (s2[0] == '*')
	s2 = &s2[1];
      if (s2[0] == '\0') return (1);
      while (s1[0] != '\0' && s1[0] != s2[0])
	s1 = &s1[1];
      s1 = my_check_letter(s1, s2[0]);
      return (match(s1, s2) && s1[0] != '\0');
    }
  else if (s2[0] == '\0' || s1[0] == '\0')
    return (s2[0] == s1[0]);
  else if (s2[0] == s1[0] || s2[0] == '?')
    return (match(&s1[1], &s2[1]));
  else
    return (0);
}
