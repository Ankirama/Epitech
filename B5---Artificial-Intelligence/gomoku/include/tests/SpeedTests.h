//
// Created by Fabien Martinez on 21/10/15.
//

#ifndef GOMOKU_SPEEDTESTS_H
#define GOMOKU_SPEEDTESTS_H

#include <ctime>
#include "Arbiter.h"
#include "UnitTests.h"

class SpeedTests : public UnitTests {
public:
  SpeedTests();
  virtual ~SpeedTests() {
    delete(this->m_arbiter);
  }

  virtual void runTests();

  virtual void testPassed() const;

private:
  void allRules();
  void firstRule();
  void secondRule();
  void noneRules();
  void assert_pass(std::string const &test, t_state_game t1, t_state_game t2);
private:
  Arbiter *m_arbiter;
  int m_testsPassed;
  int m_allTests;
};


#endif //GOMOKU_SPEEDTESTS_H
