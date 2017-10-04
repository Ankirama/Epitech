/*
** redirection.c for redirection in /home/mar_b/rendu/PSU_2013_minishell2
**
** Made by mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sun Aug  3 14:27:53 2014 mar_b
** Last update Sun Aug  3 19:21:54 2014
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "utils.h"
#include "parser.h"
#include "minishell2.h"

static void	_close_fd(int fd, char *file)
{
  if (close(fd) == -1)
    my_error(file, "unable to close");
}

/*
** brief: it will redirect the stdout into a file (ls > test or ls >> test)
** @cmd: our array for the first cmd
** @env: our environment
** @file: our file name
** @option: the option like > or >>
*/
char	dup_stdout(t_parser **lst, t_list *env)
{
  int	fd;
  int	tmp_fd;

  if ((fd = open((*lst)->next->array[0], O_CREAT | O_WRONLY |
		 (((*lst)->option == ID_FLUX_ERR) ? O_TRUNC : O_APPEND),
		 PERM)) == -1)
    return (my_error((*lst)->next->array[0], "unable to open"));
  if ((tmp_fd = dup(1)) == -1)
    return (my_error("unable to use dup", "error"));
  if (dup2(fd, 1) == -1)
    return (my_error("unable to use dup2", "error"));
  (void)my_check_fun((*lst)->array, env);
  if (dup2(tmp_fd, 1) == -1)
    return (my_error("unable to use dup2", "error"));
  _close_fd(fd, (*lst)->next->array[0]);
  _close_fd(tmp_fd, (*lst)->next->array[0]);
  (*lst) = (*lst)->next;
  return (0);
}

/*
** brief: it will redirect the stdout and stderr into a file
** @cmd: our array for the first cmd
** @env: our environment
** @file: our file name
** @option: the option like >& or >>&
*/
char	dup_stdout_err(t_parser **lst, t_list *env)
{
  int	fd;
  int	tmp_fd;
  int	tmp_fd2;

  if ((fd = open((*lst)->next->array[0], O_CREAT | O_WRONLY |
		 (((*lst)->option == ID_FLUX_ERR) ? O_TRUNC : O_APPEND),
		 PERM)) == -1)
    return (my_error((*lst)->next->array[0], "unable to open"));
  if ((tmp_fd = dup(1)) == -1 || (tmp_fd2 = dup(2)) == -1)
    return (my_error("unable to use dup", "error"));
  if (dup2(fd, 1) == -1 || dup2(fd, 2) == -1)
    return (my_error("unable to use dup2", "error"));
  (void)my_check_fun((*lst)->array, env);
  if (dup2(tmp_fd, 1) == -1 || dup2(tmp_fd2, 2) == -1)
    return (my_error("unable to use dup2", "error"));
  _close_fd(fd, (*lst)->next->array[0]);
  _close_fd(tmp_fd, (*lst)->next->array[0]);
  _close_fd(tmp_fd2, (*lst)->next->array[0]);
  (*lst) = (*lst)->next;
  return (0);
}

char	dup_stdin_sim(t_parser **lst, t_list *env)
{
  int	fd;
  int	tmp_fd;

  if ((fd = open((*lst)->next->array[0], O_RDONLY)) == -1)
    return (my_error("unable to open the file", "error"));
  if ((tmp_fd = dup(0)) == -1)
    return (my_error("unable to use dup", "error"));
  if (dup2(fd, 0) == -1)
    return (my_error("unable to use dup2", "error"));
  (void)my_check_fun((*lst)->array, env);
  if (dup2(tmp_fd, 0) == -1)
    return (my_error("unable to use dup2", "error"));
  _close_fd(fd, (*lst)->next->array[0]);
  _close_fd(tmp_fd, (*lst)->next->array[0]);
  (*lst) = (*lst)->next;
  return (0);
}
