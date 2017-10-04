/*
** my_img.h for my_img in /home/user/rendu/MUL_2013_wolf3d
**
** Made by 
** Login   
**
** Started on  Sat Jun  7 02:46:10 2014 
** Last update Sat Jun 14 15:56:01 2014 
*/

#ifndef MY_IMG_H_
# define MY_IMG_H_

# include "wolf3d.h"

int	my_expose(t_ptr *param);
t_img	*my_initimg(void *ptr);
void	my_sky_ground(t_ptr *param);
void	my_wall(t_ptr *param, t_vector *pos);

#endif /* !MY_IMG_H_ */
