//
// SdlContext.cpp for  in /home/teyssa_r/rendu/cpp_bomberman
// 
// Made by Raphael Teyssandier
// Login   <teyssa_r@epitech.net>
// 
// Started on  Mon May 11 16:29:50 2015 Raphael Teyssandier
// Last update Mon May 11 16:37:57 2015 Raphael Teyssandier
//

#include "SdlContext.hh"

gdl::SdlContext::start(unsigned int swidth, unsigned int sheight, const std::string &name, int initFlag, int windowFlags) {
  const SDL_VideoInfo	*info = NULL;
  int			bpp = 0;

  if (SDL_Init(SDL_INIT_VIDEO) < 0){
    std::cerr << "Video initialization failed\n" << std::endl;
  }
}
