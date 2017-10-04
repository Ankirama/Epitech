//
// Created by Fabien Martinez on 21/10/15.
//

#include "SpeedTests.h"
#include <string>
SpeedTests::SpeedTests() {
  this->m_arbiter = new Arbiter(true, true);
  this->m_testsPassed = 0;
  this->m_allTests = 0;
}

void SpeedTests::assert_pass(std::string const &test, t_state_game t1, t_state_game t2) {
  if (t1 == t2) {
    std::cout << "\E[32m test " << test << " passed\E[0m" << std::endl;
    ++this->m_testsPassed;
  } else {
    std::cout << "\E[31m test " << test << " not passed\E[0m" << std::endl;
  }
  ++this->m_allTests;
}

void SpeedTests::testPassed() const {
  std::cout << "\E[34m" << this->m_testsPassed << " tests passed / " << this->m_allTests << "\E[0m" << std::endl;
}

void SpeedTests::runTests() {
  std::cout << "\E[34mRUN WINNER TESTS\E[0m" << std::endl << "---------------------------------" << std::endl;
  this->allRules();
  this->firstRule();
  this->secondRule();
  this->noneRules();
  this->testPassed();
  std::cout << "\E[34mEND WINNER TESTS\E[0m" << std::endl << "---------------------------------" << std::endl;
}

void SpeedTests::allRules() {
  std::clock_t start;
  int i = 0;
  int j = 0;
  start = std::clock();
  for (i = 0; i < 19; ++i) {
    for (j = 0; j < 19; ++j) {
      if (this->m_arbiter->playAMove(i, j) != STATE_PLAYING) {
        std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
        std::cout << "i: " << i << " j: " << j << std::endl;
        return;
      }
    }
  }
}

void SpeedTests::firstRule() {

}

void SpeedTests::secondRule() {

}

void SpeedTests::noneRules() {

}
