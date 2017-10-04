#include "HUDLeft.hh"

HUDLeft::HUDLeft(int, int, Tile *tile) : m_tile(tile) {
  for (int i = 0; i < 6; ++i) {
    this->m_fonts.push_back(new Font("ressources/fonts/arial.ttf"));
  }
  this->m_fonts[0]->setText(0, 20, tile->getWidth() / 2 - 10, 75);
  this->m_fonts[1]->setText(0, 20, tile->getWidth() / 2, 155);
  this->m_fonts[2]->setText(0, 24, tile->getWidth() / 2 + 10, 242);
  this->m_fonts[3]->setText(0, 24, tile->getWidth() / 2 + 10, 345);
  this->m_fonts[4]->setText(0, 24, tile->getWidth() / 2 + 10, 430);
  this->m_fonts[5]->setText(0, 24, tile->getWidth() / 2 + 10, 526);
  this->m_tile->getSprite().setPosition(0, 0);
  this->m_time = 0;
  this->m_nb_teams = 0;
  this->m_size = 0;
  this->m_nb_players = 0;
  this->m_nb_eggs = 0;
  this->m_nb_ghosts = 0;
}

HUDLeft::~HUDLeft() {
  delete this->m_tile;
}

void	HUDLeft::setTime(int time) {
  this->m_time = time;
}

void	HUDLeft::addTeam() {
  ++this->m_nb_teams;
}

void	HUDLeft::setCells(int cells) {
  this->m_size = cells;
}

void	HUDLeft::addPlayer() {
  ++this->m_nb_players;
}

void	HUDLeft::removePlayer() {
  --this->m_nb_players;
}

void	HUDLeft::addEgg() {
  ++this->m_nb_eggs;
}

void	HUDLeft::removeEgg() {
  --this->m_nb_eggs;
}

void	HUDLeft::addGhost() {
  ++this->m_nb_ghosts;
}

void	HUDLeft::removeGhost() {
  --this->m_nb_ghosts;
}

void	HUDLeft::update() {
  this->m_fonts[0]->setText(this->m_size);
  this->m_fonts[1]->setText(this->m_time);
  this->m_fonts[2]->setText(this->m_nb_teams);
  this->m_fonts[3]->setText(this->m_nb_players);
  this->m_fonts[4]->setText(this->m_nb_eggs);
  this->m_fonts[5]->setText(this->m_nb_ghosts);
}

void	HUDLeft::draw(sf::RenderWindow *window) {
  this->m_tile->drawTile(window);
  for (unsigned int i = 0; i < this->m_fonts.size(); ++i) {
    this->m_fonts[i]->draw(window);
  }
}
