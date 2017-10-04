//
//  GenerateLib.cpp
//  cpp_nibbler
//
//  Created by Fabien Martinez on 25/03/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include "DLLoader.hh"
#include "Error.hh"

DLLoader::DLLoader(std::string const &libpath, std::string const &func_name) :
  m_libpath(libpath), m_func_name(func_name) {
  this->m_dlhandle = dlopen(this->m_libpath.c_str(), RTLD_LAZY);
  if (this->m_dlhandle == 0) {
    throw ErrorLib(dlerror(), "DLLoader");
  }
  this->m_graphLib = 0;
}

DLLoader::~DLLoader() {
  if (this->m_graphLib)
    delete this->m_graphLib;
  dlclose(this->m_dlhandle);
}

IGraphLib *DLLoader::getInstance(int width, int height, int speed, GameLogic *gameLogic) {
  void		*ptr;
  load_lib	ext_load_lib;

  if (this->m_graphLib == 0) {
    ptr = dlsym(this->m_dlhandle, this->m_func_name.c_str());
    if (ptr == 0) {
      throw ErrorLib(dlerror(), "DLLoader");
    }
    ext_load_lib = reinterpret_cast<IGraphLib* (*) (int, int, int, GameLogic *)>(ptr);
    this->m_graphLib = ext_load_lib(width, height, speed, gameLogic);
  }
  return this->m_graphLib;
}
