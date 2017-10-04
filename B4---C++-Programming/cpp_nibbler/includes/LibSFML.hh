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

#define ID_LEFT		-1
#define ID_RIGHT	1

class LibSFML : public IGraphLib {
public:
  explicit LibSFML(int width, int height, int speed, GameLogic *gameLogic);
  virtual ~LibSFML() {}
  virtual bool update();
  virtual bool draw();
  virtual bool game();
  virtual void  drawPieces();
  virtual void changeVelocity(int power);
  virtual void	setXFactor(float) {}
  virtual void	setYFactor(float) {}
  virtual float	getXVelocity() const {return 0.0f;}
  virtual float	getYVelocity() const {return 0.0f;}
  virtual bool	getMove() const {return true;}
  virtual void	setMove(bool) {}

private:
  GameLogic           *m_gameLogic;
  sf::RenderWindow    *m_window;
  int                 m_width;
  int                 m_height;
  float               m_x_scale;
  float               m_y_scale;
  int		      m_x_velocity;
  int		      m_y_velocity;
  float		      m_speed;

  void	  drawPiece(int x, int y, const sf::Color& color);
};

#endif /* defined(__cpp_nibbler__LibSFML__) */
