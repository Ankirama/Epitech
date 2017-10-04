/*
** my_error.c for error in /home/mar_b/rendu/Allum1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Jul  1 10:52:38 2014 mar_b mar_b
** Last update Thu Jul  3 10:47:21 2014 mar_b mar_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "utils.h"

/*
** brief: it will write in stderr our message
** @message: our char * we will display
*/
void	my_puterror(const char *message)
{
  (void)write(2, message, my_strlen(message));
  exit(EXIT_FAILURE);
}

/*
** brief: it will write in stderr our message
** @message: our char * we will display
*/
void	my_error(const char *message)
{
  (void)write(2, message, my_strlen(message));
}

/*
** brief: display the victory message
** @player: the player for the message
** return: return everytime 0
*/
char	my_victory(const char *player)
{
  (void)write(1, player, my_strlen(player));
  (void)write(1, ": YOU WIN!\n", 11);
  return (0);
}
