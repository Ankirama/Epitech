//
// Created by Fabien Martinez on 16/01/16.
//

#include <include/arbiter/Map.h>
#include "AI.hh"

const t_point AI::m_directions[] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}};

AI::AI(Arbiter *arbiter, t_difficulty difficulty, int player) {
  this->m_arbiter = arbiter;
  this->m_stealHeuristic.insert(std::make_pair(2, EEXXX));
  this->m_stealHeuristic.insert(std::make_pair(4, EEXXEE));
  this->m_stealHeuristic.insert(std::make_pair(6, EEXXXEE));
  this->m_stealHeuristic.insert(std::make_pair(8, EXXXXE / 2));

  this->m_heuristicValues.insert(std::make_pair(-7, EEXXXEE));
  this->m_heuristicValues.insert(std::make_pair(12, EXXXXE));
  this->m_heuristicValues.insert(std::make_pair(0, EXXXEE));
  this->m_heuristicValues.insert(std::make_pair(-12, EEXXEE));
  this->m_heuristicValues.insert(std::make_pair(15, EXXXX));
  this->m_heuristicValues.insert(std::make_pair(5, EXXXE));
  this->m_heuristicValues.insert(std::make_pair(-5, EEXXE));
  this->m_player = player;
  this->m_timer = "0";
  this->changeDifficulty(difficulty);
}

AI::~AI() {

}

void AI::changeDifficulty(t_difficulty difficulty) {
  switch (difficulty) {
    case DIFF_NORMAL:
      this->m_heuristicDirectionCell = &AI::heuristicDirectionCellNormal;
      break;
    case DIFF_HARD:
      this->m_heuristicDirectionCell = &AI::heuristicDirectionCellHard;
      break;
    default:
      this->m_heuristicDirectionCell = &AI::heuristicDirectionCellNormal;
      break;
  }
}

int AI::play() {
  this->m_move = 0;
  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
  long score = this->negamax(this->m_arbiter, 1, -INFINITY_MAX, INFINITY_MAX);
  std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
  this->m_timer = NumberToString<long long int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count());
  return this->m_move;
}

long AI::heuristicDirectionCellNormal(Arbiter *arbiter, int x, int y, int direction) {
  t_point vector = this->m_directions[direction];

  if (arbiter->getBoard()->isCellCheckedDirection(x, y, direction) || x + 5 * vector.x >= WIDTH_BOARD || y + 5 * vector.y >= HEIGHT_BOARD) return 0;
  int nbrEmptyBegin = 0;
  while (nbrEmptyBegin < 3 && arbiter->getBoard()->isCellType(x + nbrEmptyBegin * vector.x, y + nbrEmptyBegin * vector.y, CASE_EMPTY))
    ++nbrEmptyBegin;
  if (nbrEmptyBegin == 3) return 0;
  int i = nbrEmptyBegin;
  int current = arbiter->getBoard()->getCellPlayer(x + i * vector.x, y + i * vector.y);
  if (current == -1 || current == CASE_EMPTY) return 0;
  int nbrPlayer = 1;
  ++i;
  while (arbiter->getBoard()->isCellType(x + i * vector.x, y + i * vector.y, current)) {
    ++i;
    ++nbrPlayer;
  }

  int nbrEmptyEnd = 0;
  while (nbrEmptyEnd < 2 && arbiter->getBoard()->isCellType(x + (i + nbrEmptyEnd) * vector.x, y + (i + nbrEmptyEnd) * vector.y, CASE_EMPTY))
    ++nbrEmptyEnd;
  if (nbrEmptyEnd == 2 && nbrEmptyBegin == 0 && nbrPlayer == 2 && arbiter->getBoard()->isCellType(x + (i + nbrEmptyBegin) * vector.x, y + (i + nbrEmptyEnd) * vector.y, CASE_EMPTY)) {
    ++nbrEmptyEnd;
  }
  int nbCells = nbrPlayer + nbrEmptyBegin + nbrEmptyEnd;
  if (nbCells < 5 || nbrPlayer < 2) return 0;
  int res = (nbrPlayer - (nbrEmptyBegin + nbrEmptyEnd)) * nbCells;
  if (nbrPlayer == 4 && nbrEmptyBegin + nbrEmptyEnd >= 2) res = 12;
  if (nbrPlayer >= 2 && this->m_heuristicValues.find(res) != this->m_heuristicValues.end()) {
    for (int j = 1; j < nbCells - 1; ++j) {
      arbiter->getBoard()->setCellChecked(x + j * vector.x, y + j * vector.y, direction);
    }
    if (current == this->m_player) return -(this->m_heuristicValues.find(res)->second);
    return (this->m_heuristicValues.find(res))->second;
  }
  return 0;
}

long AI::heuristicDirectionCellHard(Arbiter *arbiter, int x, int y, int direction) {
  t_point vector = this->m_directions[direction];

  if (arbiter->getBoard()->isCellCheckedDirection(x, y, direction) || x + 5 * vector.x >= WIDTH_BOARD || y + 5 * vector.y >= HEIGHT_BOARD) return 0;
  int nbrEmptyBegin = 0;
  while (nbrEmptyBegin < 3 && arbiter->getBoard()->isCellType(x + nbrEmptyBegin * vector.x, y + nbrEmptyBegin * vector.y, CASE_EMPTY))
    ++nbrEmptyBegin;
  if (nbrEmptyBegin == 3) return 0;
  int i = nbrEmptyBegin;
  int current = arbiter->getBoard()->getCellPlayer(x + i * vector.x, y + i * vector.y);
  if (current == -1 || current == CASE_EMPTY) return 0;
  int nbrPlayer = 1;
  bool oneEmpty = false;
  ++i;
  while (arbiter->getBoard()->isCellType(x + i * vector.x, y + i * vector.y, current) || (!oneEmpty && arbiter->getBoard()->isCellType(x + i * vector.x, y + i * vector.y, CASE_EMPTY) && arbiter->getBoard()->isCellType(x + (i + 1) * vector.x, y + (i + 1) * vector.y, current))) {
    if (arbiter->getBoard()->isCellType(x + i * vector.x, y + i * vector.y, CASE_EMPTY)) {
      oneEmpty = true;
    } else {
      ++nbrPlayer;
    }
    ++i;
  }

  int nbrEmptyEnd = 0;
  while (nbrEmptyEnd < 2 && arbiter->getBoard()->isCellType(x + (i + nbrEmptyEnd) * vector.x, y + (i + nbrEmptyEnd) * vector.y, CASE_EMPTY))
    ++nbrEmptyEnd;
  if (nbrEmptyEnd == 2 && nbrEmptyBegin == 0 && nbrPlayer == 2 && arbiter->getBoard()->isCellType(x + (i + nbrEmptyBegin) * vector.x, y + (i + nbrEmptyEnd) * vector.y, CASE_EMPTY)) {
    ++nbrEmptyEnd;
  }
  int nbCells = nbrPlayer + nbrEmptyBegin + nbrEmptyEnd;
  if (nbCells < 5 || nbrPlayer < 2) return 0;
  int res = (nbrPlayer - (nbrEmptyBegin + nbrEmptyEnd)) * nbCells;
  if (nbrPlayer == 4 && nbrEmptyBegin + nbrEmptyEnd >= 2) res = 12;
  if (nbrPlayer >= 2 && this->m_heuristicValues.find(res) != this->m_heuristicValues.end()) {
    for (int j = 1; j < nbCells - 1; ++j) {
      arbiter->getBoard()->setCellChecked(x + j * vector.x, y + j * vector.y, direction);
    }
    if (current == this->m_player) return -(this->m_heuristicValues.find(res)->second);
    return (this->m_heuristicValues.find(res))->second;
  }
  return 0;
}

long AI::heuristicFunction(Arbiter *arbiter) {
  long score = 0;

  if (!arbiter->getWinToCancel()) {
    return -INFINITY_MAX;
  }
  for (int j = 0; j < HEIGHT_BOARD; ++j) {
    for (int i = 0; i < WIDTH_BOARD; ++i) {
      for (int index = 0; index < this->m_stealHeuristic.size(); ++index) {
        score += (this->*m_heuristicDirectionCell)(arbiter, i, j, index);
      }
    }
  }
  return score;
}

long AI::negamax(Arbiter *arbiter, int depth, long alpha, long beta) {
  if (depth == 0 || !arbiter->getWinToCancel() || arbiter->isSamePlayer()) {
    return heuristicFunction(arbiter);
  }
  long bestScore = -INFINITY_MAX;
  std::map<int, int> cells = arbiter->getBoard()->getCellsType(CASE_EMPTY);
  for (std::map<int, int>::iterator it = cells.begin(); it != cells.end(); ++it) {
    Arbiter *newArbiter = new Arbiter(*arbiter);
    int stonesStolenBefore = newArbiter->getStonesStole(newArbiter->getCurrentPlayer());
    newArbiter->playAMove(it->first % WIDTH_BOARD, it->first / WIDTH_BOARD);
    int stonesStolenAfter = newArbiter->getStonesStole(OPPONENT_PLAYER(newArbiter->getCurrentPlayer()));
    long score = -negamax(newArbiter, depth - 1, -beta, -alpha);
    if (score < INFINITY_MAX && score > -INFINITY_MAX)
      score += (stonesStolenAfter - stonesStolenBefore != 0 ? this->m_stealHeuristic[stonesStolenAfter] * (newArbiter->getCurrentPlayer() == CASE_BLACK ? -1 : 1) : 0);
    delete newArbiter;
    if (score > bestScore) {
      bestScore = score;
      this->m_move = it->first;
    }
    alpha = MAX(alpha, score);
    if (alpha >= beta) {
      break;
    }
  }
  return bestScore;
}