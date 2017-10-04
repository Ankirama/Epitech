//
// Tile.cpp for  in /home/tang_i/rendu/PSU_2014_zappy/annexes/sfml2d
// 
// Made by David Tang
// Login   <tang_i@epitech.net>
// 
// Started on  Wed Jun 24 15:48:40 2015 David Tang
// Last update Mon Jun 29 19:11:19 2015 Raphael Teyssandier
//

#include "Tile.hh"

Tile::Tile() {}

Tile::Tile(const tileType type, sf::Texture &_texture,
	   unsigned int _size, unsigned int _height) : m_type(type){
  try {
    this->m_sprite.setOrigin(sf::Vector2f(0.0f , _size * (_height - 1)));
    this->m_sprite.setTexture(_texture);
    for (unsigned int i = 0; i < NB_OBJ; ++i)
      m_tab[i] = 0;
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Tile");
  }
}

Tile::Tile(Tile const &t) : m_type(t.m_type),
			    m_sprite(t.m_sprite){
  try {
    for (unsigned int i = 0; i < NB_OBJ; ++i)
      m_tab[i] = 0;
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Tile");
  }
}

Tile::~Tile() {}

void		Tile::drawTile(sf::RenderWindow *window){
  try {
    window->draw(getSprite());
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Tile");
  }
}

tileType	Tile::getType() const{
  try {
    return (this->m_type);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Tile");
  }
}

sf::Sprite	&Tile::getSprite(){
  try {
    return (this->m_sprite);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Tile");
  }
}

void		Tile::setInv(unsigned int i, unsigned int value){
  try {
    this->m_tab[i] = value;
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Tile");
  }
}

int	Tile::getWidth() const {
  try {
    return this->m_sprite.getTexture()->getSize().x;
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Tile");
  }
}

int	Tile::getHeight() const {
  try {
    return this->m_sprite.getTexture()->getSize().y;
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Tile");
  }
}
