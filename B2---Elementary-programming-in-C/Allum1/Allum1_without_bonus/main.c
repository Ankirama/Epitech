/*
** main.c for main in /home/mar_b/rendu/Allum1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Mon Jun 30 20:29:58 2014 mar_b mar_b
** Last update Wed Jul  2 15:08:38 2014 mar_b mar_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "list.h"
#include "utils.h"
#include "game.h"

int		main(int argc, char **argv)
{
  int		size;
  t_list	*lst;

  size = (argc > 1) ? my_get_nbr(argv[1]) : ID_SIZE;
  if (size <= 0)
    my_puterror("error: problem with pyramid's size (too small)!\n");
  else if (size > 127)
    my_puterror("error: problem with pyramid's size (too big)!\n");
  else if (size % 4 != 0)
    my_puterror("error: the pyramid's size has to be mod 4 (like 4, 8, 12)\n");
  else if (size == 1)
    (void)write(1, "You LOSE!\n", 17);
  else
    {
      lst = create_list(size);
      while (my_game(lst));
      free_lst(lst);
    }
  return (0);
}
