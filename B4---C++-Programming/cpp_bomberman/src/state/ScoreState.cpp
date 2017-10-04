#include "ScoreState.hh"
#include "IntroState.hh"
#include "GameState.hh"
#include "Score.hh"
#include "Error.hpp"
#include "template_string.hh"

ScoreState	ScoreState::m_ScoreState;

static void	QuitButton(GameEngine *);

ScoreState::ScoreState(){
  try {
  this->addKey(SDLK_ESCAPE, &ScoreState::QuitState);
  this->addKey(SDLK_RETURN, &ScoreState::Enter);
  this->addKey(SDL_QUIT, &ScoreState::Quit);
  this->m_background = new Object2D(BACK_IMG, 0, 0, -1);
  this->m_backname = new Object2D(BACK_NAME, 6, 0, 0);
  this->m_button.push_back(new Button(BUT_BACK_1, BUT_BACK_2, 0, 30, &QuitButton));
  this->m_released = true;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ScoreState");
  }
}

ScoreState::~ScoreState() {
  try {
    delete this->m_background;
    delete this->m_backname;
    while (!this->m_button.empty()){
      delete this->m_button.front();
      this->m_button.erase(this->m_button.begin());
    }
    this->delAllKey();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ScoreState");
  }
}

void	ScoreState::addKey(const int key, m_tabFun func) {
  try {
    this->m_map[key] = func;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ScoreState");
  }
}

void	ScoreState::modKey(const int oldKey, const int newKey) {
  try {
    this->m_map[newKey] = this->m_map[oldKey];
    this->m_map.erase(oldKey);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ScoreState");
  }
}

void	ScoreState::delKey(const int key) {
  try {
    this->m_map.erase(key);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ScoreState");
  }
}

void	ScoreState::delAllKey() {
  try {
    while (!this->m_map.empty())
      this->m_map.erase(this->m_map.begin());
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ScoreState");
  }
}

void	ScoreState::Init(GameEngine *game){
  glm::mat4 projection;
  glm::mat4 transformation;
  std::vector<std::pair<std::string, unsigned int> >	top = Score::getInstance().getTopN(10);
  std::vector<std::pair<std::string, unsigned int> >::const_iterator	it = top.begin();
  int	i = -12;

  try {
    while (it != top.end()){
      this->m_top.push_back(new GenerateText(it->first + std::string(" ") +
					     NumberToString<unsigned int>(it->second),
					     -22, i));
      this->m_top.back()->Init();
      it++;
      i += 5;
    }
    projection = glm::perspective(100.0f, 800.0f / 600.0f, 0.1f, 100.0f);
    transformation = glm::lookAt(glm::vec3(0, 0, 30), glm::vec3(0, 0, 0),
				 glm::vec3(-90, 0, 0));
    this->m_background->Init(38.5, 51.0, -1.0, 1.0);
    this->m_backname->Init(32, 30, -1.0, 1.0);
    game->getShader().bind();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    game->getShader().setUniform("view", transformation);
    game->getShader().setUniform("projection", projection);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ScoreState");
  }
}

void	ScoreState::Cleanup(){
}

void	ScoreState::Pause(){
}

void	ScoreState::Resume(GameEngine *){
  try {
    this->m_released = true;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ScoreState");
  }
}

void	ScoreState::Update(GameEngine *game){
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
    throw ErrorBomberman(e.what(), "ScoreState");
  }
}

void	ScoreState::Draw(GameEngine *game){
  try {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    game->getShader().bind();
    this->m_it = this->m_button.begin();
    this->m_background->Draw(game->getShader());
    this->m_backname->Draw(game->getShader());
    for (std::vector<GenerateText *>::iterator it = this->m_top.begin();
	 it != this->m_top.end(); ++it){
      (*it)->Draw(game->getShader());
    }
    (*this->m_it)->Init(5.0, 10.0, 1.0);
    this->m_it = this->m_button.begin();
    (*this->m_it)->Draw(game->getShader(), SURVOLE, game);
    game->getContext().flush();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ScoreState");
  }
}

void	ScoreState::Enter(GameEngine *game){
  try {
    this->m_released = false;
    pthread_create(&game->getPthread(), &game->getAttr(),
		   pthreadSound, (void *)BUTTON_21);
    return ((*this->m_it)->Draw(game->getShader(), ENFONCE, game));
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ScoreState");
  }
}

std::vector<Button *>::iterator	&ScoreState::getIterator(){
  return (this->m_it);
}

std::vector<Button *>		&ScoreState::getVector(){
  return (this->m_button);
}

void				ScoreState::setReleased(bool mybool){
  try {
    this->m_released = mybool;
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ScoreState");
  }
}

void	ScoreState::QuitState(GameEngine *game){
  try {
    this->m_released = false;
    return (game->PopState());
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ScoreState");
  }
}

void	ScoreState::Quit(GameEngine *game){
  try {
    game->Quit();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ScoreState");
  }
}

static void	QuitButton(GameEngine *game){
  try {
    game->PopState();
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "ScoreState");
  }
}
