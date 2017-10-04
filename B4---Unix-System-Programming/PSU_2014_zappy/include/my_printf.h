/*
** my_printf.h for my_printf in /home/mar_b/rendu/PSU_2014_my_printf
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Apr 14 10:48:54 2014 Fabien Martinez
** Last update Sun Apr 20 22:47:39 2014 Fabien Martinez
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

# include <stdarg.h>

# define SPACE	0
# define SHARP	1
# define ZERO	2
# define PLUS	3
# define MINUS	4
# define POINT	5

extern int	g_fd;

typedef struct	s_flag_opt
{
  char		sharp;
  char		space;
  int		zero;
  int		number;
  char		plus;
  char		minus;
  int		prec;
  int		count;
}		t_flag_opt;

typedef int	(*my_flags)(va_list *ap, t_flag_opt *flag_opt);

typedef struct	s_ptr_fun
{
  char		*tab;
  char		*opt;
  my_flags	*ptr_fun;
  my_flags	*ptr_fun_long;
  my_flags	*ptr_fun_short;
  va_list	*ap;
}		t_ptr_fun;

int		my_printf(int fd, const char *format, ...);
char		my_print_error(int);
int		my_putnbr_base_oct(va_list *ap, t_flag_opt *flag_opt);
int		my_putnbr_base_bin(va_list *ap, t_flag_opt *flag_opt);
int		my_putnbr_base_hex_M(va_list *ap, t_flag_opt *flag_opt);
int		my_putnbr_base_hex_m(va_list *ap, t_flag_opt *flag_opt);
int		my_putnbr_base_p(va_list *ap, t_flag_opt *flag_opt);
int		my_putnbr_sign(long int);
int		my_putnbr_double(va_list *ap, t_flag_opt *flag_opt);
int		my_putnbr_rec_double(double, int);
int		my_putnbr_int(va_list *ap, t_flag_opt *flag_opt);
int		my_putnbr_un(va_list *ap, t_flag_opt *flag_opt);
int		my_putnbr_un_rec(unsigned long int);
int		my_putnbr_long(va_list *ap, t_flag_opt *flag_opt);
int		my_putnbr_base(unsigned long int, char *, int);
int		my_putnbr_long(va_list *ap, t_flag_opt *flag_opt);
int		my_putnbr_base_oct_long(va_list *ap, t_flag_opt *flag_opt);
int		my_putnbr_base_hex_M_long(va_list *ap, t_flag_opt *flag_opt);
int		my_putnbr_base_hex_m_long(va_list *ap, t_flag_opt *flag_opt);
int		my_putnbr_base_bin_long(va_list *ap, t_flag_opt *flag_opt);
int		my_putnbr_base_oct_short(va_list *ap, t_flag_opt *flag_opt);
int		my_putnbr_base_hex_M_short(va_list *ap, t_flag_opt *flag_opt);
int		my_putnbr_base_hex_m_short(va_list *ap, t_flag_opt *flag_opt);
int		my_putnbr_base_bin_short(va_list *ap, t_flag_opt *flag_opt);
int		my_count_integer(double);
int		my_putnbr_sci(va_list *ap, t_flag_opt *flag_opt);
int		my_putnbr_short(va_list *ap, t_flag_opt *flag_opt);
int		my_putnbr_un_short(va_list *ap, t_flag_opt *flag_opt);
int		my_putnbr_un_long(va_list *ap, t_flag_opt *flag_opt);
int		my_putchar(va_list *ap, t_flag_opt *flag_opt);
int		my_putmod(va_list *ap, t_flag_opt *flag_opt);
int		my_showstr(va_list *ap, t_flag_opt *flag_opt);
int		my_putstr(va_list *ap, t_flag_opt *flag_opt);
int		my_count_print(va_list *ap, t_flag_opt *flag_opt);
int		my_strlen(char *str);
int		my_nbrlen(long nbr);
int		my_baselen(unsigned long int nbr, int len);
int		my_add_space_zero(int, int, char);
char		my_putchar_c(char c);
int		my_opt_base(t_flag_opt *, char *, int);
int		my_opt_nbr(t_flag_opt *, char, int *);
int		my_opt_pointer(t_flag_opt *, int);
void		my_init_opt(t_flag_opt *);
int		my_power(int, int);
char		*my_create_tab_flags(void);
char		*my_create_tab_options(void);
my_flags	*create_ptr_fun(void);
my_flags	*create_ptr_fun_long(void);
my_flags	*create_ptr_fun_short(void);
int		my_create_nbr(const char *, int *);
int		my_pos(char *, char);
char		my_check_opt(t_ptr_fun *, t_flag_opt *, const char *, int *);
int		my_check_lh(const char *, t_ptr_fun *, int, char);
t_ptr_fun	*my_init_malloc(t_flag_opt **, int *);
void		my_display_flag(t_ptr_fun *, t_flag_opt *, const char *, int *);
void		my_let_it_go(t_flag_opt *, t_ptr_fun *);

#endif /* !MY_PRINTF_H_ */
