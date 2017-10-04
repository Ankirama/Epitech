//
// Created by Fabien Martinez on 19/10/15.
//

#include "Arbiter.h"

const t_point Arbiter::m_stones_move[] = {{0, 1}, {1, 0}, {-1, 1}, {1, 1}};

//region Constructor functions
///////////////////////////
/* CONSTRUCTOR FUNCTIONS */
///////////////////////////

Arbiter::Arbiter(bool firstRule, bool secondRule) : m_currentPlayer(CASE_WHITE), m_x_move(0), m_y_move(0) {
  this->m_board = new Map;
  this->m_winner = CASE_EMPTY;
  this->m_stones_stole[0] = 0;
  this->m_stones_stole[1] = 0;
  this->m_winToCancel = true;
  this->m_activateFirstRule = firstRule;
  this->m_activateSecondRule = secondRule;
  this->setMemberFunctionToPlay();
  this->m_board->initMap();
  this->m_samePlayer = false;
}

Arbiter::Arbiter(Arbiter &copy) {
  this->m_board = new Map(copy.getBoard()->getMap());
  this->m_winner = copy.m_winner;
  for (int i = 0; i < 2; ++i) this->m_stones_stole[i] = copy.m_stones_stole[i];
  this->m_winToCancel = copy.m_winToCancel;
  this->m_activateFirstRule = copy.m_activateFirstRule;
  this->m_activateSecondRule = copy.m_activateSecondRule;
  this->m_playYourTurn = copy.m_playYourTurn;
  this->m_currentPlayer = copy.m_currentPlayer;
}

Arbiter::~Arbiter() {
  delete this->m_board;
}

//endregion

//region Public functions
///////////////////////
/* PUBLIC FUNCTIONS  */
///////////////////////

//region Getters / setters
//---------------------//
//  GETTERS / SETTERS  //
//---------------------//

void Arbiter::setCurrentPlayer(int player) {
  this->m_currentPlayer = player;
}

int Arbiter::getCurrentPlayer() const {
  return this->m_currentPlayer;
}

void Arbiter::setMemberFunctionToPlay() {
  if (this->isFirstRuleEnabled()) {
    if (this->m_activateSecondRule) {
      this->m_playYourTurn = &Arbiter::playAMoveAllEnabled;
    } else {
      this->m_playYourTurn = &Arbiter::playAMoveFirstEnabled;
    }
  } else if (this->m_activateSecondRule){
    this->m_playYourTurn = &Arbiter::playAMoveSecondEnabled;
  } else {
    this->m_playYourTurn = &Arbiter::playAMoveNoneEnabled;
  }
}

void Arbiter::toggleFirstRule() {
  this->m_activateFirstRule = !this->m_activateFirstRule;
  this->setWinToCancel(true);
  this->setMemberFunctionToPlay();
}

void Arbiter::toggleSecondRule() {
  this->m_activateSecondRule = !this->m_activateSecondRule;
  this->setWinToCancel(true);
  this->setMemberFunctionToPlay();
}

void Arbiter::setFirstRule(bool rule) {
  this->m_activateFirstRule = rule;
  this->setWinToCancel(true);
  this->setMemberFunctionToPlay();
}

void Arbiter::setSecondRule(bool rule) {
  this->m_activateSecondRule = rule;
  this->setWinToCancel(true);
  this->setMemberFunctionToPlay();
}

void Arbiter::setWinToCancel(bool winToCancel) {
  this->m_winToCancel = winToCancel;
}

bool Arbiter::getWinToCancel() {
  return this->m_winToCancel;
}

bool Arbiter::isFirstRuleEnabled() const {
  return this->m_activateFirstRule;
}

bool Arbiter::isSecondRuleEnabled() const {
  return this->m_activateSecondRule;
}

Map *Arbiter::getBoard(){
  return this->m_board;
}

int Arbiter::getStonesStole(int player) const {
  return player == CASE_BLACK || player == CASE_WHITE ? this->m_stones_stole[player - 1] : -1;
}

//-------------------------//
//  END GETTERS / SETTERS  //
//-------------------------//
//endregion

bool Arbiter::isValidMove(int x, int y) const {
  return this->m_board->isCellEmpty(x, y);
}

void Arbiter::addStone(int x, int y, int player) {
  this->m_currentPlayer = player;
  this->m_board->setCellPlayer(x, y, this->m_currentPlayer);
  this->m_board->addCellToUpdate(x, y, this->m_currentPlayer);
}

void Arbiter::addStone(int x, int y) {
  this->m_board->setCellPlayer(x, y, this->m_currentPlayer);
  this->m_board->addCellToUpdate(x, y, this->m_currentPlayer);
}

t_state_game Arbiter::playAMove(int x, int y) {
  return ((this->*m_playYourTurn)(x, y));
}

void Arbiter::resetGame() {
  this->m_currentPlayer = CASE_WHITE;
  this->m_x_move = 0;
  this->m_y_move = 0;
  this->m_stones_stole[0] = 0;
  this->m_stones_stole[1] = 0;
  this->m_winToCancel = true;
  this->m_winner = CASE_EMPTY;
  this->m_board->initMap();
  this->m_samePlayer = false;
}

bool Arbiter::partCheckAroundFirst(int x, int y, t_point *direction, int orientation, bool isFirst) {
  int i;

  if (!this->m_winToCancel) return true;
  if (!isFirst && this->checkEatDirection(x, y, direction)) {
    if (this->m_stones_stole[this->m_board->getCellPlayer(x, y) - 1] >= 10) {
      this->m_winner = this->m_board->getCellPlayer(x, y);
      this->m_winToCancel = false;
      return true;
    } else {
      i = -1;
      while (++i < 4) {
        this->checkAroundStoneFirst(x + i * direction->x, y + i * direction->y, true); //we must check every stone updated
      }

    }
  }
  return (this->isCatchableDirection(x, y, direction, orientation));
}

bool Arbiter::checkAroundStoneFirst(int x, int y, bool isFirst) {
  int i;
  t_point direction;

  i = -1;
  if (!this->m_winToCancel) return true;

  while (++i < 4 && this->m_winToCancel) {
    direction = this->m_stones_move[i];
    if (this->partCheckAroundFirst(x, y, &direction, i, isFirst)) {
      if (this->m_winToCancel) {
        this->m_winner = this->m_board->getCellPlayer(x, y);
        this->m_winToCancel = false;
      }
      return true;
    }

    direction.x = this->m_stones_move[i].x * -1;
    direction.y = this->m_stones_move[i].y * -1;
    if (this->partCheckAroundFirst(x, y, &direction, i, isFirst)) {
      if (this->m_winToCancel) {
        this->m_winner = this->m_board->getCellPlayer(x, y);
        this->m_winToCancel = false;
      }
      return true;
    }
  }
  if (!this->m_winToCancel) {
    return true;
  }
  if (this->isWinnerHere(x, y)) {
    this->m_winner = this->m_board->getCellPlayer(x, y);
    this->m_winToCancel = false;
    return true;
  }
  return false;
}

bool Arbiter::isValidFirstRule(int x, int y) {
  if (this->checkAroundStoneFirst(x, y, false) || !this->m_winToCancel) {
    return true;
  } else {
    return false;
  }
}

bool Arbiter::isValidSecondRule(int x, int y) {
  t_point reverse;
  int nbTriple = 0;

  for (int i = 0; i < 4; ++i) {
    reverse.x = this->m_stones_move[i].x * -1;
    reverse.y = this->m_stones_move[i].y * -1;
    if (this->isTripleHere(x, y, &(this->m_stones_move[i])))
      ++nbTriple;
    if (this->isTripleHere(x, y, &reverse))
      ++nbTriple;
  }
  return (nbTriple != 2);
}

bool Arbiter::eatStones(int x, int y) {
  int i;
  t_point direction;
  t_point reverse;
  bool updated;
  int current;

  i = -1;
  updated = false;
  current = this->m_board->getCellPlayer(x, y);
  while (++i < 4) {
    direction = this->m_stones_move[i];
    reverse.x = this->m_stones_move[i].x * -1;
    reverse.y = this->m_stones_move[i].y * -1;
    if (this->checkEatDirection(x, y, &direction)) updated = true;
    if (this->checkEatDirection(x, y, &reverse)) updated = true;
  }
  if (updated && this->m_stones_stole[current - 1] >= 10) {
    this->m_winToCancel = false;
    this->m_winner = current;
    return true;
  } else {
    return false;
  }
}

////////////////////////////
/*  END PUBLIC FUNCTIONS  */
////////////////////////////
//endregion

//region Private functions
////////////////////////
/* PRIVATE FUNCTIONS  */
////////////////////////

bool Arbiter::isCatchableDirection(int x, int y, t_point *direction, int orientation) {
  int current;
  bool empty;
  int enemy;

  if (this->m_board->getCellPlayer(x, y) == CASE_EMPTY) {
    current = this->m_board->getCellPlayer(x + direction->x, y + direction->y);
    enemy = OPPONENT_PLAYER(current);
    empty = true;
  } else {
    enemy = CASE_EMPTY;
    current = OPPONENT_PLAYER(this->m_board->getCellMap(x, y));
    empty = false;
  }
  if (this->m_board->isCellType(x + direction->x, y + direction->y, current) &&
      this->m_board->isCellType(x + direction->x * 2, y + direction->y * 2, current) &&
      this->m_board->isCellType(x + direction->x * 3, y + direction->y * 3, enemy)) {
    this->m_board->setCellCatchable(x + direction->x, y + direction->y, orientation);
    this->m_board->setCellCatchable(x + 2 * direction->x, y + 2 * direction->y, orientation);
    return false;
  }
  if (empty && this->m_board->getCellPlayer(x + direction->x, y + direction->y) == this->m_board->getCellPlayer(x + direction->x * 2, y + direction->y * 2)) {
    this->m_board->resetCatchableCase(x + direction->x, y + direction->y, orientation);
    this->m_board->resetCatchableCase(x + 2 * direction->x, y + 2 * direction->y, orientation);
    if (this->m_activateFirstRule) return this->isWinnerHere(x + direction->x, y + direction->y) || this->isWinnerHere(x + 2 * direction->x, y + 2 * direction->y);
    else return false;
  } else if (empty && this->m_board->isCellType(x + direction->x, y + direction->y, OPPONENT_PLAYER(this->m_currentPlayer))) {
    this->m_board->resetCatchableCase(x + direction->x, y + direction->y, orientation);
    if (this->m_activateFirstRule) return this->isWinnerHere(x + direction->x, y + direction->y);
    else return false;
  }
  current = this->m_board->getCellPlayer(x, y);
  enemy = OPPONENT_PLAYER(current);
  if (current != CASE_EMPTY && this->m_board->isCellType(x + direction->x, y + direction->y, current)) {
    if (((this->m_board->isCellType(x + 2 * direction->x, y + 2 * direction->y, enemy) &&
          this->m_board->isCellType(x + direction->x * -1, y + direction->y * -1, CASE_EMPTY)) ||
         (this->m_board->isCellType(x + 2 * direction->x, y + 2 * direction->y, CASE_EMPTY) &&
          this->m_board->isCellType(x + direction->x * -1, y + direction->y * -1, enemy)))) {
      this->m_board->setCellCatchable(x, y, orientation);
      this->m_board->setCellCatchable(x + direction->x, y + direction->y, orientation);
      return false;
    } else {
      this->m_board->resetCatchableCase(x, y, orientation);
      this->m_board->resetCatchableCase(x + direction->x, y + direction->y, orientation);
      this->m_board->resetCatchableCase(x + direction->x * 2, y + direction->y * 2, orientation);
      // check if any winner
      if (this->m_activateFirstRule) return this->isWinnerHere(x, y) || this->isWinnerHere(x + direction->x, y + direction->y) || this->isWinnerHere(x + direction->x * 2, y + direction->y * 2);
      else return false;
    }
  } else {
    return false;
  }
}

bool Arbiter::checkEatDirection(int x, int y, t_point *direction) {
  int current;
  int enemy;

  current = this->m_board->getCellMap(x, y);
  enemy = OPPONENT_PLAYER(current);
  if (this->m_board->isCellType(x + direction->x, y + direction->y, enemy) &&
      this->m_board->isCellType(x + direction->x * 2, y + direction->y * 2, enemy) &&
      this->m_board->isCellType(x + direction->x * 3, y + direction->y * 3, current)) {
    this->m_board->setCellMap(x + direction->x, y + direction->y, CASE_EMPTY);
    this->m_board->addCellToUpdate(x + direction->x, y + direction->y, CASE_EMPTY);
    this->m_board->setCellMap(x + direction->x * 2, y + direction->y * 2, CASE_EMPTY);
    this->m_board->addCellToUpdate(x + direction->x * 2, y + direction->y * 2, CASE_EMPTY);
    this->m_stones_stole[current -1] += 2;
    return true;
  } else {
    return false;
  }
}

int Arbiter::tripleStones(int x, int y, t_point *direction) {
  t_point last_empty[2];
  int     nb_stones;
  int     tmp_stone;
  int     empty;
  int     i;

  nb_stones = 1;
  last_empty[1].x = -1;
  last_empty[1].y = -1;
  i = 0;
  empty = 0;
  while ((++i < 5 && nb_stones <= 3) || empty > 1) {
    tmp_stone = this->m_board->getCellMap(x + i * direction->x, y + i * direction->y);
    if (!this->m_board->getMapError()) {
      if (tmp_stone == this->m_currentPlayer) {
        ++nb_stones;
        empty = 0;
      } else if (tmp_stone == CASE_EMPTY && empty == 0) {
        last_empty[1].x = x + i * direction->x;
        last_empty[1].y = y + i * direction->y;
        ++empty;
      } else {
        empty = 2;
      }
    }
  }
  return empty;
}


bool Arbiter::isTripleHere(int x, int y, const t_point *direction) {
  int i = 1;
  int maxMove = 2;
  int validX = 0;
  bool empty = false;

  if (this->isSpecialTripleCase(x, y, direction))
    return true;
  if (this->m_board->isCellType(x - 1 * direction->x, y - 1 * direction->y, CASE_EMPTY)) {
    while (maxMove != 0) {
      if (this->m_board->isCellType(x + i * direction->x , y + i * direction->y, this->m_currentPlayer))
        ++validX;
      else if (!empty && this->m_board->isCellType(x + i * direction->x, y + i * direction->y, CASE_EMPTY)) {
        empty = true;
        ++maxMove;
      }
      else
        return false;
      --maxMove;
      ++i;
    }
    if (validX == 2 && this->m_board->isCellType(x + i * direction->x, y + i * direction->y, CASE_EMPTY))
      return true;
  }
  return false;
}

bool Arbiter::isSpecialTripleCase(int x, int y, const t_point *direction) {
  return this->m_board->isCellType(x - 2 * direction->x, y - 2 * direction->y, CASE_EMPTY)
    && this->m_board->isCellType(x - 1 * direction->x, y - 1 * direction->y, this->m_currentPlayer)
    && this->m_board->isCellType(x * direction->x, y * direction->y, CASE_EMPTY)
    && this->m_board->isCellType(x + 1 * direction->x, y + 1 * direction->y, this->m_currentPlayer)
    && this->m_board->isCellType(x + 2* direction->x, y + 2 * direction->y, CASE_EMPTY);
}

int Arbiter::maxStonesFirstRules(int x, int y, t_point *direction, int directionIndex, int current) {
  if (this->m_board->isCellType(x, y, current) && !this->m_board->isCellCatchable(x, y))
    return 1  + this->maxStonesFirstRules(x + direction->x, y + direction->y, direction, directionIndex, current);
  else
    return 0;
}

int Arbiter::maxStones(int x, int y, int x_move, int y_move) {
  if (this->m_board->isCellType(x, y, this->m_currentPlayer)) {
    return 1 + this->maxStones(x + x_move, y + y_move, x_move, y_move);
  } else {
    return 0;
  }
}

bool Arbiter::checkSide(int x, int y, int type) const{
  int ennemy;
  int currX;
  int currY;
  int revCurrX;
  int revCurrY;

  ennemy = OPPONENT_PLAYER(this->m_currentPlayer);
  for (int i = 0; i < 4; ++i) {
    if (i == type)
      continue;
    currX = this->m_stones_move[i].x;
    currY = this->m_stones_move[i].y;
    revCurrX = currX * -1;
    revCurrY = currY * -1;
    if (this->m_board->getCellMap(x + currX, y + currY) == this->m_currentPlayer &&
        this->m_board->getMapError() == ERR_NO_ERROR &&
       this->m_board->getCellMap(x + 2 * currX, y + 2 * currY) == ennemy &&
       this->m_board->getMapError() == ERR_NO_ERROR) {
      return (this->m_board->getCellMap(x + revCurrX, y + revCurrY) == CASE_EMPTY &&
              this->m_board->getMapError() == ERR_NO_ERROR);
    } else if (this->m_board->getCellMap(x + revCurrX, y + revCurrY) == this->m_currentPlayer &&
               this->m_board->getMapError() == ERR_NO_ERROR &&
               this->m_board->getCellMap(x + 2 * revCurrX, y + 2 * revCurrY) == ennemy &&
               this->m_board->getMapError() == ERR_NO_ERROR) {
      return (this->m_board->getCellMap(x + currX, y + currY) == CASE_EMPTY &&
              this->m_board->getMapError() == ERR_NO_ERROR);
    }

  }
  return false;
}

int Arbiter::countStoneDirection(int x, int y, const t_point *move, int type) {
  if (GET_PLAYER(this->m_board->getCellMap(x, y)) == this->m_currentPlayer &&
      this->m_board->getMapError() == ERR_NO_ERROR) {
    this->m_winToCancel = this->m_winToCancel ? true : this->checkSide(x, y, type); //need to change it I think
    return 1 + this->countStoneDirection(x + move->x, y + move->y, move, type);
  } else {
    return 0;
  }
}

bool Arbiter::isWinnerHere(int x, int y) {
  int maxStones;
  t_point direction;
  t_point reverseDirection;

  if (this->m_board->getCellPlayer(x, y) == CASE_EMPTY) return false;
  if (!this->isFirstRuleEnabled()) {
    for (int i = 0; i < 4; ++i) {
      maxStones = this->maxStones(x, y, this->m_stones_move[i].x, this->m_stones_move[i].y) +
                  this->maxStones(x + this->m_stones_move[i].x * -1, y + this->m_stones_move[i].y * -1,
                                  this->m_stones_move[i].x * -1, this->m_stones_move[i].y * -1);
      if (maxStones >= 5) {
        this->m_winToCancel = false;
        this->m_winner = this->m_board->getCellPlayer(x, y);
        return true;
      }
    }
  } else {
    for (int i = 0; i < 4; ++i) {
      direction.x = this->m_stones_move[i].x;
      direction.y = this->m_stones_move[i].y;
      reverseDirection.x = this->m_stones_move[i].x * -1;
      reverseDirection.y = this->m_stones_move[i].y * -1;
      if (this->m_board->getCellPlayer(x, y) == CASE_EMPTY) return false;
      maxStones = this->maxStonesFirstRules(x, y, &direction, i, this->m_board->getCellPlayer(x, y)) +
                  this->maxStonesFirstRules(x + reverseDirection.x, y + reverseDirection.y, &reverseDirection, i, this->m_board->getCellPlayer(x, y));
      if (maxStones >= 5) {
        this->m_winToCancel = false;
        this->m_winner = this->m_board->getCellPlayer(x, y);
        return true;
      }
    }
  }
  return false;
}

bool Arbiter::isSamePlayer() const { return this->m_samePlayer; }

t_state_game Arbiter::playAMoveAllEnabled(int x, int y) {
  this->m_samePlayer = false;
  if (this->isValidMove(x, y)) {
    // call second rule
    if (this->isValidSecondRule(x, y)) {
      this->addStone(x, y);
      if (this->isValidFirstRule(x, y)) return ((t_state_game) this->m_winner);
      else {
        this->m_currentPlayer = OPPONENT_PLAYER(this->m_currentPlayer);
      }
    } else this->m_samePlayer = true;
  } else this->m_samePlayer = true;
  return STATE_PLAYING;
}

t_state_game Arbiter::playAMoveFirstEnabled(int x, int y) {
  this->m_samePlayer = false;
  if (this->isValidMove(x, y)) {
    this->addStone(x, y);
    if (this->isValidFirstRule(x, y) || !this->m_winToCancel) return ((t_state_game) this->m_winner);
    else this->m_currentPlayer = OPPONENT_PLAYER(this->m_currentPlayer);
  } else this->m_samePlayer = true;
  return STATE_PLAYING;
}

t_state_game Arbiter::playAMoveSecondEnabled(int x, int y) {
  //Changer cette fonction pour appeler la seconde regle
  this->m_samePlayer = false;
  if (this->isValidMove(x, y)) {
    if (this->isValidSecondRule(x, y)) {
      this->addStone(x, y);
      if (this->isValidFirstRule(x, y)) return ((t_state_game) this->m_winner);
      else {
        this->m_currentPlayer = OPPONENT_PLAYER(this->m_currentPlayer);
      }
    } else this->m_samePlayer = true;
  } else this->m_samePlayer = true;
  return STATE_PLAYING;
}

t_state_game Arbiter::playAMoveNoneEnabled(int x, int y) {
  this->m_samePlayer = false;
  if (this->isValidMove(x, y)) {
    this->addStone(x, y);
    if (this->isValidFirstRule(x, y)) return ((t_state_game) this->m_winner);
    else {
      this->m_currentPlayer = OPPONENT_PLAYER(this->m_currentPlayer);
    }
  } else this->m_samePlayer = true;
  return STATE_PLAYING;
}

///////////////////////////
/* END PRIVATE FUNCTIONS */
///////////////////////////
//endregion
