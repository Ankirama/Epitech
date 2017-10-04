#include "Player.hh"

// Constructor
Player::Player(std::string const &name, unsigned int position, bool first) :
  ACharacter("Player", position), m_name(name), m_first(first), m_score(0)	{

  this->m_released = true;
  if (first == true)	{
    this->setKeyRight(SDLK_d);
    this->setKeyLeft(SDLK_a);
    this->setKeyUp(SDLK_w);
    this->setKeyDown(SDLK_s);
    this->setKeyBomb(SDLK_BACKSPACE);
  }
  else	{
    this->setKeyRight(SDLK_RIGHT);
    this->setKeyLeft(SDLK_LEFT);
    this->setKeyUp(SDLK_UP);
    this->setKeyDown(SDLK_DOWN);
    this->setKeyBomb(SDLK_RETURN);
  }
}

// Destructor
Player::~Player()	{
  try {
    this->delAllKey();
    if (this->m_animation != NULL)
      delete this->m_animation;
    Score::getInstance().addScore(this->m_name, this->m_score);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "Player");
  }
}
// Getter Key
int	Player::getKeyRight() const {
  if (this->m_first == true)
    return SDLK_d;
  else
    return SDLK_RIGHT;
}

int	Player::getKeyLeft() const {
  if (this->m_first == true)
    return SDLK_a;
  else
    return SDLK_LEFT;
}

int	Player::getKeyUp() const {
  if (this->m_first == true)
    return SDLK_w;
  else
    return SDLK_UP;
}

int	Player::getKeyDown() const {
  if (this->m_first == true)
    return SDLK_s;
  else
    return SDLK_DOWN;
}

int	Player::getKeyBomb() const {
  if (this->m_first == true)
    return SDLK_BACKSPACE;
  else
    return SDLK_RETURN;
}

// Setter Key
void	Player::setKeyRight(int key)	{
  try {
    this->addKey(key, &Player::MoveRight);
  } catch (ErrorBomberman const &e)	{
    throw ErrorBomberman(e.what(), "Player");
  }
}

void	Player::setKeyLeft(int key)	{
  try {
    this->m_input[key] = &Player::MoveLeft;
  } catch (ErrorBomberman const &e)	{
    throw ErrorBomberman(e.what(), "Player");
  }
}

void	Player::setKeyUp(int key)	{
  try {
    this->m_input[key] = &Player::MoveUp;
  } catch (ErrorBomberman const &e)	{
    throw ErrorBomberman(e.what(), "Player");
  }
}

void	Player::setKeyDown(int key)	{
  try {
    this->m_input[key] = &Player::MoveDown;
  } catch (ErrorBomberman const &e)	{
    throw ErrorBomberman(e.what(), "Player");
  }
}

void	Player::setKeyBomb(const int key)	{
  try {
    this->m_input[key] = &Player::Plant;
  } catch (ErrorBomberman const &e)	{
    throw ErrorBomberman(e.what(), "Player");
  }
}

void	Player::Plant(Maze &maze, gdl::Clock &clock) {
  if (this->m_alive == true) {
    this->plantBomb(maze, clock);
    this->increaseScore();
  }
}

void	Player::update(GameEngine *game, Maze &maze)	{
  std::map<int, m_tabFun>::iterator	it_imput = this->m_input.begin();
  std::list<Bomb *>::iterator		it_bomb = this->m_bomb.begin();

  try {
    while (it_bomb != this->m_bomb.end()) {
      (*it_bomb)->update(game->getClock(), maze);
      if ((*it_bomb)->getState() == TODELETE) {
	delete *it_bomb;
	it_bomb = this->m_bomb.erase(it_bomb);
      }
      ++it_bomb;
    }
    this->IsAlive(maze);
    while (it_imput != this->m_input.end()) {
      if ((game->getInput().getKey(it_imput->first, this->m_released))) {
        m_tabFun	tmp = it_imput->second;
	return ((this->*tmp)(maze, game->getClock()));
      }
      it_imput++;
    }
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "Player");
  }
}

// Key Setting
void	Player::addKey(const int key, m_tabFun func)	{
  try {
    this->m_input[key] = func;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "Player");
  }
}

void	Player::delKey(const int key)	{
  try {
    this->m_input.erase(key);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "Player");
  }
}

void	Player::delAllKey()	{
  try {
    while (!this->m_input.empty())
      this->m_input.erase(this->m_input.begin());
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "Player");
  }
}

// Actions
void	Player::MoveRight(Maze &maze, gdl::Clock &)	{
  if (this->m_alive == true) {
    this->m_released = true;
    this->m_direction = RIGHT;
    this->m_tomove = this->move(maze.getMaze(), maze.getWidth());
  }
}
void	Player::MoveLeft(Maze &maze, gdl::Clock &)	{
  if (this->m_alive == true) {
    this->m_released = true;
    this->m_direction = LEFT;
    this->m_tomove = this->move(maze.getMaze(), maze.getWidth());
  }
}

void	Player::MoveUp(Maze &maze, gdl::Clock &)	{
  if (this->m_alive == true) {
    this->m_released = true;
    this->m_direction = UP;
    this->m_tomove = this->move(maze.getMaze(), maze.getWidth());
  }
}

void	Player::MoveDown(Maze &maze, gdl::Clock &)	{
  if (this->m_alive == true) {
    this->m_released = true;
    this->m_direction = DOWN;
    this->m_tomove = this->move(maze.getMaze(), maze.getWidth());
  }
}
