//
// Character.cpp for  in /home/tang_i/rendu/PSU_2014_zappy
// 
// Made by David Tang
// Login   <tang_i@epitech.net>
// 
// Started on  Sat Jun 27 19:38:35 2015 David Tang
// Last update Sun Jul  5 02:18:03 2015 David Tang
//

#include "Character.hh"

Character::Character(int id, const std::string &team, int x, int y, int orien,
		     const sf::Vector2u &textureSize, int level) : m_id(id),
								   m_team(team),
								   m_x(x),
								   m_y(y),
								   m_level(level),
								   m_orientation(orien)
{
  try {
    for (unsigned int i = 0; i < NB_OBJ; ++i)
      this->m_inventory.push_back(0);
    this->m_inventory.push_back(10);
    this->m_windowX = 0;
    this->m_windowY = 0;
    this->m_width = 0;
    this->m_height = 0;
    this->m_textureSize = textureSize;
    this->m_timer = 0;
    this->initTabEmote();
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Character");
  }
}

Character::~Character(){
  try {
    this->m_inventory.clear();
    for (unsigned int i = 0; i < this->m_playerTiles.size(); ++i)
      delete this->m_playerTiles[i];
    for (unsigned int i = 0; i < this->m_playerActions.size(); ++i)
      delete this->m_playerActions[i];
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Character");
  }
}

void	Character::initTabEmote(){
  this->m_tabBool[BROADCAST] = false;
  this->m_tabBool[PICKFOOD] = false;
  this->m_tabBool[PICKSTONE] = false;
  this->m_tabBool[INCANTATION] = false;
  this->m_tabBool[LEVELUP] = false;
  this->m_tabBool[EXPULSE] = false;
  this->m_tabBool[DEATH] = false;
  this->m_tabBool[EGGS] = false;
  this->m_tabBool[EGGE] = false;
  this->m_tabEmote[BROADCAST] = &Character::broadCast;
  this->m_tabEmote[PICKFOOD] = &Character::pickFood;
  this->m_tabEmote[PICKSTONE] = &Character::pickStone;
  this->m_tabEmote[INCANTATION] = &Character::inCantation;
  this->m_tabEmote[LEVELUP] = &Character::levelup;
  this->m_tabEmote[EXPULSE] = &Character::expulse;
  this->m_tabEmote[DEATH] = &Character::death;
  this->m_tabEmote[EGGS] = &Character::egg;
  this->m_tabEmote[EGGE] = &Character::egge;
}

void	Character::setPosition(int x, int y) {
  try {
    this->m_x = x;
    this->m_y = y;
    int	x_ = getXIso(x - y, this->m_textureSize.x, 20, this->m_windowX) + 35;
    int	y_ = getYIso(x + y, this->m_textureSize, 10, this->m_windowY, this->m_height) - 5;
    for (unsigned int i = 0; i < this->m_playerTiles.size(); ++i)
      this->m_playerTiles[i]->getSprite().setPosition(x_, y_);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Character");
  }
}

void	Character::setPosition(int x, int y, int orientation) {
  try {
    this->m_x = x;
    this->m_y = y;
    int	x_ = getXIso(x - y, this->m_textureSize.x, 20, this->m_windowX) + 35;
    int	y_ = getYIso(x + y, this->m_textureSize, 10, this->m_windowY, this->m_height) -5;
    for (unsigned int i = 0; i < this->m_playerTiles.size(); ++i)
      this->m_playerTiles[i]->getSprite().setPosition(x_, y_);
    this->m_orientation = orientation;
    for (unsigned int i = 0; i < this->m_playerActions.size(); ++i)
      this->m_playerActions[i]->getSprite().setPosition(x_, y_);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Character");
  }
}

void	Character::setWindowSize(int windowX, int windowY) {
  try {
    this->m_windowX = windowX;
    this->m_windowY = windowY;
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Character");
  }
}

void	Character::setMapSize(int width, int height) {
  try {
    this->m_width = width;
    this->m_height = height;
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Character");
  }
}

void	Character::setTile(Tile *newTile) {
  try {
      this->m_playerTiles.push_back(newTile);
      this->m_playerTiles.back()->getSprite().setPosition(getXIso(this->m_x - this->m_y,
								  this->m_textureSize.x,
								  20, this->m_windowX) + 35,
							  getYIso(this->m_x + this->m_y,
								  this->m_textureSize, 10,
								  this->m_windowY, this->m_height) - 5);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Character");
  }
}

void	Character::setAction(Tile *newTile) {
  try {
      this->m_playerActions.push_back(newTile);
      this->m_playerActions.back()->getSprite().setPosition(getXIso(this->m_x - this->m_y,
								  this->m_textureSize.x,
								  20, this->m_windowX) + 35,
							  getYIso(this->m_x + this->m_y,
								  this->m_textureSize, 10,
								  this->m_windowY, this->m_height) - 5);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Character");
  }
}

void	Character::setTimer(int count)
{
  this->m_timer = count;
}

void	Character::draw(sf::RenderWindow *window) {
  try {
    if (this->m_playerTiles.size() == 4){
      this->m_playerTiles[this->m_orientation]->drawTile(window);
      for (int i = 0;i < NBEMOTE;++i)
	if (this->m_tabBool[i])
	  (this->*m_tabEmote[i])(window);
    }
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Character");
  }
}

void	Character::broadCast(sf::RenderWindow *window){
  this->m_playerActions[BROADCAST]->drawTile(window);
  if (this->m_timer > 0)
    this->m_timer -= 1;
  else
    this->m_tabBool[BROADCAST] = false;
}

void	Character::pickFood(sf::RenderWindow *window){
  this->m_playerActions[PICKFOOD]->drawTile(window);
  if (this->m_timer > 0)
    this->m_timer -= 1;
  else
    this->m_tabBool[PICKFOOD] = false;
}

void	Character::pickStone(sf::RenderWindow *window){
  this->m_playerActions[PICKSTONE]->drawTile(window);
  if (this->m_timer > 0)
    this->m_timer -= 1;
  else
    this->m_tabBool[PICKSTONE] = false;
}

void	Character::inCantation(sf::RenderWindow *window){
  this->m_playerActions[INCANTATION]->drawTile(window);
}

void	Character::levelup(sf::RenderWindow *window){
  this->m_playerActions[LEVELUP]->drawTile(window);
  if (this->m_timer > 0)
    this->m_timer -= 1;
  else
    this->m_tabBool[LEVELUP] = false;
}

void	Character::expulse(sf::RenderWindow *window){
  this->m_playerActions[EXPULSE]->drawTile(window);
  if (this->m_timer > 0)
    this->m_timer -= 1;
  else
    this->m_tabBool[EXPULSE] = false;
}

void	Character::death(sf::RenderWindow *window){
  this->m_playerActions[DEATH]->drawTile(window);
  this->m_tabBool[DEATH] = false;
}

void	Character::egg(sf::RenderWindow *window){
  this->m_playerActions[EGGS]->drawTile(window);
}

void	Character::egge(sf::RenderWindow *window){
  this->m_playerActions[EGGE]->drawTile(window);
  this->m_tabBool[EGGE] = false;
}
