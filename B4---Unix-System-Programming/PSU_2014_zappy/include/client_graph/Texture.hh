//
// Texture.hh for  in /home/tang_i/rendu/PSU_2014_zappy/annexes/sfml2d
//
// Made by David Tang
// Login   <tang_i@epitech.net>
//
// Started on  Fri Jun 19 15:24:49 2015 David Tang
// Last update Sun Jul  5 20:42:50 2015 David Tang
//

#ifndef TEXTURE_HH_
# define TEXTURE_HH_

/**
 * @file Texture.hh
 * @brief texture loader
 * @author tang_i
 * @version 1.0
 */

# include <string>
# include <map>
# include <SFML/Graphics.hpp>
# include "Error.hpp"

/**
 * @class Texture
 * @brief texture loader
 */
class			       		Texture
{
private:
  std::map<std::string, sf::Texture>   	m_textures; /**< textures map with all textures loaded */

public:
  /**
   * @brief constructor
   */
  Texture();

  /**
   * @brief destructor
   */
  ~Texture();

  /**
   * @brief load a texture and add it in the map
   *
   * @param name	: used as key in the map
   * @param file	: file we will try to load
   * @return		: -1 if any error or 0
   */
  int		       		        loadTexture(const std::string &name, const std::string &file);

  /**
   * @brief get texture in the map
   *
   * @param name	: name used to find texture in map
   *
   * @return		: texture found in the map
   */
  sf::Texture  				&getTexture(const std::string &name);
};

#endif /* !TEXTURE_HH_ */
