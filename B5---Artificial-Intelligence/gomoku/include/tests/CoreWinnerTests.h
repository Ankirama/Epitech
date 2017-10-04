//
// Created by Fabien Martinez on 20/10/15.
//

#ifndef GOMOKU_COREWINNERTESTS_H
#define GOMOKU_COREWINNERTESTS_H

#include "UnitTests.h"
#include "Arbiter.h"

class CoreWinnerTests: public UnitTests {
public:
  CoreWinnerTests();
  virtual ~CoreWinnerTests() {
    delete(this->m_arbiter);
  }

  virtual void runTests();

  virtual void testPassed() const;

private:
  void winnerTests();
  void normalTests();
  void assert_pass(std::string const &test, t_state_game t1, t_state_game t2);
private:
  Arbiter *m_arbiter;
  int m_testsPassed;
  int m_allTests;
};


#endif //GOMOKU_COREWINNERTESTS_H
