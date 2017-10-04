//
// CommandEngine.hh for  in /home/tang_i/rendu/PSU_2014_zappy/include/client_graph
// 
// Made by David Tang
// Login   <tang_i@epitech.net>
// 
// Started on  Sun Jul  5 12:35:01 2015 David Tang
// Last update Sun Jul  5 20:16:44 2015 David Tang
//

#ifndef COMMANDENGINE_HH_
# define COMMANDENGINE_HH_

/**
 * @file CommandEngine.hh
 * @author tang_i
 * @version 1.00
 */

# include <vector>
# include <map>
# include <string>
# include <iostream>
# include "Error.hpp"
# include "Network.hh"
# include "GameEngine.hh"
# include "template_string.hh"

/**
 * @class CommandEngine
 * @brief Interpret the command lines
 *
 * Used to interpret the commands from the server and launch
 * the appropriate functions
 */

class GameEngine;

class	CommandEngine {
public:
    /**
     * @brief constructor
     *
     * CommandLine's constructor, no arguments taken
     *
     * @param no parameters
     */
  CommandEngine();
    /**
     * @brief destructor
     *
     * CommandLine's destructor
     */
  ~CommandEngine();

public:
    /**
     * @brief received the size of the map
     *
     * It will received the size of the map and create a map with the given size
     *
     * @param tmp	: the entry of the command line
     * @param game	: the class GameEngine is needed to display the map
     */
  void					msz(std::string &tmp, GameEngine &game);

    /**
     * @brief information about a square of the map from the server
     *
     * It will received the position x, y and the number of element of each
     * resssources in this square.
     * Afterwards, it will set those numbers of element at the right position.
     *
     * @param tmp	: the entry of the command line
     * @param game	: the class GameEngine is needed to set the elements
     */
  void					bct(std::string &tmp, GameEngine &game);

    /**
     * @brief received the name of the team from the server
     *
     * It will set the name of the team from the server
     *
     * @param tmp	: the entry of the command line
     * @param game	: the class GameEngine is needed to set the name of the team
     */
  void					tna(std::string &tmp, GameEngine &game);

    /**
     * @brief received the connection of a new player
     *
     * It will create a new player and set his/her position, level, orientation etc..
     *
     * @param tmp	: the entry of the command line
     * @param game	: the class GameEngine is needed to set the new player
     */
  void					pnw(std::string &tmp, GameEngine &game);

    /**
     * @brief received the position of a player
     *
     * It will update the position of a player
     *
     * @param tmp	: the entry of the command line
     * @param game	: the class GameEngine is needed to update the player
     */
  void					ppo(std::string &tmp, GameEngine &game);

    /**
     * @brief received the information of a leveling player
     *
     * It will upgrade/set the level of a player
     *
     * @param tmp	: the entry of the command line
     * @param game	: the class GameEngine is needed to set the level of player
     */
  void					plv(std::string &tmp, GameEngine &game);

    /**
     * @brief received the inventory of a player
     *
     * It will set the value of each ressources
     *
     * @param tmp	: the entry of the command line
     * @param game	: the class GameEngine is needed to set the ressources
     */
  void					pin(std::string &tmp, GameEngine &game);

    /**
     * @brief received the information a player expulse others players
     *
     * It will move players who are in the same square as him/her away
     *
     * @param tmp	: the entry of the command line
     * @param game	: the class GameEngine is needed to kick player out of the square
     */
  void					pex(std::string &tmp, GameEngine &game);

    /**
     * @brief received the information a player is broadcasting
     *
     * It will send a message to players
     *
     * @param tmp	: the entry of the command line
     * @param game	: the class GameEngine is needed to send message
     */
  void					pbc(std::string &tmp, GameEngine &game);

    /**
     * @brief received the information a player is going to go through a ritual
     *
     * It will start an incantation
     *
     * @param tmp	: the entry of the command line
     * @param game	: the class GameEngine is needed to start an incantation
     */
  void					pic(std::string &tmp, GameEngine &game);

    /**
     * @brief received the information a player is under a ritual
     *
     * It will check the needed requirement and levelup the players ending
     * the ceremony
     *
     * @param tmp	: the entry of the command line
     * @param game	: the class GameEngine is needed to end the ritual
     */
  void					pie(std::string &tmp, GameEngine &game);

    /**
     * @brief received the information a player want to lay down an egg
     *
     * It will fork a player, display an egg
     *
     * @param tmp	: the entry of the command line
     * @param game	: the class GameEngine is needed to do so
     */
  void					pfk(std::string &tmp, GameEngine &game);

    /**
     * @brief received the information a player put down something
     *
     * It will display the player is putting down something on the ground
     *
     * @param tmp	: the entry of the command line
     * @param game	: the class GameEngine is needed to display it
     */
  void					pdr(std::string &tmp, GameEngine &game);

    /**
     * @brief received the information a player take a ressources
     *
     * It will display the player is taking something off the ground
     * it may be food or stones
     *
     * @param tmp	: the entry of the command line
     * @param game	: the class GameEngine is needed to display it
     */
  void					pgt(std::string &tmp, GameEngine &game);

    /**
     * @brief received the information a player is dead
     *
     * It will display the death of a player
     *
     * @param tmp	: the entry of the command line
     * @param game	: the class GameEngine is needed to display it
     */
  void					pdi(std::string &tmp, GameEngine &game);

    /**
     * @brief received the information an egg has been created
     *
     * It will create an egg and display it
     *
     * @param tmp	: the entry of the command line
     * @param game	: the class GameEngine is needed to do so
     */
  void					enw(std::string &tmp, GameEngine &game);

    /**
     * @brief received the information an egg is hatching
     *
     * It will remove the egg, add a ghost and display it
     *
     * @param tmp	: the entry of the command line
     * @param game	: the class GameEngine is needed to display it
     */
  void					eht(std::string &tmp, GameEngine &game);

    /**
     * @brief received the information a player is connected in replacement of the egg
     *
     * It will remove the egg
     *
     * @param tmp	: the entry of the command line
     * @param game	: the class GameEngine is needed to do so
     */
  void					ebo(std::string &tmp, GameEngine &game);

    /**
     * @brief received the information an egg is dead
     *
     * Nothing is done here
     */
  void					edi(std::string &tmp, GameEngine &game);

    /**
     * @brief received the time
     *
     * It will set the time
     *
     * @param tmp	: the entry of the command line
     * @param game	: the class GameEngine is needed to do so
     */
  void					sgt(std::string &tmp, GameEngine &game);

    /**
     * @brief received the information the game had ended
     *
     * It will display the winner
     *
     * @param tmp	: the entry of the command line
     * @param game	: the class GameEngine is needed to do so
     */
  void					seg(std::string &tmp, GameEngine &game);

    /**
     * @brief received a message from the server
     *
     * Nothing is done here
     */
  void					smg(std::string &tmp, GameEngine &game);

    /**
     * @brief received an unknown command from the server
     *
     * Nothing is done here
     */
  void					suc(std::string &tmp, GameEngine &game);

    /**
     * @brief received a wrong parameter from the server
     *
     * Nothing is done here
     */
  void					sbp(std::string &tmp, GameEngine &game);

    /**
     * @brief check the command line received
     *
     * It received the command's line, cut the first parameter til it found a space,
     * and return it
     *
     * @param tmp	: the command's line
     */
  std::string				getCmd(std::string &tmp) const;

    /**
     * @brief get the argument of a command's line
     *
     * It received the command's line, cut the argument and put it onto a vector
     *
     * @param tmp	: the command's line
     * @return		: return the name of the command
     */
  std::vector<std::string>		getArg(std::string &tmp);

    /**
     * @brief compare the command reveived
     *
     * It received the command's line and check if the command exist,
     * if so it will launch it
     *
     * @param tmp	: the command's line
     * @return		: return the vector of the argument
     */
  void					whichCmd(Network &network, GameEngine &game);

private:
  typedef void				(CommandEngine::*tabFun)(std::string &tmp, GameEngine &game); /**< A pointer function array to launch the appropriate function */
  std::map<std::string, tabFun>		m_function; /**< a mapping function to distinct each  */
};

#endif /* !COMMANDENGINE_HH_ */
