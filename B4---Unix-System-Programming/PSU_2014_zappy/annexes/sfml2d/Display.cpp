//
// Display.cpp for  in /home/tang_i/rendu/PSU_2014_zappy/annexes/sfml2d
// 
// Made by David Tang
// Login   <tang_i@epitech.net>
// 
// Started on  Fri Jun 19 13:54:26 2015 David Tang
// Last update Mon Jun 29 01:38:19 2015 David Tang
//

#include <iostream>
#include "Display.hh"
#include "template_string.hh"
#include "object.h"

Display::Display(int ac, char **av){
  Parser	*parser = new Parser(ac, av);

  if (parser->getPort().empty())
    throw ErrorClient("Usage: ./zappy_ai -p port [-h hostname] [-d]", "Display");
  this->m_network = new Network("GRAPHIC", parser->getPort(),
                                parser->getHostName());
  this->m_function["msz"] = &Display::msz;
  this->m_function["bct"] = &Display::bct;
  this->m_function["tna"] = &Display::tna;
  this->m_function["pnw"] = &Display::pnw;
  this->m_function["ppo"] = &Display::ppo;
  this->m_function["plv"] = &Display::plv;
  this->m_function["pin"] = &Display::pin;
  this->m_function["pex"] = &Display::pex;
  this->m_function["pbc"] = &Display::pbc;
  this->m_function["pic"] = &Display::pic;
  this->m_function["pie"] = &Display::pie;
  this->m_function["pfk"] = &Display::pfk;
  this->m_function["pdr"] = &Display::pdr;
  this->m_function["pgt"] = &Display::pgt;
  this->m_function["pdi"] = &Display::pdi;
  this->m_function["enw"] = &Display::enw;
  this->m_function["eht"] = &Display::eht;
  this->m_function["ebo"] = &Display::ebo;
  this->m_function["edi"] = &Display::edi;
  this->m_function["sgt"] = &Display::sgt;
  this->m_function["seg"] = &Display::seg;
  this->m_function["smg"] = &Display::smg;
  this->m_function["suc"] = &Display::suc;
  this->m_function["sbp"] = &Display::sbp;
  this->m_texture = new Texture();
  this->m_startmap = false;
  this->m_startitem = false;
}

Display::~Display(){
  while (!this->m_tileIndex.empty())
    this->m_tileIndex.erase(this->m_tileIndex.begin());
  while (!this->m_function.empty())
    this->m_function.erase(this->m_function.begin());
  delete this->m_texture;
}

void			Display::initTextures()
{
  this->m_texture->loadTexture("background", "ressources/background.png");
  this->m_texture->loadTexture("grass", "ressources/tiles/grass.png");
  this->m_texture->loadTexture("egg1", "ressources/tiles/egg.png");
  this->m_texture->loadTexture("egg2", "ressources/tiles/egg2.png");
  this->m_texture->loadTexture("linemate", "ressources/tiles/linemate.png");
  this->m_texture->loadTexture("deraumere", "ressources/tiles/deraumere.png");
  this->m_texture->loadTexture("sibur", "ressources/tiles/sibur.png");
  this->m_texture->loadTexture("mendiane", "ressources/tiles/mendiane.png");
  this->m_texture->loadTexture("phiras", "ressources/tiles/phiras.png");
  this->m_texture->loadTexture("thystame", "ressources/tiles/thystame.png");
  this->m_texture->loadTexture("character", "ressources/animations/character.png");
  this->m_texture->loadTexture("food", "ressources/animations/thystame.png");
}

void			Display::changeFramerate(unsigned int limit)
{
  this->m_window->setFramerateLimit(limit);
}


void			Display::positionWindow(unsigned int x, unsigned int y)
{
  this->m_window->setPosition(sf::Vector2i(x, y));
}

void			Display::initView()
{
  sf::Vector2f pos = sf::Vector2f(this->m_window->getSize());
  this->m_view.setSize(pos);
  pos *= 0.5f;
  this->m_zoom = 1.0f;
  this->m_view.setCenter(pos);
}

void			Display::initialize(unsigned int x, unsigned int y)
{
  this->m_windowX = x;
  this->m_windowY = y;
  this->m_network->initNetwork();
  this->m_network->initFd();
  while (this->m_network->readCmd() != "BIENVENUE\n")
    this->m_network->fdIsset();
  this->m_network->sendCmd(this->m_network->getName());
  this->initTextures();
  createIndex();
  this->m_window = new sf::RenderWindow(sf::VideoMode(x, y), TITLE);
  this->m_window->setFramerateLimit(60);
  this->positionWindow(350, 120);
  this->m_background = new sf::Sprite;
  this->m_background->setTexture(this->m_texture->getTexture("background"));
  this->initView();
}

void			Display::createIndex()
{
  this->m_tileIndex["grass"] = new Tile(GRASS, this->m_texture->getTexture("grass"),
					TILEMAX, 1);
  this->m_tileIndex["egg1"] = new Tile(EGG1, this->m_texture->getTexture("egg1"),
				       TILEMAX, 1);
  this->m_tileIndex["egg2"] = new Tile(EGG2, this->m_texture->getTexture("egg2"),
				       TILEMAX, 1);
  this->m_tileIndex["linemate"] = new Tile(LINEMATE, this->m_texture->getTexture("linemate"),
					   TILEMAX, 1);
  this->m_tileIndex["deraumere"] = new Tile(DERAUMERE, this->m_texture->getTexture("deraumere"),
					    TILEMAX, 1);
  this->m_tileIndex["sibur"] = new Tile(SIBUR, this->m_texture->getTexture("sibur"),
					TILEMAX, 1);
  this->m_tileIndex["mendiane"] = new Tile(MENDIANE, this->m_texture->getTexture("mendiane"),
					   TILEMAX, 1);
  this->m_tileIndex["phiras"] = new Tile(PHIRAS, this->m_texture->getTexture("phiras"),
					 TILEMAX, 1);
  this->m_tileIndex["thystame"] = new Tile(THYSTAME, this->m_texture->getTexture("thystame"),
					   TILEMAX, 1);
  this->m_tileIndex["character"] = new Tile(CHARACTER, this->m_texture->getTexture("thystame"),
					    TILEMAX, 1);
}

void			Display::inputKey()
{
  sf::Event		event;

  while (this->m_window->pollEvent(event))
    {
      if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
	this->m_window->close();
      else if (event.type == sf::Event::Resized)
      	{
      	  this->m_view.setSize(event.size.width, event.size.height);
      	  this->m_background->setPosition(this->m_window->
      	  				  mapPixelToCoords(sf::Vector2i(0, 0),
      	  						   this->m_view));
      	  sf::Vector2f pos = sf::Vector2f(event.size.width, event.size.height);
      	  pos *= 0.5f;
      	  pos = this->m_window->mapPixelToCoords(sf::Vector2i(pos), this->m_view);
      	  this->m_background->setScale(float(event.size.width) /
      	  			       float(this->m_background->getTexture()->
      	  				     getSize().x), float(event.size.height) /
      	  			       float(this->m_background->getTexture()->
      	  				     getSize().y));
      	}
      else if (event.type == sf::Event::MouseWheelMoved)
	{
	  if (event.mouseWheel.delta < 0)
	    {
	      this->m_view.zoom(2.0f);
	      this->m_zoom *= 2.0f;
	    }
	  else
	    {
	      this->m_view.zoom(.5f);
	      this->m_zoom *= .5f;
	    }
	}
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	m_view.move(-50, 0);
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	m_view.move(50, 0);
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	m_view.move(0, -50);
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	m_view.move(0, 50);
    }
}

void			Display::start()
{
  while (this->m_startmap != true && this->m_startitem != true)
    whichCmd();
}

void			Display::update()
{
  this->m_clock	= new sf::Clock;
  this->start();
  this->m_window->clear();
  while (this->m_window->isOpen())
    {
      sf::Time		elapsed = this->m_clock->restart();
      float		dt = elapsed.asSeconds();

      (void) dt;
      this->inputKey();
      this->whichCmd();
      this->m_window->clear();
      this->m_window->setView(getView());
      this->m_window->draw(*getBackground());
      this->m_map->drawMap(getWindow());
      this->m_window->display();
    }
}

sf::RenderWindow	*Display::getWindow() const
{
  return (this->m_window);
}

sf::Sprite		*Display::getBackground() const
{
  return (this->m_background);
}

sf::View		Display::getView() const
{
  return (this->m_view);
}

std::string		Display::getCmd(std::string &tmp) const{
  std::size_t		pos;
  std::string		cmd;

  pos = tmp.find(' ');
  if (pos != std::string::npos){
    cmd = tmp.substr(0, pos);
    tmp = tmp.substr(pos + 1, tmp.length());
    return (cmd);
  }
  return (tmp);
}

void			Display::whichCmd(){
  std::string		tmp;
  std::string		cmd;

  if (!(tmp = this->m_network->readCmd()).empty()){
    if (this->m_function.find((cmd = this->getCmd(tmp))) != this->m_function.end()){
      tabFun		tmpFun = this->m_function[cmd];
      (this->*tmpFun)(tmp);
    }
  }
  this->m_network->fdIsset();
}

std::vector<std::string>       	Display::getArg(std::string &tmp){
  std::size_t			pos;
  std::vector<std::string>	vecArg;

  while (!tmp.empty()){
    if ((pos = tmp.find(' ')) != std::string::npos){
      vecArg.push_back(tmp.substr(0, pos));
      tmp = tmp.substr(pos + 1, tmp.length());
    } else {
      vecArg.push_back(tmp.substr(0, tmp.length()));
      tmp.erase();
    }
  }
  return (vecArg);
}

void			Display::msz(std::string &tmp){
  std::vector<std::string>	myArg = this->getArg(tmp);

  if (myArg.size() != 2)
    throw ErrorClient("Wrong Argument", "Display");
  this->m_height = StringToNumber<unsigned int>(myArg[0]);
  this->m_width = StringToNumber<unsigned int>(myArg[1]);
  this->m_map = new Map(this->m_height, this->m_width, this->m_tileIndex,
			  this->m_windowX, this->m_windowY);
  this->m_startmap = true;
}

void				Display::bct(std::string &tmp){
  std::vector<std::string>	myArg = this->getArg(tmp);
  unsigned int			x = StringToNumber<unsigned int>(myArg[0]);
  unsigned int			y = StringToNumber<unsigned int>(myArg[1]);
  static unsigned int		count = 0;

  if (myArg.size() != 9)
    throw ErrorClient("Wrong Argument", "Display");
  this->m_map->setItem(x + y * this->m_width, ID_MEAT, StringToNumber<unsigned int>(myArg[2]));
  for (unsigned i = 0; i < NB_OBJ; ++i)
    this->m_map->setItem(x + y * this->m_width, i, StringToNumber<unsigned int> (myArg[3 + i]));

  if (this->m_startitem == false)
    {
      ++count;
      if (count > (this->m_width * this->m_height))
	this->m_startitem = true;
    }
}

void			Display::tna(std::string &tmp){
  std::cout << tmp << std::endl;
}

void			Display::pnw(std::string &tmp){
  std::vector<std::string>	myArg = this->getArg(tmp);

  if (myArg.size() != 6)
    throw ErrorClient("Wrong Argument", "Display");
  this->m_player.push_back(new Character(StringToNumber<int>(myArg[0]),
					 myArg[5],
					 StringToNumber<unsigned int>(myArg[4]),
					 StringToNumber<unsigned int>(myArg[1]) *
					 this->m_map->getWidth() +
					 StringToNumber<unsigned int>(myArg[0]),
					 StringToNumber<unsigned int>(myArg[3]),
					 new Tile(*this->m_tileIndex["character"]),
					 this->m_map->getWidth()));
}

void			Display::ppo(std::string &tmp){
  std::cout << tmp << std::endl;
}

void			Display::plv(std::string &tmp){
  std::cout << tmp << std::endl;
}

void			Display::pin(std::string &tmp){
  std::cout << tmp << std::endl;
}

void			Display::pex(std::string &tmp){
  std::cout << tmp << std::endl;
}

void			Display::pbc(std::string &tmp){
  std::cout << tmp << std::endl;
}

void			Display::pic(std::string &tmp){
  std::cout << tmp << std::endl;
}

void			Display::pie(std::string &tmp){
  std::cout << tmp << std::endl;
}

void			Display::pfk(std::string &tmp){
  std::cout << tmp << std::endl;
}

void			Display::pdr(std::string &tmp){
  std::cout << tmp << std::endl;
}

void			Display::pgt(std::string &tmp){
  std::cout << tmp << std::endl;
}

void			Display::pdi(std::string &tmp){
  std::cout << tmp << std::endl;
}

void			Display::enw(std::string &tmp){
  std::cout << tmp << std::endl;
}

void			Display::eht(std::string &tmp){
  std::cout << tmp << std::endl;
}

void			Display::ebo(std::string &tmp){
  std::cout << tmp << std::endl;
}

void			Display::edi(std::string &tmp){
  std::cout << tmp << std::endl;
}

void			Display::sgt(std::string &tmp){
  std::cout << tmp << std::endl;
}

void			Display::seg(std::string &tmp){
  std::cout << tmp << std::endl;
}

void			Display::smg(std::string &tmp){
  std::cout << tmp << std::endl;
}

void			Display::suc(std::string &tmp){
  std::cout << tmp << std::endl;
}

void			Display::sbp(std::string &tmp){
  std::cout << tmp << std::endl;
}
