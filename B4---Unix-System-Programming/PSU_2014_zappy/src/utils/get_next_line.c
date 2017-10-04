/*
** get_next_line.c for get_next_line in /home/mar_b/rendu/CPE_2013_getnextline
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Tue Apr 15 11:53:13 2014 Fabien Martinez
** Last update Fri Apr 25 20:01:45 2014 Fabien Martinez
*/

/*
** @file get_next_line.c
** @brief get_next_line to a line from file descriptor
** @author ankirama
** @version 1.0
*/

#include <unistd.h>
#include <stdlib.h>
#include "utils.h"

static char	*g_my_buffer = NULL;

/*
** @brief special strlen because it will count until a char OR \0
**
** @param str our string we want to know size
** @param c our character we will stop to count
** @return string's size
*/
static int	_my_len(char *str, char c)
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
** @brief Use to manage our static buffer
**
** it will add chars if the current buffer contain more than 1 \n
**
** @param str our string
** @param my_globale used to check if we have to free the gloab buffer 0 = free
** @return 1 if unable to malloc else 0
*/
static int	_my_add(char *str, char my_globale)
{
  int		i;
  int		j;
  char		*my_str;

  i = 0;
  if ((my_str = malloc(_my_len(str, '\0'))) == NULL)
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
** @brief This function will initialize our buffer because it's funny !
**
** @param buffer our current buffer from our fd
*/
static void	_init_buff(char *buffer)
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
** @brief create new str from buffer + global buffer
**
** This function will "alloc" the good size (or max if no \n found)
** It will create new str with last str + buffer (you've to say WOOOOW <3)
**
** @param base pointer to our string created in get_next_line
** @param src our global buffer
** @param my_glob used for my_add (0 = free)
** @return -1 if any problem or boolean between between size str with \0 or \n
*/
static char	_my_rea(char **base, char *src, char my_glob)
{
  char		*res;
  long		i;
  int		j;

  if ((res = my_malloc(_my_len((*base), 0) + _my_len(src, '\n') + 1)) == NULL)
    return (-1);
  i = 0;
  while ((*base)[i])
    {
      res[i] = (*base)[i];
      i += 1;
    }
  j = 0;
  while (j < _my_len(src, '\n'))
    {
      res[i] = src[j];
      i += 1;
      j += 1;
    }
  res[i] = '\0';
  free((*base));
  (*base) = res;
  if (j != _my_len(src, '\0') && _my_add(&src[_my_len(src, '\n')], my_glob))
    return (-1);
  return (_my_len(src, '\0') != _my_len(src, '\n'));
}

/*
** @brief This function will get the next line
**
** It'll use _my_rea to create of str until \n OR the EOF
**
** @param fd our file descriptor we will read
** @return new string created
*/
char	*get_next_line(const int fd)
{
  char	buffer[MAX_BUFF + 1];
  int	len;
  char	*my_out;
  char	res;

  len = 1;
  if ((my_out = my_malloc(sizeof(char))) == NULL)
    return (NULL);
  my_out[0] = '\0';
  res = 0;
  if (fd < 0)
    return (NULL);
  if (g_my_buffer != NULL && g_my_buffer[0])
    res = _my_rea(&my_out, g_my_buffer, 1);
  while (len != 0 && res == 0)
    {
      _init_buff(buffer);
      if ((len = my_read(fd, buffer, MAX_BUFF)) > 0)
	{
	  buffer[len] = '\0';
	  res = _my_rea(&my_out, &buffer[0], 0);
	}
    }
  return ((len < 0 || buffer[0] == '\0' ||
	   (!res && !g_my_buffer[0] && !my_out[0]) || res < 0) ? NULL : my_out);
}
