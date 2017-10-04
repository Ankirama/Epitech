//
// Error.hpp for  in /home/teyssa_r/rendu/PSU_2014_zappy
// 
// Made by Raphael Teyssandier
// Login   <teyssa_r@epitech.net>
// 
// Started on  Wed Jun 17 13:54:05 2015 Raphael Teyssandier
// Last update Sat Jun 27 20:06:51 2015 Raphael Teyssandier
//

#ifndef ERROR_HPP_
# define ERROR_HPP_

/**
 * @file Error.hpp
 * @brief Error class for client
 * @author doT
 * @version 1.0
 */

#include <string>
#include <exception>

/**
 * @class ErrorClient
 * @brief Error class for the client
 */
class	ErrorClient : public std::exception {
public:
  /**
   * @brief Constructor of the class
   */
  ErrorClient(std::string const &message, std::string const &component = "Unknown") :
    m_component(component), m_message(message) {}
  /**
   * @brief Destructor of the class
   */
  virtual	~ErrorClient() throw() {}

  /**
   * @brief Get the component
   */
  std::string	const	&getComponent() const	{return this->m_component;}
  /**
   * @brief Get the error
   */
  const	char		*what() const throw()	{return this->m_message.c_str();}

protected:
  std::string	m_component;/**<Component*/
  std::string	m_message;/**<Message*/
};

#endif /* !ERROR_HPP_ */
