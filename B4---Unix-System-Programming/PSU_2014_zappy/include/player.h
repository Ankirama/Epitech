//
// Joueur.hh for  in /home/teyssa_r/rendu/PSU_2014_zappy/include
// 
// Made by Raphael Teyssandier
// Login   <teyssa_r@epitech.net>
// 
// Started on  Tue May 26 17:54:26 2015 Raphael Teyssandier
// Last update Tue May 26 18:06:07 2015 Raphael Teyssandier
//

#ifndef PLAYER_HH_
# define PLAYER_HH_

# include	<iostream>
# include       <netdb.h>
# include       <arpa/inet.h>
# include       <netinet/in.h>
# include       <sys/socket.h>
# include       <sys/types.h>
# include       <errno.h>

class	Player {
private:
  int	m_fd;

public:
  Player();
  ~Player();
};

#endif /* !PLAYER_HH_ */
