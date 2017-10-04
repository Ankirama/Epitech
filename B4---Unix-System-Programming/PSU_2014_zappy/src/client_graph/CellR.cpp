//
// Cell.cpp for  in /home/tang_i/rendu/PSU_2014_zappy
// 
// Made by David Tang
// Login   <tang_i@epitech.net>
// 
// Started on  Sun Jun 28 23:46:25 2015 David Tang
// Last update Mon Jun 29 18:48:19 2015 Raphael Teyssandier
//

#include "CellR.hh"

CellR::CellR(const sf::Vector2i &position, const sf::Vector2i &windowSize,
	     const sf::Vector2i &mapSize, TilesIndex *tileIndex) {

  this->m_width = mapSize.x;
  this->m_height = mapSize.y;
  this->m_pos = position.x + position.y * mapSize.x;
  this->m_winX = windowSize.x;
  this->m_winY = windowSize.y;
  this->m_tileIndex = tileIndex;
  this->m_cellTile = new Tile(this->m_tileIndex->getTile("grass"));
  this->m_x = getXIso(position.x - position.y, this->m_cellTile->getWidth(), 20, this->m_winX);
  this->m_y = getYIso(position.x + position.y, this->m_cellTile->getSprite().getTexture()->getSize(), 10, this->m_winY, this->m_height);
  this->m_cellTile->getSprite().setPosition(this->m_x, this->m_y);
  this->m_color = this->m_cellTile->getSprite().getColor();
  this->m_items.push_back(new Item(this->m_x + 5, this->m_y -5,
				   new Tile(this->m_tileIndex->getTile("linemate"))));
  this->m_items.push_back(new Item(this->m_x + 5, this->m_y,
				   new Tile(this->m_tileIndex->getTile("deraumere"))));
  this->m_items.push_back(new Item(this->m_x + 5, this->m_y + 5,
				   new Tile (this->m_tileIndex->getTile("sibur"))));
  this->m_items.push_back(new Item(this->m_x - 5, this->m_y + 5,
				   new Tile (this->m_tileIndex->getTile("mendiane"))));
  this->m_items.push_back(new Item(this->m_x - 5, this->m_y - 5,
				   new Tile (this->m_tileIndex->getTile("phiras"))));
  this->m_items.push_back(new Item(this->m_x - 5, this->m_y,
				   new Tile (this->m_tileIndex->getTile("thystame"))));
  this->m_items.push_back(new Item(this->m_x, this->m_y,
				   new Tile (this->m_tileIndex->getTile("food"))));
  this->m_egg = new Tile (this->m_tileIndex->getTile("egg1"));
  this->m_egg->getSprite().setPosition(this->m_x + 20 + this->m_tileIndex->getTile("egg1").getWidth(), this->m_y + 10 + this->m_tileIndex->getTile("egg1").getHeight());
  this->m_quantityEgg = 0;
  this->m_ghost = new Tile (this->m_tileIndex->getTile("ghost"));
  this->m_ghost->getSprite().setPosition(this->m_x + 45, this->m_y);
  this->m_quantityGhost = 0;
}

CellR::~CellR() {
  delete this->m_cellTile;
  for (int i = 0; i < NB_OBJ + 1; ++i) {
    delete this->m_items[i];
  }
}

void	CellR::setItem(int idItem, unsigned int quantity) {
  try {
    if (idItem < NB_OBJ + 1)
      this->m_items[idItem]->setQuantity(quantity);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CellR");
  }
}

void	CellR::setQuantityEgg(unsigned int quantity) {
  this->m_quantityEgg = quantity;
}

unsigned int	CellR::getQuantityEgg() {
  return this->m_quantityEgg;
}

void	CellR::setQuantityGhost(unsigned int quantity) {
  this->m_quantityGhost = quantity;
}

unsigned int	CellR::getQuantityGhost() {
  return this->m_quantityGhost;
}

void	CellR::draw(sf::RenderWindow *window) {
  try {
    this->m_cellTile->drawTile(window);
    if (this->m_quantityEgg > 0)
      this->m_egg->drawTile(window);
    if (this->m_quantityGhost > 0)
      this->m_ghost->drawTile(window);
    for (unsigned int i = 0; i < this->m_items.size(); ++i) {
      this->m_items[i]->draw(window);
    }
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CellR");
  }
}

void	CellR::addPlayer(int id) {
  this->m_players.push_back(id);
}

void	CellR::removePlayer(int id) {
  unsigned int	i = 0;

  while (i < this->m_players.size() && this->m_players[i] != id)
    ++i;
  if (i < this->m_players.size())
    this->m_players.erase(this->m_players.begin() + i);
}

const std::vector<int>	&CellR::getPlayers() const {
  return this->m_players;
}

sf::Sprite	&CellR::getSprite() const{
  try {
    return (this->m_cellTile->getSprite());
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CellR");
  }
}

const sf::Color	&CellR::getColorDefault() const {
  return this->m_color;
}

int		CellR::getPos() const {
  return this->m_pos;
}
