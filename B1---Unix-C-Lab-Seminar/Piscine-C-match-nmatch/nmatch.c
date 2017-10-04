/*
** nmatch.c for nmatch in /home/mar_b/rendu/Piscine-C-match-nmatch
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Fri Mar 14 16:31:25 2014 Fabien Martinez
** Last update Sun Mar 16 15:24:46 2014 Fabien Martinez
*/

#include <stdlib.h>

int	nmatch_rec(char *s1, char *s2)
{
  if (s2[0] == '*')
    {
      if (s1[0] != 0)
	return (nmatch_rec(&s1[1], s2) + nmatch_rec(s1, &s2[1]));
      if (s1[0] == 0)
	return (nmatch_rec(s1, &s2[1]));
    }
  if (s1[0] == s2[0])
    {
      if (s1[0] != 0)
	return (nmatch_rec(&s1[1], &s2[1]));
      if (s1[0] == '\0')
	return (1);
    }
  return (0);
}

int	nmatch(char *s1, char *s2)
{
  if (s1 == NULL || s2 == NULL)
    return (0);
  return (nmatch_rec(s1, s2));
}
