//
// Created by Fabien Martinez on 19/10/15.
//

#ifndef GOMOKU_COREFIRSTRULETESTS_H
#define GOMOKU_COREFIRSTRULETESTS_H

#include <iostream>
#include "Arbiter.h"
#include "UnitTests.h"

class CoreFirstRuleTests : public UnitTests{
public:
  CoreFirstRuleTests();
  virtual ~CoreFirstRuleTests() {
    delete(this->m_arbiter);
  }

  virtual void runTests();
  virtual void testPassed() const;
private:
  void verticalTest();
  void horizontalTest();
  void diagoLeftTest();
  void diagoRightTest();
  void assert_pass(std::string const &test, bool t1, bool t2);

private:
  Arbiter *m_arbiter;
  int m_testsPassed;
  int m_allTests;
};

#endif //GOMOKU_COREFIRSTRULETESTS_H
