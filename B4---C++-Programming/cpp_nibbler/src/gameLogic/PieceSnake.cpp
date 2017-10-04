//
//  PieceSnake.cpp
//  cpp_nibbler
//
//  Created by Fabien Martinez on 24/03/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include "PieceSnake.hh"

PieceSnake::PieceSnake(typePiece type, int x, int y) : m_x(x), m_y(y), m_type(type) {}

int PieceSnake::getX() const {return this->m_x;}
int PieceSnake::getY() const {return this->m_y;}
typePiece PieceSnake::getType() const {return this->m_type;}

void PieceSnake::setX(int x) {this->m_x = x;}
void PieceSnake::setY(int y) {this->m_y = y;}
void PieceSnake::setType(typePiece type) {this->m_type = type;}