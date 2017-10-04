//
//  Food.cpp
//  cpp_nibbler
//
//  Created by Fabien Martinez on 25/03/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include "Food.hh"

Food::Food() : m_width(DEF_WIDTH), m_height(DEF_HEIGHT) {
  std::srand((unsigned int)std::time(0));
  this->m_piece = 0;
}

Food::Food(int width, int height) : m_width(width), m_height(height) {
  std::srand((unsigned int)std::time(0));
  this->m_piece = 0;
}

Food::~Food() {
  if (this->m_piece != 0)
    delete this->m_piece;
}

IPiece	*Food::getPiece() const {return this->m_piece;}

void	Food::setPiece(int x, int y) {
  this->m_piece = new PieceFood(x, y);
}

void	Food::removePiece(int x, int y) {
  if (this->m_piece != 0 &&
      this->m_piece->getX() == x && this->m_piece->getY() == y) {
    delete this->m_piece;
    this->m_piece = 0;
  }
}

void	Food::generateFood(char *map, int &freeCases) {
  int	i;
  int	j;

  do {
    i = std::rand() % this->m_width;
    j = std::rand() % this->m_height;
  } while (map[j * this->m_width + i] != ID_FREE);
  map[j * this->m_width + i] = ID_FOOD;
  --freeCases;
  this->m_piece = new PieceFood(i, j);
}
