/*
** my_file.c for my_file in /home/mar_b/rendu/PSU_2013_my_ls
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Apr 23 20:49:35 2014 Fabien Martinez
** Last update Fri May  2 19:03:38 2014 Fabien Martinez
*/

#include "my_ls.h"
#include "my_file.h"
#include "my_display.h"

/*
** Function to append an element into our t_my_file
*/
t_my_file	*my_add_file(t_my_file *files, char *curr,
			     char *path, unsigned char type)
{
  t_my_file	*tmp;
  t_my_file	*head;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    my_puterror();
  tmp->type = type;
  tmp->name = curr;
  tmp->path = path;
  tmp->next = NULL;
  if (files == NULL)
    return (tmp);
  head = files;
  while (head->next != NULL)
    head = head->next;
  head->next = tmp;
  return (files);
}
