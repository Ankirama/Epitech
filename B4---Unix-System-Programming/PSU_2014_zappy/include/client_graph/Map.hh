//
// Map.hh for  in /home/tang_i/rendu/PSU_2014_zappy/annexes/sfml2d
//
// Made by David Tang
// Login   <tang_i@epitech.net>
//
// Started on  Wed Jun 24 18:25:59 2015 David Tang
// Last update Sun Jul  5 20:41:21 2015 David Tang
//

#ifndef MAP_HH_
# define MAP_HH_

/**
 * @file Map.hh
 * @brief map class informations like cells etc
 */

# include <vector>
# include "Tile.hh"
# include "CellR.hh"
# include "TilesIndex.hh"

/**
 * @class Map
 * @brief used to draw the map with every cell and store infos about ghosts/eggs
 */
class				Map {
public:

  /**
   * @brief constructor
   *
   * set defaults values and call initMap function
   *
   * @param width	: map width (like 10)
   * @param height	: map height (like 10)
   * @param tilesIndex	: TilesIndex with all index to create new Tiles like grass
   * @param winX	: screen width (like 1280)
   * @param winY	: screen height (like 720)
   */
  Map(int width, int height, TilesIndex *tilesIndex, int winX, int winY);

  /**
   * @brief destructor
   */
  ~Map();

public:

  /**
   * @brief init map and create cells (width * height cells)
   */
  void				initMap();

  /**
   * @brief draw every cells
   *
   * @param window	: renderWindow used to draw every cell
   */
  void				draw(sf::RenderWindow *window);

  /**
   * @brief get map height
   *
   * @return	: map height
   */
  int				getHeight() const;

  /**
   * @brief get map width
   *
   * @return	: map width
   */
  int			        getWidth() const;

  /**
   * @brief set cell's item with specific quantity
   *
   * @param pos		: find cell with position in vector (pos = x + y * width)
   * @param item	: item id like ID_MEAT
   * @param quantity	: quantity we will use to set item
   */
  void				setItem(int pos, int item, unsigned int quantity);

  /**
   * @brief set cell's item with specific quantity
   *
   * @param x		: x position (normal mode to travel in map)
   * @param y		: y position (normal mode to travel in map)
   * @param item	: item id like ID_MEAT
   * @param quantity	: quantity we will use to set item
   */
  void				setItem(int x, int y, int item, unsigned int quantity);

  /**
   * @brief get cell
   *
   * @param x	: x position
   * @param y	: y position
   * @return	: specific cell
   */
  CellR				&getCell(int x, int y) const;

  /**
   * @brief get cell
   *
   * @param pos	: position of our cell (x + y * width)
   * @return	: specific cell
   */
  CellR				&getCell(int pos) const;

  /**
   * @brief add an egg in map and in the cell
   *
   * it will call CellR::setQuantityEgg function
   *
   * @param x	: x position
   * @param y	: y position
   * @param id	: egg id
   */
  void				addEgg(int x, int y, int id);

  /**
   * @brief add an egg in map and in the cell
   *
   * it will call CellR::setQuantityEgg function
   *
   * @param pos	: egg position (pos = x + y * width)
   * @param id	: egg id
   */
  void				addEgg(int pos, int id);

  /**
   * @brief remove an egg in map and in the cell
   *
   * it will call CellR::setQuantityEgg function
   * it will call Map::addGhost to add a ghost
   *
   * @param id	: egg id
   */
  void				removeEgg(int id);

  /**
   * @brief add a ghost in map and in the cell
   *
   * it will call CellR::setQuantityGhost
   *
   * @param x	: x position (ghost)
   * @param y	: y position (ghost)
   * @param id	: ghost id
   */
  void				addGhost(int x, int y, int id);

  /**
   * @brief add a ghost in map and in the cell
   *
   * it will call CellR::setQuantityGhost
   *
   * @param pos	: position (ghost) (x + y * width)
   * @param id	: ghost id
   */
  void				addGhost(int pos, int id);

  /**
   * @brief remove a ghost in map and in the cell where the id is
   *
   * it will call CellR::setQuantityGhost
   *
   * @param id	: ghost id to remove in map and cell
   */
  void				removeGhost(int id);

  /**
   * @brief return currentCell
   *
   * Used for HUDVertical and to color the cell
   *
   * @return	: current cell
   */
  CellR				&getCurrentCell() const;

  /**
   * @brief change current_cell with move
   *
   * it will reset current cell color
   * 4 moves:
   * 1 -> RIGHT
   * -1 -> LEFT
   * width -> DOWN
   * -width -> UP
   * calcul to update new position and change color
   *
   * @param move	: described below (specific move like up, left etc)
   */
  void				setNextCell(int move);

  /**
   * @brief change current_cell with new position
   *
   * it will reset current cell color and set the new current cell + color
   *
   * @param newCell	: new position Cell (= x + y * width)
   */
  void				setCurrentCell(int newCell);

private:
  int				m_height; /**< map height */
  int				m_width; /**< map width */
  TilesIndex			*m_tilesIndex; /**< tiles index with all tiles used to create new tiles (grass etc..)*/
  int				m_winX; /**< screen width */
  int				m_winY; /**< screen height */
  std::vector<CellR *>		m_cells; /**< cells vector equal to width * height */
  std::map<int, int>		m_eggs; /**< eggs map with id as key and position as value */
  std::map<int, int>		m_ghosts; /**< ghosts map with id as key and position as value */
  int				m_currentCell; /**< current position cell used to get information (hudVertical) */
  sf::Color			m_selectedCell; /**< color for selected cell */
};

#endif /* !MAP_HH_ */
