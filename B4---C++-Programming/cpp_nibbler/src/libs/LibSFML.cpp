//
//  LibSFML.cpp
//  cpp_nibbler
//
//  Created by Fabien Martinez on 25/03/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include "LibSFML.hh"

LibSFML::LibSFML(int width, int height, int speed, GameLogic* gameLogic) {
    this->m_gameLogic = gameLogic;
    this->m_window = new sf::RenderWindow(sf::VideoMode(width, height), "Nibbler", sf::Style::Close);
    this->m_window->SetFramerateLimit(60);
    this->m_width = width;
    this->m_height = height;
    this->m_speed = 1 / speed;
    this->m_x_scale = width / gameLogic->getWidth();
    this->m_y_scale = height / gameLogic->getHeight();
    this->m_x_velocity = 1;
    this->m_y_velocity = 0;
}

void	LibSFML::changeVelocity(int power) {
  if (this->m_x_velocity == 0) {
    this->m_x_velocity = this->m_y_velocity == 1 ? -1 * power : power;
    this->m_y_velocity = 0;
  }
  else {
    this->m_y_velocity = this->m_x_velocity == 1 ? power : -1 * power;
    this->m_x_velocity = 0;
  }
}

bool LibSFML::draw() {
  this->m_window->Clear();
  this->drawPieces();
  this->m_window->Display();
  return true;
}

bool LibSFML::update() {
  sf::Event event;
  bool pressed_left = false;
  bool pressed_right = false;

  while (this->m_window->GetEvent(event)) {
    switch (event.Type) {
    case sf::Event::Closed:
      this->m_window->Close();
      break;
    case sf::Event::KeyPressed:
      if (event.Key.Code == sf::Key::Escape)
	this->m_window->Close();
      else if (!pressed_left && event.Key.Code == sf::Key::Left) {
	pressed_left = true;
	this->changeVelocity(ID_LEFT);
      }
      else if (!pressed_right && event.Key.Code == sf::Key::Right) {
	pressed_right = true;
	this->changeVelocity(ID_RIGHT);
      }
      break;
    case sf::Event::KeyReleased:
      if (pressed_left && event.Key.Code == sf::Key::Left)
	pressed_left = false;
      if (pressed_right && event.Key.Code == sf::Key::Right)
	pressed_right = false;
      break;
    }
  }
  return (this->m_gameLogic->update(this->m_x_velocity, this->m_y_velocity));
}

bool LibSFML::game() {
  sf::Clock	Clock;

  while (this->m_window->IsOpened()) {
    if (Clock.GetElapsedTime() > this->m_speed * 0.125f) {
      if (!update())
	return false;
      if (!draw())
	return false;
      Clock.Reset();
    }
  }
  return (true);
}

void	LibSFML::drawPiece(int x, int y, const sf::Color &color) {
  sf::Shape		*square;
  int			x_min;
  int			y_min;
  int			x_max;
  int			y_max;

  square = new sf::Shape();
  x_min = x * this->m_x_scale;
  y_min = y * this->m_y_scale;
  x_max = x_min + this->m_x_scale;
  y_max = y_min + this->m_y_scale;
  square->AddPoint(x_min, y_min, color, sf::Color::White);
  square->AddPoint(x_min, y_max, color, sf::Color::White);
  square->AddPoint(x_max, y_max, color, sf::Color::White);
  square->AddPoint(x_max, y_min, color, sf::Color::White);
  square->EnableFill(true);
  square->EnableOutline(true);
  square->SetOutlineWidth(1);
  this->m_window->Draw(*square);
  delete square;
}

void    LibSFML::drawPieces() {
  std::vector<IPiece *>	snake;
  IPiece		*food;

  snake = this->m_gameLogic->getSnake()->getPieces();
  food = this->m_gameLogic->getFood()->getPiece();
  for (size_t i = 0; i < snake.size(); ++i) {
    this->drawPiece(snake[i]->getX(), snake[i]->getY(), sf::Color::Blue);
  }
  this->drawPiece(food->getX(), food->getY(), sf::Color::Red);
}

extern "C"
{
  IGraphLib *create_lib(int width, int height, int speed, GameLogic* gameLogic) {
    return new LibSFML(width, height, speed, gameLogic);
  }
}
