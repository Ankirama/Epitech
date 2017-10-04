//
// parser.cpp for parser in /home/chenev_d/rendu/cpp_plazza/src
// 
// Made by Alexandre Chenevier
// Login   <chenev_d@epitech.net>
// 
// Started on  Fri Apr 17 16:25:52 2015 Alexandre Chenevier
// Last update Sun Apr 26 22:13:23 2015 Alexandre Chenevier
//

#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include "Pizzas.hh"
#include "Parser.hh"
#include "Log.hh"

Parser::Parser()
{
  init_size();
}

Parser::~Parser() {}

bool	Parser::parse(const std::string &_commande)
{
  std::string	type;
  std::string	size;
  std::string	number;
  std::string	commande;
  int		nb;
  int		i;

  nb = 0;
  i = 0;
  commande = _commande;
  if (commande == "")
    return (false);
  std::replace(commande.begin(), commande.end(), ';', '\0');
  std::istringstream	iss(commande);
  nb = std::count(commande.begin(), commande.end(), ' ') + 1;
  if (nb % 3 != 0)
    {
      Log::getInstance().writeError("Not valid command. TYPE SIZE NUMBER [;TYPE SIZE NUMBER]",
				    commande);
      return (false);
    }
  while (iss && i < nb  && iss.rdbuf()->in_avail())
    {
      iss >> type;
      this->m_typeBase.push_back(type);
      iss >> size;
      this->m_sizeBase.push_back(size);
      iss >> number;
      this->m_numberBase.push_back(number);
      i++;
    }
  if (!setType() || !setSize() || !setNumber()){
    clean_vector();
    return (false);
  }
  return (true);
}

void	Parser::init_size()
{
  this->m_baseSize.push_back("S");
  this->m_baseSize.push_back("M");
  this->m_baseSize.push_back("L");
  this->m_baseSize.push_back("XL");
  this->m_baseSize.push_back("XXL");
}

bool		Parser::setType()
{
  std::string	mytype;

  while (!this->m_typeBase.empty())
    {
      mytype = this->m_typeBase.back();
      this->m_typeBase.pop_back();
      std::transform(mytype.begin(), mytype.end(), mytype.begin(), ::tolower);
      if (Pizzas::getInstance().getPizza(mytype) != 0)
	this->m_type.push_back(mytype);
      else
	{
	  Log::getInstance().writeError("Invalid type of Pizza.", mytype);
	  clean_set_vector();
	  return(false);
	}
    }
  return (true);
}

std::vector<std::string>	Parser::getType()
{
  return (this->m_type);
}

bool		Parser::setSize()
{
  size_t	i;
  std::string	mysize;

  while (!this->m_sizeBase.empty())
    {
      mysize = this->m_sizeBase.back();
      this->m_sizeBase.pop_back();
      i = 0;
      while (i < this->m_baseSize.size() && mysize.compare(this->m_baseSize[i]) != 0)
	++i;
      if (i == this->m_baseSize.size())
	{
	  Log::getInstance().writeError("Invalid size of Pizza.", mysize);
	  clean_set_vector();
	  return(false);
	}
      else
	this->m_size.push_back(this->m_baseSize[i]);
    }
  return (true);
}

std::vector<std::string>	Parser::getSize()
{
  return (this->m_size);
}

bool	Parser::setNumber()
{
  std::string		str_number;
  std::string		mynumber;
  int			number;
  int			length;
  int			i;

  while (!this->m_numberBase.empty())
    {
      mynumber = this->m_numberBase.back();
      this->m_numberBase.pop_back();
      if (mynumber[0] == 'x')
	{
	  length = mynumber.size();
	  str_number = mynumber.substr(1, length);
	  i = 0;
	  while (str_number[i] != '\0')
	    {
	      if (str_number[i] <= 48 || str_number[i] >= 57)
		{
		  Log::getInstance().writeError("Invalid Number of Pizza.", mynumber);
		  clean_set_vector();
		  return(false);
		}
	      i++;
	    }
	  std::istringstream(str_number) >> number;
	  this->m_number.push_back(number);
	}
      else
	{
	  Log::getInstance().writeError("Invalid Number of Pizza.", mynumber);
	  clean_set_vector();
	  return(false);
	}
    }
  return (true);
}

std::vector<int>	Parser::getNumber()
{
  return (this->m_number);
}

void	Parser::clean_vector()
{
  while(!this->m_typeBase.empty())
    this->m_typeBase.pop_back();
  while(!this->m_sizeBase.empty())
    this->m_sizeBase.pop_back();
  while(!this->m_numberBase.empty())
    this->m_numberBase.pop_back();
}

void	Parser::clean_set_vector()
{
  while(!this->m_type.empty())
    this->m_type.pop_back();
  while(!this->m_size.empty())
    this->m_size.pop_back();
  while(!this->m_number.empty())
    this->m_number.pop_back();
}
