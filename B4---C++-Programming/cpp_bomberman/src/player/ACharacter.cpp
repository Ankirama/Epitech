#include "ACharacter.hh"

// Constructor
ACharacter::ACharacter(std::string const &type, unsigned int position) :
  m_type(type), m_position(position),
  m_alive(true), m_direction(RIGHT),
  m_tomove(false), m_max_bomb(1),
  m_range_bomb(1), m_animation(NULL) {
  this->setAnimation(new Animation(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(90.0f, 0.0f, 0.0f),
				   glm::vec3(0.0015f, 0.0015f, 0.0015f), MARVIN));
}

bool	ACharacter::collision(char *map_maze, unsigned int width) const	{
  switch (this->m_direction)	{
  case RIGHT:
    if (map_maze[this->m_position - 1] != ID_EMPTY)
      return true;
    break;
  case LEFT:
    if (map_maze[this->m_position + 1] != ID_EMPTY)
      return true;
    break;
  case UP:
    if (map_maze[this->m_position - width] != ID_EMPTY)
      return true;
    break;
  case DOWN:
    if (map_maze[this->m_position + width] != ID_EMPTY)
      return true;
    break;
  }
  return false;
}

void	ACharacter::setCamera(float x, float y) {
  this->m_camera_x = x;
  this->m_camera_y = y;
}

bool    ACharacter::move(char *map_maze, unsigned int width)   {
  if (this->collision(map_maze, width) == false)        {
    map_maze[this->m_position] = (map_maze[this->m_position] == ID_PLAYER) ? ID_EMPTY : ID_BOMB;
    switch (this->m_direction)  {
    case RIGHT:
      this->m_position = this->m_position - 1;
      break;
    case LEFT:
      this->m_position = this->m_position + 1;
      break;
    case UP:
      this->m_position = this->m_position - width;
      break;
    case DOWN:
      this->m_position = this->m_position + width;
      break;
    }
    map_maze[this->m_position] = ID_PLAYER;
    return true;
  }
  return false;
}

void	ACharacter::initialize()	{
  if (this->m_animation != NULL)	{
    try	{
      this->m_animation->initialize();
    }
    catch (ErrorBomberman const &e)	{
      throw ErrorBomberman(e.what(), "ACharacter");
    }
  }
  else
    throw ErrorBomberman("Animation is not set !");
}

void	ACharacter::draw(gdl::AShader &shader, gdl::Clock const &clock) {
  std::list<Bomb *>::iterator	it_bomb = this->m_bomb.begin();

  setCamera(0.0, 0.0);
  if (this->m_tomove == true && this->m_alive == true) {
    switch (this->m_direction) {
    case RIGHT:
      this->m_animation->translate(glm::vec3(1.0, 0, 0));
      if (this->m_animation->getRotation() != glm::vec3(90, 90, 0))
	this->m_animation->setRotation(glm::vec3(90, 90, 0));
      if (m_type == "Player")
	setCamera(1.0, 0.0);
      break;
    case LEFT:
      this->m_animation->translate(glm::vec3(-1.0, 0, 0));
      if (this->m_animation->getRotation() != glm::vec3(90, 270, 0))
	this->m_animation->setRotation(glm::vec3(90, 270, 0));
      if (m_type == "Player")
	setCamera(-1.0, 0.0);
      break;
    case DOWN:
      this->m_animation->translate(glm::vec3(0, -1.0, 0));
      if (this->m_animation->getRotation() != glm::vec3(90, 0, 0))
	this->m_animation->setRotation(glm::vec3(90, 0, 0));
      if (m_type == "Player")
	setCamera(0.0, -1.0);
      break;
    case UP:
      this->m_animation->translate(glm::vec3(0, 1.0, 0));
      if (this->m_animation->getRotation() != glm::vec3(90, 180, 0))
	this->m_animation->setRotation(glm::vec3(90, 180, 0));
      if (m_type == "Player")
	setCamera(0.0, 1.0);
      break;
    }
  }
  if (this->m_alive == true)
    this->m_animation->draw(shader, clock);
  this->m_tomove = false;
  while (it_bomb != this->m_bomb.end()) {
    (*it_bomb)->draw(shader, clock);
    ++it_bomb;
  }
}

void    ACharacter::plantBomb(Maze &maze, gdl::Clock &clock) {
  if (this->m_bomb.size() < this->m_max_bomb)   {
    this->m_bomb.push_back(new Bomb(this->m_position, this->m_range_bomb));
    this->m_bomb.back()->initialize();
    this->m_bomb.back()->spawn(maze, clock);
  }
}

void	ACharacter::IsAlive(Maze &maze) {
  if (maze.getMaze()[this->m_position] == ID_EMPTY) {
    this->m_alive = false;
  }
}
