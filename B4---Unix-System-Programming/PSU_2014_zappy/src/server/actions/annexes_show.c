/*
** annexes_show.c for  in /home/viterb_c/rendu/PSU_2014_zappy/src/server/actions
** 
** Made by CHARLES VITERBO
** Login   <viterb_c@epitech.net>
** 
** Started on  Thu Jun 23 15:18:44 2015 CHARLES VITERBO
** Last update Sat Jul  4 15:27:22 2015 CHARLES VITERBO
*/

/*
** @file annexes_show.c
** @brief functions to send contents of a case
** @author viterb_c
** @version 1.0
*/

# include "actions.h"

/*
** @brief it will send to the client our objets's name
**
** @param server our server's structure
** @param fd our client's fd
** @param tab our array with number and name of objects
*/
static void	_send_objects(t_server *server, int fd, t_objects *tab)
{
  int		i;

  i = -1;
  while (++i < NB_VISION)
    {
      while (tab[i].id > 0)
	{
	  send_msg(server, fd, my_strdup(tab[i].name));
	  tab[i].id--;
	}
    }
}

/*=
** @brief it will initialize our array with the number of objects in the cell
**
** @param server our server's structure
** @param fd our client's fd
** @param cell our cell where the client is looking
*/
void		send_case(t_server *server, int fd, t_case *cell)
{
  t_objects	tab[NB_VISION];

  tab[0].name = " joueur";
  tab[0].id = cell->players->size;
  tab[1].name = " nourriture";
  tab[1].id = cell->food;
  tab[2].name = " linemate";
  tab[2].id = cell->stones[ID_LINEMATE];
  tab[3].name = " deraumere";
  tab[3].id = cell->stones[ID_DERAUMERE];
  tab[4].name = " sibur";
  tab[4].id = cell->stones[ID_SIBUR];
  tab[5].name = " mendiane";
  tab[5].id = cell->stones[ID_MENDIANE];
  tab[6].name = " phiras";
  tab[6].id = cell->stones[ID_PHIRAS];
  tab[7].name = " thystame";
  tab[7].id = cell->stones[ID_THYSTAME];
  _send_objects(server, fd, tab);
}
