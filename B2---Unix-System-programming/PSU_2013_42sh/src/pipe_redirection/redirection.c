/*
** redirection.c for  in /home/viterb_c/rendu/PSU_2013_42sh/src/pipe_redirection
**
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
**
** Started on  Mon Sep  8 12:32:29 2014 charles viterbo
** Last update Thu Oct  2 23:15:26 2014 charles viterbo
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "utils.h"
#include "parser.h"
#include "minishell2.h"
#include "execution.h"

static void	_close_fd(int fd, char *file)
{
  if (close(fd) == -1)
    return (my_error_close(file, "unable to close"));
  else
    return (0);
}

/*
** brief: it will redirect the stdout into a file (ls > test or ls >> test)
** @cmd: our array for the first cmd
** @env: our environment
** @file: our file name
** @option: the option like > or >>
*/
int	dup_stdout(t_ast *left, char **right, t_list *env, t_ope *ope)
{
  int	fd;
  int	tmp_fd;

  if ((fd = open(right[0], O_CREAT | O_WRONLY |
		 (ope->trunc ? O_TRUNC : O_APPEND),
		 PERM)) == -1)
    return (my_error_close((*lst)->next->array[0], "unable to open"));
  if ((tmp_fd = dup(1)) == -1)
    return (my_error_close("unable to use dup", "error"));
  if (dup2(fd, 1) == -1)
    return (my_error_close("unable to use dup2", "error"));
  (void)my_check_fun((*lst)->array, env);//fnct executable
  if (dup2(tmp_fd, 1) == -1)
    return (my_error_close("unable to use dup2", "error"));
  if (_close_fd(fd, right[0]) == -1 || _close_fd(tmp_fd, right[0]) == -1)
    return (-1);
  return (0);
}

/*
** brief: it will redirect the stdout and stderr into a file
** @cmd: our array for the first cmd
** @env: our environment
** @file: our file name
** @option: the option like >& or >>&
*/
int	dup_stdout_err(t_ast *left, char **right, t_list *env, t_ope *ope)
{
  int	fd;
  int	tmp_fd;
  int	tmp_fd2;

  if ((fd = open(right[0], O_CREAT | O_WRONLY |
		 (ope->trunc ? O_TRUNC : O_APPEND),
		 PERM)) == -1)
    return (my_error_close(right[0], "unable to open"));
  if ((tmp_fd = dup(1)) == -1 || (tmp_fd2 = dup(2)) == -1)
    return (my_error_close("unable to use dup", "error"));
  if (dup2(fd, 1) == -1 || dup2(fd, 2) == -1)
    return (my_error_close("unable to use dup2", "error"));
  (void)my_check_fun((*lst)->array, env);// NEW FUNCTION
  if (dup2(tmp_fd, 1) == -1 || dup2(tmp_fd2, 2) == -1)
    return (my_error_close("unable to use dup2", "error"));
  if (_close_fd(fd, right[0]) == -1 || (_close_fd(tmp_fd, right[0]) == -1)
      || (_close_fd(tmp_fd2, right[0]) == -1))
    return (-1);
  return (0);
}

/*
** brief: it will read from a file (cat < file)
** @lst: our list parser
** @cmd: our array for the first cmd
** @env: our environment
** @file: our file name
** @option: the option like <
*/
int	dup_stdin_sim(t_ast *left, char **right, t_list *env,
		      t_ope __attribute__((__unused__)) *ope)
{
  int	fd;
  int	tmp_fd;

  if ((fd = open(right[0], O_RDONLY)) == -1)
    return (my_error_close("unable to open the file", "error"));
  if ((tmp_fd = dup(0)) == -1)
    return (my_error_close("unable to use dup", "error"));
  if (dup2(fd, 0) == -1)
    return (my_error_close("unable to use dup2", "error"));
  (void)my_check_fun((*lst)->array, env);// NW FUNCTION
  if (dup2(tmp_fd, 0) == -1)
    return (my_error_close("unable to use dup2", "error"));
  if ((_close_fd(fd, right[0]) == -1) || (_close_fd(tmp_fd, right[0]) == -1))
    return (-1);
  return (0);
}
