#ifndef XMLSAVE_HH
#define XMLSAVE_HH

/**
 * @file GenerateMaze.hh
 * @brief create map (random or not)
 * @author ankirama
 * @version 1.01
 */

#include <fstream>
#include <vector>
#include "IA.hh"
#include "Player.hh"
#include "XmlWrite.hpp"

/**
 * @class XmlSave
 * @brief create xml file (save)
 *
 * Used to save the current GameState in a xml file
 */
class XmlSave {
public:

  /**
   * @brief XmlSave's constructor
   *
   * Set variables and set stream / xml Object
   *
   * @param filename name for our new xml save
   * @nbPlayers Players number (max 2) in the current game
   * @nbAIs AIs number (no limit) in the current game
   */
  XmlSave(std::string const& filename, int nbPlayers, int nbAIs);

  /**
   * @brief XmlSave's destructor
   */
  ~XmlSave();

  /**
   * @brief save player in xml
   *
   * It will save a player in our xml save.
   * It will use a specific pattern / tags to save it.
   *
   * @param bomber player's reference which will be saved
   * @return true if we saved it, false if we already saved every player
   */
  bool savePlayer(Player &bomber);

  /**
   * @brief save AI in xml
   *
   * It will save an AI in our xml save.
   * It will use a specific pattern / tags to save it.
   *
   * @param bomber AI's reference which will be saved
   * @return true if we saved it, false if we already saved every AI or we didnt't finish with players
   */
  bool saveAI(IA &bomber);

  /**
   * @brief save maze in xml
   *
   * It will save the maze in our xml save.
   * It will use a specific pattern / tags to save it.
   *
   * @bug we didnt check if we already added it into our xml file
   *
   * @param map Contains every cell we need to save
   * @param width maze's width
   * @param height maze's height
   * @return true if we saved it, false if players / AIs aren't done yet
   */
  bool saveMaze(char const *map, int, int);

  void saveGame();
private:
  std::ofstream m_ofs; /**< Stream used to write into our file */
  XmlWrite      m_xmlWrite; /**< xml object to write an xml file */
  int           m_nbPlayers; /**< number players used to check if we wrote all and to close players element into our xml */
  int           m_nbAIs; /**< number AIs used to check if we wrote all and to close AIs element into our xml */
  bool          m_playersDone; /**< true if we wrote all players, else false */
  bool          m_AIDone; /**< true if we wrote all AIs, else false */
  bool          m_playersStarted; /**< set to true when we start to write players. Used to add tag("players") */
  bool          m_AIsStarted; /**< set to true when we start to write AIs. Used to add tag("AIs") */
  int           m_idPlayer; /**< current player's id to check if we have another player to add */
  int           m_idAI; /**< current AI's id to check if we have another AI to add */
private:

  /**
   * @brief write texture in xml
   *
   * It will write a texturepath with tag("texture") into the current xml
   *
   * @param filepath Filepath we want to save
   */
  void writeTexture(std::string const& filepath);

  /**
   * @brief write keys in xml
   *
   * It will write keys used by a player
   *
   * @param left define for the left action
   * @param right define for the right action
   * @param up define for the up action
   * @param down define for the down action
   * @param bomb define for the bomb action
   */
  void writeKeys(int left, int right, int up, int down, int bomb);

  /**
   * @brief write bomber's bombs in xml
   *
   * It will write bomber's bombs in tag("bombs")
   *
   * @param bombs bombs' vector we will travel to write into our tag("bombs")
   */
  void writeBombs(std::list<Bomb *> const &bombs);
};

#endif
