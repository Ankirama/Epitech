//
// Texture.cpp for  in /home/tang_i/rendu/PSU_2014_zappy/annexes/sfml2d
// 
// Made by David Tang
// Login   <tang_i@epitech.net>
// 
// Started on  Fri Jun 19 15:25:02 2015 David Tang
// Last update Mon Jun 29 19:08:46 2015 Raphael Teyssandier
//

#include <iostream>
#include "Texture.hh"

Texture::Texture(){
}

Texture::~Texture(){}

int		Texture::loadTexture(const std::string &name, const std::string &file){
  try {
  sf::Texture	texture;

  if (!texture.loadFromFile(file)){
    std::cerr  << "Failed to load a texture" << std::endl;
    return (-1);
  }
  this->m_textures[name] = texture;
  return (0);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Texture");
  }
}

sf::Texture	&Texture::getTexture(const std::string &texture){
  try {
  return (this->m_textures.at(texture));
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Texture");
  }
}
