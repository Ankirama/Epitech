/*
** parser.h for parser in /root/rendu/PSU_2013_42sh
**
** Made by
** Login   <-n@epitech.net>
**
** Started on  Thu Oct  2 10:10:00 2014
** Last update Thu Oct  2 21:42:50 2014 mar_b mar_b
*/

#ifndef PARSER_H_
# define PARSER_H_

# define ERR_AST	"mysh: parse error near '"

# include "lexer.h"

t_ast	*my_parser(t_ast *ast);

#endif /* !PARSER_H_ */
