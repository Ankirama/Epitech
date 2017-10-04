/*
** my_path.c for my_path in /home/mar_b/rendu/PSU_2013_my_ls
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Apr 28 11:13:34 2014 Fabien Martinez
** Last update Fri May  2 19:34:57 2014 Fabien Martinez
*/

#include <stdlib.h>
#include "my_display.h"
#include "my_printf.h"

/*
** This function will separate the path and the name
*/
char	*my_separpath(char **str)
{
  char	*path;
  char	*file;
  int	i;
  int	j;
  int	limit;

  i = my_strlen((*str)) - 1;
  while ((*str)[i] && (*str)[i] != '/')
    i -= 1;
  i += 1;
  if ((file = malloc(my_strlen((*str)) - i + 1)) == NULL
      || (path = malloc(i + 1)) == NULL)
    my_puterror();
  limit = i;
  j = 0;
  while ((*str)[i])
    file[j++] = (*str)[i++];
  file[j] = '\0';
  i = 0;
  while (i < limit)
    path[i] = (*str)[i++];
  path[i] = '\0';
  (*str) = path;
  return (file);
}

/*
** This function is like my_separpath but for option 'd'
*/
char	*my_separpathD(char **str)
{
  char	*path;
  char	*file;
  int	i;
  int	j;
  int	limit;

  i = (*str)[my_strlen(*str) - 1] == '/' ?
    my_strlen((*str)) - 2 : my_strlen((*str)) - 1;
  while ((*str)[i] && (*str)[i] != '/')
    i -= 1;
  i += 1;
  if ((file = malloc(my_strlen((*str)) - i + 1)) == NULL
      || (path = malloc(i + 1)) == NULL)
    my_puterror();
  limit = i;
  j = 0;
  while ((*str)[i])
    file[j++] = (*str)[i++];
  file[j] = '\0';
  i = 0;
  while (i < limit)
    path[i] = (*str)[i++];
  path[i] = '\0';
  (*str) = path;
  return (file);
}

/*
** return the path + file lile ./poney.txt
*/
char	*my_pathfile(char *path, char *file, char c)
{
  char	*str;
  int	i;
  int	j;

  if ((str = malloc(my_strlen(path) + my_strlen(file) + 2)) == NULL)
    return (NULL);
  i = 0;
  while (path[i])
    str[i] = path[i++];
  j = 0;
  while (file[j])
    str[i++] = file[j++];
  if (c != '\0')
    str[i++] = c;
  str[i] = '\0';
  return (str);
}
