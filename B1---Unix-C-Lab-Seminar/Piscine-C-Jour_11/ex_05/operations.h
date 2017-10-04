/*
** operations.h for operation in /home/mar_b/rendu/Piscine-C-Jour_11/do-op
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Mar 24 09:45:59 2014 Fabien Martinez
** Last update Mon Mar 24 14:53:19 2014 Fabien Martinez
*/

#ifndef OPERATIONS_H_
# define OPERATIONS_H_

typedef struct	s_opp
{
  char		*str;
  int		(*fun) (int, int);
}		t_opp;

int	my_add(int, int);
int	my_sub(int, int);
int	my_div(int, int);
int	my_mul(int, int);
int	my_mod(int, int);

#endif /* !OPERATIONS_H_ */
