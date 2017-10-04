//
// Cell.hh for  in /home/tang_i/rendu/PSU_2014_zappy/include/client_graph
//
// Made by David Tang
// Login   <tang_i@epitech.net>
//
// Started on  Fri Jun 26 22:00:17 2015 David Tang
// Last update Sun Jul  5 20:28:44 2015 David Tang
//

#ifndef CELLR_HH_
# define CELLR_HH_

/**
 * @file CellR.hh
 * @brief class about cell in the map
 * @author ankirama
 * @version 1.00
 */

# include <vector>
# include <SFML/Graphics.hpp>
# include "Tile.hh"
# include "Item.hh"
# include "TilesIndex.hh"

/**
 * @class CellR
 * @brief specific cell in the map
 */
class				CellR
{
public:
  /*
  * @brief constructor
  *
  * It will set our variables and create our item's vector (for each stone and food)
  * It will set our Tiles (stones, food, egg, ghost)
  * @param position	: position vector (cell position)
  * @param windowSize	: window size (like 1280 x 720)
  * @param mapSize	: map size (like 10 x 10)
  * @param tileIndex	: pointer on each tile to create new Tiles
  */
  CellR(const sf::Vector2i &position,
	const sf::Vector2i &windowSize,
	const sf::Vector2i &mapSize,
	TilesIndex *tileIndex);

  /**
   * @brief destructor
   *
   * delete tiles and tiles
   */
  ~CellR();

  /**
   * @brief set item's quantity with id
   *
   * @param id		: item's id
   * @param quantity	: quantity to set for specific item
   */
  void				setItem(int id, unsigned int quantity);

  /**
   * @brief get item
   *
   * @param id	: item's id
   * @return : return the specific item found with id
   */
  Item			&getItem(int id) const {return *this->m_items[id];}

  /**
   * @brief set egg quantity
   *
   * @param quantity	: quantity to set
   */
  void				setQuantityEgg(unsigned int quantity);

  /**
   * @brief get egg quantity
   *
   * @return : return egg quantity
   */
  unsigned int			getQuantityEgg();

  /**
   * @brief set ghost quantity
   *
   * @param quantity	: quantity to set
   */
  void				setQuantityGhost(unsigned int quantity);

  /**
   * @brief get ghost quantity
   *
   * @return : return ghost quantity
   */
  unsigned int			getQuantityGhost();

  /**
   * @brief draw function to draw every tiles
   *
   * It will draw tiles and item (with quantity > 0)
   *
   * @param window	: renderWindow used to display on our screen
   */
  void				draw(sf::RenderWindow *window);

  /**
   * @brief get grass Sprite
   *
   * @return : reference to the grass Sprite
   */
  sf::Sprite			&getSprite() const;

  /**
   * @brief add player's id in vector
   *
   * Used to check how many players are on the current cell
   *
   * @param id	: player's id
   */
  void				addPlayer(int id);

  /**
   * @brief remove player's id in our vector
   *
   * @param id	: player's id
   */
  void				removePlayer(int id);

  /**
   * @brief get players' vector on the current cell
   *
   * @return : return players' vector
   */
  const std::vector<int>	&getPlayers() const;

  /**
   * @brief get default color (used to reset color on the cell)
   *
   * @return : default color
   */
  const sf::Color		&getColorDefault() const;

  /**
   * @brief get cell position (x + y * width)
   *
   * @return : cell position
   */
  int				getPos() const;

private:

  /**
   * @brief default constructor
   *
   * Not used -> private
   */
  CellR();

private:
  TilesIndex			*m_tileIndex; /**< tiles pointer used to create new Tiles */
  int				m_width; /**< map width */
  int				m_height; /**< map height */
  int				m_pos; /**< cell position (x + y * width) */
  int				m_winX; /**< screen width (like 1280) */
  int				m_winY; /**< screen height (like 720) */
  Tile				*m_cellTile; /**< grass Tile */
  int				m_x; /**< cell x position */
  int				m_y; /**< cell y position */
  std::vector<Item *>		m_items; /**< items vector with stones and food */
  Tile				*m_egg; /**< egg Tile */
  Tile				*m_ghost; /**< ghost Tile */
  unsigned int			m_quantityEgg; /**< egg quantity */
  unsigned int			m_quantityGhost; /**< ghost quantity */
  std::vector<int>		m_players; /**< players vector */
  sf::Color			m_color; /**< default color used to reset grass color */
};

#endif /* !CELLR_HH_ */
