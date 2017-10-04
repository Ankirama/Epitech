//
// Parser.cpp for  in /home/teyssa_r/rendu/PSU_2014_zappy/src/client
// 
// Made by Raphael Teyssandier
// Login   <teyssa_r@epitech.net>
// 
// Started on  Wed Jun 17 14:35:10 2015 Raphael Teyssandier
// Last update Sun Jul  5 20:33:02 2015 Raphael Teyssandier
//

#include "Parser.hh"
#include "Error.hpp"

static	std::string	tabArg[4] = {
  "-p",
  "-d",
  "-h",
  "-n"
};

Parser::Parser(int ac, char **tab, std::string const &usage, bool n) : m_arg(tab),
								       m_usage(usage),
								       m_name(getArgument("-n", n)),
								       m_port(getArgument("-p", true)),
								       m_host(getArgument("-h", false)){
  try {
    for (int i = 1;i < ac ;++i){
      if (this->m_arg[i] && this->m_arg[i - 1] && this->m_arg[i][0] == '-' &&
	  std::string(this->m_arg[i - 1]) != "-n" && !checkTab(std::string(this->m_arg[i])))
	throw ErrorClient(this->m_usage, "Parser");
    }
    if (this->m_arg[ac - 1] && std::string(this->m_arg[ac - 1]) == "-d")
      std::cout << "Name : " << this->m_name
		<< std::endl
		<< "Port : " << this->m_port
		<< std::endl
		<< "Host : " << this->m_host
		<< std::endl;
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Parser");
  }
}

Parser::~Parser(){
  if (this->m_arg)
    delete this->m_arg;
}

bool	Parser::checkTab(std::string const &str){
  bool	inOrOut = false;

  for (int i = 0;i < 4;++i)
    if (!tabArg[i].empty() && str == tabArg[i])
      inOrOut = true;
  return (inOrOut);
}

std::string	Parser::getArgument(std::string const &flag, bool needed) const{
  try {
    if (flag == "-n" && !needed)
      tabArg[3].erase();
    for (int i = 0;this->m_arg[i];++i)
      if (this->m_arg[i] && std::string(this->m_arg[i]) == flag){
	if (this->m_arg[i + 1])
	  return (std::string(this->m_arg[i + 1]));
	  else
	    throw ErrorClient(this->m_usage, "Parser");
      }
    if (flag == "-h")
      return (std::string("localhost"));
    if (needed)
      throw ErrorClient(this->m_usage, "Parser");
    return ("");
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Parser");
  }
}
