/*
** noise.h for noise in /home/user/rendu/MUL_2013_rtracer
**
** Made by 
** Login   
**
** Started on  Fri Oct 10 10:55:07 2014 
** Last update Sun Oct 12 18:34:41 2014 
*/

#ifndef NOISE_H_
# define NOISE_H_

# include "objects.h"

/*
** NOISE_C_
*/
void	create_perlin();
double	perlin_noise(t_vector *v1);

/*
** FUN_C_
*/
double	lr(double t, double a, double b);
double	fade(double t);
double	gr(int hash, double x, double y, double z);

/*
** COLOR_C_
*/
t_color	*choose_color(double n);

#endif /* !NOISE_H_ */
