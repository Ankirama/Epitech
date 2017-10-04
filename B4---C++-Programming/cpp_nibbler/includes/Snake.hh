//
//  Snake.h
//  cpp_nibbler
//
//  Created by Fabien Martinez on 24/03/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __cpp_nibbler__Snake__
#define __cpp_nibbler__Snake__

#include <vector>
#include <iostream>
#include "PieceSnake.hh"
#include "Food.hh"

class Snake {
public:
  //forme canonique
  Snake();
  Snake(int width, int height);
  ~Snake();
  
  std::vector<IPiece *> &getPieces();
  
  bool addTail(char *map, int freeCases);
  int moveMe(char *map, int x_velocity, int y_velocity, int freeCases, Food *food);
private:
  int                     m_width;
  int                     m_height;
  std::vector<IPiece *>   m_pieces;

  bool checkMove(char *map, int x_velocity, int y_velocity);
};

#endif /* defined(__cpp_nibbler__Snake__) */
