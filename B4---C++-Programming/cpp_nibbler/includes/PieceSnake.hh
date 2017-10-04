//
//  PieceSnake.h
//  cpp_nibbler
//
//  Created by Fabien Martinez on 24/03/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __cpp_nibbler__PieceSnake__
#define __cpp_nibbler__PieceSnake__

#include "IPiece.hh"

class PieceSnake : public IPiece {
public:
  explicit PieceSnake(typePiece type, int x, int y);
  virtual ~PieceSnake() {}
  
  virtual int getX() const;
  virtual int getY() const;
  virtual typePiece getType() const;
  
  virtual void setX(int x);
  virtual void setY(int y);
  virtual void setType(typePiece type);
  
private:
  int m_x;
  int m_y;
  typePiece m_type;
};

#endif /* defined(__cpp_nibbler__PieceSnake__) */
