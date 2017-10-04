#ifndef GAMEENGINE_HH_
# define GAMEENGINE_HH_

/**
 * @file GameEngine.hh
 * @brief main class for the graphic client (SFML)
 * @author ankirama
 * @version 1.0
 */
# define USAGE	std::string("Usage: ./zappy_graph -p port [-h hostname] [-d]")

# include <string>
# include <SFML/Graphics.hpp>
# include <vector>
# include "Character.hh"
# include "Network.hh"
# include "Parser.hh"
# include "Error.hpp"
# include "Map.hh"
# include "CommandEngine.hh"
# include "TilesIndex.hh"
# include "Font.hh"
# include "HUDVertical.hh"
# include "HUD.hh"
# include "HUDLeft.hh"

class CommandEngine;

/**
 * enum to define mode for HUD
 */
typedef enum	e_modeMove {
  CELL_MODE,
  CHARACTER_MODE
}		modeMove;

/**
 * @class GameEngine
 * @brief main class to update / draw in sfml
 */
class GameEngine {
public:
  /**
   * @brief constructor
   *
   * set default values and parse arguments
   * it will create / call our network class to get commands from server
   *
   * @param argc	: arguments number from main
   * @param argv	: arguments array from main
   */
  explicit GameEngine(int argc, char **argv);

  /**
   * @brief destructor
   *
   * delete all ressources allocated
   */
  ~GameEngine();

public:

  /**
   * @brief init values with specific screen size
   *
   * it will set some sf::View and init network
   *
   * @param windowX	: screen width
   * @param windowY	: screen Height
   */
  void					init(int windowX, int windowY);

  /**
   * @brief create map with width * height cells
   *
   * it will set hudVertical and hudLeft
   *
   * called by msz
   *
   * @param width	: map width
   * @param height	: map height
   */
  void					createMap(int width, int height);

  /**
   * @brief add player in a vector
   *
   * it will add a player and set every informations needed like position
   * it will set every tiles too and set HUD to get information if it's the first player
   *
   * called by pnw
   *
   * @param id		: id sent by the server (equal to fd on the serve)
   * @param x		: x position (in the map)
   * @param y		: y position (in the map)
   * @param orientation	: current orientation
   * @param level	: current level
   * @param team	: team name
   */
  void					addPlayer(int id, int x, int y,
						  int orientation, int level,
						  const std::string &team);

  /**
   * @brief add a team in a vector
   *
   * @param name	: team name
   */
  void					addTeam(const std::string &name);

  /**
   * @brief remove a player from the map
   *
   * it will remove the player in the map AND in the hud
   * it will reset currentPlayer too
   *
   * @param id	: fd we want to remove in our map
   */
  void					removePlayer(int id);

  /**
   * @brief get server time in seconds
   *
   * @return	: server time
   */
  int					getTime() const {return this->m_time;}

  /**
   * @brief set time from server
   *
   * sgt command
   *
   * used in hudLeft
   *
   * @param time	: used to set hudLeft time and gameEngine time
   */
  void					setTime(int time) {
    if (this->m_hudLeft != 0) {
      this->m_time = time;
      this->m_hudLeft->setTime(time);
    }
  }

  /**
   * @brief set win boolean
   *
   * @param value	: value used to set boolean
   */
  void					setWin(bool value);

  /**
   * @brief set team name winner
   *
   * @param name	: team name to display as winner
   */
  void					setWinner(const std::string &name);

  /**
   * @brief get a player by its id
   *
   * @param id	: used to find the player
   * @return	: player found in the map
   */
  Character				&getPlayer(int id);

  /**
   * @brief get loaded boolean
   *
   * used to check if we loaded the map and cells
   *
   * @return	: loaded boolean value
   */
  bool					isLoaded();

  /**
   * @brief get map width
   *
   * @return	: map width
   */
  int					getWidth() const;

  /**
   * @brief get map height
   *
   * @return	: map height
   */
  int					getHeight() const;

  /**
   * @brief get map
   *
   * @return	: map reference
   */
  Map					&getMap() const;

  /**
   * @brief get hudLeft (map infos hud)
   *
   * @return	: hudLeft
   */
  HUDLeft				&getHudLeft() const;

  /**
   * @brief set loaded boolean to check if the map / cell are loaded
   *
   * @param value	: true -> map / cells loaded else false
   */
  void					setLoaded(bool value);

  /**
   * @brief main function it calls update / draw functions
   */
  void					game();

private:
  int					m_windowX; /**< screen width */
  int					m_windowY; /**< screen height */
  Network				*m_network; /**< network pointer used to communicate with server */
  TilesIndex				*m_tiles; /**< tiles index with all textures and tiles */
  CommandEngine				*m_cmdEngine; /**< class used to parse server cmd and exec action */
  sf::RenderWindow			*m_window; /**< pointer to render on the screen (SFML) */
  sf::Clock				*m_clock; /**< clock SFML */
  sf::Sprite				*m_loading; /**< background loading sprite */
  sf::Sprite				*m_winBack; /**< background winner sprite */
  sf::View				m_view; /**< main view to display map / characters / eggs etc... (dynamic) */
  sf::View				m_hudView; /**< HUD view (static) */
  bool					m_mousePressed; /**< boolean to set if mouse is pressed (true) or released (false) */
  sf::Vector2i				m_positionMouse; /**< set mouse position to move m_view */
  Font					*m_font; /**< text used to display winner */
  bool					m_textLoaded; /**< used to update only once m_font */
  float					m_zoom; /**< zoom m_view */
  std::map<int, Character *>		m_players; /**< players map with fd as key and Character as value */
  std::vector<std::string>		m_teams; /**< teams name vector */
  Map					*m_map; /**< map pointer to display every cells */
  int					m_width; /**< map width */
  int					m_height; /**< map height */
  bool					m_loaded; /**< boolean to display loading background or the game */
  bool					m_win; /**< boolean to display winner background or the game */
  std::string				m_winner; /**< winner team name */
  HUDVertical				*m_hudVertical; /**< hudVertical (right) class to get cell infos */
  HUD					*m_hud; /**< hud (bot) class to get character infos */
  HUDLeft				*m_hudLeft; /**< hudLeft (left) to get map infos */
  modeMove				m_modeMove; /**< set CELL_MODE or CHARACTER_MODE for m_hud */
  std::map<int, Character *>::iterator	m_currentPlayer; /**< iterator on current player used by m_hud */
  bool					m_playerSet; /**< used to set first m_currentPlayer (if false) else do nothing */
  int					m_time; /**< server time */

private:
  /**
   * @brief main function to check events
   *
   * it will check every event to do something
   */
  void					inputKey();

  /**
   * @brief check mouse events
   *
   * It will allow to move m_view and zoom
   *
   * @param event	: event to check
   * @return		: false if event isn't a mouse event else true
   */
  bool					inputMouse(sf::Event event);

  /**
   * @brief check keys events
   *
   * it will check direction keys, escape and return keys
   *
   * @param event	: event to check
   */
  void					inputKeys(sf::Event event);

  /**
   * @brief update function
   *
   * it will check events and check current type (boolean)
   * to update some variables like hud and call CommandEngine
   */
  void					update();

  /**
   * @brief draw function
   *
   * It will draw every thing needed with specific boolean
   * 3 modes :
   * loading (only background)
   * game (draw 3 huds, map and all players / eggs / etc)
   * winner (background and text)
   */
  void					draw();
};

#endif /* !GAMEENGINE_HH_ */
