//
// Error.hh for  in /home/teyssa_r/rendu/cpp_nibbler/includes
// 
// Made by Raphael Teyssandier
// Login   <teyssa_r@epitech.net>
// 
// Started on  Sun Apr  5 16:59:01 2015 Raphael Teyssandier
// Last update Sun Apr  5 17:33:37 2015 Raphael Teyssandier
//

#ifndef ERROR_HH_
# define ERROR_HH_

# include <string>
# include <exception>

class ErrorNibbler: public std::exception {
public:
  ErrorNibbler(std::string const &message,
	       std::string const &component = "Unknown") :
    m_component(component), m_message(message) {}
  virtual ~ErrorNibbler() throw() {}
  std::string const	&getComponent() const {return this->m_component;}
  const char	*what() const throw() {return this->m_message.c_str();}
protected:
  std::string	m_component;
  std::string	m_message;
};

class ErrorNCURSES : public ErrorNibbler {
public:
  ErrorNCURSES(std::string const &message, std::string const &component = "Unknown") :
    ErrorNibbler(message, component) {}
  virtual ~ErrorNCURSES() throw() {}
};

class ErrorLib : public ErrorNibbler {
public:
  ErrorLib(std::string const &message, std::string const &component = "Unknown") :
    ErrorNibbler(message, component) {}
  virtual ~ErrorLib() throw() {}
};


#endif
