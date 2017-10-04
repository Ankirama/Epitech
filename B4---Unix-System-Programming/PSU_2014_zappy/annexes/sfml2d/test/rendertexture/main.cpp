//
// main.cpp for  in /home/tang_i/rendu/PSU_2014_zappy/annexes/sfml2d/test
// 
// Made by David Tang
// Login   <tang_i@epitech.net>
// 
// Started on  Mon Jun 22 17:01:50 2015 David Tang
// Last update Tue Jun 23 14:11:15 2015 David Tang
//

#include <SFML/Graphics.hpp>

int	main()
{

  // Create a new render-window
  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
  // Create a new render-texture
  sf::RenderTexture texture;
  if (!texture.create(500, 500))
    return -1;

  sf::CircleShape shape(50);
  shape.setFillColor(sf::Color(100, 250, 50));

  sf::Font font;
  font.loadFromFile("billy.ttf");

  sf::Text text("hello", font);
  text.setCharacterSize(140);
  text.setStyle(sf::Text::Bold);
  text.setColor(sf::Color::Blue);

  // The main loop
  while (window.isOpen())
    {
      // Event processing
      // ...
      // Clear the whole texture with red color
      texture.clear(sf::Color::Red);
      // Draw stuff to the texture
      //texture.draw(sprite);  // sprite is a sf::Sprite
      //texture.draw(shape);   // shape is a sf::Shape
      texture.draw(text);    // text is a sf::Text
      // We're done drawing to the texture
      texture.display();
      // Now we start rendering to the window, clear it first
      window.clear();
      // Draw the texture
      sf::Sprite sprite(texture.getTexture());
      window.draw(sprite);
      // End the current frame and display its contents on screen
      window.display();
    }


  return (0);
}
