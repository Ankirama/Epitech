//
// main.cpp for  in /home/tang_i/rendu/PSU_2014_zappy/annexes/sfml2d/test
// 
// Made by David Tang
// Login   <tang_i@epitech.net>
// 
// Started on  Tue Jun 23 13:56:57 2015 David Tang
// Last update Tue Jun 23 17:54:43 2015 David Tang
//

#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
  sf::RenderWindow window(sf::VideoMode(1200, 800), "test map");
  window.setPosition(sf::Vector2i(320, 120));

  sf::Texture texture;
  if(!texture.loadFromFile("test1.png", sf::IntRect(10, 10, 40, 40)))
    {
      std::cerr << "Failed to load image" << std::endl;
      return (1);
    }

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(100, 100);

  unsigned int y = 30;
  unsigned int x = 20;
  sf::Sprite s[x * y];

  unsigned int k = 0;
  for (unsigned int i = 0; i < y; ++i)
    for (unsigned int j = 0; j < x; ++j)
      {
	s[k] = sprite;
	s[k++].setPosition(i * 40, j * 40);
      }

  while (window.isOpen())
    {
      sf::Event event;
      window.clear();
      while (window.pollEvent(event))
        {
	  if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
	    window.close();
        }

      for (unsigned i = 0; i < (x * y); ++i)
	window.draw(s[i]);
      window.display();
    }
  return (0);
}
