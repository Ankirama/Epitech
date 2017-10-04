#ifndef HUDLEFT_HH_
# define HUDLEFT_HH_

/**
 * @file HUDLeft.hh
 * @brief hud on the left, used to display map's informations
 * @author ankirama
 * @version 1.00
 */

# include <SFML/Graphics.hpp>
# include <vector>
# include "Tile.hh"
# include "Font.hh"
# include "Map.hh"

/**
 * @class HUDLeft
 * @brief display / set left hud (map hud)
 */
class	HUDLeft {
public:

  /**
   * @brief constructor
   *
   * It will set texts vector, some variables like time, nb_teams etc
   *
   * @param winX	: unused parameter (screen width)
   * @param winY	: unused parameter (screen height)
   * @param tile	: background tile (hud tile)
   */
  HUDLeft(int winX, int winY, Tile *tile);

  /**
   * @brief destructor
   *
   * delete Tiles
   */
  ~HUDLeft();

  /**
   * @brief set server time (sgt command)
   *
   * @param time	: set our m_time to time
   */
  void	setTime(int time);

  /**
   * @brief increase teams number by one
   */
  void	addTeam();

  /**
   * @brief set cells number
   *
   * @param cells	: used to set our map size
   */
  void	setCells(int cells);

  /**
   * @brief increase players number by one
   */
  void	addPlayer();

  /**
   * @brief decrease players number by one
   */
  void	removePlayer();

  /**
   * @brief increase eggs number by one
   */
  void	addEgg();

  /**
   * @brief decrease eggs number by one
   */
  void	removeEgg();

  /**
   * @brief increase ghosts number by one
   */
  void	addGhost();

  /**
   * @brief decrease ghosts number by one
   */
  void	removeGhost();

  /**
   * @brief update our texts with new informations
   */
  void	update();

  /**
   * @brief draw our texts / background in the scren
   *
   * @param window	: renderWindow used to render our texts and background
   */
  void	draw(sf::RenderWindow *window);

private:
  std::vector<Font *>		m_fonts; /**< texts vector with map informations */
  Tile				*m_tile; /**< background Tile */
  int				m_nb_teams; /**< teams number */
  int				m_size; /**< cells number (width * heigth) */
  int				m_time; /**< time server */
  int				m_nb_players; /**< players number */
  int				m_nb_eggs; /**< eggs number */
  int				m_nb_ghosts; /**< ghosts number */
};

#endif /* !HUDLEFT_HH_ */
