/*
** calc.h for calc in /home/mar_b/rendu/colle3_bob42
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Sep  9 19:18:25 2014 mar_b mar_b
** Last update Tue Sep  9 22:14:03 2014 mar_b mar_b
*/

#ifndef CALC_H_
# define CALC_H_

# define	ID_PARENT_CLOSE	')'
# define	ID_PARENT_OPEN	'('
# define	ID_MULT		'*'
# define	ID_DIV		'/'
# define	ID_ADD		'+'
# define	ID_SUB		'-'
# define	ID_MOD		'%'
# define	ID_MINUS	'_'

# define	ERR_PARENT_OPEN	"can't find an open parenthesis\n"
# define	ERR_NBR		"wrong number\n"
# define	ERR_OPE		"problem with operator\n"
# define	ERR_MODULO	"Modulo by 0\n"
# define	ERR_DIVISION	"Division by 0\n"
# define	ERR_MALLOC	"can't perform a malloc\n"
# define	ERR_STRNCAT	"parameter error\n"
# define	ERR_MAIN	"usage : ./calculator \"your expression\"\n"

/*
** PARSER_C_
*/
char	*main_parser(char *str);


#endif /* !CALC_H_ */
