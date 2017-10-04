//
// Network.hh for  in /home/teyssa_r/rendu/PSU_2014_zappy/src/client
// 
// Made by Raphael Teyssandier
// Login   <teyssa_r@epitech.net>
// 
// Started on  Thu Jun 18 21:53:22 2015 Raphael Teyssandier
// Last update Sun Jul  5 16:14:18 2015 Raphael Teyssandier
//

#ifndef NETWORK_HH_
# define NETWORK_HH_

/**
 * @file Network.hh
 * @brief For client class
 * @author doT
 * @version 0.3
 */

# define	MAX_FD		1
# define	BUFF_SIZE	255
# define	NBOBJECT	8

# include	<iostream>
# include	<string.h>
# include	<errno.h>
# include	<stdio.h>
# include	<time.h>
# include	<vector>
# include	<map>
# include	"utils.h"

/**
 * @class Network
 * @brief Network class for the AI and the network
 */
class	Network {
public:
  /**
   * @brief Default constructor
   */
  Network(std::string const &name, std::string const &port,
	  std::string const &host);
  /**
   * @brief Copy constructor
   */
  Network(Network const &);
  /**
   * @brief Operator= constructor
   */
  Network	&operator=(Network const &);
  /**
   * @brief Destructor
   */
  ~Network();

  /**
   * @brief Init the network of the client
   */
  void	initNetwork();
  /**
   * @brief Send from the server
   */
  void	mSend();
  /**
   * @brief Read to the server
   */
  void	mRecv();
  /**
   * @brief Init the file desciptor
   */
  void	initFd();
  /**
   * @brief Init the buffer
   */
  void	initBuff(char *);
  /**
   * @brief Send or Recv from the server
   */
  void	fdIsset();
  /**
   * @brief Read (unfill the vector)
   */
  std::string	readCmd();
  /**
   * @brief Send msg (fill the vector)
   */
  void	sendCmd(std::string const &);
  /**
   * @brief Get name team
   */
  std::string	&getName()	{ return this->m_name; }
  /**
   * @brief Get the fd
   */
  int	getFd()	{ return this->m_fd; }

  void		displayTime();
  /**
   * @brief Parse the command voir
   */
private:
  std::string				m_name; /**<Name of the Team*/
  std::string				m_port; /**<Port*/
  std::string				m_host; /**<Hostname*/
  fd_set				m_fd_read; /**<FD read*/
  fd_set				m_fd_write; /**<FD write*/
  int					m_fd; /**<File descriptor*/
  struct protoent			*m_pe; /**<Struct protoent*/
  struct sockaddr_in			m_s_in; /**<Sockaddr_in*/
  struct hostent			*m_h; /**<Hostent*/
  struct in_addr			m_in; /**<in_addr*/
  std::vector<std::string>		m_readList; /**<Receive command*/
  std::vector<std::string>		m_writeList; /**<Command to send*/
};

#endif /* !NETWORK_HH_ */
