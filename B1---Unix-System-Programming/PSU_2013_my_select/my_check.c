/*
** my_check.c for my_check in /home/mar_b/rendu/PSU_2013_my_select
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue May 13 11:59:53 2014 mar_b mar_b
** Last update Wed May 28 14:48:10 2014 mar_b mar_b
*/

#include <stdlib.h>
#include <ncurses.h>
#include <term.h>
#include <unistd.h>
#include "my_error.h"
#include "my_termcaps.h"
#include "my_select.h"
#include "my_fun.h"
#include "my_list.h"
#include "my_cursor.h"
#include "my_mode.h"

/*
** Local function to compare s1 and s2 (used to find the TERM variable)
*/
static char	my_strcmp(char *s1, char *s2)
{
  int		i;

  i = 0;
  while (s1[i] && s2[i] && s1[i] == s2[i])
    i += 1;
  return (s1[i] == '=' && s2[i] == '\0');
}

/*
** This function will move the cursor to the next line, remove the str,
** and will write the new str underlined
*/
void	my_mode_line(char *str, int j, char active, char type)
{
  int	i;

  i = -1;
  my_move_cursor(j);
  my_delete_char(j, my_strlen(str));
  if (type)
    my_start_underline(j);
  if (active == 1)
    my_start_reverse(j);
  while (++i < my_strlen(str))
    (void)my_putchar(str[i]);
  my_end_underline();
}

/*
** This function will try to find the TERM variable in env
*/
void	my_check_database(char **env)
{
  int	res;
  int	i;

  i = 0;
  while (env[i] && !my_strcmp(env[i], "TERM"))
    i += 1;
  if (!env[i])
    my_puterror("error: unable to find a valide TERM environnement!\n", 51);
  res = tgetent(NULL, &env[i][5]);
  if (res == -1)
    my_puterror("error: unable to find termcaps' database!\n", 42);
  else if (res == 0)
    {
      (void)write(2, "error: ", 7);
      (void)write(2, &env[i][5], my_strlen(&env[i][5]));
      my_puterror(" is not a valide terminal!\n", 27);
    }
}

/*
** Will do something in term of key pressed
*/
void	my_check_key_list(char *str, t_position **pos, t_list *lst,
			  t_termios *t)
{
  if (my_strlen(str) == 1 && str[0] != 127)
    {
      if (str[0] == 27)
	my_exit(t, (*pos), lst);
      else if (str[0] == ' ')
	my_space(lst, (*pos));
      else if (str[0] == '\n')
	my_enter(t, (*pos), lst);
    }
  else if (str[0] == 27 && str[1] == '[' && (str[2] == 'A' || str[2] == 'B'))
    {
      my_mode_line(my_ret_elt(lst, (*pos)->y)->data,
		   (*pos)->y, my_ret_elt(lst, (*pos)->y)->active, 0);
      if (str[2] == 'A')
	(*pos)->y = (*pos)->y == 0 ? lst->size : (*pos)->y - 1;
      else if (str[2] == 'B')
	(*pos)->y =  (*pos)->y < lst->size ? (*pos)->y + 1 : 0;
      my_mode_line(my_ret_elt(lst, (*pos)->y)->data,
		   (*pos)->y, my_ret_elt(lst, (*pos)->y)->active, 1);
    }
  else if ((my_strlen(str) == 1 && str[0] == 127) ||
	   (str[0] == 27 && str[1] == '[' && str[2] == '3' && str[3] == '~'))
    my_remove(t, (*pos), lst);
}
