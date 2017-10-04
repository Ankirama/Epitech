//
// Music.hh for  in /home/tang_i/rendu/PSU_2014_zappy/annexes/sfml2d
//
// Made by David Tang
// Login   <tang_i@epitech.net>
//
// Started on  Fri Jun 19 14:05:50 2015 David Tang
// Last update Sun Jul  5 20:42:12 2015 David Tang
//

#ifndef MUSIC_HH_
# define MUSIC_HH_

/**
 * @file Music.hh
 * @brief play music
 * @author tang_i
 * @version 1.0
 */

# define DREAM	"ressources/songs/dream.wav"
# define DOFUS	"ressources/songs/Dofus.wav"

# include <SFML/Audio.hpp>
# include <string>
# include "Error.hpp"

/**
 * @class Music
 * @brief play music during game
 */
class				Music{
private:
  sf::Music			*m_sound; /**< music we will play */

public:

  /**
   * @brief constructor
   *
   * set default variable
   */
  Music();

  /**
   * @brief destructor
   *
   * delete sound variable
   */
  ~Music();

public:

  /**
   * @brief load music file and set loop to true
   *
   * @param filename	: try to load this file
   */
  void				loadMusic(const std::string &filename) const;

  /**
   * @brief play music
   */
  void				playMusic() const;

  /**
   * @brief stop music
   */
  void				stopMusic() const;

  /**
   * @brief get sound
   *
   * @return	: current sound
   */
  sf::Music    			*getSound() const;
};

#endif /* !MUSIC_HH_ */
