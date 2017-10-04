//
// Button.cpp for  in /home/teyssa_r/rendu/cpp_bomberman
// 
// Made by Raphael Teyssandier
// Login   <teyssa_r@epitech.net>
// 
// Started on  Tue May 12 21:45:13 2015 Raphael Teyssandier
// Last update Tue May 19 15:52:12 2015 CHARLES VITERBO
//

#include "Button.hh"
#include "GameEngine.hh"

Button::Button(const std::string &path1, const std::string &path2,
	       const int x, const int y, void (*func)(GameEngine *)){
  this->m_func = func;
  this->m_container.push_back(new Object2D(path1, y, x, 0));
  this->m_container.push_back(new Object2D(path2, y, x, 0));
}

Button::~Button(){
  if (!this->m_container.empty()){
  this->m_container.pop_back();
  this->m_container.pop_back();
  }
}

void		Button::Init(const float x, const float y, const float z){
  std::vector<Object2D *>::iterator	it = this->m_container.begin();

  while (it != this->m_container.end()){
    (*it)->Init(x, y, z, 1.0);
    it++;
  }
}

int		Button::getY() const{
  return (this->m_container.back()->getY());
}

void		Button::setY(const int y, const int x){
  this->m_container.front()->setY(y, x);
}

void		Button::Draw(gdl::BasicShader shader, const e_Etat etat,
			     GameEngine *game){
  if (!this->m_container.empty())
    switch (etat){
    case PAS_SURVOLE:
      this->m_container.front()->Draw(shader);
      break;
    case SURVOLE:
      this->m_container.back()->Draw(shader);
      break;
    case ENFONCE:
      return (this->m_func(game));
      break;
    }
}

