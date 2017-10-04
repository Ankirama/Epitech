/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sun Jun 28 01:54:05 2015 CHARLES VITERBO
*/

/*
** @file inventory.c
** @brief actions from client (only inventory)
** @author ankirama
** @version 0.1
*/

#include "actions.h"

/*
** @brief it will send the inventory
**
** @param server main structure
** @param fd file descriptor
** @param argv useless here
** @return 1
*/
int	cmd_inventory(t_server *server, int fd, char **argv)
{
  (void)argv;
  send_msg(server, fd, my_strdup("{"));
  send_msg_nbs(server, fd, "nourriture ", server->client[fd].food);
  send_msg_nbs(server, fd, ", linemate ",
	       server->client[fd].inventaire[ID_LINEMATE]);
  send_msg_nbs(server, fd, ", deraumere ",
	       server->client[fd].inventaire[ID_DERAUMERE]);
  send_msg_nbs(server, fd, ", sibur ",
	       server->client[fd].inventaire[ID_SIBUR]);
  send_msg_nbs(server, fd, ", mendiane ",
	       server->client[fd].inventaire[ID_MENDIANE]);
  send_msg_nbs(server, fd, ", phiras ",
	       server->client[fd].inventaire[ID_PHIRAS]);
  send_msg_nbs(server, fd, ", thystame ",
	      server->client[fd].inventaire[ID_THYSTAME]);
  send_msg(server, fd, my_strdup("}\n"));
  return (1);
}
