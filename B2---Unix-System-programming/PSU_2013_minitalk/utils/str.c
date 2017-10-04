/*
** str.c for str in /home/mar_b/rendu/MUL_2013_rtv1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Jul 11 18:15:56 2014 mar_b mar_b
** Last update Tue Aug  5 00:10:32 2014
*/

#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

void	my_write(int fd, const char *str, int size)
{
  if (write(fd, str, size) != size)
    exit(EXIT_FAILURE);
}

/*
** brief: will calculate the numbers of char
** @str: this is the string
** return: will return the number of char
*/
int	my_strlen(const char *str)
{
  int	i;

  i = -1;
  if (str == NULL)
    return (0);
  while (str[++i]);
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

  if ((cpy = malloc(sizeof(char) * my_strlen(str))) == NULL)
    my_puterror("error: problem to malloc!\n");
  i = -1;
  while (str[++i])
    cpy[i] = str[i];
  cpy[i] = '\0';
  return (cpy);
}
