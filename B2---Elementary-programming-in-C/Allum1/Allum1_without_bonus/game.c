/*
** game.c for game in /home/mar_b/rendu/Allum1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Jul  1 15:38:10 2014 mar_b mar_b
** Last update Thu Jul  3 15:56:45 2014 mar_b mar_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "utils.h"
#include "game.h"
#include "list.h"
#include "ia.h"

/*
** brief: we will try to set our line to choose our lucifers
** @lst: our list
** return: return -1 if any problem or 0
*/
static int	_get_line(t_list *lst)
{
  char		buff[BUFF_SIZE + 1];
  int		len;
  int		nbr;

  (void)write(1, "Choose your line: ", 18);
  my_init(buff);
  if ((len = read(0, buff, BUFF_SIZE)) == -1)
    my_puterror("error: problem to read in game.c\n");
  else if (len == 0)
    my_exit(lst);
  else if (len == BUFF_SIZE)
    return (-1);
  buff[len - 1] = '\0';
  if ((nbr = my_get_nbr(buff)) == -1 || nbr > lst->nbr_ele || nbr == 0)
    return (-1);
  return (nbr);
}

/*
** brief: we will traver our list until pos and substract our nbr
** @lst: our list
** @pos: our line
** @nbr: number of lucifer
** BRIEF: if the new nbr = 0 then we will remove the link.
** we will change the binary operation too
** return: return -1 if any pb or 0
*/
static char	_reset_lst(t_list *lst, int pos, int nbr)
{
  t_list	*tmp;
  int		i;

  i = pos;
  tmp = lst;
  while (--pos >= 0)
    tmp = tmp->next;
  if (nbr > tmp->nbr_ele)
    return (-1);
  tmp->nbr_ele -= nbr;
  if (tmp->nbr_ele == 0)
    remove_ele(lst, i);
  else
    {
      free(tmp->bin);
      tmp->bin = int_to_bin(tmp->nbr_ele);
    }
  free(lst->bin);
  lst->bin = operation_xor(lst->next);
  return (0);
}

/*
** brief: we will read the number for lucifers and substract it on our pos line
** @lst: our list
** @pos: our line (for example line 1 : pos = 1)
** return: return -1 if any pb or 0
*/
static int	_get_lucifer(t_list *lst, int pos)
{
  char		buff[BUFF_SIZE + 1];
  int		len;
  int		nbr;

  (void)write(1, "Choose the number of lucifers: ", 31);
  my_init(buff);
  if ((len = read(0, buff, BUFF_SIZE)) == -1)
    my_puterror("error: problem to read in game.c\n");
  else if (len == 0)
    my_exit(lst);
  else if (len == BUFF_SIZE)
    return (-1);
  buff[len - 1] = '\0';
  if ((nbr = my_get_nbr(buff)) == -1 || nbr == 0)
    return (-1);
  return (_reset_lst(lst, pos, nbr));
}

/*
** brief: this function will display our pyramid
** @lst: our list
*/
static void	_display(t_list *lst)
{
  t_list	*tmp;
  int		nbr;
  int		i;
  int		len;

  len = (lst->nbr_ele * 2 + 1) / 2;
  tmp = lst->next;
  nbr = 0;
  while (tmp != NULL)
    {
      i = nbr;
      while (++i < len)
	(void)write(1, " ", 1);
      i = -1;
      while (++i < tmp->nbr_ele)
	(void)write(1, "|", 1);
      (void)write(1, "\n", 1);
      ++nbr;
      tmp = tmp->next;
    }
}

/*
** brief: our main function, we will let the player play and the AI
** @lst: our list for our pyramid
** return: return 0 if one of them win or 1
*/
char		my_game(t_list *lst)
{
  int		line;

  _display(lst);
  while ((line = _get_line(lst)) == -1)
    my_error("\nyou have to enter a valid line!\n");
  while (_get_lucifer(lst, line) == -1)
    my_error("\nyou have to enter a valid lucifer number!\n");
  if (lst->nbr_ele == 1 && lst->next->nbr_ele == 1)
    return (my_victory("player"));
  else if (lst->nbr_ele == 0)
    return (my_victory("AI"));
  (void)write(1, "you played:\n", 12);
  _display(lst);
  ia_game(lst, 0, 0, 0);
  if (lst->nbr_ele == 1 && lst->next->nbr_ele == 1)
    return (my_victory("AI"));
  else if (lst->nbr_ele == 0)
    return (my_victory("player"));
  (void)write(1, "AI played : \n", 13);
  return (1);
}
