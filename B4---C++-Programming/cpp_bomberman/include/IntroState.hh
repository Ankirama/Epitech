#ifndef INTROSTATE_HH_
# define INTROSTATE_HH_

/**
 * @file IntroState.hh
 * @brief First state of the bomberman
 * @author doT
 * @version 1.0
 */

# define  HEAD_IMG	{std::string(IMG_PATH) + std::string("head.tga")}
# define  BACK_PAUSE	{std::string(IMG_PATH) + std::string("background/") + std::string("pause_background.tga")}
# define  BACK_NAME	{std::string(IMG_PATH) + std::string("texture/") + std::string("sauvegarde.tga")}

# include "IGameState.hh"
# include "Button.hh"
# include "Error.hpp"
# include "GenerateText.hh"
# include <map>

/**
 * @class IntroState
 * @brief First state of the bomberman
 *
 * Function for display the state and manage the state
 */

class IntroState : public IGameState {
public:
  /**
   * @brief Init the state
   *
   * Load the background, and other image off the state
   *
   * @param The GameEngine, motor of the game
   */
  void	Init(GameEngine *);
  /**
   * @brief Cleanup the state
   *
   * Clean the state, but don't delete his element.
   */
  void	Cleanup();
  /**
   * @brief Pause
   */
  void	Pause();
  /**
   * @brief Resume
   *
   * Resume the state after pause
   *
   * @param The GameEngine, motor of the game
   */
  void	Resume(GameEngine *);

  /**
   * @brief Update
   *
   * Alias HandleEvent, it's catch the key frol the keyboard
   *
   * @param The GameEngine, motor of the game
   */
  void	Update(GameEngine *);
  /**
   * @brief Draw the state
   *
   * Draw background, button...
   */
  void	Draw(GameEngine *);

  /**
   * @brief Key Up
   *
   * @param The GameEngine, motor of the game
   */
  void	Up(GameEngine *);
  /**
   * @brief Key Down
   *
   * @param The GameEngine, motor of the game
   */
  void	Down(GameEngine *);
  /**
   * @brief Key Enter
   *
   * @param The GameEngine, motor of the game
   */
  void	Enter(GameEngine *);
  /**
   * @brief Key Escape
   *
   * @param The GameEngine, motor of the game
   */
  void	Quit(GameEngine *);
  /**
   * @brief Key Left
   *
   * @param The GameEngine, motor of the game
   */
  void	Left(GameEngine *);
  /**
   * @brief Key Right
   *
   * @param The GameEngine, motor of the game
   */
  void	Right(GameEngine *);
  /**
   * @brief Key A
   *
   * @param The GameEngine, motor of the game
   */
  void	keyA(GameEngine *);
  /**
   * @brief Key B
   *
   * @param The GameEngine, motor of the game
   */
  void	keyB(GameEngine *);

  /**
   * @brief Effect of the function style
   *
   * @param The GameEngine, motor of the game
   * @param Int position
   * @param An iterator to the button
   */
  void	styleDraw(GameEngine *, int, std::vector<Button *>::iterator);
  /**
   * @brief Do an effect when we push a button
   *
   * @param The GameEngine, motor of the game
   */
  void	Style(GameEngine *);

  /**
   * @brief For change a key, from the map of key
   *
   * @param The old key
   * @param The new key
   */
  void	modKey(const int, const int);

  /**
   * @brief get the iterator button
   */
  std::vector<Button *>::iterator	&getIterator();
  /**
   * @brief get the vector button
   */
  std::vector<Button *>			&getVector();
  /**
   * @brief set the booleen m_released
   *
   * @param New etat of m_released
   */
  void					setReleased(bool);

  /**
   * @brief Singleton of Introstate
   */
  static IntroState*	Instance() {
    try {
    return &m_IntroState;
    } catch (ErrorBomberman const &e) {
      throw ErrorBomberman(e.what(), "IntroState");
    }
  }

  /**
   * @brief Choose the right action to do
   */
  enum	e_State {
    PLAY,
    LOAD,
    SCORE,
    OPTION,
    QUIT
  };

private:
  IntroState();
  ~IntroState();

private:
  typedef void		(IntroState::*m_tabFun)(GameEngine *);
  /**
   * @brief add a key to the map
   *
   * @param Key
   * @param Function associate to the key
   */
  void			addKey(const int, m_tabFun);
  /**
   * @brief del a key to the map
   *
   * @param Key to delete
   */
  void			delKey(const int);
  /**
   * @brief del all the key of the map
   */
  void			delAllKey();

private:
  static IntroState			m_IntroState; /**<Instance of introstate*/
  std::map<int, m_tabFun>		m_map; /**<Map of key*/
  std::vector<Button *>::iterator	m_it; /**<Iterator of the vector Button*/
  std::vector<Button *>			m_button; /**<Vector Button*/
  std::vector<std::string>		m_easter; /**<Vector EasterEgg*/
  std::vector<std::string>::iterator   	m_easterIt; /**<Iterator of the vector EasterEgg*/
  Object2D				*m_background; /**<The background of the state*/
  Object2D				*m_bomb_left; /**<The image bomb(between a button)*/
  bool					m_released; /**<The booleen for the map of key*/
};

#endif
