//
// Created by ankirama on 5/11/15.
//

#ifndef CPP_BOMBERMAN_SCORE_HH
#define CPP_BOMBERMAN_SCORE_HH

/**
 * @file Score.hh
 * @brief save score into a file and load it
 * @author ankirama
 * @version 0.42
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include "template_string.hh"
#include "split_map.hh"

/**
 * @class Score
 * @brief Save/Load score
 *
 * Save or Load scores file (scores).
 * It's a singleton so there is an unique instance
 */
class Score {
public:

  /**
   * @brief Used to return the current instance
   *
   * Our class is a singleton so we need a function to use it
   *
   * @return the current class's instance
   */
    static  Score& getInstance();

    /**
     * @brief add a player's score
     *
     * If the player is new then create a new value in our map, else add the score
     *
     * @param player player's name
     * @param score score to add
     */
    void    addScore(std::string const &player, unsigned int score);

    /**
     * @brief show the map score
     *
     * It will display the score in stdout
     */
    void    showScore() const;

    /**
     * @brief get the player's score
     *
     * If player doens't exist it will return 0
     *
     * @player player's name
     * @return player's score
     */
  unsigned int getPlayerScore(std::string const &player);

    /**
     * @brief get top N players
     *
     * Get a top N players with N <= map's size
     *
     * @bug a map sort are entries so we have to use a vector instead
     * @bug unable to create a pair with a const so we'll use std::string alone
     *
     * @param n number players to return
     * @return A new vector with n players
     */
    std::vector < std::pair<std::string, unsigned int > > getTopN(int n);

private:

  /**
   * @brief private = operator to unable it
   *
   * Unused and undefined
   */
    Score& operator=(const Score&);

    /**
     * @brief private copy constructor
     *
     * Unused
     */
    Score(const Score&) {}

    /**
     * @brief Score's constructor private
     *
     * Used to create a static instance (singleton)
     * The file 'scores' will be opened and data will be extracted (in tokens).
     */
    Score();

    /**
     * @brief Score's destructor private
     *
     * It will close our streams and we willl rewrite into our scores' log
     */
    ~Score();
private:
    static Score                        m_instance; /**< used in singleton */
    std::ofstream                       m_wFile; /**< stream to write into our file */
    std::ifstream                       m_rFile; /**< stream to read from our file */
    std::map        <std::string const, unsigned int>  m_score; /**< map to store user and score */
};

#endif //CPP_BOMBERMAN_SCORE_HH
