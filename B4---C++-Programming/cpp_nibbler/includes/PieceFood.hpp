//
//  PieceFood.hpp
//  cpp_nibbler
//
//  Created by Fabien Martinez on 25/03/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef cpp_nibbler_PieceFood_hpp
#define cpp_nibbler_PieceFood_hpp

#include "IPiece.hh"

class PieceFood : public IPiece {
public:
  explicit PieceFood(int x, int y) : m_x(x), m_y(y), m_type(FOOD) {}
  virtual ~PieceFood() {}
    
  virtual int getX() const {return m_x;}
  virtual int getY() const {return m_y;}
  virtual typePiece getType() const {return m_type;}
  
  virtual void setX(int x) {m_x = x;}
  virtual void setY(int y) {m_y = y;}
  virtual void setType(typePiece type) {m_type = type;}
  
private:
  int m_x;
  int m_y;
  typePiece m_type;
};

#endif
