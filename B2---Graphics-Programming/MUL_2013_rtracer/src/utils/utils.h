/*
** utils.h for utils in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Oct  3 11:47:40 2014 mar_b _mar_b
** Last update Sun Oct 12 16:47:51 2014 mar_b mar_b
*/

#ifndef UTILS_H_
# define UTILS_H_

# include <sys/types.h>
# include "objects.h"
# include "rtracer.h"

# define DEB_PRO	"\033[1;31mProgression... "
# define MID_PRO	"\033[1;33mProgression... "
# define END_PRO	"\033[1;32mProgression... "
# define RESET_PRO	"%\033[0m\n"

# define MAX_BUFF	1

# define ERR_MALLOC	"Can't perform a malloc.\n"
# define ERR_WRITE	"Can't use write.\n"
# define ERR_FD		"bad file descriptor\n"
# define ERR_OPEN	"Can't open the file.\n"
# define ERR_CLOSE	"Can't close the current file.\n"
# define ERR_EYE	"Error : no eye.\nHelp ! I'm blind !\n"
# define ERR_MLX_INIT	"Error: problem with mlx_init!\n"
# define ERR_MLX_WIN	"Error: problem with mlx_new_window!\n"
# define ERR_MLX_IMG	"Error: problem with mlx_new_image!\n"
# define WAR_OBJ	" is not valide.\n"

/*
** ERROR_C_
*/
void		my_puterror(char *err);
void		my_warning_obj(char *obj);

/*
** FREE_C_
*/
void		free_arr(char **arr);
void		free_scene(t_scene *scene);
void		let_it_go(t_window *ptr);

/*
** FUN_C_
*/
void		*my_malloc(size_t size);
void		my_write(const int fd, void *buf, size_t size);
void		init_buff(unsigned char *buff, int size);

/*
** GET_NEXT_LINE_C_
*/
char		*get_next_line(const int fd);

/*
** CREATE_STRUCT_C_
*/
t_vector	*create_vector(double x, double y, int z);
t_color		*create_color(int r, int g, int b);

/*
** CONV_COLOR_C_
*/
unsigned int	conv_color(int r, int g, int b);

/*
** COLOR_C_
*/
void		add_colors(t_color **v1, t_color *v2);
void		sub_colors(t_color **v1, t_color *v2);
void		mul_color(t_color **v1, int k);
void		div_color(t_color **v1, int k);

/*
** VECTOR_C_
*/
void		add_vectors(t_vector **v1, t_vector *v2);
void		sub_vectors(t_vector **v1, t_vector *v2);
void		mul_vector(t_vector **v1, int k);
void		div_vector(t_vector **v1, int k);

/*
** STR_C_
*/
int		my_strlen(const char *str);
int		my_arrlen(char **array);
char		my_strcmp(const char *s1, const char *s2);
char		*my_strcat(char *dest, char *src);
char		*my_strdup(const char *str);

/*
** NBR_C_
*/
void		display_progession(char i);
void		put_nbr(unsigned int i);

/*
** MV_POSITION_C_
*/
void		to_simple(t_vector **light, t_vector *coord,
			  t_vector *rot);
void		to_real_life(t_vector **light, t_vector *coord,
			     t_vector *rot);

/*
** LIMITE_C_
*/
t_vector	*vec_p(const t_vector *eye, const double k,
		       const t_vector *vis);
char		limit(t_vector *point, t_vector *limit_low,
		      t_vector *limit_up);

#endif /* !UTILS_H_ */
