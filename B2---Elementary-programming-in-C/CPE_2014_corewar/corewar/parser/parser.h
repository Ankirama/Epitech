/*
** parser.h for parser.h in /home/chenev_d/rendu/CPE_2014_corewar
**
** Made by chenev_d chenev_d
** Login   <chenev_d@epitech.net>
**
** Started on  Tue Aug  5 23:33:41 2014 chenev_d chenev_d
** Last update Sun Aug 31 01:54:17 2014 chenev_d chenev_d
*/

#ifndef	PARSER_H_
# define PARSER_H_

# define	ERR_BASE "/corewar [-dump nb] [-n nb] [-a nb] .cor\n"
# define	ERR_CCOR "Corewar need 1 to 4 valid champions\n"
# define	ERR_N2 "The number after -n must be between 1 and 4\n"
# define	ERR_NAU "One of your -n values is already use\n"
# define	ERR_COR "Care, you forgot your valid .cor\n"
# define	ERR_DUMP "You can't use -dump more than one time\n"
# define	ERR_NB "You can't use negativ number for -a or -n\n"
# define	ERR_A "If you decide to use -a you need to use it for all .cor\n"
# define	ERR_TOON "You use an invalid -n\n"
# define	ERR_TOOA "You use an invalid -a\n"

# include <sys/types.h>
# include "struct.h"

/*
** BASIC_FUNCTION_C_
*/
char		*int_to_array(int nbr);
void		*my_malloc(size_t size);
int		my_getnbr(const char *str);
void		my_write(int fd, const char *str, int size);
void		my_puterror(char *error);
char		*int_to_array(int nbr);
void		*my_malloc(size_t size);
int		my_getnbr(const char *str);
void		my_write(int fd, const char *str, int size);
void		my_puterror(char *error);

/*
** MY_PRECHECK_C_
*/
int		my_getnbr_p(const char *str);
void		my_precheck(char **av);
void		my_second_check_number(char **av, t_option *opt);
void		my_second_check_adress(char **av, t_option *opt);

/*
** MY_NUMBER_C_
*/
void		loop_number(int a, int c, char *number);
void		change_number(t_option *opt, int c);
void		check_the_n_number(int nb, t_option *opt);
void		check_my_number2(char *str1, char *str2, t_option *opt, char *strp);
void		check_my_number(char **av, t_option *opt);

/*
** MY_DUMP_C_
*/
int		check_my_dump(char **av, t_option *opt);

/*
** MY_COR_C_
*/
int		my_cor(char *str);
int		count_my_cor(char **av);
int		check_my_cor(char **av, t_option *opt);

/*
** MY_ADRESS_C_
*/

void		loop_adress(int a, int c, char *number);
void		check_the_a_adress(t_option *opt);
void		check_my_adress2(char *str1, char *str2, t_option *opt);
void		check_my_adress(char **av, t_option *opt);

/*
** MAINPARSER_C_
*/
t_list		*parser_option(int ac, char **av, unsigned char *vm_memory);
void		my_init(t_option *opt);
char		*int_t_array(int nbr);
void		freeparser(t_option *opt);

#endif /* !PARSER_H_ */
