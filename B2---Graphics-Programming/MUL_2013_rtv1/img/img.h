/*
** img.h for img in /home/mar_b/rendu/MUL_2013_rtv1/img
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Jul 11 18:47:04 2014 mar_b mar_b
** Last update Wed Jul 16 21:57:26 2014 mar_b mar_b
*/

#ifndef IMG_H_
# define IMG_H_

# include "rtv1.h"
# include "objects.h"

/*
** img.c
*/
t_img		*my_initimg(void *ptr);
void		my_fill_img(t_img *img, t_scene *scene, char percent);

/*
** pixel.c
*/
void		my_put_pixel_to_img(t_img *img, unsigned char *color, int i);

#endif /* !IMG_H_ */
