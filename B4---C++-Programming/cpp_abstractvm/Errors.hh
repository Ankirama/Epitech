//
//  Errors.h
//  cpp_abstractvm
//
//  Created by Fabien Martinez on 28/02/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef cpp_abstractvm_Errors_hh
#define cpp_abstractvm_Errors_hh

#include <string>
#include <exception>

class ErrorAbstract: public std::exception {
public:
  ErrorAbstract(std::string const &message,
	   std::string const &component = "Unknown") :
    m_component(component), m_message(message) {}
  virtual ~ErrorAbstract() throw() {}
  std::string const &getComponent() const {return this->m_component;}
  const char* what()const throw() {return this->m_message.c_str();}
protected:
  std::string m_component;
  std::string m_message;
};

class NumberError : public ErrorAbstract {
public:
  NumberError(std::string const &message, std::string const &component = "Unknown") :
    ErrorAbstract(message, component) {}
  virtual ~NumberError() throw() {}
};

class InstructionError : public ErrorAbstract {
public:
  InstructionError(std::string const &message, std::string const &component = "Unknown") :
    ErrorAbstract(message, component) {}
  virtual ~InstructionError() throw() {}
};

class AssertError : public ErrorAbstract {
public:
  AssertError(std::string const &message, std::string const &component = "Unknown") :
    ErrorAbstract(message, component) {}
  virtual ~AssertError() throw() {}
};

class EndError : public ErrorAbstract {
public:
  EndError(std::string const &message, std::string const &component = "Unknown") :
    ErrorAbstract(message, component) {}
  virtual ~EndError() throw() {}
};

class UnknownError : public ErrorAbstract {
public:
  UnknownError(std::string const &message, std::string const &component = "Unknown") :
    ErrorAbstract(message, component) {}
  virtual ~UnknownError() throw() {}
};

class StackError : public ErrorAbstract {
public:
  StackError(std::string const &message, std::string const &component = "Unknown") :
    ErrorAbstract(message, component) {}
  virtual ~StackError() throw() {}
};

#endif
