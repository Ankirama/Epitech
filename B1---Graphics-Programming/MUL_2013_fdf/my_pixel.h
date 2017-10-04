/*
** my_pixel.h for my_pixel in /home/mar_b/rendu/MUL_2013_fdf
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Apr 30 13:32:54 2014 Fabien Martinez
** Last update Thu May  8 23:06:55 2014 mar_b mar_b
*/

#ifndef MY_PIXEL_H_
# define MY_PIXEL_H_

typedef struct	s_pixel
{
  int		x;
  int		y;
  char		nbr_oct;
  unsigned char	*color;
}		t_pixel;

void	my_put_pixel_to_img(t_pixel *pix, char **data, int sizeline, int z);
t_pixel	*fill_my_pixel(int x, int y, char nbr_oct, unsigned char *color);

#endif /* !MY_PIXEL_H_ */
