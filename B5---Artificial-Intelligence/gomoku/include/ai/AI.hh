//
// Created by Fabien Martinez on 16/01/16.
//

#ifndef GOMOKU_AI_H
#define GOMOKU_AI_H

#include <limits>
#include <chrono>
#include "Arbiter.h"
#include "templateString.h"

# define INFINITY_MIN   std::numeric_limits<long>::min()
# define INFINITY_MAX   std::numeric_limits<long>::max()
# define MAX(X, Y)      (X > Y ? X : Y)

# define EXXXXE         69120000000000
# define EXXXX          1152000000000
# define EEXXXEE        57600000000
# define EXXXEE         1440000000
# define EXXXE          24000000
# define EEXXEE         600000
# define EEXXX          10000
# define EEXXE          100
//# define E00X

typedef enum {
  DIFF_NORMAL,
  DIFF_HARD
} t_difficulty;

class AI {
public:
  AI(Arbiter *arbiter, t_difficulty difficulty = DIFF_NORMAL, int player = CASE_BLACK);
  ~AI();

public:
  int play();
  std::string const &getTimer() const { return this->m_timer; }
    void changeDifficulty(t_difficulty difficulty);

private:
    long heuristicDirectionCellNormal(Arbiter *arbiter, int x, int y, int direction);
    long heuristicDirectionCellHard(Arbiter *arbiter, int x, int y, int direction);
    long heuristicFunction(Arbiter *arbiter);
    long negamax(Arbiter *arbiter, int depth, long alpha, long beta);

private:
  Arbiter               *m_arbiter;
  long (AI::*m_heuristicDirectionCell)(Arbiter *arbiter, int x, int y, int direction);
  static const t_point  m_directions[4];
  std::map<int, long>   m_stealHeuristic; /**< Heuristic values steal stones */
  std::map<int, long>   m_heuristicValues; /**< Heuristic values */
  int                   m_player;
  std::string           m_timer;
  int                   m_move;
};


#endif //GOMOKU_AI_H
