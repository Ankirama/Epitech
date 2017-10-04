#include "SoloState.hh"
#include "IntroState.hh"
#include "GameState.hh"
#include "ConfState.hh"
#include "template_string.hh"
#include "Error.hpp"
#include <unistd.h>

SoloState	SoloState::m_SoloState;

static void	moveState(GameEngine *);

SoloState::SoloState(){
  try {
  this->addKey(SDLK_UP, &SoloState::Up);
  this->addKey(SDLK_DOWN, &SoloState::Down);
  this->addKey(SDLK_ESCAPE, &SoloState::QuitState);
  this->addKey(SDLK_RETURN, &SoloState::Enter);
  this->addKey(SDLK_BACKSPACE, &SoloState::removeLetter);
  this->addKey(SDL_QUIT, &SoloState::Quit);
  this->m_background = new Object2D(BACK_IMG, 0, 0, -1);
  this->m_backname = new Object2D(BACK_NAME, -5, 0, 0);
  this->m_button.push_back(new Button(BUT_PLAY_1, BUT_PLAY_2, 0, 10, &moveState));
  this->m_button.push_back(new Button(BUT_BACK_1, BUT_BACK_2, 0, 20, &moveState));
  this->m_text = new GenerateText("", 50.0f, -50.0f);
  this->m_name = "";
  this->m_released = true;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "SoloState");
  }
}

SoloState::~SoloState() {
  try {
    while (!this->m_button.empty()){
      delete this->m_button.front();
      this->m_button.erase(this->m_button.begin());
    };
    delete this->m_background;
    this->delAllKey();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "SoloState");
  }
}

void	SoloState::addKey(const int key, m_tabFun func) {
  try {
    this->m_map[key] = func;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "SoloState");
  }
}

void	SoloState::modKey(const int oldKey, const int newKey) {
  try {
    this->m_map[newKey] = this->m_map[oldKey];
    this->m_map.erase(oldKey);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "SoloState");
  }
}

void	SoloState::delKey(const int key) {
  try {
    this->m_map.erase(key);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "SoloState");
  }
}

void	SoloState::delAllKey() {
  try {
    while (!this->m_map.empty())
      this->m_map.erase(this->m_map.begin());
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "SoloState");
  }
}

void	SoloState::Init(GameEngine *game){
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
    this->m_text->Init();
    this->m_backname->Init(3, 12, 0.0, 1.0);
    while (this->m_it != this->m_button.end()){
      (*this->m_it)->Init(5.0, 10.0, 1.0);
      this->m_it++;
    }
    this->m_it = this->m_button.begin();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "SoloState");
  }
}

void	SoloState::Cleanup(){
}

void	SoloState::Pause(){
}

void	SoloState::Resume(GameEngine *){
  try {
    this->m_released = true;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "SoloState");
  }
}

void	SoloState::Update(GameEngine *game){
  std::map<int, m_tabFun>::iterator	it = this->m_map.begin();
  int					name = SDLK_a;

  try {
    while (name <= SDLK_z){
      if (game->getInput().getKey(name, this->m_released))
	return (this->writeName(name, game));
      name++;
    }
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
    throw ErrorBomberman(e.what(), "SoloState");
  }
}

void	SoloState::Draw(GameEngine *game){
  std::vector<Button *>::iterator	it = this->m_button.begin();

  try {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    game->getShader().bind();
    this->m_background->Draw(game->getShader());
    this->m_backname->Draw(game->getShader());
    while (it != this->m_button.end()){
      if (it != this->m_it)
	(*it)->Draw(game->getShader(), PAS_SURVOLE, game);
      it++;
    }
    (*this->m_it)->Draw(game->getShader(), SURVOLE, game);
    this->m_text->Draw(game->getShader());
    game->getContext().flush();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "SoloState");
  }
}

void	SoloState::Up(GameEngine *){
  try {
    this->m_released = true;
    if (!this->m_button.empty() && (this->m_it == this->m_button.begin()))
      this->m_it = this->m_button.end() - 1;
    else
      this->m_it--;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "SoloState");
  }
}

void	SoloState::Down(GameEngine *){
  try {
    this->m_released = true;
    if (!this->m_button.empty() && (this->m_it == this->m_button.end() - 1))
      this->m_it = this->m_button.begin();
    else
      this->m_it++;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "SoloState");
  }
}

void	SoloState::Enter(GameEngine *game){
  try {
    this->m_released = true;
    pthread_create(&game->getPthread(), &game->getAttr(),
		   pthreadSound, (void *)BUTTON_21);
    if (this->m_it == this->m_button.begin() && this->m_name.length() == 0)
      pthread_create(&game->getPthread(), &game->getAttr(),
		     pthreadSound, (void *)HOLYSHIT);
    else
      return ((*this->m_it)->Draw(game->getShader(), ENFONCE, game));
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "SoloState");
  }
}

std::vector<Button *>::iterator	&SoloState::getIterator(){
  try {
    return (this->m_it);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "SoloState");
  }
}

std::vector<Button *>		&SoloState::getVector(){
  try {
    return (this->m_button);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "SoloState");
  }
}

void				SoloState::setReleased(bool mybool){
  try {
    this->m_released = mybool;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "SoloState");
  }
}

void	SoloState::QuitState(GameEngine *game){
  try {
    this->m_released = true;
    return (game->PopState());
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "SoloState");
  }
}

void	SoloState::Quit(GameEngine *game){
  try {
    game->Quit();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "SoloState");
  }
}

static void	moveState(GameEngine *game){
  try {
    SoloState::Instance()->setReleased(true);
    switch (SoloState::Instance()->getIterator() -
	    SoloState::Instance()->getVector().begin()){
    case SoloState::PLAY:
      GameState::Instance()->setName1(SoloState::Instance()->getName());
      GameState::Instance()->setMode(true);
      return (game->PushState(ConfState::Instance()));
      break;
    case SoloState::EXIT:
      return (game->PopState());
      break;
    }
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "SoloState");
  }
}

void	SoloState::writeName(int const letter, GameEngine *game){
  if (this->m_name.length() < 10){
    this->m_name += letter;
    delete this->m_text;
    this->m_text = new GenerateText(this->m_name, -9, -5);
    this->m_text->Init();
  } else
    pthread_create(&game->getPthread(), &game->getAttr(),
		   pthreadSound, (void *)GOD_LIKE);
}

void	SoloState::removeLetter(GameEngine *){
  this->m_name = this->m_name.substr(0, this->m_name.length() - 1);
  delete this->m_text;
  this->m_text = new GenerateText(this->m_name, -9, -5);
  this->m_text->Init();
}
