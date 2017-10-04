/*
** my_calc.h for my_calc in /home/mar_b/rendu/MUL_2013_wolf3d
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Wed Jun 11 15:26:03 2014 mar_b mar_b
** Last update Thu Jun 12 16:44:03 2014 mar_b mar_b
*/

#ifndef MY_CALC_H_
# define MY_CALC_H_

# include "wolf3d.h"

void	my_move_xy(t_ptr *par, char up, t_vector **pos);
void	my_check_collision(t_ptr *par, t_vector *pos);
float	my_range(t_ptr *pr, float x, float y);

#endif /* !MY_CALC_H_ */
