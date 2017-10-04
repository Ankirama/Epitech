/*
** Error.hpp for Error in /home/chenevd/rendu/cpp_bomberman/include
** 
** Made by Alexandre Chenevier
** Login   <chenevd@ubuntu>
** 
** Started on  Wed May 13 07:38:55 2015 Alexandre Chenevier
// Last update Thu May 21 14:40:54 2015 Raphael Teyssandier
*/

#ifndef ERROR_HPP_
# define ERROR_HPP_

#include <string>
#include <exception>

class	ErrorBomberman : public std::exception {
public:
  ErrorBomberman(std::string const &message, std::string const &component = "Unknown"):
    m_component(component), m_message(message) {}
  virtual ~ErrorBomberman() throw() {}

  std::string const	&getComponent() const {return this->m_component;}
  const char		*what() const throw() {return this->m_message.c_str();}

protected:
  std::string		m_component;
  std::string		m_message;
};

#endif /* !ERROR_HPP_ */
