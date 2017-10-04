#ifndef CPP_BOMB_HH
# define CPP_BOMB_HH

# include "Animation.hh"
# include "GenerateMaze.hh"
# include "Maze.hh"
# include "GameEngine.hh"
# include "Error.hpp"

enum	eBombState
  {
    BEFORE_EXPLOSION,
    AFTER_EXPLOSION,
    TODELETE
  };

class Bomb
{
private:
  int			m_position;
  int			m_delay;
  int			m_range;
  eBombState		m_state;
  float			m_plant;
  Animation		*m_animation;
  gdl::Texture		m_texture;
  Animation		*m_fire;
  int			m_time;
  std::list<glm::vec3>	m_flams;

private:
  Bomb();

public:
  // Constructor
  Bomb(unsigned int,  unsigned int range = 3);

  // Destructor
  ~Bomb();

  // Getter
  Animation	*getAnimation() const;
  unsigned int	getPosition() const;
  unsigned int	getDelay() const;
  unsigned int	getRange() const;
  eBombState	getState() { return this->m_state; }
  std::string const& getTexturePath() const {return this->m_animation->getTexturePath();}

  // Setter
  void		setPosition(unsigned int);
  void		setDelay(unsigned int);
  void		setRange(unsigned int);
  void		setState(eBombState state) { this->m_state = state; }

  void		upRange();
  void		downRange();
  void		setTexturePath(std::string const &);

  void		initialize();
  void		draw(gdl::AShader &, gdl::Clock const &);

  void		spawn(Maze &, gdl::Clock &);
  void		spawn_flams(int, int, int);
  void		update(gdl::Clock, Maze &);
  void		destroy(Maze &);

  bool		deleteNegative(Maze &, int, bool);
  bool		deletePositive(Maze &, int, bool);

};

#endif /* !CPP_BOMB_HH */
