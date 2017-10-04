#ifndef LOG_HH_
# define LOG_HH_

#include <iostream>
#include <fstream>
#include <string>
#include "PMutex.hh"

class Log {
public:
  static Log& getInstance();

  void	writeLog(std::string const &message,
		 std::string const &component);
  void	writeError(std::string const &message,
		   std::string const &component);
private:
  Log& operator=(const Log&);
  Log(const Log&) {}

  Log();
  ~Log();
private:
  static Log	m_instance;
  std::ofstream	m_file;
  IMutex	*m_mutex;
};

#endif /* !LOG_HH_ */
