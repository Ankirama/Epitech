/*
** main.c<2> for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Wed Apr  1 11:40:32 2015 Fabien Martinez
*/

#include "server.h"

void		add_channel(t_channel **chans, char *name)
{
  t_channel	*tmp;
  t_channel	*elt;

  tmp = *chans;
  elt = my_malloc(sizeof(t_channel));
  elt->name = strdup(name);
  elt->nb_users = 0;
  elt->clients = create_root();
  elt->next = NULL;
  if (tmp == NULL)
    *chans = elt;
  else
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = elt;
    }
}

t_channel	*get_channel(t_channel *chans, char *name)
{
  t_channel	*tmp;

  tmp = chans;
  while (tmp != NULL && strcmp(tmp->name, name) != 0)
    tmp = tmp->next;
  return (tmp);
}

void		remove_channel(t_channel **chan, char *name)
{
  t_channel	*tmp;
  t_channel	*elt;

  tmp = (*chan);
  if (tmp != NULL && strcmp(tmp->name, name) == 0)
    {
      (*chan) = (*chan)->next;
      free(tmp->name);
      let_it_go(&(tmp->clients));
      free(tmp);
    }
  else
    {
      while (tmp->next != NULL && strcmp(tmp->name, name) != 0)
	tmp = tmp->next;
      if (tmp->next)
	{
	  elt = tmp->next;
	  tmp->next = elt->next;
	  free(elt->name);
	  let_it_go(&(elt->clients));
	  free(elt);
	}
    }
}

char		*nb_channel(t_channel *chans)
{
  int		nb_chans;
  t_channel	*tmp;

  tmp = chans;
  nb_chans = 0;
  while (tmp != NULL)
    {
      ++nb_chans;
      tmp = tmp->next;
    }
  return (int_to_str(nb_chans));
}

void		free_channels(t_channel **chans)
{
  t_channel	*tmp;
  t_channel	*elt;

  tmp = *chans;
  if (tmp != NULL)
    {
      while (tmp->next != NULL)
	{
	  elt = tmp;
	  tmp = elt->next;
	  free(elt->name);
	  let_it_go(&(elt->clients));
	  free(elt);
	}
      free(tmp);
    }
}
