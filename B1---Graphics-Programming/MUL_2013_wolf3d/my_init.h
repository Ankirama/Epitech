/*
** my_init.h for my_init in /home/mar_b/rendu/MUL_2013_wolf3d
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Wed Jun 11 16:03:43 2014 mar_b mar_b
** Last update Fri Jun 13 19:53:11 2014 mar_b mar_b
*/

#ifndef MY_INIT_H_
# define MY_INIT_H_

# include "wolf3d.h"

t_vector	*my_init_pos();
void		my_init_move(t_ptr *param, float x, float y);
void		my_load_conf(t_ptr *ptr, int fd);

#endif /* !MY_INIT_H_ */
