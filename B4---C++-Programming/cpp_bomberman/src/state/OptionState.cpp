#include "OptionState.hh"
#include "IntroState.hh"
#include "GameState.hh"
#include "Error.hpp"

OptionState	OptionState::m_OptionState;

static void	moveState(GameEngine *);

OptionState::OptionState(){
  try {
    this->addKey(SDLK_UP, &OptionState::Up);
    this->addKey(SDLK_DOWN, &OptionState::Down);
    this->addKey(SDLK_ESCAPE, &OptionState::QuitState);
    this->addKey(SDLK_RETURN, &OptionState::Enter);
    this->addKey(SDL_QUIT, &OptionState::Quit);
    this->m_background = new Object2D(BACK_IMG, 0, 0, -1);
    this->m_button.push_back(new Button(BUT_RSLT_1, BUT_RSLT_2, -15, -5, &moveState));
    this->m_button.push_back(new Button(BUT_KEYB_1, BUT_KEYB_2, -15, 5, &moveState));
    this->m_button.push_back(new Button(BUT_BACK_1, BUT_BACK_2, -15, 15, &moveState));
    this->m_released = true;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "OptionState");
  }
}

OptionState::~OptionState() {
  try {
    this->delAllKey();
    while (!this->m_button.empty()){
      delete this->m_button.front();
      this->m_button.erase(this->m_button.begin());
    }
    while (!this->m_map.empty()){
      this->m_map.erase(this->m_map.begin());
    }
    delete this->m_background;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "OptionState");
  }
}

void	OptionState::addKey(const int key, m_tabFun func) {
  try {
    this->m_map[key] = func;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "OptionState");
  }
}

void	OptionState::modKey(const int oldKey, const int newKey) {
  try {
    this->m_map[newKey] = this->m_map[oldKey];
    this->m_map.erase(oldKey);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "OptionState");
  }
}

void	OptionState::delKey(const int key) {
  try {
    this->m_map.erase(key);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "OptionState");
  }
}

void	OptionState::delAllKey() {
  try {
    while (!this->m_map.empty())
      this->m_map.erase(this->m_map.begin());
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "OptionState");
  }
}

void	OptionState::Init(GameEngine *game){
  glm::mat4 projection;
  glm::mat4 transformation;

  try {
    projection = glm::perspective(100.0f, 800.0f / 600.0f, 0.1f, 100.0f);
    transformation = glm::lookAt(glm::vec3(0, 0, 30), glm::vec3(0, 0, 0),
				 glm::vec3(-90, 0, 0));
    this->m_background->Init(38.5, 51.0, -1.0, 1.0);
    game->getShader().bind();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    game->getShader().setUniform("view", transformation);
    game->getShader().setUniform("projection", projection);
    this->m_it = this->m_button.begin();
    this->m_button[0]->Init(5.0, 10.0, 1.0);
    this->m_button[1]->Init(5.0, 10.0, 1.0);
    this->m_button[2]->Init(5.0, 10.0, 1.0);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "OptionState");
  }
}

void	OptionState::Cleanup(){
}

void	OptionState::Pause(){
}

void	OptionState::Resume(GameEngine *){
  try {
    this->m_released = true;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "OptionState");
  }
}

void	OptionState::Update(GameEngine *game){
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
    throw ErrorBomberman(e.what(), "OptionState");
  }
}

void	OptionState::Draw(GameEngine *game){
  std::vector<Button *>::iterator	it = this->m_button.begin();

  try {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    game->getShader().bind();
    this->m_background->Draw(game->getShader());
    while (it != this->m_button.end()){
      if (it != this->m_it)
	(*it)->Draw(game->getShader(), PAS_SURVOLE, game);
      it++;
    }
    (*this->m_it)->Draw(game->getShader(), SURVOLE, game);
    game->getContext().flush();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "OptionState");
  }
}

void	OptionState::Up(GameEngine *){
  try {
    this->m_released = true;
    if (!this->m_button.empty() && this->m_it == this->m_button.begin())
      this->m_it = this->m_button.end() - 1;
    else
      this->m_it--;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "OptionState");
  }
}

void	OptionState::Down(GameEngine *){
  try {
    this->m_released = true;
    if (!this->m_button.empty() && this->m_it == this->m_button.end() - 1)
      this->m_it = this->m_button.begin();
    else
      this->m_it++;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "OptionState");
  }
}

void	OptionState::Enter(GameEngine *game){
  try {
    this->m_released = true;
    pthread_create(&game->getPthread(), &game->getAttr(),
		   pthreadSound, (void *)BUTTON_21);
    return ((*this->m_it)->Draw(game->getShader(), ENFONCE, game));
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "OptionState");
  }
}

std::vector<Button *>::iterator	&OptionState::getIterator(){
  return (this->m_it);
}

std::vector<Button *>		&OptionState::getVector(){
  return (this->m_button);
}

void				OptionState::setReleased(bool mybool){
  try {
    this->m_released = mybool;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "OptionState");
  }
}

void	OptionState::QuitState(GameEngine *game){
  try {
    this->m_released = true;
    return (game->PopState());
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "OptionState");
  }
}

void	OptionState::Quit(GameEngine *game){
  try {
    game->Quit();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "OptionState");
  }
}

void	OptionState::setBackground(std::string const &back){
  this->m_background = new Object2D(back, 0, 0, -1);
  this->m_background->Init(38.5, 51.0, -1.0, 1.0);
}

static void	moveState(GameEngine *game){
  try {
    OptionState::Instance()->setReleased(false);
    switch (OptionState::Instance()->getIterator() -
	    OptionState::Instance()->getVector().begin()){
    case OptionState::RES:
      return (game->PopState());
      break;
    case OptionState::SCORE:
      return (game->PopState());
      break;
    case OptionState::OPTION:
      return (game->PopState());
      break;
    case OptionState::CREDIT:
      return (game->PopState());
      break;
    }
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "OptionState");
  }
}
