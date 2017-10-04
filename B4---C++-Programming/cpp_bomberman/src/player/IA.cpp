#include "IA.hh"


// constructor

IA::IA(unsigned int position, eDifficulty difficulty, int width, int height) :
  ACharacter("AI", position), m_difficulty(difficulty), m_width(width), m_height(height), m_time(0) {
  try {
    switch (difficulty) {
    case DUMMY:
      this->m_lua = new Lua("src/botme/ai_dummy.lua", width, height);
      break;
    case EASY:
      this->m_lua = new Lua("src/botme/ai_easy.lua", width, height);
      break;
    case NORMAL:
      this->m_lua = new Lua("src/botme/ai_normal.lua", width, height);
      break;
    default:
      this->m_lua = 0;
      break;
    }
  }
  catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "IA");
  }
}

// destructor
IA::~IA()	{
  if (this->m_lua) {
    delete this->m_lua;
  }
}

// getter
eDifficulty	IA::getDifficulty() const	{
  return (this->m_difficulty);
}

// setter
void	IA::setDifficulty(eDifficulty difficulty)	{
  this->m_difficulty = difficulty;
  if (this->m_lua)
    delete this->m_lua;
  try {
    switch (this->m_difficulty) {
    case DUMMY:
      this->m_lua = new Lua("src/botme/ai_dummy.lua", this->m_width, this->m_height);
      break;
    case EASY:
      this->m_lua = new Lua("src/botme/ai_easy.lua", this->m_width, this->m_height);
      break;
    case NORMAL:
      this->m_lua = new Lua("src/botme/ai_normal.lua", this->m_width, this->m_height);
      break;
    default:
      this->m_lua = 0;
      break;
    }
  }
  catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "IA");
  }
}

void	IA::update(GameEngine *game, Maze &maze)	{
  std::list<Bomb *>::iterator		it_bomb = this->m_bomb.begin();
  int	action;
  int	x;
  int	y;

  if (this->m_time > 42) {
    this->m_time = 0;
    x = this->m_position % this->m_width;
    y = this->m_position / this->m_width;
    this->IsAlive(maze);
    if (this->m_alive) {
      action = this->m_lua->getPosition(maze.getMaze(), x, y);
      if (action == -1)
	throw ErrorBomberman("Error with lua bind", "IA");
      else if (action < IA_NONE)
	(this->*m_func[action])(maze, game->getClock());
    }
  }
  this->m_time = this->m_time + 1;
  try {
    while (it_bomb != this->m_bomb.end()) {
      (*it_bomb)->update(game->getClock(), maze);
      if ((*it_bomb)->getState() == TODELETE) {
	delete *it_bomb;
	it_bomb = this->m_bomb.erase(it_bomb);
      }
      ++it_bomb;
    }
  }
  catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "IA");
  }
}

void	IA::MoveRight(Maze &maze, gdl::Clock &)	{
  if (this->m_alive == true) {
    this->m_direction = RIGHT;
    this->m_tomove = this->move(maze.getMaze(), maze.getWidth());
  }
}
void	IA::MoveLeft(Maze &maze, gdl::Clock &)	{
  if (this->m_alive == true) {
    this->m_direction = LEFT;
    this->m_tomove = this->move(maze.getMaze(), maze.getWidth());
  }
}

void	IA::MoveUp(Maze &maze, gdl::Clock &)	{
  if (this->m_alive == true) {
    this->m_direction = UP;
    this->m_tomove = this->move(maze.getMaze(), maze.getWidth());
  }
}

void	IA::MoveDown(Maze &maze, gdl::Clock &)	{
  if (this->m_alive == true) {
    this->m_direction = DOWN;
    this->m_tomove = this->move(maze.getMaze(), maze.getWidth());
  }
}

void	IA::Plant(Maze &maze, gdl::Clock &clock) {
  if (this->m_alive == true) {
    this->plantBomb(maze, clock);
  }
}
