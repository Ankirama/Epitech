/*
** parsing.h for parsing in /home/mar_b/rendu/CPE_2014_corewar/asm
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Aug 21 13:19:39 2014 mar_b mar_b
** Last update Mon Aug 25 14:42:47 2014 teyssa_r teyssa_r
*/

#ifndef PARSING_H_
# define PARSING_H_

# include "op.h"
# include "asm_utils.h"

/*
** PARSER_C_
*/
t_asm	*my_parser(header_t *header, const int fd);

/*
** CHECK_COMMAND_C_
*/
char	good_char(char c, const char *ref);
void	check_command(char *str, t_asm **lst, int line);

#endif /* !PARSING_H_ */
