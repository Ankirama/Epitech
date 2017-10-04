//
// Item.cpp for  in /home/tang_i/rendu/PSU_2014_zappy
// 
// Made by David Tang
// Login   <tang_i@epitech.net>
// 
// Started on  Mon Jun 29 01:29:23 2015 David Tang
// Last update Mon Jun 29 18:59:14 2015 Raphael Teyssandier
//

#include "Item.hh"

Item::Item(int x, int y, Tile *itemTile) {
  this->m_x = x + itemTile->getWidth() * 2 + 5;
  this->m_y = y + itemTile->getHeight() * 2 + 5;
  this->m_itemTile = itemTile;
  this->m_itemTile->getSprite().setPosition(this->m_x, this->m_y);
  this->m_quantity = 0;
}

Item::~Item() {
  try {
    delete this->m_itemTile;
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Item");
  }
}

void		Item::setQuantity(unsigned int quantity) {
  this->m_quantity = quantity;
}

unsigned int	Item::getQuantity() const {
  return this->m_quantity;
}

void		Item::draw(sf::RenderWindow *window) {
  try {
    if (this->m_quantity > 0)
      this->m_itemTile->drawTile(window);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Item");
  }
}
