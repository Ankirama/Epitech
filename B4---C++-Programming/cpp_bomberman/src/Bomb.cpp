# include "Bomb.hh"
# include <thread>
# include <chrono>
#include <unistd.h>

Bomb::Bomb(unsigned int position, unsigned int) : m_position(position), m_range(1), m_state(BEFORE_EXPLOSION){
  this->m_animation = new Animation(glm::vec3(0, 0, 0),
				    glm::vec3(90, 0, 0),
				    glm::vec3(0.0030, 0.0030, 0.0030),
				    std::string("ressources/animation/bomb.fbx"));

  if (this->m_texture.load("ressources/animation/lave.tga") == false)
    std::cout << "Cannot load lave.tga !" << std::endl;
  this->m_fire	= new Animation(glm::vec3(0, 0, 0),
				glm::vec3(90, 0, 0),
				glm::vec3(0.0030, 0.0030, 0.0030),
				std::string("ressources/animation/fire.dae"));
}

Bomb::~Bomb()	{
  if (this->m_animation != NULL)
    delete this->m_animation;
  if (this->m_fire != NULL)
    delete this->m_fire;
}

Animation	*Bomb::getAnimation() const	{
  return (this->m_animation);
}

unsigned int	Bomb::getPosition() const {
  return (this->m_position);
}

unsigned int	Bomb::getDelay() const {
  return (this->m_delay);
}

unsigned int	Bomb::getRange() const {
  return (this->m_range);
}

void		Bomb::setPosition(unsigned int position) {
  this->m_position = position;
}

void		Bomb::setDelay(unsigned int delay) {
  this->m_delay = delay;
}

void		Bomb::setRange(unsigned int range) {
  this->m_range = range;
}

void		Bomb::upRange() {
  this->m_range += 1;
}

void		Bomb::downRange() {
  this->m_range -= 1;
  if (this->m_range <= 0)
    this->m_range = 1;
}

void		Bomb::setTexturePath(std::string const &path){
  this->m_animation->setPath(path);
}

void	Bomb::initialize() {
  try {
    this->m_animation->initialize();
    this->m_fire->initialize();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "Bomb");
  }
}

void	Bomb::draw(gdl::AShader &shader, gdl::Clock const &clock)  {
  if (this->m_state == BEFORE_EXPLOSION)
    this->m_animation->draw(shader, clock);
  else if (this->m_state == AFTER_EXPLOSION) {
    std::list<glm::vec3>::iterator	it = this->m_flams.begin();
    while (it != this->m_flams.end()) {
      this->m_fire->translate((*it));
      this->m_fire->draw(shader, clock);
      this->m_fire->setPosition(glm::vec3(0, 0, 0));
      it++;
    }
    this->m_state = TODELETE;
  }
}

void	Bomb::update(gdl::Clock, Maze &maze) {
  if (this->m_state == BEFORE_EXPLOSION)
    this->m_time = this->m_time + 1;
  if (this->m_time >= 80 && this->m_state == BEFORE_EXPLOSION)
    {
      this->m_state = AFTER_EXPLOSION;
      this->destroy(maze);
    }
}

void	Bomb::spawn(Maze &maze, gdl::Clock &clock) {
  int	x;
  int	y;
  float	anim_x;
  float	anim_y;

  this->m_time = 0;
  maze.setCase(this->m_position, ID_PLAYER_BOMB);
  x = this->m_position % maze.getWidth();
  y = this->m_position / maze.getHeight();
  anim_x = maze.getWidth() / 2 - x;
  anim_y = maze.getHeight() / 2 - y;
  this->m_plant = clock.getElapsed();
  this->m_state = BEFORE_EXPLOSION;
  this->m_animation->translate(glm::vec3(anim_x, anim_y, 2 * CASE));
}

void	Bomb::spawn_flams(int position, int width,int height) {
  int x;
  int y;

  x = position % width;
  y = position / width;
  float   coord_x = width / 2 - x;
  float   coord_y = height / 2 - y;
  this->m_flams.push_back(glm::vec3(coord_x, coord_y, 2 * CASE));
}

bool	Bomb::deleteNegative(Maze &map, int position, bool destroy) {
  if (position > 0 && destroy == true) {
    if (map.getMaze()[position] == ID_WALL)
      return false;
    else {
      map.setCase(position, ID_EMPTY);
      this->spawn_flams(position, map.getWidth(), map.getHeight());
      map.setDraw(true);
    }
  }
  return true;
}

bool	Bomb::deletePositive(Maze &map, int position, bool destroy) {
  if (position < map.getWidth() * map.getHeight() && destroy == true) {
    if (map.getMaze()[position] == ID_WALL)
      return false;
    else {
      map.setCase(position, ID_EMPTY);
      this->spawn_flams(position, map.getWidth(), map.getHeight());
      map.setDraw(true);
    }
  }
  return true;
}

void	Bomb::destroy(Maze &map)
{
  bool	destroy_right = true;
  bool	destroy_left = true;
  bool	destroy_up = true;
  bool	destroy_down = true;

  for (int i = 0; i <= this->m_range; i++)
    {
      destroy_left = this->deletePositive(map, this->m_position + i, destroy_left);
      destroy_right = this->deleteNegative(map, this->m_position - i, destroy_right);
      destroy_up = this->deleteNegative(map, this->m_position - i * map.getWidth(), destroy_up);
      destroy_down = this->deletePositive(map, this->m_position + i * map.getWidth(), destroy_down);
    }
}
