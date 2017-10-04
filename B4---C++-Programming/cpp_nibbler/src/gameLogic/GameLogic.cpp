//
//  GameLogic.cpp
//  cpp_nibbler
//
//  Created by Fabien Martinez on 24/03/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include "GameLogic.hh"

/*
** generic constructor
*/
GameLogic::GameLogic() {
  this->m_height = DEF_HEIGHT;
  this->m_width = DEF_WIDTH;
  this->m_score = 0;
  this->m_sizeArea = DEF_WIDTH * DEF_HEIGHT;
  this->m_map = new char[this->m_sizeArea];
  this->m_freeCases = DEF_WIDTH * DEF_HEIGHT - 4;
  this->m_snake = new Snake();
  this->m_food = new Food();
  this->initMap();
}

/*
** Specific constructor
*/
GameLogic::GameLogic(int width, int height) {
  this->m_height = height;
  this->m_width = width;
  this->m_score = 0;
  this->m_sizeArea = height * width;
  this->m_map = new char[this->m_sizeArea];
  this->m_freeCases = width * height - 4;
  this->m_snake = new Snake(width, height);
  this->m_food = new Food(width, height);
  this->initMap();
}

/*
** Destructor
** it will delete our map, snake and food
*/
GameLogic::~GameLogic() {
  delete this->m_food;
  delete this->m_snake;
  delete this->m_map;
}

char *GameLogic::getMap() const {return this->m_map;}

int GameLogic::getScore() const {return this->m_score;}

int GameLogic::getWidth() const {return this->m_width;}

int GameLogic::getHeight() const {return this->m_height;}

Snake *GameLogic::getSnake() const {return this->m_snake;}

Food *GameLogic::getFood() const {return this->m_food;}

bool GameLogic::update(int x_velocity, int y_velocity) {
  int cont;

  cont = this->m_snake->moveMe(this->m_map, x_velocity, y_velocity,
			       this->m_freeCases, this->m_food);
  if (cont == -1)
    return false;
  else if (cont == 1) {
    this->m_food->generateFood(this->m_map, this->m_freeCases);
    ++this->m_score;
  }
  return (true);
}

void GameLogic::draw() {
  for (int j = 0; j < this->m_height; ++j) {
    for (int i = 0; i < this->m_width; ++i) {
      std::cout << (char)(this->m_map[j * this->m_width + i] + '0');
    }
    std::cout << std::endl;
  }
  std::cout << "____________" << std::endl;
}

/*
** this function will init our map with 0, place our snake in the middle
** and place 2 food
*/
void GameLogic::initMap() {
  for (int i = 0; i < this->m_sizeArea; ++i) {
    this->m_map[i] = ID_FREE;
  }
  for (int i = this->m_width / 2 - 2; i < this->m_width / 2 + 2; ++i) {
    this->m_map[(this->m_height / 2 + 1) * this->m_width + i] = ID_SNAKE;
  }
  this->m_food->generateFood(this->m_map, this->m_freeCases);
}
