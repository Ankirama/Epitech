//
// main.cpp for  in /home/tang_i/temp/zappy/2d
// 
// Made by david tang
// Login   <tang_i@epitech.net>
// 
// Started on  Tue Jun 16 13:28:14 2015 david tang
// Last update Fri Jun 19 01:06:19 2015 David Tang
//

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  sf::Music *sound = new sf::Music;
  sound->openFromFile("TheFatRat-Time.wav");

  sound->play();
  while (window.isOpen())
    {
      sf::Event event;

      while (window.pollEvent(event))
        {
	  if (event.type == sf::Event::Closed)
	    {
	      window.close();
	      sound->stop();
	    }
        }

      window.clear();
      window.draw(shape);
      window.display();
    }

  return 0;
}
