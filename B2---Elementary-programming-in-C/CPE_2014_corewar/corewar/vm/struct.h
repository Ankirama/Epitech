/*
** struct.h for let it go in /home/viterb_c/rendu/CPE_2014_corewar/corewar
** 
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
** 
** Started on  Tue Aug 26 12:19:07 2014 charles viterbo
** Last update Sun Aug 31 23:23:36 2014 chenev_d chenev_d
** Last update Sat Aug 30 23:18:13 2014 charles viterbo
** Last update Tue Aug 26 15:58:57 2014 chenev_d chenev_d
*/

#ifndef STRUCT_H_
# define STRUCT_H_

# include "op.h"

typedef struct	s_list
{
  int		root;
  int		init_pos;
  int		pc;
  int		nb_tour;
  char		carry;
  char		live;
  int		reg[REG_NUMBER];
  header_t	*chpm;
  struct s_list	*prev;
  struct s_list	*next;
}		t_list;

typedef struct	s_option
{
  int		dump;
  int		number_of_n;
  int		n_number;
  int		*my_n_number;
  int		*my_a_adress;
  int		number_cor;
  int		option;
  int		a_adress;
  int		aid_adress;
  int		aid_number;
  char		**my_cor;
}		t_option;

#endif /* !STRUCT_H_ */
