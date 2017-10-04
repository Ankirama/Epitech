/*
** game_of_life.h for let it go in /home/mar_b/rendu/colle4_mar_b
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Sep 16 20:09:46 2014 mar_b mar_b
** Last update Tue Sep 16 21:28:15 2014 mar_b mar_b
*/

#ifndef GAME_OF_LIFE_H_
# define GAME_OF_LIFE_H_

# define SIZE_BUF	42
# define MSG_NBR	"entrez le nombre d'iterations...\n"

/*
** LIFE_C_
*/
char	**my_put_cell(char **arr, const int xmax, const int ymax, int nbr_cell);
void	my_game_of_life(char **arr, int iter, const int x_max,
			const int y_max);

#endif /* !GAME_OF_LIFE_H_ */
