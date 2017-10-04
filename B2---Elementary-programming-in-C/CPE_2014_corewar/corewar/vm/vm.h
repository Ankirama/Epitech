/*
** vm.h for  in /home/viterb_c/rendu/CPE_2014_corewar/corewar
** 
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
** 
** Started on  Mon Aug 25 23:26:27 2014 charles viterbo
** Last update Sun Aug 31 22:09:04 2014 charles viterbo
*/

#ifndef VM_H_
# define VM_H_

# define ERR_SIZE "The size between two champions is too small, change your a\n"

/*
** VM_MEMORY.c
*/
unsigned char	*init_memory(void);
void		print_memory(unsigned char *mem);
void		write_code_in_mem(unsigned char *mem, char *cor, int pos);

/*
** VM_CHAMP_POS.c
*/
void		sort_adress(t_option *option);
void		good_size(t_option *option, t_list *root_chp);
void		place_champ(t_option *option, t_list *root, unsigned char *mem);

/*
** VM_CYCLE.c
*/
int		main_cycle(t_list *root, unsigned char *mem, int limit);

/*
** FUNCTION_ARG.C
*/
int		type_arg(unsigned char octet, int func, int i, int j);
void		tab_param(t_list *champ, unsigned char *memory, int *tab);

#endif /* !VM_H_ */
