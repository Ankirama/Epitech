//
// KoalaBot.cpp for mdr de rire in /home/user/rendu/piscine_cpp_d07a/ex01
//
// Made by 
// Login   
//
// Started on  Tue Jan 13 22:25:36 2015 
// Last update Wed Jan 14 00:51:05 2015 
//

#include <string>
#include <iostream>
#include "KoalaBot.h"

KoalaBot::KoalaBot(Arms arms) : _arms(arms), _serial("Bob-01"){}
KoalaBot::KoalaBot(Legs legs) : _legs(legs), _serial("Bob-01") {}
KoalaBot::KoalaBot(Head head) : _head(head), _serial("Bob-01") {}
KoalaBot::KoalaBot() : _serial("Bob-01") {}

void KoalaBot::setParts(const Arms &arms) {
  _arms = arms;
}

void KoalaBot::setParts(const Legs &legs) {
  _legs = legs;
}

void KoalaBot::setParts(const Head &head) {
  _head = head;
}

void KoalaBot::swapParts(Arms &arms) {
  arms = _arms;
}

void KoalaBot::swapParts(Legs &legs) {
  legs = _legs;
}

void KoalaBot::swapParts(Head &head) {
  head = _head;
}

void KoalaBot::informations() {
  std::cout << "[KoalaBot] " << _serial << std::endl;
  std::cout << "       ";
  _arms.informations();
  std::cout << "       ";
  _legs.informations();
  std::cout << "       ";
  _head.informations();
}

bool KoalaBot::status() {
  if (_legs.isFunctionnal() && _arms.isFunctionnal() && _head.isFunctionnal())
    return (true);
  return (false);
}
