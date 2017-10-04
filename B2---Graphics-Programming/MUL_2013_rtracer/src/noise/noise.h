/*
** noise.h for noise in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Oct 10 10:55:07 2014 mar_b mar_b
** Last update Sun Oct 12 18:34:41 2014 mar_b mar_b
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
