#include "HUDVertical.hh"

HUDVertical::HUDVertical(int winX, int, Tile *tile, CellR &cell) : m_tile(tile) {
  for (int i = 0; i < 10; ++i) {
    this->m_fonts.push_back(new Font("ressources/fonts/arial.ttf"));
  }
  this->m_fonts[0]->setText(0, 24, winX - tile->getWidth() / 2 + 10, 50);
  this->m_fonts[1]->setText(0, 24, winX - tile->getWidth() / 2 + 10, 110);
  this->m_fonts[2]->setText(0, 24, winX - tile->getWidth() / 2 + 10, 170);
  this->m_fonts[3]->setText(0, 24, winX - tile->getWidth() / 2 + 10, 225);
  this->m_fonts[4]->setText(0, 24, winX - tile->getWidth() / 2 + 10, 295);
  this->m_fonts[5]->setText(0, 24, winX - tile->getWidth() / 2 + 10, 355);
  this->m_fonts[6]->setText(0, 24, winX - tile->getWidth() / 2 + 10, 419);
  this->m_fonts[7]->setText(0, 24, winX - tile->getWidth() / 2 + 10, 474);
  this->m_fonts[8]->setText(0, 24, winX - tile->getWidth() / 2 + 10, 535);
  this->m_fonts[9]->setText(0, 20, winX - tile->getWidth() / 2 - 10, 5);
  this->m_tile->getSprite().setPosition(winX - tile->getWidth(), 0);
  this->m_cell = &cell;
}

HUDVertical::~HUDVertical() {
  delete this->m_tile;
}

void	HUDVertical::update() {
  this->m_fonts[0]->setText(static_cast<int>(this->m_cell->getItem(ID_MEAT).getQuantity()));
  for (int i = 0; i < NB_OBJ; ++i) {
    this->m_fonts[i + 1]->setText(static_cast<int>(this->m_cell->getItem(i).getQuantity()));
  }
  this->m_fonts[7]->setText(static_cast<int>(this->m_cell->getQuantityEgg()));
  this->m_fonts[8]->setText(static_cast<int>(this->m_cell->getQuantityGhost()));
  this->m_fonts[9]->setText(this->m_cell->getPos());
}

void	HUDVertical::draw(sf::RenderWindow *window) {
  this->m_tile->drawTile(window);
  for (unsigned int i = 0; i < this->m_fonts.size(); ++i) {
    this->m_fonts[i]->draw(window);
  }
}
