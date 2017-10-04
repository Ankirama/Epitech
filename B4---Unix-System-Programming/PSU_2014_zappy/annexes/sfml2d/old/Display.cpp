//
// Display.cpp for  in /home/tang_i/rendu/PSU_2014_zappy/annexes/sfml2d
// 
// Made by David Tang
// Login   <tang_i@epitech.net>
// 
// Started on  Fri Jun 19 13:54:26 2015 David Tang
// Last update Fri Jun 26 02:24:26 2015 David Tang
//

#include <iostream>
#include "Display.hh"

Display::Display()
{
}

Display::~Display()
{
}

void			Display::initTextures()
{
  texture = new Texture;
  texture->loadTexture("background", "img/background.png");
  texture->loadTexture("grass", "img/grass.png");
  texture->loadTexture("egg1", "img/egg.png");
  texture->loadTexture("egg2", "img/egg2.png");
  texture->loadTexture("linemate", "img/linemate.png");
  texture->loadTexture("deraumere", "img/deraumere.png");
  texture->loadTexture("sibur", "img/sibur.png");
  texture->loadTexture("mendiane", "img/mendiane.png");
  texture->loadTexture("phiras", "img/phiras.png");
  texture->loadTexture("thystame", "img/thystame.png");
}

void			Display::changeFramerate(unsigned int limit)
{
  window->setFramerateLimit(limit);
}


void			Display::positionWindow(unsigned int x, unsigned int y)
{
  window->setPosition(sf::Vector2i(x, y));
}

void			Display::initView()
{
  sf::Vector2f pos = sf::Vector2f(window->getSize());
  view.setSize(pos);
  pos *= 0.5f;
  view.setCenter(pos);
}

void			Display::initialize(unsigned int x, unsigned int y)
{
  initTextures();
  createIndex();
  window = new sf::RenderWindow(sf::VideoMode(x, y), TITLE);
  window->setFramerateLimit(60);
  positionWindow(350, 120);
  background = new sf::Sprite;
  background->setTexture(texture->getTexture("background"));
  initView();
}

void			Display::createIndex()
{
  tileIndex["grass"] = new Tile(0, 0, GRASS, texture->getTexture("grass"), TILEMAX, 1);
  tileIndex["egg1"] = new Tile(0, 0, EGG1, texture->getTexture("egg1"), TILEMAX, 1);
  tileIndex["egg2"] = new Tile(0, 0, EGG2, texture->getTexture("egg2"), TILEMAX, 1);
  tileIndex["linemate"] = new Tile(0, 0, LINEMATE, texture->getTexture("linemate"), TILEMAX, 1);
  tileIndex["deraumere"] = new Tile(0, 0, DERAUMERE, texture->getTexture("deraumere"), TILEMAX, 1);
  tileIndex["sibur"] = new Tile(0, 0, SIBUR, texture->getTexture("sibur"), TILEMAX, 1);
  tileIndex["mendiane"] = new Tile(0, 0, MENDIANE, texture->getTexture("mendiane"), TILEMAX, 1);
  tileIndex["phiras"] = new Tile(0, 0, PHIRAS, texture->getTexture("phiras"), TILEMAX, 1);
  tileIndex["thystame"] = new Tile(0, 0, THYSTAME, texture->getTexture("thystame"), TILEMAX, 1);
}

void			Display::inputKey()
{
  sf::Event		event;

  while (window->pollEvent(event))
    {
      if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
	window->close();
      else if (event.type == sf::Event::Resized)
      	{
	  getView().setSize(event.size.width, event.size.height);
	  getBackground()->setPosition(getWindow()->mapPixelToCoords(sf::Vector2i(0, 0), getView()));
	  sf::Vector2f pos = sf::Vector2f(event.size.width, event.size.height);
	  pos *= 0.5f;
	  pos = getWindow()->mapPixelToCoords(sf::Vector2i(pos), getView());

	  getBackground()->setScale(float(event.size.width) / float(getBackground()->getTexture()->getSize().x), float(event.size.height) / float(getBackground()->getTexture()->getSize().y));
	}
    }
}

void			Display::update()
{
  clock	= new sf::Clock;
  map = new Map(64, 64, tileIndex);
  map->initMap();

  window->clear();
  while (window->isOpen())
    {
      sf::Time		elapsed = clock->restart();
      float		dt = elapsed.asSeconds();

      (void) dt;
      inputKey();
      window->clear();
      window->setView(getView());
      window->draw(*getBackground());
      map->drawMap(getWindow());
      window->display();
    }
}

sf::RenderWindow	*Display::getWindow() const
{
  return (window);
}

sf::Sprite		*Display::getBackground() const
{
  return (background);
}

sf::View		Display::getView() const
{
  return (view);
}
