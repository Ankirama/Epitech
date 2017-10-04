/*
** str.c for str in /home/mar_b/rendu/Allum1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Jul  3 11:39:29 2014 mar_b mar_b
** Last update Thu Jul  3 13:14:59 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "utils.h"

/*
** brief: like strdup -> copy each char into a new str WOOOOW <3 <3 <3 <3
** @src: our source char *
** return: return our new string;
*/
char	*my_strdup(const char *src)
{
  int	i;
  char	*dest;

  if ((dest = malloc(sizeof(char) * (my_strlen(src) + 1))) == NULL)
    my_puterror("error: problem to malloc in utils.c\n");
  i = -1;
  while (src[++i] != '\0')
    dest[i] = src[i];
  dest[i] = '\0';
  return (dest);
}

/*
** brief: it will return the size
** @str; our char *
** return: return our size
*/
int	my_strlen(const char *str)
{
  int	i;

  i = -1;
  while (str[++i]);
  return (i);
}
