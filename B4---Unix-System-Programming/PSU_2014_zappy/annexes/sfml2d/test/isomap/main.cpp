//
// map.cpp for  in /home/tang_i/rendu/PSU_2014_zappy/annexes/sfml2d/test/loadtexture
// 
// Made by David Tang
// Login   <tang_i@epitech.net>
// 
// Started on  Tue Jun 23 17:55:05 2015 David Tang
// Last update Wed Jun 24 00:25:35 2015 David Tang
//

#include <iostream>
#include <SFML/Graphics.hpp>

unsigned int	ratioCalculusX(unsigned int x)
{
  if (x <= 1200)
    return (1200 - (1200 / x));
  return (x - (x / 50));
}

unsigned int	ratioCalculusY(unsigned int y)
{
  if (y <= 800)
    return (800 - (800 / y));
  return (y - (y / 50));
}

int main()
{
  // unsigned int length = 5000;
  // unsigned int width = 2400;

  unsigned int length = 20;
  unsigned int width = 90;

  sf::RenderWindow window(sf::VideoMode(1200, 800), "test map");
  window.setPosition(sf::Vector2i(320, 120));

  sf::Vector2i screenDimensions(ratioCalculusX(length), ratioCalculusY(width));
  std::cout << "L= " << ratioCalculusX(length) << " W= " << ratioCalculusY(width)<< std::endl;

  sf::View view;
  view.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));
  view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));

  sf::Vector2f position(screenDimensions.x / 2, screenDimensions.y / 2);

  sf::Texture texture1;
  if(!texture1.loadFromFile("grass.png", sf::IntRect(0, 0, 100, 100)))
    {
      std::cerr << "Failed to load image" << std::endl;
      return (1);
    }

  sf::Texture texture2;
  if(!texture2.loadFromFile("egg.png", sf::IntRect(0, 0, 100, 100)))
    {
      std::cerr << "Failed to load image" << std::endl;
      return (1);
    }



  // int scale = 0.5;

  sf::Sprite grass;
  grass.setTexture(texture1);
  grass.setPosition(100, 100);
  //grass.scale(0.5f , 0.5f);

  sf::Sprite egg1;
  egg1.setTexture(texture2);
  egg1.setPosition(100, 100);


  sf::Sprite g0;
  g0 = grass;
  g0.setPosition(100, 100);

  sf::Sprite g1;
  g1 = grass;
  g1.setPosition(50, 125);

  sf::Sprite g2;
  g2 = grass;
  g2.setPosition(150, 125);

  sf::Sprite g3;
  g3 = grass;
  g3.setPosition(100, 150);

  // sf::Sprite e0;
  // e0 = egg1;
  // e0.setPosition(110, 80);

  while (window.isOpen())
    {
      sf::Event event;
      window.clear();
      while (window.pollEvent(event))
        {
	  if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
	    window.close();
        }

      window.setView(view);
      window.draw(g0);
      window.draw(g1);
      window.draw(g2);
      window.draw(g3);

      // window.setView(window.getDefaultView());
      // window.draw(e0);
      window.display();
    }
  return (0);
}
