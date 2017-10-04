/*
** my_fun.c for my_fun in /home/mar_b/rendu/PSU_2013_my_select
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Mon May 12 14:06:34 2014 mar_b mar_b
** Last update Wed May 28 14:30:43 2014 mar_b mar_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_select.h"
#include "my_error.h"

static int	g_my_fd;

/*
** Will initialize our str (buffer)
*/
void	my_init(char *str, int size, int fd)
{
  int	i;

  i = 0;
  while (i < size)
    str[i++] = 0;
  g_my_fd = fd;
}

/*
** Used for tputs
*/
int	my_putchar(int c)
{
  return (write(g_my_fd, &c, 1));
}

void	my_putstr(char *str, int size)
{
  int	i;

  i = -1;
  while (++i < size)
    (void)my_putchar(str[i]);
}

/*
** Will return the string's length
*/
int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i += 1;
  return (i);
}

/*
** will create our "vector"
*/
t_position	*create_pos()
{
  t_position	*pos;

  if ((pos = malloc(sizeof(*pos))) == NULL)
    my_puterror("error: problem to malloc vector!\n", 33);
  pos->x = 0;
  pos->y = 0;
  return (pos);
}
