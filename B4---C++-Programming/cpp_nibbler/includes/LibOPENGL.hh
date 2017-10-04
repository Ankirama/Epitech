//
//  LibOPENGL.h
//  cpp_nibbler
//
//  Created by Fabien Martinez on 25/03/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __cpp_nibbler__LibOPENGL__
#define __cpp_nibbler__LibOPENGL__

#include <GL/freeglut.h>
#include "IGraphLib.hh"

#define ID_LEFT		-1
#define ID_RIGHT	1

class LibOPENGL : public IGraphLib {
public:
  explicit LibOPENGL(int width, int height, int speed, GameLogic *gameLogic);
  virtual ~LibOPENGL() {}
  virtual bool update();
  virtual bool draw() {return true;}
  virtual bool game();
  virtual void changeVelocity(int power);
  virtual void  drawPieces();

  virtual void	setXFactor(float x) {this->m_x_factor = x;}
  virtual void	setYFactor(float y) {this->m_y_factor = y;}
  virtual float	getXVelocity() const {return this->m_x_velocity;}
  virtual float	getYVelocity() const {return this->m_y_velocity;}
  virtual bool	getMove() const {return this->m_move;}
  virtual void	setMove(bool movable) {this->m_move = movable;}

private:
  GameLogic           *m_gameLogic;
  int                 m_width;
  int                 m_height;
  float               m_x_scale;
  float               m_y_scale;
  float		      m_x_velocity;
  float		      m_y_velocity;
  float		      m_x_factor;
  float		      m_y_factor;
  float		      m_speed;
  bool		      m_move;

  void	drawPiece(float x, float y, GLfloat *color);
  void	resize(int, int);
};

#endif /* defined(__cpp_nibbler__LibOPENGL__) */
