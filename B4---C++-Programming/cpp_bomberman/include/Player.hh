#ifndef CPP_PLAYER_HH
# define CPP_PLAYER_HH

/**
 * @file ACharacter.hh
 * @brief a human player
 * @author viterb_c
 * @version 1.1
 */


# include "ACharacter.hh"
# include "Error.hpp"
# include "GameEngine.hh"
# include "Bomb.hh"
# include "Maze.hh"
# include "Camera.hh"

class Player : public ACharacter	{
private:
  typedef void	(Player::*m_tabFun)(Maze &, gdl::Clock &);
  std::string			m_name;
  std::map<int, m_tabFun>	m_input;
  bool				m_released;
  bool				m_first;
  unsigned int			m_score;

public:
  // Getter
  int	getKeyRight() const;
  int	getKeyLeft() const;
  int	getKeyUp() const;
  int	getKeyDown() const;
  int	getKeyBomb() const;
  int	getScore() const { return this->m_score; }
  std::string	getName() const { return this->m_name; }

  // Setter
  void	setKeyRight(int);
  void	setKeyLeft(int);
  void	setKeyUp(int);
  void	setKeyDown(int);
  void	setKeyBomb(int);
  void	setScore(unsigned int score) { this->m_score = score; }

  // Score functions
  void	increaseScore() { this->m_score = this->m_score + 100; }

  // Constructor
  Player(std::string const &, unsigned int position, bool first = true);

  // Destructor
  ~Player();

  // Key functions
  void	addKey(const int key, m_tabFun);
  void	delKey(const int key);
  void	delAllKey();

  void	MoveRight(Maze &, gdl::Clock &);
  void	MoveLeft(Maze &, gdl::Clock &);
  void	MoveUp(Maze &, gdl::Clock &);
  void	MoveDown(Maze &, gdl::Clock &);
  void	Plant(Maze &, gdl::Clock &);

  virtual void	update(GameEngine *, Maze &);
};

#endif /* !CPP_PLAYER_HH */
