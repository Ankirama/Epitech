/*
** bsq.c for bsq in /home/mar_b/rendu/CPE-2013-BSQ
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue May  6 14:59:41 2014 mar_b mar_b
** Last update Sun May 11 20:01:09 2014 mar_b mar_b
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "bsq.h"
#include "my_fun.h"
#include "my_fun2.h"

/*
** Will init our vector (with x = 0 and y = 0)
*/
t_vector	*my_init_vector()
{
  t_vector	*pos;

  if ((pos = malloc(sizeof(*pos))) == NULL)
    my_puterror("ERROR: Problem with malloc!\n", 28);
  pos->x = 0;
  pos->y = 0;
  return (pos);
}

/*
** This function will try to find the biggest square
*/
void		my_bsq(char **arr, int lenarr, int lenrow, int max)
{
  t_vector	*pos;
  t_vector	*save;
  int		size;
  char		up;

  pos = my_init_vector();
  save = my_init_vector();
  size = 1;
  while (size + pos->y < lenarr && size <= max && arr[pos->y])
    {
      pos->x = 0;
      while (size + pos->x < lenrow && size <= max && arr[pos->y][pos->x])
	{
	  up = 0;
	  while (!my_search(arr, pos->x, pos->y, size))
	    {
	      up = 1;
	      size += 1;
	    }
	  my_change_pos(&save, pos->x, pos->y, up);
	  pos->x += 1;
	}
      pos->y += 1;
    }
  arr = my_add_array(arr, size - 1, &save, &pos);
}

int	main(int argc, char **argv)
{
  char	*s;
  int	fd;
  int	len;
  int	row;
  int	i;
  char	**arr;

  if (argc < 2)
    my_puterror("ERROR: not enough params!\n", 26);
  if ((fd = open(argv[1], O_RDONLY)) == -1)
    my_puterror("ERROR: problem to open the file!\n", 33);
  if ((s = get_next_line(fd)) == NULL)
    my_puterror("ERROR: Not enough lines!\n", 25);
  len = my_get_nbr(s);
  arr = malloc(sizeof(char *) * len);
  i = 0;
  while (s = get_next_line(fd))
    arr[i++] = s;
  arr[i] = 0;
  row = my_strlen(arr[0]);
  my_bsq(arr, len, row, row < len ? len : row);
  my_display(arr);
  if (close(fd) == -1)
    my_puterror("ERROR: problem to close the file!\n", 34);
  return (0);
}
