//
// TilesIndex.hh for  in /home/tang_i/rendu/PSU_2014_zappy
// 
// Made by David Tang
// Login   <tang_i@epitech.net>
// 
// Started on  Sun Jul  5 18:58:09 2015 David Tang
// Last update Sun Jul  5 20:13:30 2015 David Tang
//

#ifndef TILESINDEX_HH_
# define TILESINDEX_HH_

/**
 * @file TilesIndex.hh
 * @brief Index of Tile
 * @author tang_i
 * @version 1.00
 */

#include <map>
#include <string>
#include "Tile.hh"
#include "Texture.hh"

/**
 * @class TilesIndex
 * @brief It allow us to attach the tile we needed to the appropriate square
 */
class TilesIndex {
public:

  /**
   * @brief constructor
   *
   * We initialize the image's loading and the sprite's loading
   */
  TilesIndex();

  /**
   * @brief destructor
   */
  ~TilesIndex();

  /**
   * @brief we return the appropriate enum from a matching map
   *
   * @param name	: the name we want the enum
   * @return		: return the enum
   */
  Tile				&getTile(const std::string &name);

  /**
   * @brief we return a texture reference by the name
   *
   * @param name	: the name we want the texture
   * @return		: return the texture
   */
  sf::Texture			&getTexture(const std::string &texture) const;

private:

  /**
   * @brief map creating by loading the image with the appropriate name
   *
   * we load the image file here but only once for each tyle we want to create
   */
  void				initTextures();

  /**
   * @brief we create the tile for each object
   *
   * we create the tile with the appropriate name by matching the map created before
   */
  void				initTiles();

private:
  Texture			*m_texture; /**< the pointer fo the class texture  */
  std::map<std::string, Tile *>	m_tileIndex; /**< the map we are creating to match it */
};

#endif /* !TILESINDEX_HH_ */
