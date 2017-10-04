//
//  IGraphLib.hh
//  cpp_nibbler
//
//  Created by Fabien Martinez on 25/03/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef cpp_nibbler_IGraphLib_hh
#define cpp_nibbler_IGraphLib_hh

#include "GameLogic.hh"

#define SCREEN_WIDTH    800
#define SCREEN_HEIGHT   640

class   IGraphLib {
public:
  virtual ~IGraphLib() {}
  
  virtual bool update() = 0;
  virtual bool draw() = 0;
  virtual bool game() = 0;
  virtual void changeVelocity(int power) = 0;
  virtual void  drawPieces() = 0;
  virtual void	setXFactor(float x) = 0;
  virtual void	setYFactor(float y) = 0;
  virtual float	getXVelocity() const = 0;
  virtual float	getYVelocity() const = 0;
  virtual bool	getMove() const = 0;
  virtual void	setMove(bool movable) = 0;
};

#endif
