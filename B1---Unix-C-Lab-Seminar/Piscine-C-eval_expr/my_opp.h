/*
** my_opp.h for my_opp.h in /home/mar_b/rendu/Piscine-C-eval_expr
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Sun Mar 30 17:19:18 2014 Fabien Martinez
** Last update Sun Mar 30 17:20:59 2014 Fabien Martinez
*/

#ifndef MY_OPP_H_
# define MY_OPP_H_

t_opp	g_opptab[] = {{"+", &my_add}, {"-", &my_sub}, {"/", &my_div},
		      {"*", &my_mul}, {"%", &my_mod}, {"", &my_usage}};

#endif /* !MY_OPP_H_ */
