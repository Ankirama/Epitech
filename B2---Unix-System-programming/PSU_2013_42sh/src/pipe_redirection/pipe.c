/*
** pipe.c for  in /home/viterb_c/rendu/PSU_2013_42sh/src/pipe_redirection
**
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
**
** Started on  Thu Oct  2 17:26:09 2014 charles viterbo
** Last update Thu Oct  2 23:16:30 2014 charles viterbo
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "utils.h"
#include "lexer.h"
#include "execution.h"

/*
** brief :
** @left :
** @right :
** @end :
*/
static char	_pipe(t_ast *left, char **right, t_list *end)
{
  int		pipes[2];
  pid_t		pid;

  if (pipe(pipes) == -1)
    return (my_puterror(ERR_PIP));
  if ((pid = fork()) < 0)
    return (my_puterror(ERR_FORK));
  else if (pid == 0)
    {
      if (close(pipes[0]) == -1 || dup2(pipes[1], 1) == -1)
	return (my_puterror(ERR_CHD));
      return (my_exec());
    }
  else
    {
      if (close(pipes[1]) == -1 || dup2(pipes[0], 0) == -1)
	return (my_puterror(ERR_PAR));
      return (my_exec());
    }
  return (0);
}

/*
** brief :
** @left :
** @right :
** @env :
*/
int	pipe_cmd(t_ast *left, char **right, t_list *env,
		 t_ope __attribute__((__unused__)) *ope)
{
  int	pipes[2];

  if (_pipe(lest, right, env) == -1)
    return (-1);
  return (0);
}
