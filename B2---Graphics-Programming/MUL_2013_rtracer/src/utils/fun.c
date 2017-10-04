/*
** fun.c for  in /home/teyssa_r/rendu/MUL_2013_rtracer/src/utils
**
** Made by teyssa_r teyssa_r
** Login   <teyssa_r@epitech.net>
**
** Started on  Sun Oct 12 16:02:49 2014 teyssa_r teyssa_r
** Last update Sun Oct 12 16:49:08 2014 mar_b mar_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "utils.h"
#include "objects.h"

/*
** brief: to malloc a variable and check if malloc failed
** return: the element malloc or NULL
*/
void	*my_malloc(size_t size)
{
  void	*ptr;

  if ((ptr = malloc(size)) == NULL)
    my_puterror(ERR_MALLOC);
  return (ptr);
}

/*
** brief: to write and check if write failed
*/
void	my_write(int fd, void *buf, size_t size)
{
  if (write(fd, buf, size) < 0)
    my_puterror(ERR_WRITE);
}

/*
** brief: init buff to 0
*/
void	init_buff(unsigned char *buff, int size)
{
  int	i;

  i = -1;
  while (++i < size)
    buff[i] = 0;
}
