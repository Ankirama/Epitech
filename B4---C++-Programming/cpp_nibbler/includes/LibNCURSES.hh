//
//  LibSFML.h
//  cpp_nibbler
//
//  Created by Fabien Martinez on 25/03/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __cpp_nibbler__LibSFML__
#define __cpp_nibbler__LibSFML__

#include "IGraphLib.hh"

#define ID_LEFT         -1
#define ID_RIGHT        1

class LibNCURSES : public IGraphLib {
public:
  explicit LibNCURSES(int width, int height, int speed, GameLogic *gameLogic);
  virtual ~LibNCURSES() {}
  virtual bool draw();
  virtual void changeVelocity(int power);
  virtual void  drawPieces() {};
  virtual void	setXFactor(float) {}
  virtual void	setYFactor(float) {}
  virtual float	getXVelocity() const {return 0.0f;}
  virtual float	getYVelocity() const {return 0.0f;}
  virtual bool	getMove() const {return true;}
  virtual void	setMove(bool) {}
  virtual bool update();
  virtual bool game();

private:
  GameLogic		*m_gameLogic;
  WINDOW		*m_win;
  int			m_width;
  int			m_height;
  int			m_x_velocity;
  int			m_y_velocity;

  void			close();
};

#endif /* defined(__cpp_nibbler__LibSFML__) */
