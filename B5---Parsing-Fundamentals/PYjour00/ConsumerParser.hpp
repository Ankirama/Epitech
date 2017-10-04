//
//  ConsumerParser.h
//  PYjour00
//
//  Created by Fabien Martinez on 14/09/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __PYjour00__ConsumerParser__
#define __PYjour00__ConsumerParser__

#include <vector>
#include <map>
#include "ProducterStream.hpp"
#include "string.h"

typedef struct {
    std::string buffer;
    int         position;
} myBuffer;

typedef struct {
    int bufferIndex;
    int startPosition;
} myCapture;

class ConsumerParser {
public:
    explicit ConsumerParser(ProducterStream &producter);
    ~ConsumerParser();
    
    inline bool flush();
    inline bool peekChar(char c) {
      if (this->m_buffer.empty())
	this->m_buffer = this->m_producter.nextString();
      return !(this->m_buffer.empty() || this->m_buffer[0] != c);
    }

    inline bool readChar(char c) {
        bool res;
        
        res = this->peekChar(c);
        if (res) {
	  this->m_buffer.erase(0, 1);
        }
        return res;
    }

  inline bool readRange(char begin, char end) {
    char oldHead;

    if (this->m_buffer.empty())
      this->m_buffer = this->m_producter.nextString();

    oldHead = this->m_buffer[0];
    while (begin < end && oldHead != begin)
      ++begin;
    if (begin <= end && oldHead == begin) {
      this->m_buffer.erase(0, 1);
      return true;
    }
    return false;
  }

  bool readText(char *text);
  bool readEOF();
  bool readUntil(char c);
  bool readUntilEOF();
  bool readInteger();
  bool readIdentifier();
  inline bool beginCapture(std::string tag) {
    return true;
  }
  inline bool endCapture(std::string tag, std::string& out) {
    return true;
  }
    
private:
  inline bool internReadRange(char begin, char end) {
    char oldHead;
        
    if (this->m_buffer.empty())
      return false;
    oldHead = this->m_buffer[0];
    while (begin < end && oldHead != begin)
      ++begin;
    if (begin <= end && oldHead == begin) {
      this->m_buffer.erase(0, 1);
      return true;
    }
    return false;
  }
    
private:
  ProducterStream &m_producter;
  std::string	   m_buffer;
};

#endif /* defined(__PYjour00__ConsumerParser__) */
