//
// Created by Fabien Martinez on 21/10/15.
//

#include "CoreSecondRuleTests.h"

CoreSecondRuleTests::CoreSecondRuleTests() {
  this->m_arbiter = new Arbiter(false, true);
  this->m_testsPassed = 0;
  this->m_allTests = 0;
}

void CoreSecondRuleTests::assert_pass(std::string const &test, bool t1, bool t2) {
  if (t1 == t2) {
    std::cout << "\E[32m test " << test << " passed\E[0m" << std::endl;
    ++this->m_testsPassed;
  } else {
    std::cout << "\E[31m test " << test << " not passed\E[0m" << std::endl;
  }
  ++this->m_allTests;
}

void CoreSecondRuleTests::testPassed() const {
  std::cout << "\E[34m" << this->m_testsPassed << " tests passed / " << this->m_allTests << "\E[0m" << std::endl;
}

void CoreSecondRuleTests::runTests() {
  std::cout << "\E[34mRUN SECOND RULE TESTS\E[0m" << std::endl << "---------------------------------" << std::endl;;
  this->arroundTheWorld();
  this->testPassed();
  std::cout << "\E[34mEND SECOND RULE TESTS\E[0m" << std::endl << "---------------------------------" << std::endl;
}

void CoreSecondRuleTests::arroundTheWorld() {
  std::cout << "\E[34mAROUND THE WORLD TEST\E[0m" << std::endl << "====================" << std::endl;
  static t_point _move[8] = {
      {0, 1},
      {1, 0},
      {-1, 1},
      {1, 1},
      {0, -1},
      {-1, 0},
      {1, -1},
      {-1, -1},
  };
  int x;
  int y;

  x = 9;
  y = 9;
  std::cout << "\E[34mWITHOUT SPACE TESTS\E[0m" << std::endl << "____" << std::endl;
  for (int i = 0; i < 8; ++i) {
    std::cout << "TEST " << i << std::endl;
    for (int j = i + 1; j < 8; ++j) {
      if (i + 4 == j)
        continue;
      this->m_arbiter->toggleSecondRule();
      this->m_arbiter->getBoard()->setCellMap(x + _move[i].x, y + _move[i].y, 1);
      this->m_arbiter->getBoard()->setCellMap(x + 2 * _move[i].x, y + 2 * _move[i].y, 1);
      this->m_arbiter->getBoard()->setCellMap(x + _move[j].x, y + _move[j].y, 1);
      this->m_arbiter->getBoard()->setCellMap(x + 2 * _move[j].x, y + 2 * _move[j].y, 1);
      this->assert_pass(std::string(""), this->m_arbiter->isValidSecondRule(x, y), false);
      this->m_arbiter->resetGame();
    }
    std::cout << "___" << std::endl;
  }
  std::cout << "\E[34mWITH SPACE TESTS\E[0m" << std::endl << "____" << std::endl;
  for (int i = 0; i < 8; ++i) {
    std::cout << "TEST " << i << std::endl;
    for (int j = i + 1; j < 8; ++j) {
      if (i + 4 == j)
        continue;
      this->m_arbiter->toggleSecondRule();
      this->m_arbiter->getBoard()->setCellMap(x + _move[i].x, y + _move[i].y, 1);
      this->m_arbiter->getBoard()->setCellMap(x + 3 * _move[i].x, y + 3 * _move[i].y, 1);
      this->m_arbiter->getBoard()->setCellMap(x + _move[j].x, y + _move[j].y, 1);
      this->m_arbiter->getBoard()->setCellMap(x + 3 * _move[j].x, y + 3 * _move[j].y, 1);
      this->assert_pass(std::string(""), this->m_arbiter->isValidSecondRule(x, y), false);
      this->m_arbiter->resetGame();
    }
    std::cout << "___" << std::endl;
  }
  std::cout << "\E[34mEND AROUND THE WORLD TEST\E[0m" << std::endl << "====================" << std::endl;
}