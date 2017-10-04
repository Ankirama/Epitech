/*
** my_pixel.h for my_pixel in /home/user/rendu/MUL_2013_wolf3d
**
** Made by 
** Login   
**
** Started on  Sat Jun  7 02:49:29 2014 
** Last update Sun Jun 15 13:59:41 2014 
*/

#ifndef MY_PIXEL_H_
# define MY_PIXEL_H_

# include "wolf3d.h"

int	my_put_pixel_to_img(t_img *img, unsigned char *color, int i);
int	my_img_to_pixel(t_ptr *param, t_img *img, int i, int *k);
void    my_put_pixel_to_mini(t_img *img, int x, int y, unsigned char *color);

#endif /* !MY_PIXEL_H_ */
