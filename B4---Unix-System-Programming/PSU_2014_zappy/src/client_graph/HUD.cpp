#include "HUD.hh"

HUD::HUD(int winX, int winY, Tile *hud) {
  this->m_hud = hud;
  this->m_hud->getSprite().setPosition(0, winY - this->m_hud->getHeight());
  this->m_winX = winX;
  this->m_winY = winY;
  this->m_playerSet = false;
  for (int i = 0; i < 10; ++i) {
    this->m_fonts.push_back(new Font("ressources/fonts/arial.ttf"));
  }
  this->m_fonts[0]->setText("Cell mode", 40, 50, winY - hud->getHeight() + 50);
  this->m_fonts[1]->setText(0, 24, 905, winY - hud->getHeight() + 15);
  for (int i = 0; i < NB_OBJ; ++i) {
    this->m_fonts[2 + i]->setText(0, 24, 950 + i * 48, winY - hud->getHeight() + 75);
  }
  this->m_fonts[8]->setText(0, 20, 915, winY - hud->getHeight() + 77);
  this->m_fonts[9]->setText("None", 32, 960, winY - hud->getHeight() + 110);
  this->m_mode = 0;
}

HUD::~HUD() {
  delete this->m_hud;
}

void	HUD::update() {
  if (!this->m_mode) {
    this->m_fonts[0]->setText("Cell mode");
  }
  else {
    this->m_fonts[0]->setText("Character mode");
    if (this->m_playerSet) {
      this->m_fonts[1]->setText(this->m_character->getQuantityItem(ID_MEAT));
      for (int i = 0; i < NB_OBJ; ++i) {
	this->m_fonts[2 + i]->setText(this->m_character->getQuantityItem(i));
      }
      this->m_fonts[8]->setText(this->m_character->getLevel());
      this->m_fonts[9]->setText(this->m_character->getTeam());
    }
  }
}

void	HUD::draw(sf::RenderWindow *window) {
  this->m_hud->drawTile(window);
  if (!this->m_playerSet || this->m_mode == 0) {
    this->m_fonts[0]->draw(window);
  }
  else {
    for (unsigned int i = 0; i < this->m_fonts.size(); ++i) {
      this->m_fonts[i]->draw(window);
    }
  }
}
