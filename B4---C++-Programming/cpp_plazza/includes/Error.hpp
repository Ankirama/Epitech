#ifndef ERROR_HPP_
# define ERROR_HPP_

# include <string>
# include <exception>

class ErrorPlazza : public std::exception {
public:
  ErrorPlazza(std::string const &message,
	      std::string const &component = "Unknown") :
    m_component(component), m_message(message) {}
  virtual ~ErrorPlazza() throw() {}
  std::string const	&getComponent() const {return this->m_component;}
  const char		*what() const throw() {return this->m_message.c_str();}
protected:
  std::string	m_component;
  std::string	m_message;
};

class ErrorMutex : public ErrorPlazza {
public:
  ErrorMutex(std::string const &message, std::string const &component = "Unknown") :
    ErrorPlazza(message, component) {}
  virtual ~ErrorMutex() throw() {}
};

class ErrorCondVar : public ErrorPlazza {
public:
  ErrorCondVar(std::string const &message, std::string const &component = "Unknown") :
    ErrorPlazza(message, component) {}
  virtual ~ErrorCondVar() throw() {}
};

class ErrorThread : public ErrorPlazza {
public:
  ErrorThread(std::string const &message, std::string const &component = "Unknown") :
    ErrorPlazza(message, component) {}
  virtual ~ErrorThread() throw() {}
};

#endif /* !ERROR_HPP_ */
