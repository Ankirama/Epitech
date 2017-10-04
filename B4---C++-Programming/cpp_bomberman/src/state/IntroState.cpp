#include <SFML/Audio.hpp>
#include "IntroState.hh"
#include "GameState.hh"
#include "OptionState.hh"
#include "ScoreState.hh"
#include "LoadState.hh"
#include "PlayState.hh"
#include "Error.hpp"

IntroState	IntroState::m_IntroState;

static void	moveState(GameEngine *);
static void	QuitGame(GameEngine *);

IntroState::IntroState() : IGameState(){
  try {
    this->addKey(SDLK_UP, &IntroState::Up);
    this->addKey(SDLK_DOWN, &IntroState::Down);
    this->addKey(SDLK_RETURN, &IntroState::Enter);
    this->addKey(SDLK_ESCAPE, &IntroState::Quit);
    this->addKey(SDLK_a, &IntroState::keyA);
    this->addKey(SDLK_b, &IntroState::keyB);
    this->addKey(SDLK_LEFT, &IntroState::Left);
    this->addKey(SDLK_RIGHT, &IntroState::Right);
    this->addKey(SDL_QUIT, &IntroState::Quit);
    this->m_background = new Object2D(BACK_IMG, 0, 0, -1);
    this->m_bomb_left = new Object2D(HEAD_IMG, 0, -10, 1);
    this->m_button.push_back(new Button(BUT_PLAY_1, BUT_PLAY_2, 0, -10, &moveState));
    this->m_button.push_back(new Button(BUT_LOAD_1, BUT_LOAD_2, 0, 0, &moveState));
    this->m_button.push_back(new Button(BUT_TP10_1, BUT_TP10_2, 0, 10, &moveState));
    this->m_button.push_back(new Button(BUT_OPTN_1, BUT_OPTN_2, 0, 20, &moveState));
    this->m_button.push_back(new Button(BUT_EXIT_1, BUT_EXIT_2, 0, 30, &QuitGame));
    this->m_easter.push_back(std::string("Up"));
    this->m_easter.push_back(std::string("Up"));
    this->m_easter.push_back(std::string("Down"));
    this->m_easter.push_back(std::string("Down"));
    this->m_easter.push_back(std::string("Left"));
    this->m_easter.push_back(std::string("Right"));
    this->m_easter.push_back(std::string("Left"));
    this->m_easter.push_back(std::string("Right"));
    this->m_easter.push_back(std::string("B"));
    this->m_easter.push_back(std::string("A"));
    this->m_easterIt = this->m_easter.begin();
    this->m_it = this->m_button.begin();
    this->m_released = true;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "IntroState");
  }
}

IntroState::~IntroState() {
  try {
    while (!this->m_button.empty()){
      delete this->m_button.front();
      this->m_button.erase(this->m_button.begin());
    }
    delete this->m_background;
    delete this->m_bomb_left;
    this->delAllKey();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "IntroState");
  }
}

void	IntroState::addKey(const int key, m_tabFun func) {
  try {
    this->m_map[key] = func;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "IntroState");
  }
}

void	IntroState::modKey(const int oldKey, const int newKey) {
  try {
    this->m_map[newKey] = this->m_map[oldKey];
    this->m_map.erase(oldKey);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "IntroState");
  }
}

void	IntroState::delKey(const int key) {
  try {
    this->m_map.erase(key);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "IntroState");
  }
}

void	IntroState::delAllKey() {
  try {
    while (!this->m_map.empty())
      this->m_map.erase(this->m_map.begin());
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "IntroState");
  }
}

void	IntroState::Init(GameEngine *game){
  glm::mat4 projection;
  glm::mat4 transformation;

  try {
    projection = glm::perspective(100.0f, 800.0f / 600.0f, 0.1f, 100.0f);
    transformation = glm::lookAt(glm::vec3(0, 0, 30), glm::vec3(0, 0, 0),
				 glm::vec3(-90, 0, 0));
    game->getShader().bind();
    this->m_background->Init(38.5, 51.0, -1.0, 1.0);
    this->m_bomb_left->Init(2.0, 2.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    game->getShader().setUniform("view", transformation);
    game->getShader().setUniform("projection", projection);
    this->m_bomb_left->setY((*this->m_it)->getY(), -10);
    this->m_it = this->m_button.begin();
    while (this->m_it != this->m_button.end()){
      (*this->m_it)->Init(5.0, 10.0, 1.0);
      this->m_it++;
    }
    this->m_it = this->m_button.begin();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "IntroState");
  }
}

void	IntroState::Cleanup(){
}

void	IntroState::Pause(){
}

void	IntroState::Resume(GameEngine *game){
  try {
    this->m_released = true;
    this->Init(game);
    this->m_bomb_left->setY(this->m_button.front()->getY(), -10);
    std::vector<Button *>::iterator	it = this->m_button.begin();
    int					i = -10;

    while (it != this->m_button.end()){
      (*it)->setY(i, 0);
      it++;
      i += 10;
    }
    this->m_it = this->m_button.begin();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "IntroState");
  }
}

void	IntroState::Update(GameEngine *game){
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
    throw ErrorBomberman(e.what(), "IntroState");
  }
}

void	IntroState::Draw(GameEngine *game){
  std::vector<Button *>::iterator	it = this->m_button.begin();

  try {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    game->getShader().bind();
    this->m_background->Draw(game->getShader());
    this->m_bomb_left->Draw(game->getShader());
    while (it != this->m_button.end()){
      if (it != this->m_it)
	(*it)->Draw(game->getShader(), PAS_SURVOLE, game);
      it++;
    }
    (*this->m_it)->Draw(game->getShader(), SURVOLE, game);
    game->getContext().flush();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "IntroState");
  }
}

void	IntroState::Up(GameEngine *){
  try {
    this->m_released = true;
    if (!this->m_button.empty() && (this->m_it == this->m_button.begin()))
      this->m_it = this->m_button.end() - 1;
    else
      this->m_it--;
    this->m_bomb_left->setY((*this->m_it)->getY(), -10);
    if ("Up" == (*(this->m_easterIt)))
      this->m_easterIt++;
    else
      this->m_easterIt = this->m_easter.begin();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "IntroState");
  }
}

void	IntroState::Down(GameEngine *){
  try {
    this->m_released = true;
    if (!this->m_button.empty() && (this->m_it == this->m_button.end() - 1))
      this->m_it = this->m_button.begin();
    else
      this->m_it++;
    this->m_bomb_left->setY((*this->m_it)->getY(), -10);
    if ("Down" == (*(this->m_easterIt)))
      this->m_easterIt++;
    else
      this->m_easterIt = this->m_easter.begin();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "IntroState");
  }
}

void	IntroState::Left(GameEngine *){
  this->m_released = true;
  if ("Left" == (*(this->m_easterIt)))
    this->m_easterIt++;
  else
    this->m_easterIt = this->m_easter.begin();
}

void	IntroState::Right(GameEngine *){
  this->m_released = true;
  if ("Right" == (*(this->m_easterIt)))
    this->m_easterIt++;
  else
    this->m_easterIt = this->m_easter.begin();
}

void	IntroState::keyA(GameEngine *game){
  this->m_released = true;
  if ("A" == (*(this->m_easterIt))){
    this->m_easterIt++;
    Object2D	*background = new Object2D("./ressources/img/Carmen.tga", 0, 0, -1);
    background->Init(38.5, 51.0, 2.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    game->getShader().bind();
    this->m_background->Draw(game->getShader());
    background->Draw(game->getShader());
    game->getContext().flush();
    this->m_easterIt = this->m_easter.begin();
    pthread_create(&game->getPthread(), &game->getAttr(),
		   pthreadSound, (void *)BB_TRIPLE);
    for (int i = 0;i < 1000000000;++i){
    }
  }
  else
    this->m_easterIt = this->m_easter.begin();
}

void	IntroState::keyB(GameEngine *){
  this->m_released = true;
  if ("B" == (*(this->m_easterIt)))
    this->m_easterIt++;
  else
    this->m_easterIt = this->m_easter.begin();
}

void	IntroState::Enter(GameEngine *game){
  try {
    this->m_released = true;
    this->m_background->Draw(game->getShader());
    if (this->m_it != this->m_button.end() - 1)
      pthread_create(&game->getPthread(), &game->getAttr(),
		     pthreadSound, (void *)BUTTON_21);
    return ((*this->m_it)->Draw(game->getShader(), ENFONCE, game));
    this->m_easterIt = this->m_easter.begin();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "IntroState");
  }
}

std::vector<Button *>::iterator	&IntroState::getIterator(){
  return (this->m_it);
}

std::vector<Button *>		&IntroState::getVector(){
  return (this->m_button);
}

void				IntroState::setReleased(bool mybool){
  try {
    this->m_released = mybool;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "IntroState");
  }
}

static void	moveState(GameEngine *game){
  try {
    IntroState::Instance()->setReleased(false);
    switch (IntroState::Instance()->getIterator() -
	    IntroState::Instance()->getVector().begin()){
    case IntroState::PLAY:
      IntroState::Instance()->Style(game);
      return (game->PushState(PlayState::Instance()));
      break;
    case IntroState::LOAD:
      IntroState::Instance()->Style(game);
      return (game->PushState(LoadState::Instance()));
      break;
    case IntroState::SCORE:
      IntroState::Instance()->Style(game);
      return (game->PushState(ScoreState::Instance()));
      break;
    case IntroState::OPTION:
      IntroState::Instance()->Style(game);
      return (game->PushState(OptionState::Instance()));
      break;
    case IntroState::QUIT:
      return (game->Quit());
      break;
    }
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "IntroState");
  }
}

void	IntroState::Quit(GameEngine *game){
  try {
    game->Quit();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "IntroState");
  }
}

void	IntroState::styleDraw(GameEngine *game, int i,
			      std::vector<Button *>::iterator it){
  try {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    this->m_background->Draw(game->getShader());
    game->getShader().bind();
    (*it)->setY((*it)->getY(), -i * 2);
    (*it)->Draw(game->getShader(), PAS_SURVOLE, game);
    for (std::vector<Button *>::iterator tmp = this->m_button.begin();
	 tmp != this->m_button.end(); ++tmp){
      if (tmp != this->m_it && tmp != it)
	(*tmp)->Draw(game->getShader(), PAS_SURVOLE, game);
    }
    (*this->m_it)->Draw(game->getShader(), SURVOLE, game);
    game->getContext().flush();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "IntroState");
  }
}

void	IntroState::Style(GameEngine *game){
  std::vector<Button *>::iterator	it;
  gdl::Clock				clock;
  int					i = 0;

  try {
    it = this->m_button.begin();
    while (it < this->m_it){
      if (this->m_it != it){
	i = 0;
	while (i < 30){
	  this->styleDraw(game, i * 2, it);
	  i++;
	}
      }
      it++;
    }
    while (it < this->m_button.end()){
      if (this->m_it != it){
	i = 0;
	while (i < 30){
	  this->styleDraw(game, -i * 2, it);
	  i++;
	}
      }
      it++;
    }
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "IntroState");
  }
}

static	void	QuitGame(GameEngine *game){
  try {
    game->Quit();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "IntroState");
  }
}
