/*
** 42sh.h for  in /home/teyssa_r/rendu/PSU_2013_42sh
**
** Made by teyssa_r teyssa_r
** Login   <teyssa_r@epitech.net>
**
** Started on  Mon Sep  1 18:14:09 2014 teyssa_r teyssa_r
** Last update Thu Oct  2 23:02:59 2014 charles viterbo
*/

#ifndef MINI_H_
# define MINI_H_

# define ERR_SIGN	"error: problem with signal SIGINT\n"
# define ERR_READ	"error: problem with read\n"

# define ID_EOF		0
# define BUFF		512
# define CLR_SHELL	"\033[1;31m$>\033[0m"

# include "list.h"

/*
** MY_PROMPT_C_
*/
void	my_prompt();

/*
** SIGNAL_C_
*/
char	my_signal(t_list *env);

#endif /* !MINI_H_ */
