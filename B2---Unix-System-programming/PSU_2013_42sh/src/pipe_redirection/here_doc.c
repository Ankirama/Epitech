/*
** here_doc.c for here_doc in /home/chenev_d/rendu/PSU_2013_42sh/old_minishells/minishell2_mar_b/minishell2_mar_b
**
** Made by chenev_d chenev_d
** Login   <chenev_d@epitech.net>
**
** Started on  Thu Oct  2 17:41:51 2014 chenev_d chenev_d
** Last update Thu Oct  2 23:17:42 2014 charles viterbo
*/

#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "list.h"
#include "utils.h"
#include "parser.h"
#include "execution.h"

/*
** brief: filled my list
** @list: list for fill
** @word: word to add to list
*/
t_double	*my_add(t_double **list, char *word)
{
  t_double	*elem;
  t_double	*tmp;

  tmp = (*list);
  if ((elem = malloc(sizeof(t_double*))) == NULL)
    return (my_puterror_null(ERR_MALLOC));
  elem->str = word;
  elem->next = NULL;
  if((*list) == NULL)
    return (elem);
  else
    {
      while (tmp->next != NULL)
        tmp = tmp->next;
      tmp->next = elem;
      return (*list);
    }
}

/*
** brief: read & filled my list
** @l_double: list which contain our word enter before
** @list: list of parser
*/
t_double	*fill_tab(t_double **l_double, char **right)
{
  char		*s;

  while (s = get_next_line(0))
    {
      if (my_strcmp(s, right[0], 0) != 0)
        return (*l_double);
      if (((*l_double) = my_add(l_double, s)) == -1)
	return (-1);
    }
}

/*
** brief: write on standart exit to execute later
** @l_double: list which contain our word enter before
** @fd: tab int to manage enter and exit standard
*/
char	fct_write(t_double *l_double, int fd[2])
{
  while (l_double != NULL)
    {
      (void)write(fd[1], l_double->str, my_strlen(l_double->str));
      (void)write(fd[1], "\n", 1);
      l_double = l_double->next;
    }
}

/*
** brief: fct who send our list to our execve
** @list: list for fillw
** @fd: tab int to manage enter and exit standard
** @l_double: list which contain our word enter before
** @env: Our env
*/
char	process_heredoc(t_ast *left, int fd[2], t_double *l_double, t_list *env)
{
  int	status;
  int	pid;

  pipe(fd);
  if ((pid = fork()) == -1)
    return (my_puterror(ERR_FORK));
  if (pid == 0)
    {
      close(fd[0]);
      fct_write(l_double, fd);
      close(fd[1]);
      return (0);
    }
  else
    {
      close(fd[1]);
      dup2(fd[0], 0);
      (void)my_check_fun((*lst)->array, env); // NOUVELE FONCTION
      close(fd[0]);
      if(waitpid(pid, &status, 0) == -1)
	return (my_puterror(ERR_WPID));
      return (0);
    }
  return (0);
}

/*
** brief: main function for heredoc
** @list: list of parser
** @env: our env
*/
int		dup_stdin_doub(t_ast *left, char **right, t_list *env,
			       t_ope __attribute__((__unused__)) *ope)
{
  t_double	*l_double;
  int		status;
  int		fd[2];

  l_double = NULL;
  if (l_double = fill_tab(&l_double, right) == - 1)
    return (-1);
  /*(*lst)->next = (*lst)->next->next;*/
  if (process_heredoc(left, fd, l_double, env) == -1)
    return (-1);
  return (0);
}
