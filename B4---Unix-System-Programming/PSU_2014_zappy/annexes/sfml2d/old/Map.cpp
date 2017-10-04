//
// Map.cpp for  in /home/tang_i/rendu/PSU_2014_zappy/annexes/sfml2d
// 
// Made by David Tang
// Login   <tang_i@epitech.net>
// 
// Started on  Wed Jun 24 18:26:02 2015 David Tang
// Last update Fri Jun 26 02:27:11 2015 David Tang
//

#include <iostream> // a retirer
#include "Map.hh"

Map::Map(const unsigned int &height, const unsigned int &width,
	 std::map<std::string, Tile*> &tileIndex) : m_height(height),
						    m_width(width),
						    m_tileIndex(tileIndex){
}

Map::~Map(){
}

void				Map::initMap()
{
  //  this->tiles = new std::vector<Tile>;
  for (unsigned int y = 0; y < this->m_height * this->m_width; ++y)
    this->m_tiles.push_back(this->m_tileIndex["grass"]);


  // int count = 0;
  // int z = 0;
  // for (unsigned int y = 0; y < getHeight(); ++y)
  //   {
  //     for (unsigned int x = 0; x < getWidth(); ++x)
  // 	{
  // 	  if (tiles[y].getType() == GRASS)
  // 	    {
  // 	      sf::Vector2f pos;
  // 	      pos.x = (x - y) * 8 + getWidth() * 8;
  // 	      pos.y = (x + y) * 8 * 0.5;
	      // std::cout << "y= "<< pos.y << std::endl;
	      // std::cout << "x= "<< pos.x << std::endl;
	      // tiles[z].getSprite().setPosition(pos.x, pos.y);

	      // sf::Vector2f pos2 = tiles[z].getSprite().getPosition();
	      // std::cout << "y= "<< pos2.y << std::endl;
	      // std::cout << "x= "<< pos2.x << std::endl;
	      // ++count;
	      // ++z;
	      // std::cout << "GRASS"<< std::endl;
	//     }
  	// }
    // }

  // std::cout << "total "<< getHeight() * getWidth()<< " GRASS= "<<count << std::endl;
}

void				Map::drawMap(sf::RenderWindow *window)
{
  for (unsigned int y = 0; y < this->m_height; ++y)
    {
      for (unsigned int x = 0; x < this->m_width; ++x)
	{
	  sf::Vector2f pos;
	  pos.x = (x - y) * TILEMAX + this->m_width * TILEMAX;
	  pos.y = (x + y) * TILEMAX * 0.5;

	  this->m_tiles[y * this->m_width + x]->getSprite().setPosition(pos);
	  this->m_tiles[y * this->m_width + x]->drawTile(window);
	  sf::Vector2f pos2 = m_tiles[y * getWidth() + x]->getSprite().getPosition();
	  std::cout << "x= "<< pos2.x << std::endl;
	  std::cout << "y= "<< pos2.y << std::endl;
	}
    }
}

unsigned int		        Map::getHeight() const
{
  return (this->m_height);
}

unsigned int		        Map::getWidth() const
{
  return (this->m_width);
}
