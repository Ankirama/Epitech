//
// Exam.cpp for djqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwqdjqwpodpqwokdqwkdkwfqwo[fawpfpwq in /home/mar_b/rendu/piscine_cpp_d07m/ex05
//
// Made by Fabien Martinez
// Login   <mar_b@epitech.net>
//
// Started on  Tue Jan 13 17:50:48 2015 Fabien Martinez
// Last update Tue Jan 13 20:45:29 2015 Fabien Martinez
//

#include <iostream>
#include "Exam.hh"

bool Exam::cheat = false;

Exam::Exam(bool *cheat) {
  *cheat = false;
}

bool Exam::isCheating() {
  return (cheat);
}

Exam::~Exam(){}

void Exam::start(int coucou) {
  std::cout << "[The exam is starting]" << std::endl;
  std::cout << coucou << " Klingon vessels appeared out of nowhere." << std::endl;
  std::cout << "they are fully armed and shielded" << std::endl;
  if (Exam::cheat)
    std::cout << "What the... someone changed the parameters of the exam !" << std::endl;
  else
    std::cout << "This exam is hard... you lost again." << std::endl;
}
