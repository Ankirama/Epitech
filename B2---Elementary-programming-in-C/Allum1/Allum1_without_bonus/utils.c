/*
** str.c for str in /home/mar_b/rendu/Allum1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Jul  1 10:54:17 2014 mar_b mar_b
** Last update Thu Jul  3 11:43:08 2014 mar_b mar_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "game.h"
#include "utils.h"
#include "list.h"

/*
** brief: it will check if the tmp->bin has same 1 than lst->bin
** @lst: our list head
** @tmp: our current link
** @i: our position
** return: return 0 if no match else 1
*/
char	same_binary(const t_list *lst, const t_list *tmp, int i)
{
  while (++i < ID_OCTET)
    {
      if (lst->bin[i] == 1 && tmp->bin[i] == 0)
        return (0);
    }
  return (1);
}

/*
** brief: this function will exit avec EOF read
** @lst: we will free lst
*/
void	my_exit(t_list *lst)
{
  free_lst(lst);
  (void)write(1, "exit\n", 5);
  exit(EXIT_SUCCESS);
}

/*
** brief: initialize our buffer
** @buff: our char *
*/
void	my_init(char *buff)
{
  int	i;

  i = -1;
  while (++i < BUFF_SIZE + 1)
    buff[i] = '\0';
}
