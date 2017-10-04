/*
** utils.h for utils in /home/mar_b/rendu/CPE_2014_corewar/utils
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Jul 15 15:06:25 2014 mar_b mar_b
** Last update Sun Aug 31 18:06:54 2014
*/

#ifndef UTILS_H_
# define UTILS_H_

# define MAX_BUFF	2

# include <sys/types.h>

/*
** STR_C_
*/
int		my_strlen(const char *str);
char		*my_strdup(const char *str);
char		*my_strcpy(char *, char *);
char		my_strcmp(const char *s1, const char *s2);
void		my_strcat(const char *src, char *dest);

/*
** NBR_C_
*/
void		my_puterror(char *);
int		my_getnbr(const char *str);
void		my_putnbr(int nbr, const int fd);

/*
** ERROR_C_
*/
void		my_puterror(char *error);
void		my_puterror_file(char *error, char *file);
void		my_error(const char *file, const char *msg);

/*
** CONV_C_
*/
int		my_pow(int nbr, int pow);
char		conv_color_char(const char *color, const char *base);
unsigned int	conv_color_int(const char *color, const char *base);
void		display_hexa(int nbr, const char *base, const int size,
			     int zero);
int		convert_bytes_int(unsigned char *bytes, int size);

/*
** FUN_C_
*/
void		my_write(int fd, const char *str, int size);
void		my_lseek(const int fd, off_t offset, int whence);
int		my_open(const char *pathname, int flags, mode_t mode);
void		my_close(const int fd, const char *str);
void		*my_malloc(size_t size);

/*
** FUN_2_C
*/
int		my_read(int fd, void *buf, size_t count);

/*
** GET_NEXT_LINE_C_
*/
char		*get_next_line(const int fd);

/*
** ARR_C_
*/
int		my_strlen_arr(char **);
void		my_display_arr(char **arr, const int fd);

/*
** PRINT_C_
*/
void		my_putchar(const int fd, const char c);

#endif /* !UTILS_H_ */
