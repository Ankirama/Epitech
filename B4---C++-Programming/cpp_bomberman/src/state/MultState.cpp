#include "MultState.hh"
#include "IntroState.hh"
#include "ConfState.hh"
#include "GameState.hh"
#include "template_string.hh"
#include "Error.hpp"
#include <unistd.h>

MultState	MultState::m_MultState;

static void	moveState(GameEngine *);

MultState::MultState(){
  try {
  this->addKey(SDLK_UP, &MultState::Up);
  this->addKey(SDLK_DOWN, &MultState::Down);
  this->addKey(SDLK_ESCAPE, &MultState::QuitState);
  this->addKey(SDLK_RETURN, &MultState::Enter);
  this->addKey(SDLK_BACKSPACE, &MultState::removeLetter);
  this->addKey(SDL_QUIT, &MultState::Quit);
  this->m_background = new Object2D(BACK_IMG, 0, 0, -1);
  this->m_backname1 = new Object2D(BACK_NAME, -5, 5, 0);
  this->m_backname2 = new Object2D(BACK_NAME, 0, 5, 0);
  this->m_head = new Object2D(HEAD_IMG, 0, 0, -1);
  this->m_button.push_back(new Button(BUT_PLAY_1, BUT_PLAY_2, 0, 10, &moveState));
  this->m_button.push_back(new Button(BUT_BACK_1, BUT_BACK_2, 0, 20, &moveState));
  this->m_player.push_back(new GenerateText("Player1", -20, -5));
  this->m_player.push_back(new GenerateText("", 0, 0));
  this->m_player.push_back(new GenerateText("Player2", -20, 0));
  this->m_player.push_back(new GenerateText("", 0, 0));
  this->m_name1 = "";
  this->m_name2 = "";
  this->m_released = true;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MultState");
  }
}

MultState::~MultState() {
  try {
    delete this->m_background;
    delete this->m_backname1;
    delete this->m_backname2;
    delete this->m_head;
    while (!this->m_button.empty()){
      delete this->m_button.front();
      this->m_button.erase(this->m_button.begin());
    }
    while (!this->m_player.empty()){
      delete this->m_player.front();
      this->m_player.erase(this->m_player.begin());
    }
    this->delAllKey();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MultState");
  }
}

void	MultState::addKey(const int key, m_tabFun func) {
  try {
    this->m_map[key] = func;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MultState");
  }
}

void	MultState::modKey(const int oldKey, const int newKey) {
  try {
    this->m_map[newKey] = this->m_map[oldKey];
    this->m_map.erase(oldKey);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MultState");
  }
}

void	MultState::delKey(const int key) {
  try {
    this->m_map.erase(key);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MultState");
  }
}

void	MultState::delAllKey() {
  try {
    while (!this->m_map.empty())
      this->m_map.erase(this->m_map.begin());
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MultState");
  }
}

void	MultState::Init(GameEngine *game){
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
    for (std::vector<GenerateText *>::iterator it = this->m_player.begin();
	 it != this->m_player.end(); ++it){
      (*it)->Init();
    }
    this->m_it = this->m_button.begin();
    this->m_backname1->Init(3, 12, 0.0, 1.0);
    this->m_backname2->Init(3, 12, 0.0, 1.0);
    this->m_iterator = 0;
    this->m_head->Init(2.0, 2.0, 1.0, 1.0);
    this->m_head->setY(this->m_player[0]->getY(), -25);
    while (this->m_it != this->m_button.end()){
      (*this->m_it)->Init(5.0, 10.0, 1.0);
      this->m_it++;
    }
    this->m_it = this->m_button.end();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MultState");
  }
}

void	MultState::Cleanup(){
}

void	MultState::Pause(){
}

void	MultState::Resume(GameEngine *){
  try {
    this->m_released = true;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MultState");
  }
}

void	MultState::Update(GameEngine *game){
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
    throw ErrorBomberman(e.what(), "MultState");
  }
}

void	MultState::Draw(GameEngine *game){
  std::vector<Button *>::iterator	it = this->m_button.begin();

  try {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    game->getShader().bind();
    this->m_background->Draw(game->getShader());
    this->m_backname1->Draw(game->getShader());
    this->m_backname2->Draw(game->getShader());
    this->m_head->Draw(game->getShader());
    for (std::vector<GenerateText *>::iterator itP = this->m_player.begin();
	 itP != this->m_player.end(); ++itP){
      (*itP)->Draw(game->getShader());
    }
    while (it != this->m_button.end()){
      if (it != this->m_it)
	(*it)->Draw(game->getShader(), PAS_SURVOLE, game);
      it++;
    }
    if (this->m_it != this->m_button.end())
      (*this->m_it)->Draw(game->getShader(), SURVOLE, game);
    game->getContext().flush();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MultState");
  }
}

void	MultState::Up(GameEngine *){
  try {
    this->m_released = true;
    if (this->m_iterator < 2){
      if (this->m_iterator == 0){
	this->m_it = this->m_button.end() - 1;
	this->m_iterator = 3;
	this->m_head->setY((*this->m_it)->getY(), -25);
      } else {
	this->m_it = this->m_button.end();
	this->m_iterator--;
	this->m_head->setY(this->m_player[0]->getY(), -25);
      }
    } else {
      if (!this->m_button.empty() && (this->m_it == this->m_button.begin())){
	this->m_it = this->m_button.end();
	this->m_iterator = 1;
	this->m_head->setY(this->m_player[2]->getY(), -25);
      } else {
	this->m_iterator--;
	this->m_it--;
	this->m_head->setY((*this->m_it)->getY(), -25);
      }
    }
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MultState");
  }
}

void	MultState::Down(GameEngine *){
  try {
    this->m_released = true;
    if (this->m_iterator < 2){
      if (this->m_iterator == 1){
	this->m_it = this->m_button.begin();
	this->m_iterator = 2;
	this->m_head->setY((*this->m_it)->getY(), -25);
      } else {
	this->m_it = this->m_button.end();
	this->m_iterator++;
	this->m_head->setY(this->m_player[2]->getY(), -25);
      }
    } else {
      if (!this->m_button.empty() && (this->m_it == this->m_button.end() - 1)){
	this->m_it = this->m_button.end();
	this->m_iterator = 0;
	this->m_head->setY(this->m_player[0]->getY(), -25);
      } else {
	this->m_iterator++;
	this->m_it++;
	this->m_head->setY((*this->m_it)->getY(), -25);
      }
    }
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MultState");
  }
}

void	MultState::Enter(GameEngine *game){
  try {
    this->m_released = true;
    pthread_create(&game->getPthread(), &game->getAttr(),
		   pthreadSound, (void *)BUTTON_21);
    if (this->m_it != this->m_button.end() &&
	!this->m_name1.empty() && !this->m_name2.empty() &&
	this->m_name1 != this->m_name2)
      return ((*this->m_it)->Draw(game->getShader(), ENFONCE, game));
    else
      pthread_create(&game->getPthread(), &game->getAttr(),
		   pthreadSound, (void *)DING);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MultState");
  }
}

std::vector<Button *>::iterator	&MultState::getIterator(){
  try {
    return (this->m_it);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MultState");
  }
}

std::vector<Button *>		&MultState::getVector(){
  try {
    return (this->m_button);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MultState");
  }
}

void				MultState::setReleased(bool mybool){
  try {
    this->m_released = mybool;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MultState");
  }
}

void	MultState::QuitState(GameEngine *game){
  try {
    this->m_released = true;
    return (game->PopState());
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MultState");
  }
}

void	MultState::Quit(GameEngine *game){
  try {
    game->Quit();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MultState");
  }
}

static void	moveState(GameEngine *game){
  try {
    MultState::Instance()->setReleased(true);
    switch (MultState::Instance()->getIterator() -
	    MultState::Instance()->getVector().begin()){
    case MultState::PLAY:
      GameState::Instance()->setName1(MultState::Instance()->getName1());
      GameState::Instance()->setName2(MultState::Instance()->getName2());
      GameState::Instance()->setMode(false);
      return (game->PushState(ConfState::Instance()));
      break;
    case MultState::EXIT:
      return (game->PopState());
      break;
    }
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "MultState");
  }
}

void	MultState::writeName(int const letter, GameEngine *game){
  if (this->m_iterator == 0){
    if (this->m_name1.length() < 10){
      this->m_name1 += letter;
      delete this->m_player[1];
      this->m_player[1] = new GenerateText(this->m_name1, -4.5, -5);
      this->m_player[1]->Init();
    } else
      pthread_create(&game->getPthread(), &game->getAttr(),
		     pthreadSound, (void *)GOD_LIKE);
  } else if (this->m_iterator == 1){
    if (this->m_name2.length() < 10){
      this->m_name2 += letter;
      delete this->m_player[3];
      this->m_player[3] = new GenerateText(this->m_name2, -4.5, 0);
      this->m_player[3]->Init();
    } else
      pthread_create(&game->getPthread(), &game->getAttr(),
		     pthreadSound, (void *)GOD_LIKE);
  }
}

void	MultState::removeLetter(GameEngine *){
  if (this->m_iterator == 0){
    this->m_name1 = this->m_name1.substr(0, this->m_name1.length() - 1);
    delete this->m_player[1];
    this->m_player[1] = new GenerateText(this->m_name1, -4.5, -5);
    this->m_player[1]->Init();
  } else if (this->m_iterator == 1){
    this->m_name2 = this->m_name2.substr(0, this->m_name2.length() - 1);
    delete this->m_player[3];
    this->m_player[3] = new GenerateText(this->m_name2, -4.5, 0);
    this->m_player[3]->Init();
  }
}
