/*
** my_select.c for my_select in /home/mar_b/rendu/PSU_2013_my_select
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue May 13 23:47:16 2014 mar_b mar_b
** Last update Sun Jun  1 19:42:11 2014 mar_b mar_b
*/

#include <stdlib.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <ncurses.h>
#include "my_select.h"
#include "my_cursor.h"
#include "my_error.h"
#include "my_fun.h"
#include "my_list.h"
#include "my_list2.h"
#include "my_termcaps.h"
#include "my_check.h"

/*
** It will turn off ICANON and ECHO right now !
** (VMIN -> 1 char, VTIME -> don't wait)
*/
static void	raw_mode()
{
  t_termios	*t;

  if ((t = malloc(sizeof(*t))) == NULL)
    my_puterror("error: problem to malloc termios!\n", 34);
  if (tcgetattr(0, t) == -1)
    my_puterror("error: problem with tcgetattr!\n", 31);
  t->c_lflag &= ~ICANON;
  t->c_lflag &= ~ECHO;
  t->c_cc[VMIN] = 1;
  t->c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, t) == -1)
    my_puterror("error: problem with tcsetattr!\n", 31);
}

/*
** Will clear the shell, hide the cursor and display our list (argv)
*/
static t_list	*my_init_shell(int argc, char **argv, char **env)
{
  t_list       	*lst;

  my_check_database(env);
  raw_mode();
  my_clear_shell();
  lst = my_create_list(argv, argc);
  my_display_list(lst);
  my_hide_cursor();
  return (lst);
}

int		main(int argc, char **argv, char **env)
{
  char		buf[4];
  t_termios	*saved_t;
  t_position	*pos;
  t_list	*lst;

  if (argc < 2)
    my_puterror("error: You've to specified at least 1 argument!\n", 48);
  pos = create_pos();
  if ((saved_t = malloc(sizeof(*saved_t))) == NULL ||
      tcgetattr(0, saved_t) == -1)
    my_puterror("error: problem with struct termios!\n", 36);
  if ((pos->fd = open("/dev/tty", O_WRONLY, O_NOCTTY)) == -1)
    my_puterror("error: problem with open!\n", 26);
  lst = my_init_shell(argc, argv, env);
  my_mode_line(argv[1], 0, 0, 1);
  my_init(buf, 4, pos->fd);
  while (read(0, buf, 4) > 0)
    {
      my_check_key_list(buf, &pos, lst, saved_t);
      my_init(buf, 4, pos->fd);
    }
  return (write(2, "error: problem to read!\n", 24));
}
