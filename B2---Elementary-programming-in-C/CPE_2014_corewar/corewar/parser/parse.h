/*
** parse.h for  in /home/teyssa_r/rendu/CPE_2014_corewar/corewar/parse_vm
** 
** Made by teyssa_r teyssa_r
** Login   <teyssa_r@epitech.net>
** 
** Started on  Mon Aug 11 19:18:45 2014 teyssa_r teyssa_r
** Last update Sun Aug 31 23:17:43 2014 charles viterbo
*/

#ifndef PARSE_H_
# define PARSE_H_

# include "op.h"
# include "struct.h"

/*
** LIST_CHAM_C_
*/
t_list		*make_list();
void		add_before(t_list **, int, int, int);
void		delete_list(t_list **);

/*
** PARSE_VM_C_
*/
t_list		*parse_vm(t_option *opt, unsigned char *mem);
int		header_or_not(int nb);

#endif /* !PARSE_H_ */
