/*
** my_str.c for my_str in /home/mar_b/rendu/PSU_2013_minishell1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Wed Jun 18 12:36:02 2014 mar_b mar_b
** Last update Tue Jul 29 18:32:59 2014
*/

#include <stdlib.h>
#include "utils.h"

/*
** brief: it will compare s1 and s2
** @s1: first string we will compare
** @s2: and the second one
** @equal: if equal = 1 then we will check if s1 = '=' and s2 = '\0',
** if equal = 2 then we will check if s2 = '\0' (for our parser)
** return: we will return 1 if they are equal
*/
char	my_strcmp(const char *s1, const char *s2, char equal)
{
  int	i;

  i = -1;
  while (s1[++i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]);
  if (equal == 1)
    return (s1[i] == '=' && s2[i] == '\0');
  else if (equal == 2)
    return (s2[i] == '\0');
  return ((s1[i] == s2[i] || s1[i] == ' ' || s1[i] == '\t') && s2[i] == '\0');
}

/*
** brief: we will calculate the str's size
** @str: we will find the str's size
** return: we will return the str's size
*/
int	my_strlen(const char *str)
{
  int	i;

  i = -1;
  if (str == NULL)
    return (0);
  while (str[++i] != '\0');
  return (i);
}

/*
** brief: it will copy each char into the new string
** @str: the string we will copy
** return: return the new string
*/
char    *my_strdup(const char *str)
{
  int   i;
  char  *cpy;

  if (str == NULL)
    return (NULL);
  if ((cpy = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    my_puterror("error: problem to malloc in my_str.c: l60!\n");
  i = 0;
  while (str[i] != '\0')
    {
      cpy[i] = str[i];
      ++i;
    }
  cpy[i] = '\0';
  return (cpy);
}

/*
** brief: this function will add our src into our dest
** @src: the source char *
** @dest: the destination char *
** return: we will return the dest;
*/
char	*my_strcat(char *dest, const char *src)
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
** brief: return the size of char**
** @arr: our char **
** return: return the size of char**
*/
int	my_arrlen(char **arr)
{
  int	i;

  i = -1;
  while (arr[++i] != NULL);
  return (i);
}
