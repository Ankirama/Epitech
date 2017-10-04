/*
** str.c for str in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sun Oct 12 15:01:32 2014 mar_b mar_b
** Last update Sun Oct 12 15:01:36 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "utils.h"

/*
** brief : to count the longer of the string
** @str : the string
** return : the longer of the string
*/
int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    {
      while (str[i] != '\0')
	++i;
    }
  return (i);
}

/*
** brief: put src to the end of dest
** @dest: destination
** @src: source
*/
char	*my_strcat(char *dest, char *src)
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
  return (dest);
}

/*
** brief : to count the longer of the array
** @str : the array
** return : the longer of the array
*/
int	my_arrlen(char **array)
{
  int	i;

  i = 0;
  while (array[i] != NULL)
    i++;
  return (i);
}

/*
** brief : to compare two string
** @s1: the first string
** @s2: the second string
** return : 0 or the difference ascii
*/
char	my_strcmp(const char *s1, const char *s2)
{
  int	i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (1);
  while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
    ++i;
  return (s1[i] == '\0' && s2[i] == s1[i] ? 0 : 1);
}

/*
** brief : to malloc an other variable size of str, and copy str to
** the new variable
** @sstr: the constant str
** return : destination
*/
char	*my_strdup(const char *str)
{
  int	i;
  char	*dest;

  dest = my_malloc(sizeof(char) * (my_strlen(str) + 1));
  i = -1;
  while (str[++i] != '\0')
    dest[i] = str[i];
  dest[i] = '\0';
  return (dest);
}
