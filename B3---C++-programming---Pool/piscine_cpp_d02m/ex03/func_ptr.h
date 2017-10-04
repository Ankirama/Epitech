/*
** func_ptr.h for func in /home/mar_b/rendu/piscine_cpp_d02m/ex03
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu Jan  8 10:45:28 2015 Fabien Martinez
** Last update Thu Jan  8 11:12:37 2015 Fabien Martinez
*/

#ifndef FUNC_PTR_H_
# define FUNC_PTR_H_

# include "func_ptr_enum.h"

void	print_normal(char *str);
void	print_reverse(char *str);
void	print_upper(char *str);
void	print_42(char *str);
void	do_action(t_action action, char *str);

typedef struct	s_do_action
{
  t_action	current;
  void	(*my_func)(char *);
}		t_do_action;

#endif /* !FUNC_PTR_H_ */
