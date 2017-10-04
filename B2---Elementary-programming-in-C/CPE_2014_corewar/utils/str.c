/*
** str.c for str in /home/mar_b/rendu/MUL_2013_rtv1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Jul 11 18:15:56 2014 mar_b mar_b
** Last update Sun Aug 17 16:58:48 2014 mar_b mar_b
*/

#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

/*
** brief: will calculate the numbers of char
** @str: this is the string
** return: will return the number of char
*/
int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    ++i;
  return (i);
}

/*
** brief: it will copy each char into the new string
** @str: the string we will copy
** return: return the new string
*/
char	*my_strdup(const char *str)
{
  int	i;
  char	*cpy;

  cpy = my_malloc(sizeof(char) * my_strlen(str));
  i = -1;
  while (str[++i])
    cpy[i] = str[i];
  cpy[i] = '\0';
  return (cpy);
}

/*
** brief: like strcmp : cmp 2 strings
** @s1, s2: our string we want to compare
** return (1 if there is a match, else 0)
*/
char	my_strcmp(const char *s1, const char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
    ++i;
  return (s1[i] == s2[i] && s1[i] == '\0');
}

/*
** brief: like strcat, we will concatenate dest+src
** @src: the string we will add to dest
** @dest: our string
*/
void	my_strcat(const char *src, char *dest)
{
  int	i;
  int	j;

  i = 0;
  while (dest[i] != '\0')
    ++i;
  j = -1;
  while (src[++j] != '\0')
    {
      dest[i] = src[j];
      ++i;
    }
  dest[i] = '\0';
}

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  i = i + 1;
  dest[i] = '\0';
  return (dest);
}
