/*
** my_parser.h for my_parser in /home/mar_b/minishell/parser
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Mon Jun 23 16:34:39 2014 mar_b mar_b
** Last update Sun Aug  3 19:57:55 2014 mar_b
*/

#ifndef PARSER_H_
# define PARSER_H_

# include "list.h"

# define ID_ADD_FERR	0
# define ID_ADD_FOUT	1
# define ID_FLUX_ERR	2
# define ID_FLUX_OUT	3
# define ID_ADD_FIN	4
# define ID_FLUX_IN	5
# define ID_PIPE	6
# define ID_WAIT	7

# define NBR_OPT	8

typedef struct		s_parser
{
  char			**array;
  int			option;
  struct s_parser	*next;
}			t_parser;

typedef struct	s_arrPars
{
  int		opt;
  void		(*fun)(t_parser *, t_list *);
}		t_arrPars;

/*
** my_str_to_wordtab.c
*/
char		**my_str_to_wordtab(char *str, const char *sep, int end);

/*
** pre_parser.c
*/
t_parser	*my_pre_parser(char *str);

/*
** parser.c
*/
void		my_parser(char *str, t_list *env);

#endif /* !PARSER_H_ */
