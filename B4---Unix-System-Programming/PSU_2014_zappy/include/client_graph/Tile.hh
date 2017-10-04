//
// Tile.hh for  in /home/tang_i/rendu/PSU_2014_zappy/annexes/sfml2d
//
// Made by David Tang
// Login   <tang_i@epitech.net>
//
// Started on  Wed Jun 24 15:48:37 2015 David Tang
// Last update Sun Jul  5 20:43:28 2015 David Tang
//

#ifndef TILE_HH_
# define TILE_HH_

/**
 * @file Tile.hh
 * @brief Tile's Sprite for the display
 * @author tang_i
 * @version 1.00
 */

# include <SFML/Graphics.hpp>
# include <cmath>
# include <iostream>
# include "object.h"
# include "Error.hpp"

/**
 * @TILEMAX	: a define for stretching the tile
 */
# define TILEMAX		10

/**
 * @tileType	: an enum to distinct the different type of sprite
 */
enum tileType
{
  VOID,
  GRASS,
  EGG1,
  EGG2,
  LINEMATE,
  DERAUMERE,
  SIBUR,
  MENDIANE,
  PHIRAS,
  THYSTAME,
  CHARACTER,
  FOOD
};

/**
 * @class Tyle
 * @brief use to create the Tile's sprite
 *
 * It will allow us to create the differents sprite for the display
 * It is a Tile display so we can ajust the correct coordinate or size
 * of the sprite here
 *
 */

class				Tile {
public:
    /**
     * @brief constructor
     */
  Tile();

    /**
     * @brief constructor
     *
     * Tile's constructor
     *
     * @param type		: the type enum we juste created above
     * @param _texture		: the image we loaded
     * @param _size		: the define for stretching the sprite if needed
     * @param _height		: the stretching height value
     */
  Tile(const tileType type, sf::Texture &_texture,
       unsigned int _size, unsigned int _height);

    /**
     * @brief a copy constructor of Tile
     *
     * @param	: the tile we want to copy it
     */
  Tile(Tile const &t);

    /**
     * @brief a destructor of Tile
     */
  ~Tile();

public:
    /**
     * @brief draw the tile
     *
     * @param window	: the pointer of the window is needed to display the tile
     */
  void				drawTile(sf::RenderWindow *window);

    /**
     * @brief return the type of the tyle
     *
     * @return	: the type
     */
  tileType			getType() const;

    /**
     * @brief return the sprite attached to the tyle
     *
     * @return	: the sprite
     */
  sf::Sprite			&getSprite();

    /**
     * @brief set the inventory contained in this tyle
     *
     * @parami		: the id of ressource
     * @paramvalue	: the value we want to change
     */
  void	 			setInv(unsigned int i, unsigned int value);

    /**
     * @brief return the width of the texture
     *
     * @return	: the width of the texture
     */
  int				getWidth() const;

    /**
     * @brief return the height of the texture
     *
     * @return	: the height of the texture
     */
  int				getHeight() const;

private:
  tileType			m_type; /**<  the type enum */
  sf::Sprite			m_sprite; /**< the sprite loaded */
  int				m_tab[NB_OBJ]; /**< an array of int which represent the ressources */
};

/**
 * @brief convert into isometric x
 *
 * @param xy		: equal to x - y
 * @param widthTexture	: cell texture width
 * @param cut		: percentage removed to set object position (default 20 for x)
 * @param width		: screen width (like 1280)
 * @return		: new x (in isometric)
 */
inline float getXIso(float xy, float widthTexture, float cut, float width) {
  return (width / 2 - widthTexture / 2 + xy * (widthTexture / 2 - widthTexture / cut));
}

/**
 * @brief convert into isometric y
 *
 * @param		: xy equal to x + y
 * @param textureSize	: cell texture dimension
 * @param cut		: percentage removed to set object position (default 10)
 * @return		: new y (in isometric)
 */
inline float getYIso(float xy, const sf::Vector2u textureSize, float cut, float, float) {
  float	heightTexture = textureSize.y;

  return (xy * (heightTexture / 2 - heightTexture / cut));
}

#endif /* !TILE_HH_ */
