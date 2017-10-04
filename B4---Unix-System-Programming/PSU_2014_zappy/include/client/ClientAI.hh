//
// ClientAI.hh for  in /home/teyssa_r/rendu/PSU_2014_zappy
// 
// Made by Raphael Teyssandier
// Login   <teyssa_r@epitech.net>
// 
// Started on  Thu Jun 18 22:06:41 2015 Raphael Teyssandier
// Last update Sun Jul  5 18:13:38 2015 Raphael Teyssandier
//

#ifndef CLIENTAI_HH_
# define CLIENTAI_HH_

/**
 * @file ClientAI.hh
 * @brief Network + Artificial Intelligence
 * @author dot & Areku
 * @version 1.0
 */

# define PRENDRE(h)	(std::string("prend ") + std::string(h) + std::string("\n"))
# define POSER(h)	(std::string("pose ") + std::string(h) + std::string("\n"))
# define AVANCE		"avance\n"
# define DROITE		"droite\n"
# define GAUCHE		"gauche\n"
# define VOIR		"voir\n"
# define INVENTAIRE	"inventaire\n"
# define EXPULSE	"expulse\n"
# define INCANTATION	"incantation\n"
# define FORK		"fork\n"
# define CONNECT_NBR	"connect_nbr\n"
# define USAGE		std::string("Usage: ./zappy_ai -n nameteam -p port [-h hostname] [-d]")

# include "Network.hh"
# include "Error.hpp"
# include "template_string.hh"
# include "ParseClient.hh"
# include <fstream>
# include <ctime>

/**
 * @class ClientAI
 * @brief Network + Artificial Intelligence
 */
class	ClientAI {
public:
  /**
   * @brief Default constructor
   */
  ClientAI(int, char **);
  /**
   * @brief Copy constructor
   */
  ClientAI(ClientAI const &);
  /**
   * @brief Operator = constructor
   */
  ClientAI	&operator=(ClientAI const &);
  /**
   * @brief Default destructor
   */
  ~ClientAI();

  /**
   * @brief Enum of object in case or a player
   */
  typedef enum  e_Case {
    ID_PLAYER = 0,
    ID_FOOD,
    ID_LINEMATE,
    ID_DERAUMETE,
    ID_SIBUR,
    ID_MENDIANE,
    ID_PHIRAS,
    ID_THYSTAME
  }             t_Case;

  /**
   * @brief Initialisation
   */
  void	init();
  /**
   * @brief Default cycle
   */
  void	cycle();
  /**
   * @brief function which will send & receiv
   * info for/from server
   * @param1 The command to send
   */
  bool	sendInfo(std::string);
  /**
   * @brief function which will return true
   * if item is on one case
   * false if it's not
   * @param1 What i want
   * @param2 Who much
   */
  bool	checkSee(int, int);
  /**
   * @brief main function for IA
   */
  void	loop();
  /**
   * @brief function to find help
   */
  void	goForHelp();
  /**
   * @brief function to find IA which elevate
   */
  void	findElevation();
  /**
   * @brief function to apply fork
   */
  void	doFork();
  /**
   * @brief Seek the string corresponding to the t_Case in the map
   */
  std::string	seekInMap(int) const;
  /**
   * @brief Seek element on the real map
   */
  void	seekElem(int, int);
  /**
   * @brief Advance
   */
  void	advance(int &);
  /**
   * @brief Advance and take the food
   */
  void	advance();
  /**
   * @brief Go on the left or on the right
   */
  void	leftOrRight(int &);
  /**
   * @brief Take all the food on one case
   */
  void	takeFood();
  /**
   * @brief Go to an one direction for helping one guys
   */
  void	helpDirection(int);
  /**
   * @brief Do fdIsset() while nothing is receive
   */
  void	recvMessage();
  /**
   * @brief Take or pose the stone on the ground
   */
  void	takeOrPose();
  /**
   * @brief Receive the information from broadcast
   */
  void	recvInfoIncant();
  /**
   * @brief Print the log
   * @param1 The Parameter
   * @param2 The message
   * @param3 Color
   */
  void	log(std::string const,
	    std::string const,
	    std::string const);

private:
  int					m_currentLevel;/**<Current level of the player*/
  bool					m_goHelp;/**<Someone need help*/
  int					m_idHelp;/**<ID of the player who need help*/
  ParseClient				*m_parsing;/**<Parse the command "voir" and "inventaire"*/
  int					m_posX;/**<Pos X, for seek an elem*/
  int					m_posY;/**<Pos Y, for seek an elem*/
  bool					m_canIncant;/**<If no one need help, and i can incant*/
  bool					m_alive;/**<If i'm alive or not*/
  std::string				m_messageHelp;/**<Message from the player who need help*/
  std::string				m_message;/**<Message*/
  std::string				m_receive;/**<Receive last message from the server*/
  Network				*m_network;/**<Party network of the client*/
  std::vector<std::vector<std::vector<int> > >	m_floor;/**<Result of the command "voir"*/
  std::map<std::string, int>		 m_map;/**<Map of string with the right Enum number*/
  int					m_tab[NBOBJECT];/**<Result of the command "inventaire"*/
};

#endif /* !CLIENT_HH_ */
