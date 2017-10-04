/*
** pipe.c for pipe in /home/mar_b/rendu/PSU_2013_minishell2
**
** Made by mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sun Aug  3 14:27:43 2014 mar_b
** Last update Sun Aug  3 14:44:57 2014 mar_b
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "parser.h"
#include "utils.h"
#include "minishell2.h"

/*
** brief: used to close each pipes
** @pipes: pipes[2]
** @nbr: the pipe we won't close
*/
static void	_close(int *pipes, int nbr)
{
  int		i;

  i = -1;
  while (++i < 2)
    if (nbr != i && close(pipes[i]) == -1)
      my_puterror("error: impossible to close the fd in pipe.c\n");
}

/*
** brief: used to call a fun like ls .. not a built-in
** @par: our parser
** @env: our environment
** @pipes: our pipes[2]
** @tmp_fd: our file descriptor temp
*/
static void	_my_fun(t_parser **par, t_list *env, int *pipes, int *tmp_fd)
{
  pid_t		pid;

  my_pipe(pipes);
  if ((pid = fork()) == -1)
    my_puterror("error: problem with fork!\n");
  else if (pid == 0)
    {
      my_dup(*tmp_fd, 0);
      if ((*par)->next != NULL)
	my_dup(pipes[1], 1);
      _close(pipes, 1);
      my_exec_pipe(env, (*par)->array, my_path(my_find_element(env, "PATH")));
      exit(EXIT_FAILURE);
    }
  else
    {
      my_wait();
      _close(pipes, 0);
      *tmp_fd = pipes[0];
      (*par) = (*par)->next;
    }
}

/*
** brief: our main loop for pipe
** @par: our structure
** @env: our environment
** @pipes: our pipes[2]
** @tmp_fd: our temporary file descriptor
*/
static void	_loop_pipe(t_parser **par, t_list *env, int *pipes, int tmp_fd)
{
  int		len;
  char		buff[BUFF + 1];

  while ((*par) != NULL && ((*par)->option == ID_PIPE
			    || (*par)->option == NBR_OPT))
    {
      if ((*par)->array == NULL || (*par)->array[0] == NULL)
	{
	  my_init(&buff[0]);
	  if ((len = read(0, buff, BUFF)) > 0)
	    {
	      if (len == BUFF)
		my_puterror("error: command too big!\n");
	      buff[len - 1] = '\0';
	      (*par)->array = my_str_to_wordtab(buff, " \t", -1);
	    }
	  else if (len == -1)
	    my_puterror("error: problem with read!\n");
	}
      else if (my_builtin_fun((*par)->array, env) == 0)
	_my_fun(par, env, pipes, &tmp_fd);
      else
	*par = (*par)->next;
    }
}

char		pipe_cmd(t_parser **par, t_list *env)
{
  int		pipes[2];

  _loop_pipe(par, env, pipes, 0);
  return (0);
}
