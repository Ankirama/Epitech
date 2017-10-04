//
// Created by Fabien Martinez on 19/10/15.
//

#include <string>
#include "CoreFirstRuleTests.h"

CoreFirstRuleTests::CoreFirstRuleTests() {
  this->m_arbiter = new Arbiter(true, true);
  this->m_testsPassed = 0;
  this->m_allTests = 0;
}

void CoreFirstRuleTests::assert_pass(std::string const &test, bool t1, bool t2) {
  if (t1 == t2) {
    std::cout << "\E[32m test " << test << " passed\E[0m" << std::endl;
    ++this->m_testsPassed;
  } else {
    std::cout << "\E[31m test " << test << " not passed\E[0m" << std::endl;
  }
  ++this->m_allTests;
}

void CoreFirstRuleTests::testPassed() const {
  std::cout << "\E[34m" << this->m_testsPassed << " tests passed / " << this->m_allTests << "\E[0m" << std::endl;
}

void CoreFirstRuleTests::runTests() {
  std::cout << "\E[34mRUN FIRST RULE TESTS\E[0m" << std::endl << "---------------------------------" << std::endl;
  this->verticalTest();
  this->m_arbiter->resetGame();

  this->m_arbiter->toggleFirstRule();
  this->horizontalTest();
  this->m_arbiter->resetGame();

  this->m_arbiter->toggleFirstRule();
  this->diagoLeftTest();
  this->m_arbiter->resetGame();

  this->m_arbiter->toggleFirstRule();
  this->diagoRightTest();
  this->m_arbiter->resetGame();
  this->testPassed();
  std::cout << "\E[34mEND FIRST RULE TESTS\E[0m" << std::endl << "---------------------------------" << std::endl;
}

void CoreFirstRuleTests::verticalTest() {
  std::cout << "\E[34mVERTICAL TEST\E[0m" << std::endl << "====================" << std::endl;
  this->m_arbiter->getBoard()->setCellMap(8, 4, 1);
  this->m_arbiter->getBoard()->setCellMap(8, 5, 1);
  this->m_arbiter->getBoard()->setCellMap(8, 6, 1);
  this->m_arbiter->getBoard()->setCellMap(8, 7, 1);
  this->m_arbiter->getBoard()->setCellMap(8, 8, 1);

  // TRUE TESTS
  std::cout << "\E[34mTRUE TESTS\E[0m" << std::endl << "_______" << std::endl;
  // TEST 1 left
  this->m_arbiter->getBoard()->setCellMap(7, 4, 1);
  this->m_arbiter->getBoard()->setCellMap(6, 4, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 1 left"), this->m_arbiter->isValidFirstRule(8, 4), true);
  this->m_arbiter->getBoard()->setCellMap(7, 4, 0);
  this->m_arbiter->getBoard()->setCellMap(6, 4, 0);

  // TEST 2 right
  this->m_arbiter->getBoard()->setCellMap(9, 4, 1);
  this->m_arbiter->getBoard()->setCellMap(10, 4, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 2 right"), this->m_arbiter->isValidFirstRule(8, 4), true);
  this->m_arbiter->getBoard()->setCellMap(9, 4, 0);
  this->m_arbiter->getBoard()->setCellMap(10, 4, 0);

  // TEST 3 diago left left (diago left du cote gauche des 5 stones)
  this->m_arbiter->getBoard()->setCellMap(7, 3, 1);
  this->m_arbiter->getBoard()->setCellMap(6, 2, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 3 diago left left (diago left du cote gauche des 5 stones)"), this->m_arbiter->isValidFirstRule(8, 4), true);
  this->m_arbiter->getBoard()->setCellMap(7, 3, 0);
  this->m_arbiter->getBoard()->setCellMap(6, 2, 0);

  // TEST 4 diago left right
  this->m_arbiter->getBoard()->setCellMap(9, 5, 1);
  this->m_arbiter->getBoard()->setCellMap(10, 6, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 4 diago left right"), this->m_arbiter->isValidFirstRule(8, 4), true);
  this->m_arbiter->getBoard()->setCellMap(9, 5, 0);
  this->m_arbiter->getBoard()->setCellMap(10, 6, 0);

  // TEST 5 diago right left
  this->m_arbiter->getBoard()->setCellMap(7, 5, 1);
  this->m_arbiter->getBoard()->setCellMap(6, 6, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 5 diago right left"), this->m_arbiter->isValidFirstRule(8, 4), true);
  this->m_arbiter->getBoard()->setCellMap(7, 5, 0);
  this->m_arbiter->getBoard()->setCellMap(6, 6, 0);

  // TEST 6 diago right right
  this->m_arbiter->getBoard()->setCellMap(9, 3, 1);
  this->m_arbiter->getBoard()->setCellMap(10, 2, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 6 diago right right"), this->m_arbiter->isValidFirstRule(8, 4), true);
  this->m_arbiter->getBoard()->setCellMap(9, 3, 0);
  this->m_arbiter->getBoard()->setCellMap(10, 2, 0);

  // FALSE TESTS
  std::cout << "\E[34mFALSE TESTS\E[0m" << std::endl << "_______" << std::endl;
  // TEST 1 right with 2x same stones
  this->m_arbiter->getBoard()->setCellMap(9, 4, 1);
  this->m_arbiter->getBoard()->setCellMap(10, 4, 1);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 1 right with 2x same stones"), this->m_arbiter->isValidFirstRule(8, 4), false);
  this->m_arbiter->getBoard()->setCellMap(9, 4, 0);
  this->m_arbiter->getBoard()->setCellMap(10, 4, 0);

  // TEST 2 right / left (1x same stone)
  this->m_arbiter->getBoard()->setCellMap(9, 4, 1);
  this->m_arbiter->getBoard()->setCellMap(7, 4, 1);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 2 right / left (1x same stone)"), this->m_arbiter->isValidFirstRule(8, 4), false);
  this->m_arbiter->getBoard()->setCellMap(9, 4, 0);
  this->m_arbiter->getBoard()->setCellMap(7, 4, 0);

  // TEST 3
  this->m_arbiter->getBoard()->setCellMap(9, 4, 1);
  this->m_arbiter->getBoard()->setCellMap(10, 4, 2);
  this->m_arbiter->getBoard()->setCellMap(7, 4, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 3"), this->m_arbiter->isValidFirstRule(8, 4), false);
  this->m_arbiter->getBoard()->setCellMap(9, 4, 0);
  this->m_arbiter->getBoard()->setCellMap(10, 4, 0);
  this->m_arbiter->getBoard()->setCellMap(7, 4, 0);

  // TEST 4 right / left (1x same stone (ennemy))
  this->m_arbiter->getBoard()->setCellMap(9, 4, 2);
  this->m_arbiter->getBoard()->setCellMap(7, 4, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 4 right / left (1x same stone (ennemy))"), this->m_arbiter->isValidFirstRule(8, 4), false);
  this->m_arbiter->getBoard()->setCellMap(9, 4, 0);
  this->m_arbiter->getBoard()->setCellMap(7, 4, 0);


  std::cout << "\E[34mEND VERTICAL TEST\E[0m" << std::endl << "====================" << std::endl;
}

void CoreFirstRuleTests::horizontalTest() {
  std::cout << "\E[34mHORIZONTAL TEST\E[0m" << std::endl << "====================" << std::endl;
  this->m_arbiter->getBoard()->setCellMap(6, 6, 1);
  this->m_arbiter->getBoard()->setCellMap(7, 6, 1);
  this->m_arbiter->getBoard()->setCellMap(8, 6, 1);
  this->m_arbiter->getBoard()->setCellMap(9, 6, 1);
  this->m_arbiter->getBoard()->setCellMap(10, 6, 1);

  // TRUE TESTS
  std::cout << "\E[34mTRUE TESTS\E[0m" << std::endl << "_______" << std::endl;
  // TEST 1 up
  this->m_arbiter->getBoard()->setCellMap(6, 5, 1);
  this->m_arbiter->getBoard()->setCellMap(6, 4, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 1 up"), this->m_arbiter->isValidFirstRule(6, 6), true);
  this->m_arbiter->getBoard()->setCellMap(6, 5, 0);
  this->m_arbiter->getBoard()->setCellMap(6, 4, 0);

  // TEST 2 down
  this->m_arbiter->getBoard()->setCellMap(6, 7, 1);
  this->m_arbiter->getBoard()->setCellMap(6, 8, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 2 down"), this->m_arbiter->isValidFirstRule(6, 6), true);
  this->m_arbiter->getBoard()->setCellMap(6, 7, 0);
  this->m_arbiter->getBoard()->setCellMap(6, 8, 0);

  // TEST 3 diago right down (diago left en bas des 5 stones)
  this->m_arbiter->getBoard()->setCellMap(5, 7, 1);
  this->m_arbiter->getBoard()->setCellMap(4, 8, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 3 diago right down (diago right en bas des 5 stones)"), this->m_arbiter->isValidFirstRule(6, 6), true);
  this->m_arbiter->getBoard()->setCellMap(5, 7, 0);
  this->m_arbiter->getBoard()->setCellMap(4, 8, 0);

  // TEST 4 diago right up
  this->m_arbiter->getBoard()->setCellMap(7, 5, 1);
  this->m_arbiter->getBoard()->setCellMap(8, 4, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 4 diago right up"), this->m_arbiter->isValidFirstRule(6, 6), true);
  this->m_arbiter->getBoard()->setCellMap(7, 5, 0);
  this->m_arbiter->getBoard()->setCellMap(8, 4, 0);

  // TEST 5 diago left down
  this->m_arbiter->getBoard()->setCellMap(7, 7, 1);
  this->m_arbiter->getBoard()->setCellMap(8, 8, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 5 diago left down"), this->m_arbiter->isValidFirstRule(6, 6), true);
  this->m_arbiter->getBoard()->setCellMap(7, 7, 0);
  this->m_arbiter->getBoard()->setCellMap(8, 8, 0);

  // TEST 6 diago left up
  this->m_arbiter->getBoard()->setCellMap(7, 7, 1);
  this->m_arbiter->getBoard()->setCellMap(8, 8, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 6 diago left up"), this->m_arbiter->isValidFirstRule(6, 6), true);
  this->m_arbiter->getBoard()->setCellMap(7, 7, 0);
  this->m_arbiter->getBoard()->setCellMap(8, 8, 0);

  // FALSE TESTS
  std::cout << "\E[34mFALSE TESTS\E[0m" << std::endl << "_______" << std::endl;
  // TEST 1 up with 2x same stones
  this->m_arbiter->getBoard()->setCellMap(6, 5, 1);
  this->m_arbiter->getBoard()->setCellMap(6, 4, 1);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 1 up with 2x same stones"), this->m_arbiter->isValidFirstRule(6, 6), false);
  this->m_arbiter->getBoard()->setCellMap(6, 5, 0);
  this->m_arbiter->getBoard()->setCellMap(6, 4, 0);

  // TEST 2 up / down (1x same stone)
  this->m_arbiter->getBoard()->setCellMap(6, 5, 1);
  this->m_arbiter->getBoard()->setCellMap(6, 7, 1);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 2 up / down (1x same stone)"), this->m_arbiter->isValidFirstRule(6, 6), false);
  this->m_arbiter->getBoard()->setCellMap(6, 5, 0);
  this->m_arbiter->getBoard()->setCellMap(6, 7, 0);

  // TEST 3 2 up / 1 down
  this->m_arbiter->getBoard()->setCellMap(6, 5, 1);
  this->m_arbiter->getBoard()->setCellMap(6, 4, 2);
  this->m_arbiter->getBoard()->setCellMap(6, 7, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 3 2 up / 1 down"), this->m_arbiter->isValidFirstRule(6, 6), false);
  this->m_arbiter->getBoard()->setCellMap(6, 5, 0);
  this->m_arbiter->getBoard()->setCellMap(6, 4, 0);
  this->m_arbiter->getBoard()->setCellMap(6, 7, 0);

  // TEST 4 right / left (1x same stone (ennemy))
  this->m_arbiter->getBoard()->setCellMap(6, 5, 2);
  this->m_arbiter->getBoard()->setCellMap(6, 7, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 4 right / left (1x same stone (ennemy))"), this->m_arbiter->isValidFirstRule(6, 6), false);
  this->m_arbiter->getBoard()->setCellMap(6, 5, 0);
  this->m_arbiter->getBoard()->setCellMap(6, 7, 0);
  std::cout << "\E[34mEND HORIZONTAL TEST\E[0m" << std::endl << "====================" << std::endl;
}

void CoreFirstRuleTests::diagoLeftTest() {
  std::cout << "\E[34mDIAGOLEFT TEST\E[0m" << std::endl << "====================" << std::endl;
  this->m_arbiter->getBoard()->setCellMap(6, 4, 1);
  this->m_arbiter->getBoard()->setCellMap(7, 5, 1);
  this->m_arbiter->getBoard()->setCellMap(8, 6, 1);
  this->m_arbiter->getBoard()->setCellMap(9, 7, 1);
  this->m_arbiter->getBoard()->setCellMap(10, 8, 1);

  // TRUE TESTS
  std::cout << "\E[34mTRUE TESTS\E[0m" << std::endl << "_______" << std::endl;
  // TEST 1 left
  this->m_arbiter->getBoard()->setCellMap(5, 4, 1);
  this->m_arbiter->getBoard()->setCellMap(4, 4, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 1 left"), this->m_arbiter->isValidFirstRule(6, 4), true);
  this->m_arbiter->getBoard()->setCellMap(5, 4, 0);
  this->m_arbiter->getBoard()->setCellMap(4, 4, 0);

  // TEST 2 right
  this->m_arbiter->getBoard()->setCellMap(7, 4, 1);
  this->m_arbiter->getBoard()->setCellMap(8, 4, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 2 right"), this->m_arbiter->isValidFirstRule(6, 4), true);
  this->m_arbiter->getBoard()->setCellMap(7, 4, 0);
  this->m_arbiter->getBoard()->setCellMap(8, 4, 0);

  // TEST 3 diago up
  this->m_arbiter->getBoard()->setCellMap(6, 3, 1);
  this->m_arbiter->getBoard()->setCellMap(6, 2, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 3 up"), this->m_arbiter->isValidFirstRule(6, 4), true);
  this->m_arbiter->getBoard()->setCellMap(6, 3, 0);
  this->m_arbiter->getBoard()->setCellMap(6, 2, 0);

  // TEST 4 diago down
  this->m_arbiter->getBoard()->setCellMap(6, 5, 1);
  this->m_arbiter->getBoard()->setCellMap(6, 6, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 4 down"), this->m_arbiter->isValidFirstRule(6, 4), true);
  this->m_arbiter->getBoard()->setCellMap(6, 5, 0);
  this->m_arbiter->getBoard()->setCellMap(6, 6, 0);

  // TEST 5 diago right left
  this->m_arbiter->getBoard()->setCellMap(5, 5, 1);
  this->m_arbiter->getBoard()->setCellMap(4, 6, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 5 diago right left"), this->m_arbiter->isValidFirstRule(6, 4), true);
  this->m_arbiter->getBoard()->setCellMap(5, 5, 0);
  this->m_arbiter->getBoard()->setCellMap(4, 6, 0);

  // TEST 6 diago right right
  this->m_arbiter->getBoard()->setCellMap(7, 3, 1);
  this->m_arbiter->getBoard()->setCellMap(8, 2, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 6 diago right right"), this->m_arbiter->isValidFirstRule(6, 4), true);
  this->m_arbiter->getBoard()->setCellMap(7, 3, 0);
  this->m_arbiter->getBoard()->setCellMap(8, 2, 0);

  // FALSE TESTS
  std::cout << "\E[34mFALSE TESTS\E[0m" << std::endl << "_______" << std::endl;
  // TEST 1 right with 2x same stones
  this->m_arbiter->getBoard()->setCellMap(7, 4, 1);
  this->m_arbiter->getBoard()->setCellMap(8, 4, 1);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 1 right with 2x same stones"), this->m_arbiter->isValidFirstRule(6, 4), false);
  this->m_arbiter->getBoard()->setCellMap(7, 4, 0);
  this->m_arbiter->getBoard()->setCellMap(8, 4, 0);

  // TEST 2 right / left (1x same stone)
  this->m_arbiter->getBoard()->setCellMap(7, 4, 1);
  this->m_arbiter->getBoard()->setCellMap(5, 4, 1);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 2 right / left (1x same stone)"), this->m_arbiter->isValidFirstRule(6, 4), false);
  this->m_arbiter->getBoard()->setCellMap(7, 4, 0);
  this->m_arbiter->getBoard()->setCellMap(5, 4, 0);

  // TEST 3
  this->m_arbiter->getBoard()->setCellMap(7, 4, 1);
  this->m_arbiter->getBoard()->setCellMap(8, 4, 2);
  this->m_arbiter->getBoard()->setCellMap(5, 4, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 3 2x right / 1 left"), this->m_arbiter->isValidFirstRule(6, 4), false);
  this->m_arbiter->getBoard()->setCellMap(7, 4, 0);
  this->m_arbiter->getBoard()->setCellMap(8, 4, 0);
  this->m_arbiter->getBoard()->setCellMap(5, 4, 0);

  // TEST 4 right / left (1x same stone (ennemy))
  this->m_arbiter->getBoard()->setCellMap(7, 4, 2);
  this->m_arbiter->getBoard()->setCellMap(5, 4, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 4 right / left (1x same stone (ennemy))"), this->m_arbiter->isValidFirstRule(6, 4), false);
  this->m_arbiter->getBoard()->setCellMap(7, 4, 0);
  this->m_arbiter->getBoard()->setCellMap(5, 4, 0);
  std::cout << "\E[34mEND DIAGOLEFT TEST\E[0m" << std::endl << "====================" << std::endl;
}

void CoreFirstRuleTests::diagoRightTest() {
  std::cout << "\E[34mDIAGORIGHT TEST\E[0m" << std::endl << "====================" << std::endl;
  this->m_arbiter->getBoard()->setCellMap(10, 4, 1);
  this->m_arbiter->getBoard()->setCellMap(9, 5, 1);
  this->m_arbiter->getBoard()->setCellMap(8, 6, 1);
  this->m_arbiter->getBoard()->setCellMap(7, 7, 1);
  this->m_arbiter->getBoard()->setCellMap(6, 8, 1);

  // TRUE TESTS
  std::cout << "\E[34mTRUE TESTS\E[0m" << std::endl << "_______" << std::endl;
  // TEST 1 left
  this->m_arbiter->getBoard()->setCellMap(9, 4, 1);
  this->m_arbiter->getBoard()->setCellMap(8, 4, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 1 left"), this->m_arbiter->isValidFirstRule(10, 4), true);
  this->m_arbiter->getBoard()->setCellMap(9, 4, 0);
  this->m_arbiter->getBoard()->setCellMap(8, 4, 0);

  // TEST 2 right
  this->m_arbiter->getBoard()->setCellMap(11, 4, 1);
  this->m_arbiter->getBoard()->setCellMap(12, 4, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 2 right"), this->m_arbiter->isValidFirstRule(10, 4), true);
  this->m_arbiter->getBoard()->setCellMap(11, 4, 0);
  this->m_arbiter->getBoard()->setCellMap(12, 4, 0);

  // TEST 3 diago left left (diago left du cote gauche des 5 stones)
  this->m_arbiter->getBoard()->setCellMap(9, 3, 1);
  this->m_arbiter->getBoard()->setCellMap(8, 2, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 3 diago left left (diago left du cote gauche des 5 stones)"), this->m_arbiter->isValidFirstRule(10, 4), true);
  this->m_arbiter->getBoard()->setCellMap(9, 3, 0);
  this->m_arbiter->getBoard()->setCellMap(8, 2, 0);

  // TEST 4 diago left right
  this->m_arbiter->getBoard()->setCellMap(11, 5, 1);
  this->m_arbiter->getBoard()->setCellMap(12, 6, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 4 diago left right"), this->m_arbiter->isValidFirstRule(10, 4), true);
  this->m_arbiter->getBoard()->setCellMap(11, 5, 0);
  this->m_arbiter->getBoard()->setCellMap(12, 6, 0);

  // TEST 5 up
  this->m_arbiter->getBoard()->setCellMap(10, 3, 1);
  this->m_arbiter->getBoard()->setCellMap(10, 2, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 5 up"), this->m_arbiter->isValidFirstRule(10, 4), true);
  this->m_arbiter->getBoard()->setCellMap(10, 3, 0);
  this->m_arbiter->getBoard()->setCellMap(10, 2, 0);

  // TEST 6 down
  this->m_arbiter->getBoard()->setCellMap(10, 5, 1);
  this->m_arbiter->getBoard()->setCellMap(10, 6, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 6 down"), this->m_arbiter->isValidFirstRule(10, 4), true);
  this->m_arbiter->getBoard()->setCellMap(10, 5, 0);
  this->m_arbiter->getBoard()->setCellMap(10, 6, 0);

  // FALSE TESTS
  std::cout << "\E[34mFALSE TESTS\E[0m" << std::endl << "_______" << std::endl;
  // TEST 1 right with 2x same stones
  this->m_arbiter->getBoard()->setCellMap(11, 4, 1);
  this->m_arbiter->getBoard()->setCellMap(12, 4, 1);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 1 right with 2x same stones"), this->m_arbiter->isValidFirstRule(10, 4), false);
  this->m_arbiter->getBoard()->setCellMap(11, 4, 0);
  this->m_arbiter->getBoard()->setCellMap(12, 4, 0);

  // TEST 2 right / left (1x same stone)
  this->m_arbiter->getBoard()->setCellMap(9, 4, 1);
  this->m_arbiter->getBoard()->setCellMap(11, 4, 1);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 2 right / left (1x same stone)"), this->m_arbiter->isValidFirstRule(10, 4), false);
  this->m_arbiter->getBoard()->setCellMap(9, 4, 0);
  this->m_arbiter->getBoard()->setCellMap(11, 4, 0);

  // TEST 3
  this->m_arbiter->getBoard()->setCellMap(11, 4, 1);
  this->m_arbiter->getBoard()->setCellMap(12, 4, 2);
  this->m_arbiter->getBoard()->setCellMap(9, 4, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 3 2x right / 1 left"), this->m_arbiter->isValidFirstRule(10, 4), false);
  this->m_arbiter->getBoard()->setCellMap(11, 4, 0);
  this->m_arbiter->getBoard()->setCellMap(12, 4, 0);
  this->m_arbiter->getBoard()->setCellMap(9, 4, 0);

  // TEST 4 right / left (1x same stone (ennemy))
  this->m_arbiter->getBoard()->setCellMap(11, 4, 2);
  this->m_arbiter->getBoard()->setCellMap(9, 4, 2);
  this->m_arbiter->setWinToCancel(false);
  this->assert_pass(std::string("test 4 right / left (1x same stone (ennemy))"), this->m_arbiter->isValidFirstRule(10, 4), false);
  this->m_arbiter->getBoard()->setCellMap(11, 4, 0);
  this->m_arbiter->getBoard()->setCellMap(9, 4, 0);
  std::cout << "\E[34mEND DIAGORIGHT TEST\E[0m" << std::endl << "====================" << std::endl;
}