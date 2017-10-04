//
// Parser.hh for Parser in /home/chenev_d/rendu/cpp_plazza/src
// 
// Made by Alexandre Chenevier
// Login   <chenev_d@epitech.net>
// 
// Started on  Fri Apr 17 17:02:55 2015 Alexandre Chenevier
// Last update Thu Apr 23 19:05:00 2015 Alexandre Chenevier
//

#ifndef	PARSER_HH_
# define PARSER_HH_

#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include "IPizza.hh"
#include "Pizzas.hh"

class Parser
{
private:
  std::vector<std::string>	m_baseType;
  std::vector<std::string>	m_baseSize;

  std::vector<std::string>	m_typeBase;
  std::vector<std::string>	m_sizeBase;
  std::vector<std::string>	m_numberBase;

  std::vector<std::string>	m_type;
  std::vector<std::string>	m_size;
  std::vector<int>		m_number;

public:
  explicit Parser();
  ~Parser();
  bool				parse(const std::string &);
  bool				setType();
  std::vector<std::string>	getType();
  bool				setSize();
  std::vector<std::string>	getSize();
  bool				setNumber();
  std::vector<int>		getNumber();
  void			      	init_size();
  void				clean_vector();
  void				clean_set_vector();
};

#endif /* !PARSER_HH_ */
