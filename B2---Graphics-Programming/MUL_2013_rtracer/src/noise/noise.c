/*
** noise.c for perlin in /home/mar_b/rendu/MUL_2013_rtracer/src/noise
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Wed Oct  8 20:40:30 2014 mar_b mar_b
** Last update Mon Oct  6 04:52:09 2014
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include "utils.h"
#include "noise.h"

static int	g_per[512] = {0};

/*
** brief: it will fill our array form our file
*/
void		create_perlin()
{
  int		fd;
  char		*s;
  int		i;

  if ((fd = open("./src/noise/perlin.noise", O_RDONLY)) == -1)
    my_puterror(ERR_OPEN);
  i = -1;
  while ((s = get_next_line(fd)) != NULL)
    {
      g_per[++i] = atoi(s);
      free(s);
    }
  if (close(fd) == -1)
    my_puterror(ERR_CLOSE);
}

/*
** brief: like a random number but more organizated
** @v1: it will use to randomize our values
*/
double		perlin_noise(t_vector *v1)
{
  int		pos[3];
  t_vector	*v;
  int		h[6];

  pos[0] = (int)floor(v1->x) & 255;
  pos[1] = (int)floor(v1->y) & 255;
  pos[2] = (int)floor(v1->z) & 255;
  v1->x -= floor(v1->x);
  v1->y -= floor(v1->y);
  v1->z -= floor(v1->z);
  v = create_vector(fade(v1->x), fade(v1->y), fade(v1->z));
  h[0] = g_per[pos[0]] + pos[1];
  h[1] = g_per[h[0]] + pos[2];
  h[2] = g_per[h[0] + 1] + pos[2];
  h[3] = g_per[pos[0] + 1] + pos[1];
  h[4] = g_per[h[3]] + pos[2];
  h[5] = g_per[h[3] + 1] + pos[2];
  return (lr(v->z, lr(v->y, lr(v->x, gr(g_per[h[1]], v1->x, v1->y, v1->z),
			       gr(g_per[h[4]], v1->x - 1, v1->y, v1->z)),
		      lr(v->x, gr(g_per[h[2]], v1->x, v1->y - 1, v1->z),
			 gr(g_per[h[5]], v1->x - 1, v1->y - 1, v1->z))),
	     lr(v->y, lr(v->x, gr(g_per[h[1] + 1], v1->x, v1->y, v1->z - 1),
			 gr(g_per[h[4] + 1], v1->x - 1, v1->y, v1->z - 1)),
		lr(v->x, gr(g_per[h[2] + 1], v1->x, v1->y - 1, v1->z - 1),
		   gr(g_per[h[5] + 1], v1->x - 1, v1->y - 1, v1->z - 1)))));
}
