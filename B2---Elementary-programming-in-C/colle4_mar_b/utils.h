/*
** utils.h for utils in /home/mar_b/rendu/colle4_mar_b
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Sep 16 19:21:35 2014 mar_b mar_b
** Last update Tue Sep 16 22:48:55 2014 mar_b mar_b
*/

#ifndef UTILS_H_
# define UTILS_H_

# define ERR_NBR	"Wrong syntax\nUsage: ./game_of_life x y nbr_cell\n"
# define ERR_NBR_SIZE	"Number to big\n"
# define ERR_ARG	"Usage: ./game_of_life x y nbr_cell\n"
# define ERR_READ	"problem to read stdin\n"
# define ERR_MALLOC	"can't perform a malloc\n"
# define ERR_X		"x is to little\n"
# define ERR_Y		"y is to little\n"
# define ERR_NBR_CELL	"nbr_cell is to big\n"
# define ERR_SYSTEM	"problem with a system function\n"

/*
** FUN_C_
*/
void	my_write(int fd, const void *buf, size_t count);
int	my_strlen(const char *str);
void	my_puterror(const char *str);

/*
** NBR_C_
*/
int	my_rand_nbr(int nbr_cases);
int	my_power(int nbr, int power);
int	my_nbr_size(int nbr);
int    	my_getnbr(const char *str);

/*
** MY_AFF_TAB_
*/
void	my_aff_tab(char **tab);

/*
** MY_TAB
*/
char	**main_tab(const int xmax, const int ymax, const int nbr_cell);
char	check_my_tab(char **arr);
void	let_it_go(char **arr);

#endif /* !UTILS_H_ */
