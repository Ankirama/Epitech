/*
** my_conv.c for my_conv in /home/mar_b/rendu/PSU_2013_minishell2
**
** Made by mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sun Aug  3 14:28:07 2014 mar_b
** Last update Sun Aug  3 14:28:08 2014 mar_b
*/

#include <stdlib.h>
#include "list.h"
#include "utils.h"

/*
** brief: it will convert our list into char **
** @env: our env list
** return: return our char **
*/
char		**my_conv_lst(t_list *env)
{
  t_list	*tmp;
  char		**arr;
  int		i;
  int		count;

  count = 0;
  if (env == NULL)
    return (NULL);
  tmp = env->next;
  while (tmp != env)
    {
      ++count;
      tmp = tmp->next;
    }
  if ((arr = malloc(sizeof(char *) * (count + 1))) == NULL)
    my_puterror("error: problem to malloc in my_exec.c: l30\n");
  i = -1;
  tmp = env->next;
  while (tmp != env)
    {
      arr[++i] = my_strdup(tmp->data);
      tmp = tmp->next;
    }
  arr[++i] = NULL;
  return (arr);
}
