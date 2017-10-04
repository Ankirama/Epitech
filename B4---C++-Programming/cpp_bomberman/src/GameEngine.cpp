#include "IGameState.hh"
#include "GameEngine.hh"
#include "SdlContext.hh"
#include "Error.hpp"
#include <pthread.h>
#include <SFML/Audio.hpp>

GameEngine::GameEngine() {
}

GameEngine::~GameEngine() {
}

bool		GameEngine::initialize() {
  glm::mat4 projection;
  glm::mat4 transformation;

  try {
    pthread_attr_init(&this->m_attr);
    pthread_attr_setdetachstate(&this->m_attr, PTHREAD_CREATE_DETACHED);
    this->m_running = true;
    if (!this->m_music.openFromFile(START_MUSIC))
      throw ErrorBomberman("Cannot load the start music", "GameEngine");
    if (!this->m_context.start(1280, 720, "Bomberman v1.1"))
      return (false);
    if (!this->m_shader.load("./lib/gdl/shaders/basic.fp", GL_FRAGMENT_SHADER) ||
        !this->m_shader.load("./lib/gdl/shaders/basic.vp", GL_VERTEX_SHADER) ||
        !this->m_shader.build())
      throw ErrorBomberman("Unable to load shader", "GameState");
    glEnable(GL_DEPTH_TEST);
    return (true);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameEngine");
  }
}

void	*pthreadSound(void *str){
  sf::SoundBuffer     buffer;
  sf::Sound           sound;

  if (!buffer.loadFromFile((char *)str)){
      std::cerr << "sf::SoundBuffer: error load" << std::endl;
  }
  sound.setBuffer(buffer);
  sound.setVolume(100.0f);
  sound.play();
  while (sound.getStatus() == sf::Sound::Status::Playing){
  }
  return (NULL);
}

void	GameEngine::Cleanup(){
  try {
    while (!this->m_states.empty()){
      this->m_states.back()->Cleanup();
      this->m_states.pop_back();
    }
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameEngine");
  }
}

void	GameEngine::ChangeState(IGameState *state) {
  try {
    if (!this->m_states.empty()){
      this->m_states.back()->Cleanup();
      this->m_states.pop_back();
    }
    this->m_states.push_back(state);
    this->m_states.back()->Init(this);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameEngine");
  }
}

void	GameEngine::PushState(IGameState *state) {
  try {
    if (!this->m_states.empty()){
      this->m_states.back()->Pause();
    }
    this->m_states.push_back(state);
    this->m_states.back()->Init(this);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameEngine");
  }
}

void	GameEngine::PopState() {
  try {
    if (!this->m_states.empty()){
      this->m_states.back()->Cleanup();
      this->m_states.pop_back();
    }
    if (!this->m_states.empty()){
      this->m_states.back()->Resume(this);
    }
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameEngine");
  }
}

bool	GameEngine::update() {
  try {
    this->m_context.updateClock(this->m_clock);
    this->m_states.back()->Update(this);
    return (true);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameEngine");
  }
}

void	GameEngine::draw() {
  try {
    this->m_states.back()->Draw(this);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameEngine");
  }
}

gdl::SdlContext	GameEngine::getContext() const{
  try {
    return (this->m_context);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameEngine");
  }
}

gdl::Clock	&GameEngine::getClock() {
  try {
    return (this->m_clock);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameEngine");
  }
}

gdl::Clock	GameEngine::getClock() const{
  try {
    return (this->m_clock);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameEngine");
  }
}

void	GameEngine::resizeWindow(int width, int height) {
  glm::mat4 projection;
  glm::mat4 transformation;

  try {
    this->m_running = true;
    this->m_context.stop();
    if (!this->m_context.start(width, height, "Bomberman v1.0"))
      throw ErrorBomberman("Unable to start window", "GameEngine");
    this->m_states.front()->Init(this);
    this->m_states.back()->Init(this);
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "GameEngine");
  }
}

bool	GameEngine::getLock() const{
  return (this->m_lock);
}

void	GameEngine::setLock(const bool lock){
  this->m_lock = lock;
}

gdl::BasicShader	&GameEngine::getShader(){
  return (this->m_shader);
}

gdl::Input	&GameEngine::getInput(){
  return (this->m_input);
}
