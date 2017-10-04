/*
** ex_6.h for struct in /home/mar_b/rendu/piscine_cpp_d01/ex06
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Jan  7 23:26:49 2015 Fabien Martinez
** Last update Thu Jan  8 01:04:24 2015 Fabien Martinez
*/

#ifndef EX_6_H_
# define EX_6_H_

typedef union	s_nbr
{
  char		foo[2];
  char		bar[2];
}		t_nbr;


typedef struct	s_strct
{
  short int   	foo;
  union s_nbr	bar;
}		u_strct;

typedef union	s_foo
{
  struct s_strct foo;
  int		bar;
}		t_foo;

#endif /* !EX_6_H_ */
