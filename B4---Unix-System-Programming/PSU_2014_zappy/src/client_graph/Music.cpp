//
// Music.cpp for  in /home/tang_i/rendu/PSU_2014_zappy/annexes/sfml2d
// 
// Made by David Tang
// Login   <tang_i@epitech.net>
// 
// Started on  Fri Jun 19 14:06:52 2015 David Tang
// Last update Mon Jun 29 19:06:07 2015 Raphael Teyssandier
//

#include "Music.hh"

Music::Music(){
  try {
    this->m_sound = new sf::Music;
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Music");
  }
}

Music::~Music(){
  try {
    delete this->m_sound;
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Music");
  }
}

void	Music::loadMusic(const std::string &title) const{
  try {
    if (this->m_sound != NULL) {
      this->m_sound->stop();
    }
    if (this->m_sound->openFromFile(title) == false)
      throw ErrorClient("Unable to open music file", "Music");
    this->m_sound->setLoop(true);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Music");
  }
}

void	Music::playMusic() const{
  try {
    this->m_sound->play();
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Music");
  }
}

void	Music::stopMusic() const{
  try {
    this->m_sound->stop();
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Music");
  }
}

sf::Music	*Music::getSound() const{
  try {
    return (this->m_sound);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Music");
  }
}
