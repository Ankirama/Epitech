/*
** main.c<2> for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Wed Apr  1 10:32:07 2015 Fabien Martinez
*/

#include "utils.h"

/*
** brief: add at the end a =n element
** @root: our root element from our list
** @name: our name we want to add
** return: return 0 if no problem, else 1 (malloc problem)
*/
int		add_element(t_list **root, void *data)
{
  t_list	*tmp;
  t_list	*new;

  if ((new = my_malloc(sizeof(t_list))) == NULL)
    return (1);
  if (!(new->data = strdup(data)))
    {
      my_printf(2, "strdup: %s\n", strerror(errno));
      exit(1);
    }
  new->size = strlen(data);
  (*root)->size += new->size;
  tmp = (*root);
  while (tmp->next != *root)
    tmp = tmp->next;
  new->next = *root;
  tmp->next = new;
  return (0);
}

/*
** brief: it will remove the first element (not the root element)
** @root: our root element from our list
*/
void		remove_first(t_list **root)
{
  t_list	*tmp;

  if (*root != (*root)->next)
    {
      tmp = (*root)->next;
      (*root)->next = (*root)->next->next;
      free(tmp->data);
      free(tmp);
    }
}

/*
** brief: it will create our list with our root element
** return: return null if problem malloc, else our new root
*/
t_list		*create_root()
{
  t_list	*root;

  if ((root = my_malloc(sizeof(t_list))) == NULL)
    return (NULL);
  root->data = NULL;
  root->size = 0;
  root->next = root;
  return (root);
}

/*
** brief: free our list + our data
** @root: our root element from our list
*/
void		let_it_go(t_list **root)
{
  t_list	*tmp;
  t_list	*elt;

  tmp = (*root)->next;
  while (tmp != *root)
    {
      elt = tmp;
      tmp = tmp->next;
      free(elt->data);
      free(elt);
    }
  free(*root);
}

/*
** brief: it will display our datas from our list (conv into char*)
** @root: our root element from our list
** @fd: the fd where we will write
*/
void		display_list(t_list *root, int fd)
{
  t_list	*tmp;

  tmp = root->next;
  while (tmp != root)
    {
      my_printf(fd, "%s", (char *)tmp->data);
      tmp = tmp->next;
      if (tmp == root)
	my_printf(fd, "\n");
    }
}
