#include "Error.hpp"
#include "GameState.hh"
#include "MenuState.hh"
#include "IntroState.hh"
# include "ACharacter.hh"
# include "Player.hh"

GameState	GameState::m_GameState;

static std::random_device       _rd;
static std::mt19937             _gen(_rd());

GameState::GameState(){
  try {
    this->m_condition = IN_PROGRESS;
    this->m_load = false;
    this->m_released = true;
    this->addKey(SDLK_ESCAPE, &GameState::ChangeState);
    this->addKey(SDL_QUIT, &GameState::Quit);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameState");
  }
}

GameState::~GameState() {
  for (unsigned int i = 0; i < this->m_characters.size(); i++)
    delete this->m_characters[i];
}

void	GameState::addKey(const int key, m_tabFun func) {
  try {
    this->m_map[key] = func;
    delete this->m_camera;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameState");
  }
}


void	GameState::modKey(const int oldKey, const int newKey) {
  try {
    this->m_map[newKey] = this->m_map[oldKey];
    this->m_map.erase(oldKey);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameState");
  }
}

void	GameState::delKey(const int key) {
  try {
    this->m_map.erase(key);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameState");
  }
}

void	GameState::delAllKey(){
  try {
    while (!this->m_map.empty())
      this->m_map.erase(this->m_map.begin());
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameState");
  }
}

void	GameState::initTextures() {
  try {
    Bomb	*bomb_init = new Bomb(0);
    bomb_init->initialize();

    this->m_background = new Object2D(BACK_IMG, 0, 0, -1);
    this->m_background->Init(38.5, 51.0, -1.0, 1.0);
    this->m_background->Rotate(glm::vec3(0, 0, 1), 270);

    this->m_victory = new Object2D(TEXT_VICTORY, 0, 0, -1);
    this->m_victory->Init(20.5, 33.0, -1.0, 1.0);
    this->m_victory->Rotate(glm::vec3(0, 0, 1), 270);

    this->m_gameover = new Object2D(TEXT_GAMEOVER, 0, 0, -1);
    this->m_gameover->Init(20.5, 33.0, -1.0, 1.0);
    this->m_gameover->Rotate(glm::vec3(0, 0, 1), 270);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameState");
  }
}

void	GameState::initNewGame() {
  if (this->m_solo == true) {
    ACharacter *player1 = new Player(this->m_name1, 0, true);
    this->m_characters.push_back(player1);
  }
  else {
    ACharacter *player1 = new Player(this->m_name1, 0, true);
    ACharacter *player2 = new Player(this->m_name2, 0, false);
    this->m_characters.push_back(player1);
    this->m_characters.push_back(player2);
  }
  this->m_width = (this->m_width % 2 == 0) ? this->m_width + 1 : this->m_width;
  this->m_height = (this->m_height % 2 == 0) ? this->m_height + 1 : this->m_height;
  GenerateMaze::getInstance().create(this->m_width, this->m_height);
  this->m_maze = new Maze(this->m_width, this->m_height, GenerateMaze::getInstance().getMap());
  for (int i = 0; i < m_nbrAI; i++)
    this->m_characters.push_back(new IA(0, static_cast<eDifficulty>(m_difficulty), m_width + 2, m_height + 2));
}

void	GameState::Init(GameEngine *game){
  glm::mat4     projection;
  glm::mat4     transformation;

  try {
    if (this->m_solo == true)
      this->m_camera = new Camera();
    else
      this->m_camera = new Camera(glm::vec3(0.0f, 0.0f, 15.0f));
    game->getShader().setUniform("view", this->m_camera->getTransformation());
    game->getShader().setUniform("projection", this->m_camera->getProjection());
    this->initTextures();

    if (this->m_load == false)
      initNewGame();
    game->getShader().bind();
    this->m_maze->initialize();

    for (unsigned int i = 0; i < this->m_characters.size(); i++)	{
      spawn_character(*this->m_maze, this->m_characters[i]);
      this->m_characters[i]->initialize();
    }

  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameState");
  }
}

void	GameState::Cleanup(){
  try {
    this->delAllKey();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameState");
  }
}

void	GameState::Pause(){
}

void	GameState::Resume(GameEngine *){
  try {
    this->m_released = true;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameState");
  }
}

void	GameState::Update(GameEngine *game)		{
  std::map<int, m_tabFun>::iterator     it = this->m_map.begin();

  try {
    gameCondition();
    if (this->m_condition == IN_PROGRESS) {
      for (unsigned int i = 0; i < this->m_characters.size(); i++) {
	this->m_characters[i]->update(game, *this->m_maze);
      }
    }
    while (it != this->m_map.end()){
      if ((game->getInput().getKey(it->first, this->m_released) ||
	   game->getInput().getInput(it->first, this->m_released))){
	m_tabFun  tmp = it->second;
	return ((this->*tmp)(game));
      }
      it++;
    }
  this->m_released = true;
  game->getContext().updateInputs(game->getInput());
  game->getContext().updateClock(this->m_clock);
} catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameState");
  }
}

void	GameState::Draw(GameEngine *game){
  try {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    game->getShader().bind();
    if (this->m_condition == IN_PROGRESS)
      this->m_background->Draw(game->getShader());
    else if (this->m_condition == VICTORY) {
      this->m_victory->Draw(game->getShader());
      this->m_camera->defaultCamera();
      this->m_camera->changeCamera(game);
    }
    else {
      this->m_gameover->Draw(game->getShader());
      this->m_camera->defaultCamera();
      this->m_camera->changeCamera(game);
    }
    if (this->m_condition == IN_PROGRESS) {
      this->m_maze->draw(game->getShader(), this->m_clock);

      for (unsigned int i = 0; i < this->m_characters.size(); i++) {
	this->m_characters[i]->draw(game->getShader(), game->getClock());
	if (this->m_characters[i]->getType() == "Player" && this->m_solo == true) {
	  m_camera->setCamera(this->m_characters[i]->getCameraX(), this->m_characters[i]->getCameraY());
	  game->getShader().setUniform("view", this->m_camera->getTransformation());
	  game->getShader().setUniform("projection", this->m_camera->getProjection());
	}
      }
    }
    game->getContext().flush();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameState");
  }
}

void	GameState::ChangeState(GameEngine *game){
  try {
    this->m_released = true;
    return (game->PushState(MenuState::Instance()));
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameState");
  }
}

void	GameState::Quit(GameEngine *game){
  try {
    this->m_released = true;
    game->Quit();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameState");
  }
}

void	GameState::check_border(int position, Maze &maze) {
  int	x;
  int	y;

  x = position % maze.getWidth();
  y = position / maze.getWidth();
  if ((x > 0 && x < maze.getWidth() - 1) &&
      (y > 0 && y < maze.getHeight() - 1) &&
      maze.getMaze()[position] != ID_PLAYER)
    maze.setCase(position, ID_EMPTY);
}

void    GameState::spawn_character(Maze &maze, ACharacter *character) {
  int  max_size = maze.getWidth() * maze.getHeight();
  int  x;
  int  y;
  float	anim_x;
  float	anim_y;

  int  position;

  if (character->getPosition() == 0) {
    do    {
      position = this->randomSpawn(max_size);
      x = position % maze.getWidth();
      y = position / maze.getWidth();
      anim_x = maze.getWidth() / 2 - x;
      anim_y = maze.getHeight() / 2 - y;
    }
    while (maze.getMaze()[position] == ID_PLAYER || (x <= 0 || x >= maze.getWidth() - 1) ||
	   (y <= 0 || y >= maze.getHeight() - 1));
    character->setPosition(position);
    maze.setCase(position, ID_PLAYER);
  }
  try {
    maze.setCase(position, ID_PLAYER);
    check_border(position + 1, maze);
    check_border(position - 1, maze);
    check_border(position + maze.getWidth(), maze);
    check_border(position - maze.getWidth(), maze);
    character->getAnimation().setPosition(glm::vec3(anim_x, anim_y, 2 * CASE));
    if (m_solo == true && character->getType() == "Player")
      m_camera->setCamera(anim_x, anim_y);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameState");
  }
}

int     GameState::randomSpawn(unsigned int max) const {
  static std::uniform_int_distribution<>  disSpawn(0, max);
  return static_cast<int>(disSpawn(_gen));
}

unsigned int	GameState::checkAll() {
  int	survivors = 0;

  for (unsigned int i = 0; i < this->m_characters.size(); i++) {
    if (this->m_characters[i]->getState() == false)
      survivors++;
  }
  return survivors;
}

void	GameState::gameCondition() {
  if (this->m_solo == true && this->m_characters[0]->getState() == false) {
    this->m_condition = GAME_OVER;
  }
  else if (this->m_solo == true && this->m_characters[0]->getState() == true
	   && this->checkAll() == (this->m_characters.size() - 1)) {
    this->m_condition = VICTORY;
  }
}
