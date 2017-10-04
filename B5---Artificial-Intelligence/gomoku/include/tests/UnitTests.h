//
// Created by Fabien Martinez on 19/10/15.
//

#ifndef GOMOKU_UNITTESTS_H
#define GOMOKU_UNITTESTS_H


class UnitTests {
public:
  virtual ~UnitTests() {}

  virtual void runTests() = 0;
  virtual void testPassed() const = 0;
};


#endif //GOMOKU_UNITTESTS_H
