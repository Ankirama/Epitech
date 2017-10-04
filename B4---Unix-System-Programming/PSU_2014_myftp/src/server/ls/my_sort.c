/*
** my_sort.c for my_sort.c in /home/mar_b/rendu/PSU_2013_my_ls
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Tue Apr 29 15:18:21 2014 Fabien Martinez
** Last update Fri May  2 19:37:02 2014 Fabien Martinez
*/

#include "my_file.h"
#include "my_fun.h"
#include "my_sort.h"
#include "my_ls.h"

/*
** Use to swap / sort our t_my_file
*/
static t_my_def_file	*crt_def(char *name, unsigned char type)
{
  t_my_def_file		*tmp;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    my_puterror();
  tmp->name = name;
  tmp->type = type;
  return (tmp);
}

/*
** This function will sort the list
*/
char		my_sort_list(t_my_file **begin, char reverse, char *opt)
{
  t_my_file	*head;
  char		done;
  t_my_def_file	*tmp;

  done = 1;
  while (done)
    {
      head = (*begin);
      done = 0;
      while (head != NULL && head->next != NULL)
	{
	  if (my_strcmp(head, head->next, reverse, opt) > 0)
	    {
	      tmp = crt_def(head->name, head->type);
	      head->name = (head->next)->name;
	      head->type = (head->next)->type;
	      (head->next)->name = tmp->name;
	      (head->next)->type = tmp->type;
	      free(tmp);
	      done = 1;
	    }
	  head = head->next;
	}
    }
  return (0);
}

/*
** This function will sort argv
*/
char	**my_sort_alpha(char **arr, char reverse)
{
  int	i;
  int	done;
  char	*tmp;

  done = 1;
  while (done)
    {
      done = 0;
      i = 0;
      while (arr[i] != 0 && arr[i + 1] != 0)
	{
	  if (my_strcmp_name(arr[i], arr[i + 1], reverse) > 0)
	    {
	      tmp = arr[i];
	      arr[i] = arr[i + 1];
	      arr[i + 1] = tmp;
	      done = 1;
	    }
	  i += 1;
	}
    }
  return (arr);
}
