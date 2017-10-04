#ifndef XMLLOAD_HH_
#define XMLLOAD_HH_

/**
 * @file XmlLoad.hh
 * @brief load xml file
 * @author ankirama
 * @version 0.42
 */

#include <string>
#include <vector>
#include "IA.hh"
#include "ACharacter.hh"
#include "Player.hh"
#include "Bomb.hh"
#include "tinyxml2.h"

/**
 * @class XmlLoad
 * @brief load xml file
 *
 * Load a xml file and set GameState instance
 */
class XmlLoad {
public:

  /**
   * @brief XmlLoad's constructor
   *
   * It will load our file and set a xml's object
   *
   * @param filename xml file we want to load
   */
  XmlLoad(std::string const &filename);

  /**
   * @brief XmlLoad's destructor
   *
   * It will close our file and delete our xml's object
   */
  ~XmlLoad();

  /**
   * @brief Set GameState from xml file
   *
   * Main function to read our xml file and set our GameState
   */
  void loadSave();

private:
  tinyxml2::XMLDocument m_xmlDoc; /**< Xml object needed to load and read xml file */

private:
  /**
   * @brief get int from xml
   *
   * It will search the first child element needed and return the value
   *
   * @param root Current position into our xml file
   * @param name Name used in FirstChildElement to find our element
   * @return The value found in our FirstChildElement
   */
  int           getIntValue(tinyxml2::XMLElement *root, std::string const &name) const;

  /**
   * @brief get float from xml
   *
   * It will search the first child element needed and return the value
   *
   * @param root Current position into our xml file
   * @param name Name used in FirstChildElement to find our element
   * @return The value found in our FirstChildElement
   */
  float         getFloatValue(tinyxml2::XMLElement *root, std::string const &name) const;

  /**
   * @brief get unsigned int from xml
   *
   * It will search the first child element needed and return the value
   *
   * @param root Current position into our xml file
   * @param name Name used in FirstChildElement to find our element
   * @return The value found in our FirstChildElement
   */
  unsigned int  getUnIntValue(tinyxml2::XMLElement *root, std::string const &name) const;

  /**
   * @brief get bool from xml
   *
   * It will search the first child element needed and return the value
   *
   * @param root Current position into our xml file
   * @param name Name used in FirstChildElement to find our element
   * @return The value found in our FirstChildElement
   */
  bool getBoolValue(tinyxml2::XMLElement *root, std::string const &name) const;

  /**
   * @brief load bombermans from xml
   *
   * It will load "players" and "AIs" elements.
   * It will call createPlayer and createAI until the end
   *
   * @param root the current pointer on "save" tag (root tag in xml save)
   * @return Bombermans' vector with all players/AIs loaded
   */
  std::vector<ACharacter *>  loadBombers(tinyxml2::XMLElement *root, int width, int height) const;

  /**
   * @brief load player from xml
   *
   * It will create a player from our xml players' list
   *
   * @param player pointer into a element of players' list
   * @return New player loaded/created from our xml
   */
  Player        *createPlayer(tinyxml2::XMLElement *player) const;

  /**
   * @brief load AI from xml
   *
   * It will create an AI from our xml AIs' list
   *
   * @param ai pointer into a element of AIs' list
   * @return New player loaded/created from our xml
   */
  IA            *createAI(tinyxml2::XMLElement *ai, int width, int height) const;

  /**
   * @brief load bombs from player/ai
   *
   * It will create a bombs' vector from current player/ai
   *
   * @param bombs pointer into player/ai's bombs
   * @return bombs's vector loaded
   */
  std::list<Bomb *> createBombs(tinyxml2::XMLElement *bombs) const;

  /**
   * @brief load maze from xml
   *
   * It will create the maze from our xml
   *
   * @param maze pointer into our xml
   * @return New maze loaded/created from our xml
   */
  Maze          *createMaze(tinyxml2::XMLElement *maze) const;
};

#endif
