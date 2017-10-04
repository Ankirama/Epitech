#ifndef HUD_HH_
# define HUD_HH_

/**
 * @file HUD.hh
 * @brief hud on the bottom
 * @author ankirama
 * @version 1.0
 */

# include <SFML/Graphics.hpp>
# include <vector>
# include "Tile.hh"
# include "Font.hh"
# include "Character.hh"
# include "CellR.hh"

/**
 * @class HUD
 * @brief HUD class used to display bottom hud
 */
class HUD {
public:

  /**
   * @brief constructor
   *
   * It will set default values like screen size, texts and Tiles
   *
   * @param winX	: screen width
   * @param winY	: screen height
   * @para hud		: hud Tile used to display our hud
   */
  HUD(int winX, int winY, Tile *hud);

  /**
   * @brief destructor
   *
   * delete Tile
   */
  ~HUD();

  /**
   * @brief set player information
   *
   * It will allow us to get our current character inventory, life etc..
   * It will set mode to CHARACTER_MODE and boolean to true (to check if we have a player)
   *
   * @param character	: character on pointer
   */
  void	setPlayer(Character *character) { this->m_playerSet = true; this->m_mode = 1; this->m_character = character;}

  /**
   * @brief remove a player (just set boolean to false)
   */
  void	removePlayer() {this->m_playerSet = false;}

  /**
   * @brief set specific mode
   *
   * 0 -> CELL_MODE
   * 1 -> CHARACTER_MODE
   *
   * @param mode	: set our mode (used to display "CELL MODE" or "CHARACTER MODE")
   */
  void	setMode(int mode) {this->m_mode = mode;}

  /**
   * @brief update fonction to set texts
   *
   * It will check our mode and set texts / information about current player
   */
  void	update();

  /**
   * @brief draw our text / hud on the screen
   *
   * @param window	: renderWindow to render texts
   */
  void	draw(sf::RenderWindow *window);

private:
  Tile			*m_hud; /**< hud Tile, the background */
  int			m_winX; /**< screen width */
  int			m_winY; /**< screen height */
  int			m_mode; /**< specific mode: 0 -> CELL, 1 -> CHARACTER */
  bool			m_playerSet; /**< boolean to check if we have a current player or not */
  Character		*m_character; /**< our current character used to display his infos */
  std::vector<Font *>	m_fonts; /**< fonts vector with every information about player */
};

#endif /* !HUD_HH_ */
