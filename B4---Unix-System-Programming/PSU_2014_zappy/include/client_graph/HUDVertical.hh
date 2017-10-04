#ifndef HUDVERTICAL_HH_
# define HUDVERTICAL_HH_

/**
 * @file HUDVertical.hh
 * @brief hud on right used to display current cell informations
 * @author ankirama
 * @version 1.0
 */

# include <SFML/Graphics.hpp>
# include <vector>
# include "Tile.hh"
# include "Font.hh"
# include "CellR.hh"

/**
 * @class HUDVertical
 * @brief display current cell informations on the right
 */
class HUDVertical {
public:

  /**
   * @brief constructor
   *
   * it will set default values and texts
   *
   * @param winX	: screen width
   * @param winY	: unused parameter (scree height)
   * @param tile	: background tile
   * @param cell	: default CellR (position 0)
   */
  HUDVertical(int winX, int winY, Tile *tile, CellR &cell);

  /**
   * @brief destructor
   *
   * delete tiles
   */
  ~HUDVertical();

  /**
   * @brief set current cell to get informations about it
   *
   * @param cell	: cell we will used to get informations
   */
  void		setCell(CellR &cell) {this->m_cell = &cell;}

  /**
   * @brief update cell information in hud
   */
  void		update();

  /**
   * @brief draw texts and background
   *
   * @param window	: renderWindow used to render texts and background
   */
  void		draw(sf::RenderWindow *window);
private:

  /**
   * @brief default constructor -> unused
   */
  HUDVertical();

private:
  Tile			*m_tile; /**< background tile */
  std::vector<Font *>	m_fonts; /**< texts vector to get cell informations */
  CellR			*m_cell; /**< current cell to update texts */
};

#endif /* !HUDVERTICAL_HH_ */
