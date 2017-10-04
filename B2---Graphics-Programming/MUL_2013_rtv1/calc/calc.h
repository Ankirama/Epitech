/*
** calc.h for calc in /home/user/rendu/MUL_2013_rtv1/calc
**
** Made by 
** Login   
**
** Started on  Sat Jul 12 18:03:06 2014 
** Last update Wed Jul 23 15:14:32 2014 
*/

#ifndef CALC_H_
# define CALC_H_

# include "objects.h"

# define C_ANG(ang)	(M_PI * ang / 180)

/*
** calc.c
*/
unsigned int	my_calc(int x, int y, t_scene *scene);

/*
** light.c
*/
unsigned int	my_brightness(float cos_a, unsigned int color);

/*
** vec_calc.c
*/
void		rotation_x(t_vector *pos, float ang);
void		rotation_y(t_vector *pos, float ang);
void		rotation_z(t_vector *pos, float ang);

#endif /* !CALC_H_ */
