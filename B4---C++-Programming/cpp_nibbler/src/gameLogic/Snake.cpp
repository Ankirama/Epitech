//
//  Snake.cpp
//  cpp_nibbler
//
//  Created by Fabien Martinez on 24/03/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include "Snake.hh"

/*
** Pour les faire progresser, partir de la queue et donner la position de l'element qui est juste avant exemple:
** elt[0] = 0,0 elt[1] = 1,0 elt[2] = 2,0 elt[3] = 3,0
** elt[3] = 2,0 elt[2] = 1,0 elt[1] = 1,0 elt[0] = 0,1
*/

/*
** our constructor
** It will create our snake with 1 HEAD, 1 TAIL and 2 BODY in the middle
*/
Snake::Snake(int width, int heigth) : m_width(width), m_height(heigth) {
  this->m_pieces.push_back(new PieceSnake(HEAD, this->m_width / 2 + 1, this->m_height / 2 + 1));
  this->m_pieces.push_back(new PieceSnake(BODY, this->m_width / 2, this->m_height / 2 + 1));
  this->m_pieces.push_back(new PieceSnake(BODY, this->m_width / 2 - 1, this->m_height / 2 + 1));
  this->m_pieces.push_back(new PieceSnake(TAIL, this->m_width / 2 - 2, this->m_height / 2 + 1));
}

/*
** generic constructor, same than the other one
*/
Snake::Snake() : m_width(DEF_WIDTH), m_height(DEF_HEIGHT) {
  this->m_pieces.push_back(new PieceSnake(HEAD, this->m_width / 2 + 1, this->m_height / 2 + 1));
  this->m_pieces.push_back(new PieceSnake(BODY, this->m_width / 2, this->m_height / 2 + 1));
  this->m_pieces.push_back(new PieceSnake(BODY, this->m_width / 2 - 1, this->m_height / 2 + 1));
  this->m_pieces.push_back(new PieceSnake(TAIL, this->m_width / 2 - 2, this->m_height / 2 + 1));
}

/*
** Destructor
** It will delete every piece and clear the vector
*/
Snake::~Snake() {
  for (size_t i = 0; i < this->m_pieces.size(); ++i) {
    delete this->m_pieces[i];
  }
  this->m_pieces.clear();
}

std::vector<IPiece *> &Snake::getPieces() {return this->m_pieces;}

/*
** this function will add and element to the end of our snake
** the position will be the old tail's position
** else return true and add the TAIL
*/
bool Snake::addTail(char *map, int freeCases) {
  int x = this->m_pieces[this->m_pieces.size() - 1]->getX();
  int y = this->m_pieces[this->m_pieces.size() - 1]->getY();
    
  this->m_pieces[this->m_pieces.size() - 1]->setType(BODY);
  this->m_pieces.push_back(new PieceSnake(TAIL, x, y));
  map[y * this->m_width + x] = ID_SNAKE;
  if (freeCases == 0)
    {
      std::cout << "NO MORE FREE CASES" << std::endl;
      return false;
    }
  return true;
}

/*
** It will check if we can move.
** we can't move if : new pos for head -> wall / snake
** return true if we can move, else false
*/
bool Snake::checkMove(char *map, int x_velocity, int y_velocity) {
  if (this->m_pieces[0]->getX() + x_velocity < 0 ||
      this->m_pieces[0]->getX() + x_velocity >= this->m_width ||
      this->m_pieces[0]->getY() + y_velocity < 0 ||
      this->m_pieces[0]->getY() + y_velocity >= this->m_height) {
    std::cout << "Out of range or you ate yourself" << std::endl;
    return false;
  }
  else if (map[(this->m_pieces[0]->getY() + y_velocity) *
	       this->m_width + this->m_pieces[0]->getX() + x_velocity] == ID_SNAKE)
    {
      std::cout << "Snake eats snake" << std::endl;
      return false;
    }
  return true;
}

/*
** it will move each piece of snake, if the head_x + x_velocity or head_y + y_velocity
** is out of range then -> DIE BITCH
** if there is food in new position -> addTail
** we will travel our vector change each position like last = last - 1 etc
** we just need to change tail / head position in our map 
** if we ate then we don't need to change the map tail because new tail is the last tail's pos
** return -1 if out of range else if ate 1 else 0
*/
int Snake::moveMe(char *map, int x_velocity, int y_velocity,
		  int freeCases, Food *food) {
  bool    ate = false;
  int     x = this->m_pieces[this->m_pieces.size() - 1]->getX();
  int     y = this->m_pieces[this->m_pieces.size() - 1]->getY();

  if (this->checkMove(map, x_velocity, y_velocity) == false)
    return (-1);
  if (this->m_pieces[0]->getX() + x_velocity == food->getPiece()->getX() &&
      m_pieces[0]->getY() + y_velocity == food->getPiece()->getY()) {
    ate = true;
    if (this->addTail(map, freeCases) == false)
      return (-1);
  }
  else
    ate = false;
  for (size_t i = this->m_pieces.size() - 1; i > 0; --i) {
    this->m_pieces[i]->setX(this->m_pieces[i - 1]->getX());
    this->m_pieces[i]->setY(this->m_pieces[i - 1]->getY());
  }
  this->m_pieces[0]->setX(this->m_pieces[0]->getX() + x_velocity);
  this->m_pieces[0]->setY(this->m_pieces[0]->getY() + y_velocity);
  map[this->m_pieces[0]->getY() * this->m_width + this->m_pieces[0]->getX()] = ID_SNAKE;
  if (ate == true) {
    food->removePiece(this->m_pieces[0]->getX(), this->m_pieces[0]->getY());
    return 1;
  }
  else
    map[y * this->m_width + x] = ID_FREE;
  return 0;
}
