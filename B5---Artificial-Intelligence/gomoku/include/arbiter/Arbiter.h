//
// Created by Fabien Martinez on 19/10/15.
//

/**
 * @file: Arbiter.h
 * @brief: Arbiter file with the map and all checks (rules)
 * @author: ankirama
 * @version: 1.0.0
 */

#ifndef GOMOKU_ARBITER_H
#define GOMOKU_ARBITER_H

#include <iostream>
#include "Map.h"

// ================ //
// BINARY VARIABLES //
// ================ //

# define CASE_AI         0x03 // 0011 (bin)
# define CASE_NEAR_TRIPLE   0x04 // 0100 (bin) // it will contain 1 if there is a triple near it
# define CASE_IS_CATCHABLE  0x10 // 0001 0000 (bin) // true if this stone can be catch

// ================= //
// BINARY OPERATIONS //
// ================= //

/**
 * @def OPPONENT_PLAYER(PLAYER)
 *
 * keep player and reverse it
 */
# define OPPONENT_PLAYER(PLAYER)   (((~PLAYER) & 0x03))

/** enum to define current state in the game
 * It will define current state on the game
 */
typedef enum {
  STATE_PLAYING,
  STATE_WINNER_1,
  STATE_WINNER_2
} t_state_game;

/**
 * @class: Arbiter
 *
 * @brief: Class to execute rules and check them
 */
class Arbiter {
public:

  /**
   * @brief: Basic constructor
   */
  Arbiter(bool firstRule = false, bool secondRule = false);

  /**
   * @brief: Basic destructor
   */
  ~Arbiter();

  Arbiter(Arbiter &copy);

  /**
   * @brief: Check if the next move is a valid one
   *
   * It will check every rule
   *
   * @param x: x position
   * @param y: y position
   * @param player: used to force a specific player to play. Useful for tests
   * @return: true if the next move is valid, else return false
   */
  bool isValidMove(int x, int y) const;

  void addStone(int x, int y, int player);

  void addStone(int x, int y);

  bool checkRules(int x, int y);

  bool isWinnerHere(int x, int y);

  /**
   * @brief: Check if we can remove stones;
   *
   * @param x: x new cell
   * @param y: y new cell
   * @brief: return true if we have 10 stones stole, else false
   */
  bool eatStones(int x, int y);

  /**
   * @brief: reset the GameEngine (all variables) to restart the game for example
   */
  void resetGame();

  /**
   * @brief: Check if the first rule is still valid
   *
   * Check if a player with 5 stones can still lose his stones
   *
   * @param x: x position
   * @param y: y position
   * @return: true if enemy can still play, else return false (WE HAVE A WINNER)
   */
  bool isValidFirstRule(int x, int y);

  /**
 * @brief: Check if the last rule is still valid
 *
 * It's forbidden to do double-triple
 * check http://www.infop7.org/file/576/IK3_projet-3_2012.pdf ('deuxieme regle')
 *
 * @param x: x position
 * @param y: y position
 * @return: true if there is no double triple, else false
 */
  bool isValidSecondRule(int x, int y);

public:
  /**
   * @brief: getters / setters
   */

  /**
   * @brief: set current player
   *
   * @param player: could be CASE_PLAYER_1 or CASE_PLAYER_2
   */
  void setCurrentPlayer(int player);

  int getCurrentPlayer() const;

  /**
   * @brief: enable / disable first rule
   *
   */
  void toggleFirstRule();

  /**
   * @brief set state first rule
   *
   * @param rule: boolean true / false
   */
  void setFirstRule(bool state);

  /**
   * @brief: check if first rule is activate or not
   *
   * @return enable/disable boolean about first rule
   */
  bool isFirstRuleEnabled() const;

  /**
   * @brief: enable / disable second rule
   */
  void toggleSecondRule();

  /**
   * @brief set state second rule
   *
   * @param rule: boolean true / false
   */
  void setSecondRule(bool state);

  /**
  * @brief: check if first rule is activate or not
  *
  * @return enable/disable boolean about first rule
  */
  bool isSecondRuleEnabled() const;

  /**
   * @brief: set winToCancel variable
   * This variable allow us to know if the winner with firstRule is a real winner
   *
   * @winToCancel: boolean true / false
   */
  void setWinToCancel(bool winToCancel);

  /**
   * @brief: get winToCancel variable
   * This variable allow us to know if the winner with firstRule is a real winner
   *
   * @return: m_winToCancel
   */
  bool getWinToCancel();

  /**
   * @brief: Set our pointer on member function with first rule / second rule (enable or disable)
   * It will set the good function, to use the pointer we will call playAMove()
   * This function will check this->m_activateFirstRule and this->m_activateSecondRule with 2 getters
   */
  void setMemberFunctionToPlay();

  /**
   * @brief: get pointer to Map class
   *
   * @return pointer to Map class
  */
  Map *getBoard();

  int getStonesStole(int player) const;

  bool isSamePlayer() const;

public:
  /**
   * @brief: These functions will allow to define our pointer on function member with the good rule enabled
   */

  /**
   * @brief: like a get to play our different move and avoid some baka tests
   */
  t_state_game playAMove(int x, int y);

  /**
   * @brief: it will check if we can add a stone and we will do it + check winner + change player
   * This function will check firstRule and secondRule
   *
   * @param x: current case x we want to add
   * @param y: current case y we want to add
   * @return: state like PLAYING / WINNER_1 / WINNER_2
   */
  t_state_game playAMoveAllEnabled(int x, int y);


  /**
   * @brief: it will check if we can add a stone and we will do it + check winner + change player
   * This function will check firstRule
   *
   * @param x: current case x we want to add
   * @param y: current case y we want to add
   * @return: state like PLAYING / WINNER_1 / WINNER_2
   */
  t_state_game playAMoveFirstEnabled(int x, int y);


  /**
   * @brief: it will check if we can add a stone and we will do it + check winner + change player
   * This function will check secondRule
   *
   * @param x: current case x we want to add
   * @param y: current case y we want to add
   * @return: state like PLAYING / WINNER_1 / WINNER_2
   */
  t_state_game playAMoveSecondEnabled(int x, int y);

  /**
   * @brief: it will check if we can add a stone and we will do it + check winner + change player
   * This function will check secondRule
   *
   * @param x: current case x we want to add
   * @param y: current case y we want to add
   * @return: state like PLAYING / WINNER_1 / WINNER_2
   */
  t_state_game playAMoveNoneEnabled(int x, int y);

private:

  int tripleStones(int x, int y, t_point *direction);

  bool isTripleHere(int x, int y, const t_point *direction);

  bool isSpecialTripleCase(int x, int y, const t_point *direction);

  int countStoneDirection(int x, int y, const t_point *move, int type);

  int maxStonesFirstRules(int x, int y, t_point *direction, int indexDirection, int current);

  bool checkAroundStone(int x, int y);

  bool checkAroundStoneFirst(int x, int y, bool isFirst);

  bool isCatchableDirection(int x, int y, t_point *direction, int orientation);

  bool checkEatDirection(int x, int y, t_point *direction);

  bool partCheckAroundFirst(int x, int y, t_point *direction, int orientation, bool isFirst);

  int maxStones(int x, int y, int x_move, int y_move);

  /**
   * @brief: used for first rule
   * It checks side of the 5 stones
   *
   * @param x: current x stone position
   * @param y: current y stone position
   * @param type: current type 5 stones like vertical, horizontal, diago left or right
   * @return: true if enemy can still play, else false
   */
  bool checkSide(int x, int y, int type) const;

  bool isCatchable(int x, int y, int directionIndex);

  bool checkEatStones(int x, int y, t_point *direction);

private:
  static const t_point m_stones_move[4]; /**< It will contain our 4 move for each direction */
  int m_currentPlayer; /**< define the current player. Useful to check winner */
  int m_x_move;
  int m_y_move;
  bool m_activateFirstRule;
  bool m_activateSecondRule;
  t_state_game (Arbiter::*m_playYourTurn)(int x, int y);
  int m_stones_stole[2]; /**< Contain number of stones stole by each player */
  bool m_winToCancel; /**< true player can still cancel win, else false */
  int m_winner;
  Map *m_board; /**< our map */
  bool m_samePlayer;
};


#endif //GOMOKU_ARBITER_H
