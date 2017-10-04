/*
** main.c for dqwl in /home/mar_b/rendu/piscine_cpp_d01/ex04
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu Jan  8 08:20:28 2015 Fabien Martinez
** Last update Thu Jan  8 08:32:13 2015 Fabien Martinez
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include "drawing.h"
#include "bitmap.h"

int     menger(int x, int y, int size, int n, unsigned int **img);

int     main(int argc, char **argv)
{
  t_bmp_header		header;
  t_bmp_info_header	info;
  unsigned int		*buffer;
  unsigned int		**img;
  size_t		i;
  t_point		p = {0, 0};
  size_t		size = atoi(argv[2]);;
  int			d;

  if (argc != 4)
    {
      write(2, "menger_face file_name size level\n", 33);
      return (EXIT_FAILURE);
    }
  /* Creates a two-dimensional array. */
  buffer = malloc(size * size * sizeof(*buffer));
  img = malloc(size * sizeof(*img));
  memset(buffer, 0, size * size * sizeof(*buffer));
  for (i = 0; i < size; ++i)
    img[i] = buffer + i * size;
  make_bmp_header(&header, size);
  make_bmp_info_header(&info, size);
  draw_square(img, &p, size, 0x00000000);
  menger(size / 3, size / 3, size / 3, atoi(argv[3]) + 1, img);
  d = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
  write(d, &header, sizeof(header));
  write(d, &info, sizeof(info));
  write(d, buffer, size * size * sizeof(*buffer));
  close(d);
  return EXIT_SUCCESS;
}
