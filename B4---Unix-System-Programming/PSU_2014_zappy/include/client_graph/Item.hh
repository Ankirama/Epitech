#ifndef ITEM_HH_
# define ITEM_HH_

/**
 * @file Item.hh
 * @brief item like food / stone
 */

#include <vector>
#include <string>
#include "Tile.hh"

/**
 * @class Item
 * @brief class to create / display specific item like stone or food
 */
class	Item {
public:
  /**
   * @brief default constructor --> unused
   */
  Item() {}

  /**
   * @brief constructor
   *
   * it will set x / y position (isometric mode) and quantity / tile
   *
   * @param x		: basic x position. It will be converted to isometric
   * @param y		: basic y position. It will be converted to isometric
   * @param itemTile	: item tile
   */
  Item(int x, int y, Tile *itemTile);

  /**
   * @brief destructor
   *
   * delete tile
   */
  ~Item();

  /**
   * @brief set item quantity
   *
   * @param quantity	: used to set our item quantity
   */
  void	setQuantity(unsigned int quantity);

  /**
   * @brief get item quantity
   *
   * @return	: item quantity
   */
  unsigned int	getQuantity() const;

  /**
   * @brief draw tile
   *
   * It will draw our tile if quantity > 0
   *
   * @param window	: renderWindow to render our tile
   */
  void draw(sf::RenderWindow *window);
private:
  int		m_x; /**< x position (isometric position) */
  int		m_y; /**< y position (isometric mode) */
  Tile		*m_itemTile; /**< item tile */
  unsigned int	m_quantity; /**< item quantity */
};

#endif /* !ITEM_HH_ */
