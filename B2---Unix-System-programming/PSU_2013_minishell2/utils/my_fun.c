/*
** my_fun.c for my_fu in /home/mar_b/rendu/PSU_2013_minishell2
**
** Made by mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sun Aug  3 14:28:22 2014 mar_b
** Last update Sun Aug  3 14:30:43 2014 mar_b
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "utils.h"
#include "minishell2.h"

void	my_init(char *str)
{
  int	i;

  i = -1;
  while (++i <= BUFF)
    str[i] = '\0';
}

void	my_wait()
{
  if (wait(NULL) == -1)
    my_puterror("error: problem with wait !\n");
}

void	my_dup(int oldfd, int newfd)
{
  if (dup2(oldfd, newfd) == -1)
    my_puterror("error: problem with dup2!\n");
}

void	my_pipe(int pipes[2])
{
  if (pipe(pipes) == -1)
    my_puterror("error: problem with pipe!\n");
}
