//
//  GenerateLib.h
//  cpp_nibbler
//
//  Created by Fabien Martinez on 25/03/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __cpp_nibbler__GenerateLib__
#define __cpp_nibbler__GenerateLib__

#include <string>
#include <dlfcn.h>
#include <iostream>
#include "IGraphLib.hh"
#include "GameLogic.hh"

class DLLoader {
public:
  explicit DLLoader(std::string const &libpath, std::string const &func_name);
  ~DLLoader();
  IGraphLib *getInstance(int width, int height, int speed, GameLogic *game);
private:
  typedef IGraphLib* (*load_lib)(int, int, int, GameLogic *);

  std::string         const m_libpath;
  std::string         const m_func_name;
  void                *m_dlhandle;
  IGraphLib           *m_graphLib;
};

#endif /* defined(__cpp_nibbler__GenerateLib__) */
