//
//  GameLogic.h
//  cpp_nibbler
//
//  Created by Fabien Martinez on 24/03/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __cpp_nibbler__GameLogic__
#define __cpp_nibbler__GameLogic__

#include <string>
#include "Snake.hh"
#include "Food.hh"

class GameLogic {
public:
  //faire la forme canonique
  GameLogic();
  GameLogic(int width, int height);
  ~GameLogic();

  char		*getMap() const;
  int		getScore() const;
  int		getWidth() const;
  int		getHeight() const;
  Snake		*getSnake() const;
  Food		*getFood() const;

  bool    update(int x_velocity, int y_velocity);
  void	  draw();
private:
  Snake   *m_snake;
  Food    *m_food;
  int     m_score;
  char    *m_map;
  int     m_height;
  int     m_width;
  int     m_sizeArea;
  int     m_freeCases;

  void    initMap();
};

#endif /* defined(__cpp_nibbler__GameLogic__) */
