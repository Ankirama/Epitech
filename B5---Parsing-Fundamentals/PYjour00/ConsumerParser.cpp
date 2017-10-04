//
//  ConsumerParser.cpp
//  PYjour00
//
//  Created by Fabien Martinez on 14/09/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include "ConsumerParser.hpp"

ConsumerParser::ConsumerParser(ProducterStream &producter) : m_producter(producter) {
  this->m_buffer = this->m_producter.nextString();
}

ConsumerParser::~ConsumerParser() {}

bool ConsumerParser::flush() {
  this->m_buffer.clear();
  return true;
}

bool ConsumerParser::readText(char *text) {
    std::string::size_type n;

    if (this->m_buffer.empty())
      this->m_buffer = this->m_producter.nextString();

    n = this->m_buffer.find(text, 0);
    if (n == 0) {
      this->m_buffer.erase(0, strlen(text));
      return true;
    }
    return false;
}

bool ConsumerParser::readEOF() {
  return this->m_buffer.empty();
}

bool ConsumerParser::readUntil(char c) {
    std::string::size_type n;

    if (this->m_buffer.empty())
      this->m_buffer = this->m_producter.nextString();
    n = this->m_buffer.find(c, 0);
    if (n == std::string::npos)
      return false;
    this->m_buffer.erase(0, n + 1);
    return true;
}

bool ConsumerParser::readUntilEOF() {
  this->m_buffer.clear();
  return true;
}

bool ConsumerParser::readInteger() {
    bool currRes;

    if (this->m_buffer.empty())
      this->m_buffer = this->m_producter.nextString();

    if (this->m_buffer.empty())
      return false;
    
    if (!(currRes = this->internReadRange('0', '9')))
      return false;
    while (this->internReadRange('0', '9'));
    return true;
}

bool ConsumerParser::readIdentifier() {
  if (this->m_buffer.empty())
    this->m_buffer = this->m_producter.nextString();
  if (!(this->internReadRange('a', 'b') || this->internReadRange('A', 'Z') || this->m_buffer[0] == '_'))
    return false;
  while (!this->m_buffer.empty() && (
				     this->internReadRange('a', 'b') || this->internReadRange('A', 'Z') || this->m_buffer[0] == '_'
				     ));
  return (true);
}
