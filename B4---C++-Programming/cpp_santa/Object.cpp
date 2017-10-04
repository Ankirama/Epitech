//
// Object.cpp for  in /home/viterb_c/rendu/cpp_santa
// 
// Made by CHARLES VITERBO
// Login   <viterb_c@epitech.net>
// 
// Started on  Fri Jan 16 23:52:17 2015 CHARLES VITERBO
// Last update Sat Jan 17 16:01:23 2015 Alexandre Chenevier
//

#include "Object.hh"

#include <iostream>

// Constructors
Object::Object() : m_weight(0), m_isTaken(false), m_type(UNKNOWN){
  std::cerr << "Warning : you just create an object without weight. Good job, you broke the law of physic !" << std::endl;
}

Object::Object(int weight, t_type type) : m_weight(weight), m_isTaken(false), m_type(type) {
};

Object::Object(Object const &copy)	{
  this->m_weight = copy.m_weight;
  this->m_isTaken = copy.m_isTaken;
  this->m_type = copy.m_type;
}

Object&	Object::operator=(Object const &copy)	{
  if (this != &copy) {
    this->m_weight = copy.m_weight;
    this->m_isTaken = copy.m_isTaken;
    this->m_type = copy.m_type;
  }
  return (*this);
}


// Destructor
Object::~Object()	{
}


// Getter
int     Object::getWeight() const	{
  return (this->m_weight);
}

t_type    Object::getType() const { return this->m_type; }

bool Object::operator!=(Object const& test) const {
  return (this->m_weight != test.getWeight() || this->m_type != test.getWeight() || this->m_isTaken != test.m_isTaken);
}
