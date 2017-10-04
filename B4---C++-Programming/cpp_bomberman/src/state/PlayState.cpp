#include "PlayState.hh"
#include "IntroState.hh"
#include "MultState.hh"
#include "SoloState.hh"
#include "template_string.hh"
#include "Error.hpp"

PlayState	PlayState::m_PlayState;

static void	moveState(GameEngine *);

PlayState::PlayState(){
  try {
  this->addKey(SDLK_UP, &PlayState::Up);
  this->addKey(SDLK_DOWN, &PlayState::Down);
  this->addKey(SDLK_ESCAPE, &PlayState::QuitState);
  this->addKey(SDLK_RETURN, &PlayState::Enter);
  this->addKey(SDL_QUIT, &PlayState::Quit);
  this->m_background = new Object2D(BACK_IMG, 0, 0, -1);
  this->m_button.push_back(new Button(BUT_SOLO_1, BUT_SOLO_2, 0, 0, &moveState));
  this->m_button.push_back(new Button(BUT_MULT_1, BUT_MULT_2, 0, 10, &moveState));
  this->m_button.push_back(new Button(BUT_BACK_1, BUT_BACK_2, 0, 20, &moveState));
  this->m_released = true;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "PlayState");
  }
}

PlayState::~PlayState() {
  try {
  this->delAllKey();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "PlayState");
  }
}

void	PlayState::addKey(const int key, m_tabFun func) {
  try {
    this->m_map[key] = func;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "PlayState");
  }
}

void	PlayState::modKey(const int oldKey, const int newKey) {
  try {
    this->m_map[newKey] = this->m_map[oldKey];
    this->m_map.erase(oldKey);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "PlayState");
  }
}

void	PlayState::delKey(const int key) {
  try {
    this->m_map.erase(key);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "PlayState");
  }
}

void	PlayState::delAllKey() {
  try {
    while (!this->m_map.empty())
      this->m_map.erase(this->m_map.begin());
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "PlayState");
  }
}

void	PlayState::Init(GameEngine *game){
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
    while (this->m_it != this->m_button.end()){
      (*this->m_it)->Init(5.0, 10.0, 1.0);
      this->m_it++;
    }
    this->m_it = this->m_button.begin();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "PlayState");
  }
}

void	PlayState::Cleanup(){
}

void	PlayState::Pause(){
}

void	PlayState::Resume(GameEngine *){
  try {
    this->m_released = true;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "PlayState");
  }
}

void	PlayState::Update(GameEngine *game){
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
    throw ErrorBomberman(e.what(), "PlayState");
  }
}

void	PlayState::Draw(GameEngine *game){
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
    throw ErrorBomberman(e.what(), "PlayState");
  }
}

void	PlayState::Up(GameEngine *){
  try {
    this->m_released = true;
    if (!this->m_button.empty() && (this->m_it == this->m_button.begin()))
      this->m_it = this->m_button.end() - 1;
    else
      this->m_it--;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "PlayState");
  }
}

void	PlayState::Down(GameEngine *){
  try {
    this->m_released = true;
    if (!this->m_button.empty() && (this->m_it == this->m_button.end() - 1))
      this->m_it = this->m_button.begin();
    else
      this->m_it++;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "PlayState");
  }
}

void	PlayState::Enter(GameEngine *game){
  try {
    this->m_released = true;
    pthread_create(&game->getPthread(), &game->getAttr(),
		   pthreadSound, (void *)BUTTON_21);
    return ((*this->m_it)->Draw(game->getShader(), ENFONCE, game));
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "PlayState");
  }
}

std::vector<Button *>::iterator	&PlayState::getIterator(){
  try {
    return (this->m_it);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "PlayState");
  }
}

std::vector<Button *>		&PlayState::getVector(){
  try {
    return (this->m_button);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "PlayState");
  }
}

void				PlayState::setReleased(bool mybool){
  try {
    this->m_released = mybool;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "PlayState");
  }
}

void	PlayState::QuitState(GameEngine *game){
  try {
    this->m_released = true;
    return (game->PopState());
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "PlayState");
  }
}

void	PlayState::Quit(GameEngine *game){
  try {
    game->Quit();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "PlayState");
  }
}

static void	moveState(GameEngine *game){
  try {
    PlayState::Instance()->setReleased(true);
    switch (PlayState::Instance()->getIterator() -
	    PlayState::Instance()->getVector().begin()){
    case PlayState::SOLO:
      return (game->PushState(SoloState::Instance()));
      break;
    case PlayState::MULT:
      return (game->PushState(MultState::Instance()));
      break;
    case PlayState::EXIT:
      return (game->PopState());
      break;
    }
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "PlayState");
  }
}
