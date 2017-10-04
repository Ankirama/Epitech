//
//  Food.h
//  cpp_nibbler
//
//  Created by Fabien Martinez on 25/03/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __cpp_nibbler__Food__
#define __cpp_nibbler__Food__

#include <cstdlib>
#include <ctime>

#include "PieceFood.hpp"

class Food {
public:
  Food();
  Food(int width, int height);
  ~Food();

  IPiece *getPiece() const;
  void setPiece(int x, int y);
  void removePiece(int x, int y);

  void generateFood(char *map, int &freeCases);
private:
  int m_width;
  int m_height;
  IPiece *m_piece;
};

#endif /* defined(__cpp_nibbler__Food__) */
