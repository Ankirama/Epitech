#ifndef CPP_ACHARACTER_HH
# define CPP_ACHARACTER_HH

/**
 * @file ACharacter.hh
 * @brief abstract class character
 * @author viterb_c
 * @version 1.1
 */

# include <string>
# include <vector>
# include <list>

# include "Maze.hh"
# include "Bomb.hh"
# include "Animation.hh"
# include "Score.hh"
# include "GenerateMaze.hh"
# include "Error.hpp"
# include "GameEngine.hh"
# include "GenerateMaze.hh"

# define MARVIN "ressources/animation/marvin.fbx"

enum	eDirection
  {
    RIGHT,
    LEFT,
    UP,
    DOWN
  };

enum    eActions
  {
    MOVE_RIGHT,
    MOVE_LEFT,
    MOVE_UP,
    MOVE_DOWN,
    PLANT_BOMB
  };

class	ACharacter	{
protected:
  std::string const	m_type;
  unsigned int		m_position;
  bool			m_alive;
  eDirection		m_direction;
  bool			m_tomove;
  unsigned int		m_max_bomb;
  unsigned int		m_range_bomb;
  float			m_speed;
  std::list<Bomb *>	m_bomb;
  unsigned int		m_score;
  Animation		*m_animation;
  float			m_camera_x;
  float			m_camera_y;


public:
  // Constructor
  ACharacter(std::string const &, unsigned int);

  // Destructor
  virtual ~ACharacter()	{
  }

  // Getter
  std::string const& 	getType() const		{ return this->m_type; }
  bool			getState() const	{ return this->m_alive; }
  eDirection		getDirection() const	{ return this->m_direction; }
  std::list<Bomb *>	&getBombs()		{ return this->m_bomb; }
  Animation&		getAnimation() const	{ return *this->m_animation; }
  unsigned int		getMaxBombs() const	{ return this->m_max_bomb; }
  unsigned int		getRangeBomb() const	{ return this->m_range_bomb; }
  unsigned int		getPosition() const	{ return this->m_position; }
  unsigned int		getScore() const	{ return this->m_score; }
  float			getSpeed() const	{ return this->m_speed; }
  std::string		getTexturePath() const	{ return this->m_animation->getTexturePath(); }
  float			getCameraX() const	{ return this->m_camera_x; }
  float			getCameraY() const	{ return this->m_camera_y; }

  // Setter
  void	setState(bool alive)		{ this->m_alive = alive; }
  void	setDirection(eDirection direction){ this->m_direction = direction; }
  void	setBombs(std::list<Bomb *> vector_b) { this->m_bomb = vector_b; }
  void	pushBomb(Bomb *bomb)			{ this->m_bomb.push_back(bomb); }
  void	setSpeed(float speed)			{ this->m_speed = speed; }
  void	setAnimation(Animation *Animation)	{ this->m_animation = Animation; }
  void	setTexturePath(std::string const & texturepath)	{ this->m_animation->setPath(texturepath); }
  void	setMaxBombs(unsigned int max_bomb)	{ this->m_max_bomb = max_bomb; }
  void	setRangeBomb(unsigned int range_bomb)	{ this->m_range_bomb = range_bomb; }
  // Set position animation
  void	setPosition(unsigned int position)	{ this->m_position = position; }
  void	setCamera(float, float);

  virtual void	IsAlive(Maze &);
  virtual bool	collision(char *, unsigned int) const;
  virtual bool	move(char *, unsigned int);
  virtual void	initialize();
  virtual void	draw(gdl::AShader &, gdl::Clock const &);
  virtual void	plantBomb(Maze &, gdl::Clock &);

  virtual void	update(GameEngine *, Maze &) = 0;

private:
  ACharacter();
  ACharacter(ACharacter const &);
  ACharacter	&operator=(ACharacter const &);

};

#endif /* !CPP_ACHARACTER_HH */
