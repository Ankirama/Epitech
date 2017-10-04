//
//  IPiece.hh
//  cpp_nibbler
//
//  Created by Fabien Martinez on 24/03/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef cpp_nibbler_IPiece_hh
#define cpp_nibbler_IPiece_hh

#include <iostream>

typedef enum    e_typePiece {
  HEAD,
  BODY,
  TAIL,
  FOOD
}               typePiece;

#define ID_FREE     0
#define ID_SNAKE    1
#define ID_FOOD     2

#define DEF_HEIGHT  20
#define DEF_WIDTH   30

class IPiece {
public:
  virtual ~IPiece() {}
    
  virtual int getX() const = 0;
  virtual int getY() const = 0;
  virtual typePiece getType() const = 0;
  virtual void setX(int x) = 0;
  virtual void setY(int y) = 0;
  virtual void setType(typePiece type) = 0;
};

#endif
