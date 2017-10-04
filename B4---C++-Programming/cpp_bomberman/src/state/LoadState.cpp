#include "LoadState.hh"
#include "IntroState.hh"
#include "GameState.hh"
#include "Error.hpp"
#include "XmlLoad.hh"
#include "ListDir.hh"

LoadState	LoadState::m_LoadState;

static void	QuitButton(GameEngine *);

LoadState::LoadState(){
  try {
  this->addKey(SDLK_ESCAPE, &LoadState::QuitState);
  this->addKey(SDLK_RETURN, &LoadState::Enter);
  this->addKey(SDLK_UP, &LoadState::Up);
  this->addKey(SDLK_DOWN, &LoadState::Down);
  this->addKey(SDL_QUIT, &LoadState::Quit);
  this->m_background = new Object2D(BACK_IMG, 0, 0, -1);
  this->m_backsave = new Object2D(BACK_NAME, 6, 0, 0);
  this->m_bomb = new Object2D(HEAD_IMG, -25, -5, -1);
  this->m_button.push_back(new Button(BUT_LOAD_1, BUT_LOAD_2, 0, 23, &QuitButton));
  this->m_button.push_back(new Button(BUT_BACK_1, BUT_BACK_2, 0, 30, &QuitButton));
  this->m_it = this->m_button.begin();
  this->m_released = true;
  this->m_load = false;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "LoadState");
  }
}

LoadState::~LoadState() {
  try {
    delete this->m_background;
    delete this->m_backsave;
    delete this->m_bomb;
    while (!this->m_button.empty()){
      delete this->m_button.front();
      this->m_button.erase(this->m_button.begin());
    }
    this->delAllKey();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "LoadState");
  }
}

void	LoadState::addKey(const int key, m_tabFun func) {
  try {
    this->m_map[key] = func;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "LoadState");
  }
}

void	LoadState::modKey(const int oldKey, const int newKey) {
  try {
    this->m_map[newKey] = this->m_map[oldKey];
    this->m_map.erase(oldKey);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "LoadState");
  }
}

void	LoadState::delKey(const int key) {
  try {
    this->m_map.erase(key);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "LoadState");
  }
}

void	LoadState::delAllKey() {
  try {
    while (!this->m_map.empty())
      this->m_map.erase(this->m_map.begin());
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "LoadState");
  }
}

void	LoadState::Init(GameEngine *game){
  try {
    glm::mat4			projection;
    glm::mat4			transformation;
    ListDir			*list = new ListDir();
    std::vector<std::string>	listFile = list->getFiles("./ressources/save/");
    std::vector<std::string>::iterator it = listFile.begin();
    int	i = -5;

    while (it != listFile.end() && i != 20){
      this->m_file.push_back(new GenerateText((*it), -20, i));
      this->m_file.back()->Init();
      i += 5;
      it++;
    }
    this->m_itFile = this->m_file.begin();
    this->m_load = false;
    projection = glm::perspective(100.0f, 800.0f / 600.0f, 0.1f, 100.0f);
    transformation = glm::lookAt(glm::vec3(0, 0, 30), glm::vec3(0, 0, 0),
				 glm::vec3(-90, 0, 0));
    this->m_background->Init(38.5, 51.0, -1.0, 1.0);
    this->m_backsave->Init(20, 26.5, -1.0, 1.0);
    this->m_button[0]->Init(5.0, 10.0, 1.0);
    this->m_button[1]->Init(5.0, 10.0, 1.0);
    this->m_bomb->Init(2.0, 2.0, 1.0, 1.0);
    this->m_bomb->setY((*this->m_itFile)->getY(), -25);
    game->getShader().bind();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    game->getShader().setUniform("view", transformation);
    game->getShader().setUniform("projection", projection);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "LoadState");
  }
}

void	LoadState::Cleanup(){
}

void	LoadState::Pause(){
}

void	LoadState::Resume(GameEngine *){
  try {
    this->m_released = true;
    this->m_load = false;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "LoadState");
  }
}

void	LoadState::Update(GameEngine *game){
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
    this->m_released = true;
    game->getContext().updateInputs(game->getInput());
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "LoadState");
  }
}

void	LoadState::Draw(GameEngine *game){
  std::vector<Button *>::iterator	it = this->m_button.begin();
  std::vector<GenerateText *>::iterator	itFile = this->m_file.begin();
  int					i = 0;

  try {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    game->getShader().bind();
    this->m_background->Draw(game->getShader());
    this->m_backsave->Draw(game->getShader());
    while (itFile != this->m_file.end() && i < 5){
      (*itFile)->Draw(game->getShader());
      itFile++;
      i++;
    }
    while (it != this->m_button.end()){
      if (it != this->m_it)
	(*it)->Draw(game->getShader(), PAS_SURVOLE, game);
      it++;
    }
    if (!this->m_load)
      (*this->m_it)->Draw(game->getShader(), SURVOLE, game);
    else {
      (*this->m_it)->Draw(game->getShader(), PAS_SURVOLE, game);
      this->m_bomb->Draw(game->getShader());
    }
    game->getContext().flush();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "LoadState");
  }
}

void	LoadState::Up(GameEngine *){
  try {
    this->m_released = true;
    if (this->m_load){
      if (!this->m_file.empty() && this->m_itFile == this->m_file.begin())
	this->m_itFile = this->m_file.end() - 1;
      else
	this->m_itFile--;
      this->m_bomb->setY((*this->m_itFile)->getY(), -25);
    } else {
      if (!this->m_button.empty() && this->m_it == this->m_button.begin())
	this->m_it = this->m_button.end() - 1;
      else
	this->m_it--;
    }
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "LoadState");
  }
}

void	LoadState::Down(GameEngine *){
  try {
    this->m_released = true;
    if (this->m_load){
      if (!this->m_file.empty() && this->m_itFile == this->m_file.end() - 1)
	this->m_itFile = this->m_file.begin();
      else
	this->m_itFile++;
      this->m_bomb->setY((*this->m_itFile)->getY(), -25);
    } else {
      if (!this->m_button.empty() && this->m_it == this->m_button.end() - 1)
	this->m_it = this->m_button.begin();
      else
	this->m_it++;
    }
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "LoadState");
  }
}

void	LoadState::Enter(GameEngine *game){
  try {
    this->m_released = false;
    pthread_create(&game->getPthread(), &game->getAttr(),
		   pthreadSound, (void *)BUTTON_21);
    if (this->m_load){
      XmlLoad	*load = new XmlLoad(std::string("ressources/save/") + 
				    (*this->m_itFile)->getStr() +
				    std::string(".save"));
      load->loadSave();
      delete load;
      return (game->ChangeState(GameState::Instance()));
    }
    if (this->m_it == this->m_button.begin() && !this->m_load)
      this->m_load = true;
    else
      return ((*this->m_it)->Draw(game->getShader(), ENFONCE, game));
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "LoadState");
  }
}

std::vector<Button *>::iterator	&LoadState::getIterator(){
  return (this->m_it);
}

std::vector<Button *>		&LoadState::getVector(){
  return (this->m_button);
}

void				LoadState::setReleased(bool mybool){
  try {
    this->m_released = mybool;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "LoadState");
  }
}

void	LoadState::QuitState(GameEngine *game){
  try {
    this->m_released = false;
    if (this->m_load)
      this->m_load = false;
    else
      return (game->PopState());
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "LoadState");
  }
}

void	LoadState::Quit(GameEngine *game){
  try {
    game->Quit();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "LoadState");
  }
}

static void	QuitButton(GameEngine *game){
  try {
    game->PopState();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "LoadState");
  }
}
