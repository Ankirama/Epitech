//
// Created by Fabien Martinez on 20/10/15.
//

#include "CoreWinnerTests.h"
#include <string>

CoreWinnerTests::CoreWinnerTests() {
  this->m_arbiter = new Arbiter(true, true);
  this->m_testsPassed = 0;
  this->m_allTests = 0;
}

void CoreWinnerTests::assert_pass(std::string const &test, t_state_game t1, t_state_game t2) {
  if (t1 == t2) {
    std::cout << "\E[32m test " << test << " passed\E[0m" << std::endl;
    ++this->m_testsPassed;
  } else {
    std::cout << "\E[31m test " << test << " not passed\E[0m" << std::endl;
  }
  ++this->m_allTests;
}

void CoreWinnerTests::testPassed() const {
  std::cout << "\E[34m" << this->m_testsPassed << " tests passed / " << this->m_allTests << "\E[0m" << std::endl;
}

void CoreWinnerTests::runTests() {
  std::cout << "\E[34mRUN WINNER TESTS\E[0m" << std::endl << "---------------------------------" << std::endl;
  this->winnerTests();
  this->m_arbiter->resetGame();
  this->m_arbiter->toggleFirstRule();
  this->m_arbiter->toggleSecondRule();
  this->normalTests();
  this->testPassed();
  std::cout << "\E[34mEND WINNER TESTS\E[0m" << std::endl << "---------------------------------" << std::endl;
}

void CoreWinnerTests::winnerTests() {
  std::cout << "\E[34mWINNER TESTS\E[0m" << std::endl << "====================" << std::endl;

  std::cout << "\E[34mWINNER 1 TESTS\E[0m" << std::endl << "____" << std::endl;
  //TEST 1 stones HORIZONTAL
  this->m_arbiter->toggleFirstRule();
  this->m_arbiter->toggleSecondRule();
  this->m_arbiter->getBoard()->setCellMap(6, 6, 1);
  this->m_arbiter->getBoard()->setCellMap(7, 6, 1);
  this->m_arbiter->getBoard()->setCellMap(8, 6, 1);
  this->m_arbiter->getBoard()->setCellMap(9, 6, 1);
  this->assert_pass(std::string("test horizontal"), this->m_arbiter->playAMove(10, 6), STATE_WINNER_1);
  this->m_arbiter->resetGame();

  //TEST 2 stones VERTICAL
  this->m_arbiter->toggleFirstRule();
  this->m_arbiter->toggleSecondRule();
  this->m_arbiter->getBoard()->setCellMap(8, 4, 1);
  this->m_arbiter->getBoard()->setCellMap(8, 5, 1);
  this->m_arbiter->getBoard()->setCellMap(8, 6, 1);
  this->m_arbiter->getBoard()->setCellMap(8, 7, 1);
  this->assert_pass(std::string("test vertical"), this->m_arbiter->playAMove(8, 8), STATE_WINNER_1);
  this->m_arbiter->resetGame();

  //TEST 3 stones DIAGO LEFT
  this->m_arbiter->toggleFirstRule();
  this->m_arbiter->toggleSecondRule();
  this->m_arbiter->getBoard()->setCellMap(6, 4, 1);
  this->m_arbiter->getBoard()->setCellMap(7, 5, 1);
  this->m_arbiter->getBoard()->setCellMap(8, 6, 1);
  this->m_arbiter->getBoard()->setCellMap(9, 7, 1);
  this->assert_pass(std::string("test diago left"), this->m_arbiter->playAMove(10, 8), STATE_WINNER_1);
  this->m_arbiter->resetGame();

  //TEST 4 stones DIAGO RIGHT
  this->m_arbiter->toggleFirstRule();
  this->m_arbiter->toggleSecondRule();
  this->m_arbiter->getBoard()->setCellMap(10, 4, 1);
  this->m_arbiter->getBoard()->setCellMap(9, 5, 1);
  this->m_arbiter->getBoard()->setCellMap(8, 6, 1);
  this->m_arbiter->getBoard()->setCellMap(7, 7, 1);
  this->assert_pass(std::string("test diago right"), this->m_arbiter->playAMove(6, 8), STATE_WINNER_1);
  this->m_arbiter->resetGame();

  std::cout << "\E[34mWINNER 2 TESTS\E[0m" << std::endl << "____" << std::endl;

  //TEST 1 stones HORIZONTAL
  this->m_arbiter->toggleFirstRule();
  this->m_arbiter->toggleSecondRule();
  this->m_arbiter->setCurrentPlayer(2);
  this->m_arbiter->getBoard()->setCellMap(6, 6, 2);
  this->m_arbiter->getBoard()->setCellMap(7, 6, 2);
  this->m_arbiter->getBoard()->setCellMap(8, 6, 2);
  this->m_arbiter->getBoard()->setCellMap(9, 6, 2);
  this->assert_pass(std::string("test horizontal"), this->m_arbiter->playAMove(10, 6), STATE_WINNER_2);
  this->m_arbiter->resetGame();

  //TEST 2 stones VERTICAL
  this->m_arbiter->toggleFirstRule();
  this->m_arbiter->toggleSecondRule();
  this->m_arbiter->setCurrentPlayer(2);
  this->m_arbiter->getBoard()->setCellMap(8, 4, 2);
  this->m_arbiter->getBoard()->setCellMap(8, 5, 2);
  this->m_arbiter->getBoard()->setCellMap(8, 6, 2);
  this->m_arbiter->getBoard()->setCellMap(8, 7, 2);
  this->assert_pass(std::string("test vertical"), this->m_arbiter->playAMove(8, 8), STATE_WINNER_2);
  this->m_arbiter->resetGame();

  //TEST 3 stones DIAGO LEFT
  this->m_arbiter->toggleFirstRule();
  this->m_arbiter->toggleSecondRule();
  this->m_arbiter->setCurrentPlayer(2);
  this->m_arbiter->getBoard()->setCellMap(6, 4, 2);
  this->m_arbiter->getBoard()->setCellMap(7, 5, 2);
  this->m_arbiter->getBoard()->setCellMap(8, 6, 2);
  this->m_arbiter->getBoard()->setCellMap(9, 7, 2);
  this->assert_pass(std::string("test diago left"), this->m_arbiter->playAMove(10, 8), STATE_WINNER_2);
  this->m_arbiter->resetGame();

  //TEST 4 stones DIAGO RIGHT
  this->m_arbiter->toggleFirstRule();
  this->m_arbiter->toggleSecondRule();
  this->m_arbiter->setCurrentPlayer(2);
  this->m_arbiter->getBoard()->setCellMap(10, 4, 2);
  this->m_arbiter->getBoard()->setCellMap(9, 5, 2);
  this->m_arbiter->getBoard()->setCellMap(8, 6, 2);
  this->m_arbiter->getBoard()->setCellMap(7, 7, 2);
  this->assert_pass(std::string("test diago right"), this->m_arbiter->playAMove(6, 8), STATE_WINNER_2);
  this->m_arbiter->resetGame();

  // TEST EAT STONES WINNER
  this->m_arbiter->toggleFirstRule();
  this->m_arbiter->toggleSecondRule();

  std::cout << "\E[34mEND WINNER TESTS\E[0m" << std::endl << "====================" << std::endl;
}

void CoreWinnerTests::normalTests() {
  std::cout << "\E[34mNORMAL TESTS\E[0m" << std::endl << "====================" << std::endl;
  std::cout << "\E[34mNORMAL WINNER TESTS\E[0m" << std::endl << "====================" << std::endl;
}