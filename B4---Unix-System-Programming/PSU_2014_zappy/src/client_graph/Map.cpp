//
// Map.cpp for  in /home/tang_i/rendu/PSU_2014_zappy/annexes/sfml2d
// 
// Made by David Tang
// Login   <tang_i@epitech.net>
// 
// Started on  Wed Jun 24 18:26:02 2015 David Tang
// Last update Sat Jul  4 00:22:51 2015 David Tang
//

#include "Map.hh"
#include <iostream>

Map::Map(int width, int height, TilesIndex *tilesIndex, int winX, int winY) :
  m_height(height), m_width(width), m_tilesIndex(tilesIndex),  m_winX(winX), m_winY(winY) {
  try {
    this->initMap();
    this->m_currentCell = 0;
    this->m_selectedCell = sf::Color(244, 102, 27);
  }  catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Map");
  }
}

Map::~Map(){
}

void				Map::initMap(){
  try {
    int	pos = 0;
    int	max = this->m_width * this->m_height;
    while (pos < max) {
      this->m_cells.push_back(new CellR(sf::Vector2i(pos % this->m_width, pos / this->m_width),
					sf::Vector2i(this->m_winX, this->m_winY),
					sf::Vector2i(this->m_width, this->m_height),
					this->m_tilesIndex));
      if (pos == 0)
	this->m_cells[pos]->getSprite().setColor(sf::Color(244, 102, 27));
      ++pos;
    }
  }  catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Map");
  }
}

void				Map::draw(sf::RenderWindow *window){
  try {
    for (unsigned int i = 0; i < m_cells.size(); ++i)
      this->m_cells[i]->draw(window);
  }  catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Map");
  }
}

CellR			&Map::getCell(int x, int y) const {
  return *this->m_cells[x + y * this->m_width];
}

CellR			&Map::getCell(int pos) const {
  return *this->m_cells[pos];
}

int		        Map::getHeight() const{
  try {
    return (this->m_height);
  }  catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Map");
  }
}

int		        Map::getWidth() const{
  try {
    return (this->m_width);
  }  catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Map");
  }
}

void				Map::setItem(int pos, int item, unsigned int nb) {
  try {
    if (pos < this->m_width * this->m_height && pos >= 0)
      this->m_cells[pos]->setItem(item, nb);
  }  catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Map");
  }
}

void				Map::setItem(int x, int y, int item, unsigned int nb) {
  try {
    int				pos;

    pos = x + y * this->m_width;
    if (pos < this->m_width * this->m_height && pos >= 0)
      this->m_cells[pos]->setItem(item, nb);
  }  catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Map");
  }
}

void				Map::addEgg(int x, int y, int id) {
  this->m_eggs[id] = x + y * this->m_width;
  this->m_cells[x + y * this->m_width]->setQuantityEgg(this->m_cells[x + y * this->m_width]->getQuantityEgg() + 1);
}

void				Map::addEgg(int pos, int id) {
  this->m_eggs[id] = pos;
  this->m_cells[pos]->setQuantityEgg(this->m_cells[pos]->getQuantityEgg() + 1);
}

void				Map::removeEgg(int id) {
  this->m_cells[this->m_eggs[id]]->setQuantityEgg(this->m_cells[this->m_eggs[id]]->getQuantityEgg() - 1);
  this->addGhost(this->m_eggs[id], id);
  this->m_eggs.erase(id);
}

void				Map::addGhost(int x, int y, int id) {
  this->m_ghosts[id] = x + y * this->m_width;
  this->m_cells[x + y * this->m_width]->setQuantityGhost(this->m_cells[x + y * this->m_width]->getQuantityGhost() + 1);
}

void				Map::addGhost(int pos, int id) {
  this->m_ghosts[id] = pos;
  this->m_cells[pos]->setQuantityGhost(this->m_cells[pos]->getQuantityGhost() + 1);
}

void				Map::removeGhost(int id) {
  this->m_cells[this->m_ghosts[id]]->setQuantityGhost(this->m_cells[this->m_ghosts[id]]->getQuantityGhost() - 1);
  this->m_ghosts.erase(id);
}

CellR				&Map::getCurrentCell() const {
  return *this->m_cells[this->m_currentCell];
}

void				Map::setNextCell(int move) {
  int				newCell = this->m_currentCell;

  this->m_cells[this->m_currentCell]->getSprite().setColor(this->m_cells[this->m_currentCell]->getColorDefault());
  if (move == 1) {
    newCell = this->m_currentCell % this->m_width == this->m_width - 1 ?
      this->m_currentCell - (this->m_width - 1) :
      this->m_currentCell + 1;
  }
  else if (move == -1) {
    newCell = this->m_currentCell % this->m_width == 0 ?
      (this->m_currentCell + this->m_width - 1) :
      this->m_currentCell - 1;
  }
  else if (move == this->m_width * -1) {
    newCell = (this->m_currentCell < this->m_width) ?
      (this->m_width * (this->m_height - 1) + this->m_currentCell) :
      this->m_currentCell - this->m_width;
  }
  else if (move == this->m_width) {
    newCell = this->m_currentCell >= this->m_width * (this->m_height - 1) ?
      this->m_currentCell % this->m_width :
      this->m_currentCell + this->m_width;
  }
  this->m_currentCell = newCell;
  this->m_cells[this->m_currentCell]->getSprite().setColor(this->m_selectedCell);
}

void				Map::setCurrentCell(int newCell) {
  this->m_cells[this->m_currentCell]->getSprite().setColor(this->m_cells[this->m_currentCell]->getColorDefault());
  this->m_currentCell = newCell;
  this->m_cells[this->m_currentCell]->getSprite().setColor(this->m_selectedCell);
}
