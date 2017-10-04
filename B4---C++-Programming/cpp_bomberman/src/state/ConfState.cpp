#include "ConfState.hh"
#include "IntroState.hh"
#include "GameState.hh"
#include "template_string.hh"
#include "Error.hpp"
#include <unistd.h>

ConfState	ConfState::m_ConfState;

static void	moveState(GameEngine *);

ConfState::ConfState(){
  try {
    this->addKey(SDLK_UP, &ConfState::Up);
    this->addKey(SDLK_DOWN, &ConfState::Down);
    this->addKey(SDLK_ESCAPE, &ConfState::QuitState);
    this->addKey(SDLK_RETURN, &ConfState::Enter);
    this->addKey(SDLK_BACKSPACE, &ConfState::removeLetter);
    this->addKey(SDL_QUIT, &ConfState::Quit);
    this->m_background = new Object2D(BACK_IMG, 0, 0, -1);
    this->m_backx = new Object2D(BACK_NAME, -5, 12, 0);
    this->m_backnbAI = new Object2D(BACK_NAME, 0, 12, 0);
    this->m_backDifficulty = new Object2D(BACK_NAME, 5, 12, 0);
    this->m_head = new Object2D(HEAD_IMG, 0, 0, -1);
    this->m_button.push_back(new Button(BUT_PLAY_1, BUT_PLAY_2, 0, 23, &moveState));
    this->m_button.push_back(new Button(BUT_BACK_1, BUT_BACK_2, 0, 30, &moveState));
    this->m_player.push_back(new GenerateText("X 10 10000", -20, -5));
    this->m_player.push_back(new GenerateText("", 0, 0));
    this->m_player.push_back(new GenerateText("Number AI", -20, 0));
    this->m_player.push_back(new GenerateText("", 0, 0));
    this->m_player.push_back(new GenerateText("Difficulty", -20, 5));
    this->m_player.push_back(new GenerateText("", 0, 0));
    this->m_player.push_back(new GenerateText("1 2 3", -15, 10));
    this->m_x = "";
    this->m_nbAI = "";
    this->m_difficulty = "";
    this->m_released = true;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ConfState");
  }
}

ConfState::~ConfState() {
  try {
    this->delAllKey();
    delete this->m_background;
    delete this->m_backx;
    delete this->m_backy;
    delete this->m_backnbAI;
    delete this->m_backDifficulty;
    delete this->m_head;
     while (!this->m_button.empty()){
      delete this->m_button.front();
      this->m_button.erase(this->m_button.begin());
    }
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ConfState");
  }
}

void	ConfState::addKey(const int key, m_tabFun func) {
  try {
    this->m_map[key] = func;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ConfState");
  }
}

void	ConfState::modKey(const int oldKey, const int newKey) {
  try {
    this->m_map[newKey] = this->m_map[oldKey];
    this->m_map.erase(oldKey);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ConfState");
  }
}

void	ConfState::delKey(const int key) {
  try {
    this->m_map.erase(key);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ConfState");
  }
}

void	ConfState::delAllKey() {
  try {
    while (!this->m_map.empty())
      this->m_map.erase(this->m_map.begin());
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ConfState");
  }
}

void	ConfState::Init(GameEngine *game){
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
    this->m_backx->Init(3, 12, 0.0, 1.0);
    this->m_backnbAI->Init(3, 12, 0.0, 1.0);
    this->m_backDifficulty->Init(3, 12, 0.0, 1.0);
    this->m_iterator = 0;
    this->m_head->Init(2.0, 2.0, 1.0, 1.0);
    this->m_head->setY(this->m_player[0]->getY(), -25);
    while (this->m_it != this->m_button.end()){
      (*this->m_it)->Init(5.0, 10.0, 1.0);
      this->m_it++;
    }
    this->m_it = this->m_button.end();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ConfState");
  }
}

void	ConfState::Cleanup(){
}

void	ConfState::Pause(){
}

void	ConfState::Resume(GameEngine *){
  try {
    this->m_released = true;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ConfState");
  }
}

void	ConfState::Update(GameEngine *game){
  std::map<int, m_tabFun>::iterator	it = this->m_map.begin();
  int					name = SDLK_0;

  try {
    while (name <= SDLK_9){
      if (game->getInput().getKey(name, this->m_released)){
	return (this->writeName(name, game));
      }
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
    throw ErrorBomberman(e.what(), "ConfState");
  }
}

void	ConfState::Draw(GameEngine *game){
  std::vector<Button *>::iterator	it = this->m_button.begin();

  try {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    game->getShader().bind();
    this->m_background->Draw(game->getShader());
    this->m_backx->Draw(game->getShader());
    this->m_backnbAI->Draw(game->getShader());
    this->m_backDifficulty->Draw(game->getShader());
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
    throw ErrorBomberman(e.what(), "ConfState");
  }
}

void	ConfState::Up(GameEngine *){
  try {
    this->m_released = true;
    if (this->m_iterator < 3){
      if (this->m_iterator == 0){
	this->m_it = this->m_button.end() - 1;
	this->m_iterator = 4;
	this->m_head->setY((*this->m_it)->getY(), -25);
      } else {
	this->m_it = this->m_button.end();
	this->m_iterator --;
	this->m_head->setY(this->m_player[this->m_iterator * 2]->getY(), -25);
      }
    } else {
      if (!this->m_button.empty() && (this->m_it == this->m_button.begin())){
	this->m_it = this->m_button.end();
	this->m_iterator = 2;
	this->m_head->setY(this->m_player[this->m_iterator * 2]->getY(), -25);
      } else {
	this->m_iterator--;
	this->m_it--;
	this->m_head->setY((*this->m_it)->getY(), -25);
      }
    }
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ConfState");
  }
}

void	ConfState::Down(GameEngine *){
  try {
    this->m_released = true;
    if (this->m_iterator < 3){
      if (this->m_iterator == 2){
	this->m_it = this->m_button.begin();
	this->m_iterator = 3;
	this->m_head->setY((*this->m_it)->getY(), -25);
      } else {
	this->m_it = this->m_button.end();
	this->m_iterator++;
	this->m_head->setY(this->m_player[this->m_iterator * 2]->getY(), -25);
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
    throw ErrorBomberman(e.what(), "ConfState");
  }
}

bool	ConfState::rightNumber(){
  if (!this->m_x.empty() &&
      !this->m_nbAI.empty() &&
      !this->m_difficulty.empty() &&
      StringToNumber<int>(this->m_x) >= 10 &&
      StringToNumber<int>(this->m_nbAI) > 0 &&
      StringToNumber<int>(this->m_difficulty) > 0) {
	GameState::Instance()->setWidth(StringToNumber<int>(this->m_x));
	GameState::Instance()->setHeight(StringToNumber<int>(this->m_x));
	GameState::Instance()->setNbrAI(StringToNumber<int>(this->m_nbAI));
	GameState::Instance()->setDifficulty(StringToNumber<int>(this->m_difficulty));
    return true;
  }
  return false;
}

void	ConfState::Enter(GameEngine *game){
  try {
    this->m_released = true;
    pthread_create(&game->getPthread(), &game->getAttr(),
		   pthreadSound, (void *)BUTTON_21);
    if (this->m_it != this->m_button.end()){
      return ((*this->m_it)->Draw(game->getShader(), ENFONCE, game));
    }
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ConfState");
  }
}

std::vector<Button *>::iterator	&ConfState::getIterator(){
  try {
    return (this->m_it);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ConfState");
  }
}

std::vector<Button *>		&ConfState::getVector(){
  try {
    return (this->m_button);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ConfState");
  }
}

void				ConfState::setReleased(bool mybool){
  try {
    this->m_released = mybool;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ConfState");
  }
}

void	ConfState::QuitState(GameEngine *game){
  try {
    this->m_released = true;
    return (game->PopState());
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ConfState");
  }
}

void	ConfState::Quit(GameEngine *game){
  try {
    game->Quit();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ConfState");
  }
}

static void	moveState(GameEngine *game){
  try {
    ConfState::Instance()->setReleased(true);
    switch (ConfState::Instance()->getIterator() -
	    ConfState::Instance()->getVector().begin()){
    case ConfState::PLAY:
      if (ConfState::Instance()->rightNumber()) {
	game->getMusic().stop();
	return (game->PushState(GameState::Instance()));
      }
      break;
    case ConfState::EXIT:
      return (game->PopState());
      break;
    }
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ConfState");
  }
}

void	ConfState::writeText(GameEngine *game, std::string &name, int const letter){
  if (name.length() < 10){
    name += letter;
    delete this->m_player[this->m_iterator * 2 + 1];
    this->m_player[this->m_iterator * 2 + 1] =
      new GenerateText(name, 2, this->m_player[this->m_iterator * 2]->getY());
    this->m_player[this->m_iterator * 2 + 1]->Init();
  } else
    pthread_create(&game->getPthread(), &game->getAttr(),
		   pthreadSound, (void *)GOD_LIKE);
}

void	ConfState::writeName(int letter, GameEngine *game){
  switch (this->m_iterator){
  case 0:
    if (StringToNumber<int>(this->m_x) <= 10000)
      return this->writeText(game, this->m_x, letter);
    break;
  case 1:
    if (StringToNumber<int>(this->m_nbAI) <
	(StringToNumber<int>(this->m_x) *
	 StringToNumber<int>(this->m_x) * 0.30))
      return this->writeText(game, this->m_nbAI, letter);
    break;
  case 2:
    if ((letter == '1' || letter == '2' || letter == '3') &&
	this->m_difficulty.length() == 0)
      return this->writeText(game, this->m_difficulty, letter);
    break;
  }
  pthread_create(&game->getPthread(), &game->getAttr(),
		 pthreadSound, (void *)DING);
}

void	ConfState::removeOneLetter(GameEngine *game, std::string &name){
  if (name.length() > 0){
    name = name.substr(0, name.length() - 1);
    delete this->m_player[this->m_iterator * 2 + 1];
    this->m_player[this->m_iterator * 2 + 1] =
      new GenerateText(name, 2, this->m_player[this->m_iterator * 2]->getY());
    this->m_player[this->m_iterator * 2 + 1]->Init();
  } else
    pthread_create(&game->getPthread(), &game->getAttr(),
		   pthreadSound, (void *)DING);
}

void	ConfState::removeLetter(GameEngine *game){
  switch (this->m_iterator){
  case 0:
    this->removeOneLetter(game, this->m_x);
    break;
  case 1:
    this->removeOneLetter(game, this->m_nbAI);
    break;
  case 2:
    this->removeOneLetter(game, this->m_difficulty);
    break;
  }
}
