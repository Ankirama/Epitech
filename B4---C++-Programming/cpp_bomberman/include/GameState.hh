//
// GameState.hh for  in /home/teyssa_r/rendu/cpp_bomberman
// 
// Made by Raphael Teyssandier
// Login   <teyssa_r@epitech.net>
// 
// Started on  Tue May 12 18:30:07 2015 Raphael Teyssandier
// Last update Sun Jun 14 20:59:13 2015 CHARLES VITERBO
//

#ifndef GAMESTATE_H
# define GAMESTATE_H

# include "Maze.hh"
# include "IGameState.hh"
# include "Object2D.hh"
# include "GenerateMaze.hh"
# include "ACharacter.hh"
# include "IA.hh"
# include "Camera.hh"

# define DEFAULT_SIZE	15
# define TEXTURE_BACKGROUND "ressources/img/background/pause_background.tga"
# define TEXT_VICTORY "ressources/img/background/win.tga"
# define TEXT_GAMEOVER "ressources/img/background/loose.tga"
# define MARVIN	"ressources/animation/marvin.fbx"

enum	eGameCondition
  {
    IN_PROGRESS,
    GAME_OVER,
    VICTORY
  };

class GameState : public IGameState {
public:
  void	Init(GameEngine *);
  void	initNewGame();
  void	Cleanup();
  void	Pause();
  void	Resume(GameEngine *);

  void	Update(GameEngine *);
  void	Draw(GameEngine *);

  void	ChangeState(GameEngine *);
  void	Quit(GameEngine *);

  void	modKey(const int oldKey, const int newKey);

  static GameState*	Instance() {
    return &m_GameState;
  }

  // setter
  void	setName1(std::string const &name) { this->m_name1 = name; }
  void	setName2(std::string const &name) { this->m_name2 = name; }
  void	setWidth(int width) { this->m_width = width; }
  void	setHeight(int height) { this->m_height = height; }
  void	setNbrAI(int nbr) { this->m_nbrAI = nbr; }
  void	setDifficulty(int difficulty) { this->m_difficulty = difficulty; }
  void	setMode(bool solo) { this->m_solo = solo; }
  void	setPlayers(std::vector<ACharacter *> players) { this->m_characters = players; }
  void	setMaze(Maze *maze) { this->m_maze = maze; }
  void	setLoad(bool load) { this->m_load= load; }

 // getter
  std::string	getName1(void) const { return this->m_name1; }
  std::string	getName2(void) const { return this->m_name2; }
  int		getWidth(void) const { return this->m_width; }
  int		getHeight(void) const { return this->m_height; }
  int		getNbrAI(void) const { return this->m_nbrAI; }
  int		getDifficulty(void) const { return this->m_difficulty; }
  bool		getMode(void) const { return this->m_solo; }
  std::vector<ACharacter *> &	getPlayers() { return (*this).m_characters; }
  Maze	&	getMaze() const { return *this->m_maze; }
  bool		getLoad() const { return this->m_load; }

  // Spawn
  int	randomSpawn(unsigned int) const;
  void	spawn_character(Maze &, ACharacter *);
  void	check_border(int, Maze &);


  // Backgrounds
  void		initTextures();
  void		gameCondition();
  unsigned int	checkAll();


protected:
  GameState();
  ~GameState();

private:
  typedef void		(GameState::*m_tabFun)(GameEngine *);
  void	addKey(const int key, m_tabFun);
  void	delKey(const int key);
  void	delAllKey();

private:
  static GameState		m_GameState;
  gdl::Clock			m_clock;
  bool				m_released;
  std::map<int, m_tabFun>	m_map;

  bool				m_load;
  Object2D			*m_background;
  Object2D			*m_victory;
  Object2D			*m_gameover;
  Maze				*m_maze;
  std::vector<ACharacter *>	m_characters;
  Camera			*m_camera;
  eGameCondition		m_condition;

  // Value to initialize
  bool		m_solo;
  std::string	m_name1;
  std::string	m_name2;
  int		m_width;
  int		m_height;
  int		m_nbrAI;
  int		m_difficulty;
};

#endif
