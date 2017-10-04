//
// font.cpp for  in /home/tang_i/rendu/PSU_2014_zappy/annexes/sfml2d/test/rendertexture
// 
// Made by David Tang
// Login   <tang_i@epitech.net>
// 
// Started on  Tue Jun 23 14:08:29 2015 David Tang
// Last update Tue Jun 23 14:16:21 2015 David Tang
//

#include <iostream>
#include <SFML/Graphics.hpp>

int	main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

  sf::Font font;
  if (!font.loadFromFile("billy.ttf"))
    {
      std::cerr << "Failed to load font." << std::endl;
      return (-1);
    }

  sf::Text text("hello", font);
  text.setCharacterSize(140);
  text.setStyle(sf::Text::Bold);
  text.setColor(sf::Color::Blue);

  while (window.isOpen())
    {
      window.clear();
      window.draw(text);
      window.display();
    }
  return (0);
}
