/*
** asm_utils.h for utils in /home/mar_b/rendu/CPE_2014_corewar/asm
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Aug 21 13:19:50 2014 mar_b mar_b
** Last update Fri Aug 29 15:47:10 2014 mar_b mar_b
*/

#ifndef ASM_UTILS_H_
# define ASM_UTILS_H_

# define ERR_LINE	"Syntax error line "
# define ERR_UNDEF	" undefine line "
# define ERR_REG	"no such register line "
# define ERR_SIZENAME	"'s length is too big, the max size is "
# define ERR_INDIR	"Warning Indirection to far line "
# define ERR_DIR	"Warning Direct too big line "

typedef struct	s_asm
{
  char		**data;
  char		type;
  int		line;
  char		bytes;
  struct s_asm	*next;
}		t_asm;

/*
** STR_ASM_C
*/
char		my_strcmp_pre_asm(const char *s1, const char *s2);

/*
** STR_WORDTAB_C_
*/
char		**my_str_to_wordtab(char *str, char sep, char stop);

/*
** LIST_C_
*/
void		add_label(t_asm **lst, char *data, int line);
void		add_instru(t_asm **lst, char *data, int line);
void		display_list(t_asm *lst);
void		let_it_go(t_asm *lst);

/*
** ERROR_C_
*/
void		my_error_line(int line);
void		error_label(const char *label, const int line, const char *str);
void		my_error_register(const int line, const char *str);
void		my_warning(const char *err, const int line);

/*
** NBR_C_
*/
int		my_getnbr_asm(const char *str, char *error);

#endif /* !ASM_UTILS_H_ */
