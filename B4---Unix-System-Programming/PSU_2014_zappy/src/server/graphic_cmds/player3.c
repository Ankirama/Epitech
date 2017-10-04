/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Jul  5 16:58:11 2015 CHARLES VITERBO
*/

/*
** @file player3.c
** @brief functions about player gfx
** @author ankirama
** @version 1.0
*/

#include "graphic_cmds.h"

/*
** @brief send pic, position and level
**
** @param server our server's structure
** @param idx our client's fd
** @param i our graphic client's fd
*/
static void	_player_start(t_server *server, int idx, int i)
{
  int		pos;

  pos = server->client[idx].pos;
  send_msg_nbs(server, i, "pic ", pos % server->map.width);
  send_msg_nbs(server, i, " ", pos / server->map.height);
  send_msg_nbs(server, i, " ", server->client[idx].level);
}

/*
** @brief send all informations needed when incantation
**
** @param server our server's structure
** @param idx our client'fd
*/
void		player_start_incant(t_server *server, int idx)
{
  int		i;
  t_list	*tmp;
  int		pos;
  t_client	*client;

  pos = server->client[idx].pos;
  for (i = 0; i <= server->curr_max; ++i)
    {
      if (server->type_fd[i] == FD_GFX)
	{
	  _player_start(server, idx, i);
	  tmp = server->map.map[pos].players->next;
	  while (tmp != server->map.map[pos].players &&
		 tmp->next != server->map.map[pos].players)
	    {
	      client = tmp->data;
	      send_msg_nbs(server, i, " ", client->fd);
	      tmp = tmp->next;
	    }
	  client = tmp->data;
	  send_msg_nb(server, i, " ", client->fd);
	  nbr_log("pic sent to", i, "player_start_incant", TYPE_INFO);
	}
    }
}

/*
** @brief send plv and the player's level
**
** @param server our server's structure
** @param idx our client's fd
** @param fd_gfx our graphic client fd
*/
static void	_player_level(t_server *server, int idx, int fd_gfx)
{
  send_msg_nbs(server, fd_gfx, "plv ", idx);
  send_msg_nb(server, fd_gfx, " ", server->client[idx].level);
  nbr_log("plv sent to", fd_gfx, "player_level", TYPE_INFO);
}

/*
** @brief send all the client's level
**
** @param server our server's strucutre
** @param idx our client's fd
** @param fd_gfx our graphic client's fd
*/
static void	_all_level(t_server *server, int idx, int fd_gfx)
{
  t_list	*tmp;
  t_client	*tmp_c;

  tmp = server->map.map[server->client[idx].pos].players == NULL ? NULL :
    server->map.map[server->client[idx].pos].players->next;
  while (tmp != NULL && tmp != server->map.map[server->client[idx].pos].players)
    {
      tmp_c = tmp->data;
      _player_level(server, tmp_c->fd, fd_gfx);
      tmp = tmp->next;
    }
}

/*
** @brief send pie and clients' level at the end of incantatation
**
** @param server our server's structure
** @param idx our our client's fd
** @param success client's level
*/
void	player_end_incant(t_server *server, int idx, int success)
{
  int	i;

  for (i = 0; i <= server->curr_max; ++i)
    {
      if (server->type_fd[i] == FD_GFX)
	{
	  send_msg_nbs(server, i, "pie ",
		       server->client[idx].pos % server->map.width);
	  send_msg_nbs(server, i, " ",
		       server->client[idx].pos / server->map.width);
	  send_msg_nb(server, i, " ", success);
	  nbr_log("pie sent to", i, "player_end_incant", TYPE_INFO);
	  _all_level(server, idx, i);
	}
    }
}
