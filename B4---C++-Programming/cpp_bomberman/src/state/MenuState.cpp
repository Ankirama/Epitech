#include "MenuState.hh"
#include "SaveState.hh"
#include "IntroState.hh"
#include "GameState.hh"
#include "OptionState.hh"
#include "Error.hpp"

MenuState	MenuState::m_MenuState;

static void	moveState(GameEngine *);
static void	quitGame(GameEngine *);

MenuState::MenuState(){
  try {
    this->addKey(SDLK_UP, &MenuState::Up);
    this->addKey(SDLK_DOWN, &MenuState::Down);
    this->addKey(SDLK_RIGHT, &MenuState::Right);
    this->addKey(SDLK_LEFT, &MenuState::Left);
    this->addKey(SDLK_ESCAPE, &MenuState::QuitState);
    this->addKey(SDLK_RETURN, &MenuState::Enter);
    this->addKey(SDL_QUIT, &MenuState::Quit);
    this->m_background = new Object2D(BACK_PAUSE,
				      0, 0, -1);
    this->m_button.push_back(new Button(BUT_BACK_1, BUT_BACK_2, 0, -5, &moveState));
    this->m_button.push_back(new Button(BUT_SAVE_1, BUT_SAVE_2, 0, 5, &moveState));
    this->m_button.push_back(new Button(BUT_OPTN_1, BUT_OPTN_2, 0, 15, &moveState));
    this->m_button.push_back(new Button(BUT_EXIT_1, BUT_EXIT_2, 0, 25, &quitGame));
    this->m_it = this->m_button.begin();
    this->m_released = true;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MenuState");
  }
}

MenuState::~MenuState() {
  try {
    while (!this->m_button.empty()){
      delete this->m_button.front();
      this->m_button.erase(this->m_button.begin());
    }
    delete this->m_background;
    this->delAllKey();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MenuState");
  }
}

void	MenuState::addKey(const int key, m_tabFun func) {
  try {
    this->m_map[key] = func;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MenuState");
  }
}

void	MenuState::modKey(const int oldKey, const int newKey) {
  try {
    this->m_map[newKey] = this->m_map[oldKey];
    this->m_map.erase(oldKey);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MenuState");
  }
}

void	MenuState::delKey(const int key) {
  try {
    this->m_map.erase(key);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MenuState");
  }
}

void	MenuState::delAllKey() {
  try {
    while (!this->m_map.empty())
      this->m_map.erase(this->m_map.begin());
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MenuState");
  }
}

void	MenuState::Init(GameEngine *game){
  glm::mat4 projection;
  glm::mat4 transformation;

  try {
    projection = glm::perspective(100.0f, 800.0f / 600.0f, 0.1f, 100.0f);
    transformation = glm::lookAt(glm::vec3(0, 0, 30), glm::vec3(0, 0, 0),
				 glm::vec3(-90, 0, 0));
    game->getShader().bind();
    game->getShader().setUniform("view", transformation);
    game->getShader().setUniform("projection", projection);
    this->m_background->Init(38.5, 51.0, -1.0, 1.0);
    this->m_it = this->m_button.begin();
    while (this->m_it != this->m_button.end()){
      (*this->m_it)->Init(5.0, 10.0, 1.0);
      this->m_it++;
    }
    this->m_it = this->m_button.begin();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MenuState");
  }
}

void	MenuState::Cleanup(){
}

void	MenuState::Pause(){
}

void	MenuState::Resume(GameEngine *){
  try {
    this->m_released = true;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MenuState");
  }
}

void	MenuState::Update(GameEngine *game){
  std::map<int, m_tabFun>::iterator	it = this->m_map.begin();

  try {
    while (it != this->m_map.end()){
      if ((game->getInput().getKey(it->first, this->m_released) ||
	   game->getInput().getInput(it->first, this->m_released))){
	m_tabFun	tmp = it->second;
	return ((this->*tmp)(game));
      }
      it++;
    }
    game->getContext().updateInputs(game->getInput());
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MenuState");
  }
}

void	MenuState::Draw(GameEngine *game){
  std::vector<Button *>::iterator	it = this->m_button.begin();

  try {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    game->getShader().bind();
    //    GameState::Instance()->Draw(game);
    this->m_background->Draw(game->getShader());
    while (it != this->m_button.end()){
      if (it != this->m_it)
	(*it)->Draw(game->getShader(), PAS_SURVOLE, game);
      it++;
    }
    (*this->m_it)->Draw(game->getShader(), SURVOLE, game);
    game->getContext().flush();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MenuState");
  }
}

void	MenuState::Up(GameEngine *){
  try {
    this->m_released = true;
    if (!this->m_button.empty() && (this->m_it == this->m_button.begin()))
      this->m_it = this->m_button.end() - 1;
    else
      this->m_it--;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MenuState");
  }
}

void	MenuState::Down(GameEngine *){
  try {
    this->m_released = true;
    if (!this->m_button.empty() && (this->m_it == this->m_button.end() - 1))
      this->m_it = this->m_button.begin();
    else
      this->m_it++;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MenuState");
  }
}

void	MenuState::Right(GameEngine *){
  try {
    this->m_released = true;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MenuState");
  }
}

void	MenuState::Left(GameEngine *){
  try {
    this->m_released = true;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MenuState");
  }
}

void	MenuState::Enter(GameEngine *game){
  try {
    this->m_released = true;
    return ((*this->m_it)->Draw(game->getShader(), ENFONCE, game));
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MenuState");
  }
}

std::vector<Button *>::iterator	&MenuState::getIterator(){
  try {
    return (this->m_it);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MenuState");
  }
}

std::vector<Button *>		&MenuState::getVector(){
  try {
    return (this->m_button);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MenuState");
  }
}

void				MenuState::setReleased(bool mybool){
  try {
    this->m_released = mybool;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MenuState");
  }
}

void	MenuState::QuitState(GameEngine *game){
  try {
    this->m_released = true;
    return (game->PopState());
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MenuState");
  }

}

void	MenuState::Quit(GameEngine *game){
  try {
    game->Quit();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MenuState");
  }
}

static void	moveState(GameEngine *game){
  try {
    MenuState::Instance()->setReleased(true);
    switch (MenuState::Instance()->getIterator() -
	    MenuState::Instance()->getVector().begin()){
    case MenuState::RES:
      return (game->PopState());
      break;
    case MenuState::SAVE:
      return (game->PushState(SaveState::Instance()));
      break;
    case MenuState::OPTION:
      OptionState::Instance()->setBackground(BACK_PAUSE);
      return (game->PushState(OptionState::Instance()));
      break;
    case MenuState::CREDIT:
      return (game->Quit());
      break;
    }
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MenuState");
  }
}

void	quitGame(GameEngine *game){
  try {
    game->Quit();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MenuState");
  }
}
