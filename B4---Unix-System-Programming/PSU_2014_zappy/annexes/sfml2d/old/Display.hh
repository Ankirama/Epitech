//
// Display.hh for  in /home/tang_i/rendu/PSU_2014_zappy/annexes/sfml2d
// 
// Made by David Tang
// Login   <tang_i@epitech.net>
// 
// Started on  Fri Jun 19 13:57:35 2015 David Tang
// Last update Fri Jun 26 02:23:24 2015 David Tang
//

#ifndef DISPLAY_HH_
# define DISPLAY_HH_

#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include "Texture.hh"
#include "Tile.hh"
#include "Map.hh"

#define		TITLE		"Zappy"
#define		HEIGHT		1200
#define		WIDTH		800

class				Display
{
protected:
  sf::RenderWindow		*window;
  sf::Clock			*clock;
  sf::View			view;
  sf::Sprite			*background;
  Texture			*texture;
  std::map<std::string, Tile *>	tileIndex;
  Map				*map;

public:
  Display();
  ~Display();

public:
  void		       		initTextures();
  void			       	changeFramerate(unsigned int);
  void				positionWindow(unsigned int, unsigned int);
  void			       	initialize(unsigned int, unsigned int);
  void				initView();
  void				createIndex();
  void	       			inputKey();
  void 				update();

  sf::RenderWindow	       	*getWindow() const;
  sf::Sprite			*getBackground() const;
  sf::View			getView() const;
};

#endif /* !DISPLAY_HH_ */
