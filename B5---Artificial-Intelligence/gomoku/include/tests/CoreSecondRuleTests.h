//
// Created by Fabien Martinez on 21/10/15.
//

#ifndef GOMOKU_CORESECONDRULETESTS_H
#define GOMOKU_CORESECONDRULETESTS_H

#include <iostream>
#include <string>
#include "Arbiter.h"
#include "UnitTests.h"

class CoreSecondRuleTests : public UnitTests {
public:
  CoreSecondRuleTests();
  virtual ~CoreSecondRuleTests() {
    delete(this->m_arbiter);
  }

  virtual void runTests();
  virtual void testPassed() const;
private:
  void assert_pass(std::string const &test, bool t1, bool t2);
  void arroundTheWorld();
private:
  Arbiter *m_arbiter;
  int m_testsPassed;
  int m_allTests;
};

#endif //GOMOKU_CORESECONDRULETESTS_H
