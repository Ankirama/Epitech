/*
** str.c for str in /home/mar_b/rendu/MUL_2013_rtv1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Jul 11 18:15:56 2014 mar_b mar_b
** Last update Sat Sep 27 13:24:45 2014 mar_b mar_b
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
  while (str[i] != '\0')
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

  if ((cpy = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (my_puterror_null(ERR_MALLOC));
  i = -1;
  while (str[++i] != '\0')
    cpy[i] = str[i];
  cpy[i] = '\0';
  return (cpy);
}

/*
** brief: it will compare s1 and s2
** @s1: first string we will compare
** @s2: and the second one
** @equal: if equal = 1 then we will check if s1 = '=' and s2 = '\0'
** else normal strcmp
** return: we will return 1 if they are equal
*/
char	my_strcmp(const char *s1, const char *s2, const char equal)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
    ++i;
  if (equal == 1)
    return (s1[i] == '=' && s2[i] == '\0');
  else
    return ((s1[i] == s2[i] || s1[i] == ' ' || s1[i] == '\t') && s2[i] == '\0');
}

/*
** brief: like strcat, we will concatenate dest+src
** @src: the string we will add to dest
** @dest: our string
*/
char	*my_strcat(const char *src, char *dest)
{
  int	i;
  int	j;

  if (src != NULL)
    {
      i = my_strlen(dest);
      j = -1;
      while (src[++j] != '\0')
	{
	  dest[i] = src[j];
	  ++i;
	}
      dest[i] = '\0';
    }
  return (dest);
}

/*
** brief: it will return the array's size
** @arr: our char **
** return : return the nbr words
*/
int	my_arrlen(char **arr)
{
  int	i;

  if (arr == NULL)
    return (0);
  i = 0;
  while (arr[i] != NULL)
    ++i;
  return (i);
}
