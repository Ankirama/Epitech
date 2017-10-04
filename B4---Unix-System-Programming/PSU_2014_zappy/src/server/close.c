/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Jul  5 03:43:17 2015 Alexandre Chenevier
*/

/*
** @file close.c
** @brief function to close a server
** @author ankirama
** @version 1.0
*/

#include "close.h"

/*
** @brief it will find the higher fd in our structure server
**
** @param server our structure server
** @param fd our client's fd
**
** @return the higher fd
*/
int	_find_higher_fd(t_server *server, int fd)
{
  int	i;

  i = fd - 1;
  while (i >= 0 && server->type_fd[i] == FD_FREE)
    --i;
  return (i);
}

/*
** @brief it will close connection and "free" client
**
** It will remove client in then team, free client and set fd to FD_FREE
** It will set the curr_max
**
** @param server main structure
** @param fd file descriptor
*/
void	close_connection(t_server *server, int fd)
{
  nbr_log("Connection closed:", fd, "close_connection", TYPE_INFO);
  server->curr_max = server->curr_max == fd ? _find_higher_fd(server, fd)
    : server->curr_max;
  let_it_go(&server->write_buffer[fd]);
  free_cmds(&server->client[fd].cmds);
  remove_player(server, fd);
  free(server->client[fd].team);
  memset(&(server->client[fd]), 0, sizeof(t_client));
  if (server->type_fd[fd] == FD_CLIENT)
    player_dead(server, fd);
  server->type_fd[fd] = FD_FREE;
  my_close(fd);
}

/*
** @brief it will free all our teams in server structure
**
** @param server our server's structure
*/
static void	_free_teams(t_server *server)
{
  t_list	*tmp;
  t_list	**root;
  t_list	*elt;
  int		i;

  for (i = 0; i < server->nb_teams; ++i)
    {
      root = &(server->teams[i].players);
      if (*root != NULL)
	{
	  tmp = (*root)->next;
	  while (tmp != NULL && tmp != *root)
	    {
	      elt = tmp;
	      free(elt);
	      tmp = tmp->next;
	    }
	  free(*root);
	}
      free_list(&server->teams[i].forks);
      free(server->teams[i].name);
    }
}

/*
** @brief it will free all our structure from server
**
** @param server main structure
*/
static void	_free_server(t_server *server)
{
  unsigned int	i;
  unsigned int	size;
  t_list	**root;

  i = 0;
  size = server->map.width * server->map.height;
  while (i < size)
    {
      root = &(server->map.map[i].players);
      free_link(root);
      i++;
    }
  free(server->map.map);
  free(server->write_buffer);
  free(server->type_fd);
  free(server->fct_read);
  free(server->fct_write);
  free(server->ports);
  free(server->client);
  _free_teams(server);
  free(server->teams);
  free_list(&(server->forks));
}

/*
** @brief it will close our fd opened from server (FD_SERVER)
**
** @param server main structure
*/
void	close_server(t_server *server)
{
  int	i;
  int	ok_server;

  for (i = 0; i < server->nb_fd; ++i)
    {
      if (server->type_fd[i] == FD_GFX || server->type_fd[i] == FD_CLIENT)
	close_connection(server, i);
    }
  i = -1;
  ok_server = 0;
  while (++i < server->nb_fd)
    {
      if (server->type_fd[i] == FD_SERVER)
	{
	  ok_server = 1;
	  my_close(server->type_fd[i]);
	}
    }
  _free_server(server);
  if (ok_server)
    cmd_log("Server(s) ZAPPY closed", "close_server", xdate(), TYPE_INFO);
  close_log_file();
}
