//
// Character.hh for  in /home/tang_i/rendu/PSU_2014_zappy
// 
// Made by David Tang
// Login   <tang_i@epitech.net>
// 
// Started on  Sat Jun 27 19:38:31 2015 David Tang
// Last update Sun Jul  5 20:15:07 2015 David Tang
//

#ifndef CHARACTER_HH_
# define CHARACTER_HH_

/**
 * @file Character.hh
 * @brief Character class for the client graphic
 * @author tang_i
 */

# include <string>
# include <vector>
# include "Tile.hh"
# include "object.h"

/**
 * @NBEMOTE	: define for the number of emote
 */
# define NBEMOTE	9

/**
 * @ACTION	: enum for the differents emote
 */
enum ACTION
  {
    BROADCAST,
    PICKFOOD,
    PICKSTONE,
    INCANTATION,
    LEVELUP,
    EXPULSE,
    DEATH,
    EGGS,
    EGGE
  };

class					Character {
public:
    /**
     * @brief constructor
     *
     * Character's constructor where we will init Character's object
     *
     * @param id		: id's number of the character
     * @param team		: the name of the team
     * @param x			: the x's position
     * @param y			: the y's position
     * @param orien		: the character's orientation
     * @param textureSize	: the size of the grass' texture
     * @param level		: the level of the character
     */
  explicit Character(int id, const std::string &team, int x, int y, int orien,
		     const sf::Vector2u &textureSize, int level);

    /**
     * @brief destructor
     *
     * Character's destructor
     */
  ~Character();

public:
    /**
     * @brief draw the sprite
     *
     * @param window	: pointer window allow us to draw the window
     */
  void	draw(sf::RenderWindow *window);

    /**
     * @brief set the level of a character
     *
     * @param level	: the level we want to set
     */
  void	setLevel(unsigned int level) {this->m_level = level;}

    /**
     * @param brief upgrade the level of a character by 1
     */
  void	levelUp() {++this->m_level;}

    /**
     * @brief set the boolean value of die
     *
     * @param value	: the new boolean value we want to set it
     */
  void	setDie(bool value) {this->m_tabBool[DEATH] = value;}

    /**
     * @brief set the boolean value of expulse
     *
     * @param value	: the new boolean value we want to set it
     */
  void	setExpulse(bool value) { this->m_tabBool[EXPULSE] = value;}

    /**
     * @brief set the boolean value of egg
     *
     * @param value	: the new boolean value we want to set it
     */
  void	setEgg(bool value) { this->m_tabBool[EGGS] = value;}

    /**
     * @brief set the boolean value of egg (emoicone)
     *
     * @param value	: the new boolean value we want to set it
     */
  void	setEgge(bool value) { this->m_tabBool[EGGE] = value;}

    /**
     * @brief set the boolean value of the incantion
     *
     * @param value	: the new boolean value we want to set it
     */
  void	setIncantation(bool value) {this->m_tabBool[INCANTATION] = value;}

    /**
     * @brief set the boolean value of levelup
     *
     * @param value	: the new boolean value we want to set it
     */
  void	setLevelUp(bool value) {this->m_tabBool[LEVELUP] = value;}

    /**
     * @brief set the boolean value of broadcast
     *
     * @param value	: the new boolean value we want to set it
     */
  void	setBroadcast(bool value) {this->m_tabBool[BROADCAST] = value;}

    /**
     * @brief set the boolean value of pickfood
     *
     * @param value	: the new boolean value we want to set it
     */
  void	setPickFood(bool value) {this->m_tabBool[PICKFOOD] = value;}

    /**
     * @brief set the boolean value of pickstone
     *
     * @param value	: the new boolean value we want to set it
     */
  void	setPickStone(bool value) {this->m_tabBool[PICKSTONE] = value;}

    /**
     * @brief set the number of item
     *
     * @param idItem   	: the id of the item
     * @param quantity	: the new number it assigns
     */
  void	setItem(int idItem, unsigned int quantity) {
    if (idItem >= 0 && idItem < NB_OBJ + 1)
      this->m_inventory[idItem] = quantity;
  }

    /**
     * @brief set the orientation of the character
     *
     * @param orientation	: the new orientation
     */
  void	setOrientation(int orientation) {this->m_orientation = orientation;}

    /**
     * @brief set the new position of the character
     *
     * @param x	: the x's new position
     * @param y	: the y's new position
     */
  void	setPosition(int x, int y);

    /**
     * @brief set the new position of the character and the orientation
     *
     * @param x		     	: the x's new position
     * @param y			: the y's new position
     * @param orientation	: the new orientation
     */
  void	setPosition(int x, int y, int orientation);

    /**
     * @brief set the window's size
     *
     * @param windowX	     	: the width's window
     * @param windowY		: the height's window
     */
  void	setWindowSize(int windowX, int windowY);

    /**
     * @brief set the map size
     *
     * @param width	     	: the width's map
     * @param height		: the height's map
     */
  void	setMapSize(int width, int height);

    /**
     * @brief set the character's sprite's orientation onto a vector
     *
     * @param newTile		: the pointer of the sprite
     */
  void	setTile(Tile *newTile);

    /**
     * @brief set the character's sprite's emoicone onto a vector
     *
     * @param newTile		: the pointer of the sprite
     */
  void	setAction(Tile *newTile);

    /**
     * @brief set a timer for the display of the emoicone
     *
     * @param count		: the time we want to display it
     */
  void	setTimer(int count);

    /**
     * @brief return the pointer of the inventory's
     */
  const std::vector<unsigned int>	&getInventory() const {return this->m_inventory;}

    /**
     * @brief return the quantity of the id given as a parameter
     *
     * @param idItem   	: the idItem we want the quantity
     * @return		: return the inventory vector
     */
  unsigned int	getQuantityItem(int idItem) const {
    if (idItem >= 0 && idItem < NB_OBJ + 1)
      return this->m_inventory[idItem];
    return -1;
  }

    /**
     * @brief return the orientation of the character
     *
     * @return	: return the orientation of the character
     */
  int		getOrientation() const {return this->m_orientation;}

    /**
     * @brief return the id of the character
     *
     * @return	: return the id of the character
     */
  int		getId() const {return this->m_id;}

    /**
     * @brief return the character's x position
     *
     * @return	: return the position x
     */
  int		getX() const {return this->m_x;}

    /**
     * @brief return the character's y position
     *
     * @return	: return the position y
     */
  int		getY() const {return this->m_y;}

    /**
     * @brief return the character's level
     *
     * @return	: return the level of the character
     */
  unsigned int	getLevel() const {return this->m_level;}

    /**
     * @brief return the character's team's name
     *
     * @return	: return the name of the team
     */
  const std::string	&getTeam() const {return this->m_team;}

private:
    /**
     * @brief create an boolean array
     *
     * Create and initialize the boolean Emote's array
     */
  void		initTabEmote();

    /**
     * @brief display an emote for the broadcast
     *
     * @param window	: the pointer of the window is needed for the display
     */
  void		broadCast(sf::RenderWindow *window);

    /**
     * @brief display an emote to pickup the food
     *
     * @param window	: the pointer of the window is needed for the display
     */
  void		pickFood(sf::RenderWindow *window);

    /**
     * @brief display an emote to pickup the stone
     *
     * @param window	: the pointer of the window is needed for the display
     */
  void		pickStone(sf::RenderWindow *window);

    /**
     * @brief display an emote foee the incantation
     *
     * @param window	: the pointer of the window is needed for the display
     */
  void		inCantation(sf::RenderWindow *window);

    /**
     * @brief display an emote for the leveling
     *
     * @param window	: the pointer of the window is needed for the display
     */
  void		levelup(sf::RenderWindow *window);

    /**
     * @brief display an emote when the character expulse others characters
     *
     * @param window	: the pointer of the window is needed for the display
     */
  void		expulse(sf::RenderWindow *window);

    /**
     * @brief display an emote when the character is dead
     *
     * @param window	: the pointer of the window is needed for the display
     */
  void		death(sf::RenderWindow *window);

    /**
     * @brief display an egg when forking
     *
     * @param window	: the pointer of the window is needed for the display
     */
  void		egg(sf::RenderWindow *window);

    /**
     * @brief display an emote when forking
     *
     * @param window	: the pointer of the window is needed for the display
     */
  void		egge(sf::RenderWindow *window);

private:
int					m_id; /**< id/fd of the character */
  std::string				m_team; /**<  name of the character's team */
  int					m_x; /**<  character's x's position */
  int					m_y; /**< character's y's position */
  unsigned int				m_level; /**< character's level */
  int					m_orientation; /**< character's orientation */
  std::vector<unsigned int>		m_inventory; /**< character's inventory */
  std::vector<Tile *>			m_playerTiles; /**< character's orientation's sprite */
  std::vector<Tile *>			m_playerActions; /**< character's emotes' icone */
  int					m_windowX; /**< window's width  */
  int					m_windowY; /**< window's height */
  int					m_width; /**< map's width */
  int					m_height; /**< map's height */
  int					m_timer; /**< emote's display timer */
  typedef void				(Character::*tabFun)(sf::RenderWindow *); /**< emote pointer array function */
  tabFun				m_tabEmote[NBEMOTE]; /**< emote array function */
  bool					m_tabBool[NBEMOTE]; /**< emote bool array  */
  sf::Vector2u				m_textureSize; /**< grass' texture size */
};

#endif /* !CHARACTER_HH_ */
