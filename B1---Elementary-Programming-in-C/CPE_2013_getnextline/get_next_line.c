/*
** get_next_line.c for get_next_line in /home/mar_b/rendu/CPE_2013_getnextline
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Tue Apr 15 11:53:13 2014 Fabien Martinez
** Last update Fri Apr 25 20:01:45 2014 Fabien Martinez
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static char *g_my_buffer = NULL;

/*
** This is a special my_strlen because it will count until a char OR \0 (ofc)
*/
static int	my_strlen(char *str, char c)
{
  int		i;

  i = 0;
  if (!str)
    return (i);
  while (str[i] && str[i] != c)
    i += 1;
  return (i);
}

/*
** Use to manage our static buffer (it will add chars if the current buffer)
** contain more than 1 \n
*/
static int	my_add(char *str, char my_globale)
{
  int		i;
  int		j;
  char		*my_str;

  i = 0;
  if ((my_str = malloc(my_strlen(str, '\0'))) == NULL)
    return (1);
  if (str[i] == '\n')
    i += 1;
  j = 0;
  while (str[i])
    my_str[j++] = str[i++];
  my_str[j] = '\0';
  if (my_globale == 0)
    free(g_my_buffer);
  g_my_buffer = my_str;
  return (0);
}

/*
** This function will initialize our buffer because it's funny !
*/
static void	init_buff(char *buffer)
{
  int		i;

  i = 0;
  while (i < MAX_BUFF + 1)
    {
      buffer[i] = '\0';
      i += 1;
    }
}

/*
** This function will "alloc" the good size (or max if no \n found)
** It will create new str with last str + buffer (you've to say WOOOOW <3)
*/
static char	my_realloc(char **base, char *src, char my_glob)
{
  char		*res;
  long		i;
  int		j;

  if ((res = malloc(my_strlen((*base), 0) + my_strlen(src, '\n') + 1)) == NULL)
    return (-1);
  i = 0;
  while ((*base)[i])
    {
      res[i] = (*base)[i];
      i += 1;
    }
  j = 0;
  while (j < my_strlen(src, '\n'))
    {
      res[i] = src[j];
      i += 1;
      j += 1;
    }
  res[i] = '\0';
  free((*base));
  (*base) = res;
  if (j != my_strlen(src, '\0') && my_add(&src[my_strlen(src, '\n')], my_glob))
    return (-1);
  return (my_strlen(src, '\0') != my_strlen(src, '\n'));
}

/*
** This function will get the next line.... TROLL
** In fact, it'll use my_realloc to create of str until \n OR the EOF
*/
char	*get_next_line(const int fd)
{
  char	buffer[MAX_BUFF + 1];
  int	len;
  char	*my_out;
  char	res;

  len = 1;
  if ((my_out = malloc(sizeof(char))) == NULL)
    return (NULL);
  my_out[0] = '\0';
  res = 0;
  if (fd < 0)
    return (NULL);
  if (g_my_buffer != NULL && g_my_buffer[0])
    res = my_realloc(&my_out, g_my_buffer, 1);
  while (len != 0 && res == 0)
    {
      init_buff(buffer);
      if ((len = read(fd, buffer, MAX_BUFF)) > 0)
	{
	  buffer[len] = '\0';
	  res = my_realloc(&my_out, &buffer[0], 0);
	}
    }
  return ((len < 0 || buffer[0] == '\0' ||
	   (!res && !g_my_buffer[0] && !my_out[0]) || res < 0) ? NULL : my_out);
}
