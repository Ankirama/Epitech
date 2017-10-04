/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Fri Jul  3 13:01:10 2015 CHARLES VITERBO
*/

/*
** @file dead.c
** @brief actions from client (only dead)
** @author ankirama
** @version 0.1
*/

#include "actions.h"

/*
** @brief it will check the current food and remove unit
**
** It will check if the client need to eat and check if he is  alive
**
** @param server main structure
** @param fd file descriptor
** @param argv useless.
** @return 1 if still alive, else 0
*/
int	cmd_dead(t_server *server, int fd, char **argv)
{
  long	timer;

  timer = TIME_LIFE * 1000 / server->time;
  (void)argv;
  if (server->client[fd].created == 0)
    return (1);
  if (is_time_elapsed(&server->client[fd].start_life, timer))
    {
      --(server->client[fd].food);
      player_inventory(server, fd);
      if (server->debug_mode)
	send_msg_nb(server, fd, "Current unit time: ", server->client[fd].food);
      if (server->client[fd].food == 0)
	{
	  remove_client(&server->map.map[server->client[fd].pos].players, fd);
	  send_msg(server, fd, my_strdup("mort\n"));
	  write_client(server, fd);
	  close_connection(server, fd);
	  return (0);
	}
      else
	gettimeofday(&server->client[fd].start_life, NULL);
    }
  return (1);
}
