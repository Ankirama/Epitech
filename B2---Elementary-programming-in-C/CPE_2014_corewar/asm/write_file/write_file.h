/*
** write_file.h for write_file in /home/mar_b/rendu/CPE_2014_corewar/asm
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Aug 21 13:21:17 2014 mar_b mar_b
** Last update Fri Aug 29 21:04:51 2014 mar_b mar_b
*/

#ifndef WRITE_FILE_H_
# define WRITE_FILE_H_

# include "op.h"
# include "asm_utils.h"

# define PERM   S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH

/*
** CHECK_INSTRU_C_
*/
void	check_instru(t_asm *lst, t_asm *head, int *head_size);

/*
** CHECK_TYPE_C_
*/
char	check_dir(char *str, t_asm *lst, const int line);
char	check_reg(char *str, const int line);
char	check_ind(char *str, t_asm *lst, const int line);

/*
** HEADER_C_
*/
void	create_header(header_t *header, const int fd, t_asm *lst);

/*
** WRITE_C_
*/
void	write_int(const int fd, unsigned int value, unsigned char i,
		  const int max);
void	write_int_neg(const int fd, unsigned int value, unsigned char i,
		      const int max);
void	write_str(const int fd, const char *str, const int max_size);

/*
** WRITE_FILE_C_
*/
void	write_file(t_asm *lst, const int fd, header_t *header,
		   const char *file);

/*
** WRITE_COMMANDS_C_
*/
void	write_instruction(char **arr, const int fd, const int line,
			  t_asm *head);

/*
** LABEL_C_
*/
int	my_label(t_asm *head, const int line, const char *label);

#endif /* !WRITE_FILE_H_ */
