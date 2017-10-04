//
//  LibSFML.cpp
//  cpp_nibbler
//
//  Created by Fabien Martinez on 25/03/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

static void _create_map(char *map, int w, int h)
{
  for (int i = 0; i < w * h; ++i)
    map[i] = 0;
  map[h / 2 * w + w / 2 - 1] = 1;
  map[h / 2 * w + w / 2] = 1;
  map[h / 2 * w + w / 2 + 1] = 1;
}

static void add_rect(std::vector <sf::RectangleShape *> &snake, int x, int y, float x_scale, float y_scale) {
  sf::RectangleShape *tmp = new sf::RectangleShape(sf::Vector2f(x_scale, y_scale));

  tmp->setFillColor(sf::Color(200, 150, 50));
  tmp->setPosition(sf::Vector2f(x * x_scale, y * y_scale));
  tmp->setOutlineThickness(2);
  tmp->setOutlineColor(sf::Color(255, 255, 255));
  snake.push_back(tmp);
}

static void move_snake(std::vector <sf::RectangleShape *> &snake, float x_velocity, float y_velocity) {
  x_velocity /= 10;
  y_velocity /= 10;
  for (size_t i = 0; i < snake.size(); ++i)
    {
      sf::Vector2f tmp = snake[i]->getPosition();
      snake[i]->setPosition(sf::Vector2f(tmp.x + x_velocity, tmp.y + y_velocity));
    }
}

int main() {
  std::vector<sf::RectangleShape *> snake;
  float x_scale;
  float y_scale;
  float x;
  float y;
  bool pressed = false;
  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
  int i;
  char	*map = new char[20 * 20];
  x_scale = 800 / 20;
  y_scale = 600 / 20;
  //  add_rect(snake, 10, 10, x_scale, y_scale);
  add_rect(snake, 20 / 2 - 1, 20 / 2, x_scale, y_scale);
  add_rect(snake, 20 / 2, 20 / 2, x_scale, y_scale);
  add_rect(snake, 20 / 2 + 1, 20 / 2, x_scale, y_scale);
  _create_map(map, 20, 20);
  x = 1;
  y = 0.00;
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
	window.close();
	break;
      case sf::Event::KeyPressed:
	if (event.key.code == sf::Keyboard::Escape)
	  window.close();
	if (!pressed && event.key.code == sf::Keyboard::Left)
	  {
	    pressed = true;
	    if (y == 1)
	      {
		x = -1;
		y = 0;
	      }
	    else if (y == -1)
	      {
		x = 1;
		y = 0;
	      }
	    else if (x == 1)
	      {
		y = 1;
		x = 0;
	      }
	    else if (x == -1)
	      {
		y = -1;
		x = 0;
	      }
	  }
	else if (!pressed && event.key.code == sf::Keyboard::Right)
	  {
	    pressed = true;
	    if (y == 1)
	      {
		x = 1;
		y = 0;
	      }
	    else if (y == -1)
	      {
		x = -1;
		y = 0;
	      }
	    else if (x == 1)
	      {
		y = -1;
		x = 0;
	      }
	    else if (x == -1)
	      {
		y = 1;
		x = 0;
	      }
	    break;
	  }
      case sf::Event::KeyReleased:
	if (pressed && (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right))
	  pressed = false;
	break;
      }
    }
    window.clear();
    for (size_t k = 0; k < snake.size(); ++k)
      window.draw(*snake[k]);
    window.display();
    move_snake(snake, x, y);
    ++i;
  }
  return (0);
}
