/*
** signal.c for signal in /home/mar_b/rendu/PSU_2013_42sh/src
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Oct  2 16:32:14 2014 mar_b mar_b
** Last update Thu Oct  2 16:34:55 2014 mar_b mar_b
*/

#include <unistd.h>
#include <signal.h>
#include "utils.h"
#include "mini.h"
#include "list.h"

/*
** brief: it will write a \n and the promp
*/
static void	_my_write_sig(int __attribute__((__unused__)) sig)
{
  (void)write(1, "\n", 1);
  (void)write(1, CLR_SHELL, my_strlen(CLR_SHELL));
}

/*
** brief: we will check our Ctrl-C, if any pb then we'll free and put AND ERROR!
** @env: could be free
*/
char	my_signal(t_list *env)
{
  if (signal(SIGINT, _my_write_sig) == SIG_ERR)
    {
      free_lst(env);
      return (my_puterror(ERR_SIGN));
    }
  return (0);
}
