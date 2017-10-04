#include "Error.hpp"
#include "GameState.hh"
#include "MenuState.hh"
#include "IntroState.hh"

GameState	GameState::m_GameState;

GameState::GameState(){
  try {
    this->m_released = true;
    this->addKey(SDLK_UP, &GameState::Up);
    this->addKey(SDLK_DOWN, &GameState::Down);
    this->addKey(SDLK_RIGHT, &GameState::Right);
    this->addKey(SDLK_LEFT, &GameState::Left);
    this->addKey(SDLK_ESCAPE, &GameState::Quit);
    this->addKey(SDL_QUIT, &GameState::Quit);
    this->m_x = 0.0f;
    this->m_x = 0.0f;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameState");
  }
}

GameState::~GameState() {
}

void	GameState::addKey(const int key, m_tabFun func) {
  try {
    this->m_map[key] = func;
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

void	GameState::Init(GameEngine *game){
  glm::mat4     projection;
  glm::mat4     transformation;

  try {
    projection = glm::perspective(60.0f, 16.0f / 9.0f, 0.1f, 200.0f);
    transformation = glm::lookAt(glm::vec3(-4.5, 5, 7),
				 glm::vec3(-4.5 + m_x, 7.5 + m_y, 0), glm::vec3(0.0f, 0.01f, 0.0f));
    game->getShader().bind();
    game->getShader().setUniform("view", transformation);
    game->getShader().setUniform("projection", projection);
    GenerateMaze::getInstance().create(15, 15);
    this->m_maze = new Maze(15, 15, GenerateMaze::getInstance().getMap(), "ressources/img/texture/sol.tga",
			    "ressources/img/texture/mur.tga", "ressources/img/texture/caisse.tga");
    this->m_maze->add_bomberman("Toto", 30);
    this->m_maze->init(38.5, 51.0);
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

void	GameState::Resume(GameEngine *game){
  try {
    this->m_released = true;
    this->Init(game);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameState");
  }
}

void	GameState::HandleEvents(GameEngine *game){
  std::map<int, m_tabFun>::iterator     it = this->m_map.begin();

  try {
    while (it != this->m_map.end()){
      if ((this->m_input.getKey(it->first, this->m_released) ||
	   this->m_input.getInput(it->first, this->m_released))){
	m_tabFun  tmp = it->second;
	return ((this->*tmp)(game));
      }
      it++;
    }
    this->m_released = true;
    game->getContext().updateInputs(this->m_input);
    game->getContext().updateClock(this->m_clock);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameState");
  }
}

void	GameState::Update(GameEngine *)		{
}

void	GameState::Draw(GameEngine *game){
  try {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    game->getShader().bind();
    this->m_maze->draw(game->getShader(), this->m_clock);
    game->getContext().flush();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameState");
  }
}

void	GameState::Up(GameEngine *game){
  glm::mat4     transformation;
  try {
    if (this->m_maze->getBomberman()[0]->collision(UP, this->m_maze->getMaze()) == true)	{
      m_y = m_y + 0.1;
      this->m_maze->getBomberman()[0]->setY(1.0);
      std::cout << "this->m_y = " << this->m_maze->getBomberman()[0]->getY() << std::endl;
      transformation = glm::lookAt(glm::vec3(-4.5 + m_x, 6 + m_y, 5),
				   glm::vec3(-4.5 + m_x, 7.5 + m_y, 0), glm::vec3(0.0f, 0.01f, 0.0f));
      this->m_maze->getBomberman()[0]->getAnimation()->translate(glm::vec3(0, 1.0, 0));
      game->getShader().setUniform("view", transformation);
    }
    this->m_released = true;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameState");
  }
}

void	GameState::Down(GameEngine *game){
  glm::mat4     transformation;
  try {
    if (this->m_maze->getBomberman()[0]->collision(DOWN, this->m_maze->getMaze()) == true)	{
      m_y = m_y - 0.1;
      this->m_maze->getBomberman()[0]->setY(-1.0);
      std::cout << "this->m_y = " << this->m_maze->getBomberman()[0]->getY() << std::endl;
      transformation = glm::lookAt(glm::vec3(-4.5 + m_x, 6 + m_y, 5),
				   glm::vec3(-4.5 + m_x, 7.5 + m_y, 0), glm::vec3(0.0f, 0.01f, 0.0f));
      this->m_maze->getBomberman()[0]->getAnimation()->translate(glm::vec3(0, -0.1, 0));
      game->getShader().setUniform("view", transformation);
    }
    this->m_released = true;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameState");
  }
}

void	GameState::Right(GameEngine *game){
  glm::mat4     transformation;
  try {
    m_x = m_x + 0.1;
    transformation = glm::lookAt(glm::vec3(-4.5 + m_x, 6 + m_y, 5),
				 glm::vec3(-4.5 + m_x, 7.5 + m_y, 0), glm::vec3(0.0f, 0.01f, 0.0f));
    this->m_maze->getBomberman()[0]->getAnimation()->translate(glm::vec3(0.1, 0, 0));
    game->getShader().setUniform("view", transformation);
    this->m_released = true;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameState");
  }
}

void	GameState::Left(GameEngine *game){
  glm::mat4     transformation;
  try {
    m_x = m_x - 0.1;
    transformation = glm::lookAt(glm::vec3(-4.5 + m_x, 6 + m_y, 5),
				 glm::vec3(-4.5 + m_x, 7.5 + m_y, 0), glm::vec3(0.0f, 0.01f, 0.0f));
    this->m_maze->getBomberman()[0]->getAnimation()->translate(glm::vec3(-0.1, 0, 0));
    game->getShader().setUniform("view", transformation);
    this->m_released = true;
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
