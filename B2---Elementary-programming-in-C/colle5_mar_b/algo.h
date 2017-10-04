/*
** algo.h for let it go in /home/user/rendu/colle5_
**
** Made by 
** Login   
**
** Started on  Tue Sep 23 19:12:48 2014 
** Last update Tue Sep 23 20:16:54 2014 
*/

#ifndef ALGO_H_
# define ALGO_H_

# define MY_UPPER(letter)	(letter - 32)
# define MY_LOWER(letter)	(letter + 32)

typedef struct	s_boogle
{
  char		*tab;
  char		*word;
  int		sizeline;
}		t_boogle;

int	next_is_ok(t_boogle *boogle, char letter, int x, int y);
char	my_find_word(t_boogle *boogle, char *word, int x, int y);

#endif /* !ALGO_H_ */
