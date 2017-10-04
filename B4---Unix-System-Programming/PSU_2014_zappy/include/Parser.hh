//
// Parser.hh for  in /home/teyssa_r/rendu/PSU_2014_zappy/src/client
// 
// Made by Raphael Teyssandier
// Login   <teyssa_r@epitech.net>
// 
// Started on  Wed Jun 17 14:26:22 2015 Raphael Teyssandier
// Last update Sun Jul  5 19:55:04 2015 Raphael Teyssandier
//

#ifndef PARSER_HH_
# define PARSER_HH_

/**
 * @file Parser.hh
 * @brief Parser of the argv
 * @author doT
 * @version 1.0
 */

#include <iostream>

/**
 * @class Parser
 * @brief For parsing the argument
 */
class	Parser {
public:
  /**
   * @brief Default constructor
   * @param argument number, argument
   */
  Parser(int ac, char **tab, std::string const&, bool);
  /**
   * @brief Copy constructor
   * @param Parser reference
   */
  ~Parser();

  /**
   * @brief Get the hostname
   */
  std::string	&getHostName()	{	return this->m_host;	}
  /**
   * @brief Get the port
   */
  std::string	&getPort()	{	return this->m_port;	}
  /**
   * @brief Get the name
   */
  std::string	&getName()	{	return this->m_name;	}
  /**
   * @brief Get the argument
   * @param1 The flag
   * @param2 If needed or not
   */
  std::string	getArgument(std::string const &, bool) const;
  /**
   * @brief Check if the str is in the tabArg
   */
  bool		checkTab(std::string const &);

private:
  Parser(Parser const &);
  /**
   * @brief Operator = constructor
   * @param Parser reference
   */
  Parser operator=(Parser const &);
  /**
   * @brief Default destructor
   */

private:
  char		**m_arg; /**<Argument*/
  std::string	m_usage; /**<Usage*/
  std::string	m_name; /**<Name team*/
  std::string	m_port; /**<Port*/
  std::string	m_host; /**<Hostname*/
};

#endif /* !PARSER_HH_ */
