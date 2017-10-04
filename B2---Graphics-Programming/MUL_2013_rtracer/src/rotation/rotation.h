/*
** rotation.h for  in /home/viterb_c/rendu/MUL_2013_rtracer/src/rotation
** 
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
** 
** Started on  Sat Oct  4 13:52:08 2014 charles viterbo
** Last update Wed Oct  8 18:43:39 2014 charles viterbo
*/

#ifndef ROTATION_H_
# define ROTATION_H_

#include "utils.h"

/*
** ROTATION_H_
*/
char		rot_x(const double*, double *y, double *z, double angle);
char		rot_y(double *x, const double*, double *z, double angle);
char		rot_z(double *x, double *y, const double*, double angle);
t_vector	*rotate_vector(t_vector *vec, t_vector *angle, double coeff);

#endif /* !ROTATION_H_ */
