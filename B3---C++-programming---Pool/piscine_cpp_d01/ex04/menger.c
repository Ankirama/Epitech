#include "drawing.h"
#include "bitmap.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdio.h>

int     menger(int x, int y, int size, int n, unsigned int **img)
{
  int   grey;
  t_point	p;

  n--;
  p.x = x;
  p.y = y;
  if (n > 1)
    {
      grey = (int)255 / n;
      grey = grey * 256 * 256 + grey * 256 + grey;
      draw_square(img, &p, size, (uint32_t)grey);
    }
  else if (n == 1)
    draw_square(img, &p, size, 0x00FFFFFF);
  if (size == 1)
    draw_square(img, &p, size, 0x00FFFFFF);
  if (n > 0)
    {
      menger(x - 2 * size / 3, y - 2 * size / 3, size / 3, n, img);
      menger(x - 2 * size / 3, y + size / 3, size / 3, n, img);
      menger(x - 2 * size / 3, y + size + size / 3, size / 3, n, img);
      menger(x + size / 3, y - 2 * size / 3, size / 3, n, img);
      menger(x + size / 3, y + size + size / 3, size / 3, n, img);
      menger(x + size + size / 3 , y - 2 * size / 3, size / 3, n, img);
      menger(x + size + size / 3, y + size / 3, size / 3, n, img);
      menger(x + size + size / 3, y + size + size / 3 ,size / 3, n, img);
    }
  return (0);
}
