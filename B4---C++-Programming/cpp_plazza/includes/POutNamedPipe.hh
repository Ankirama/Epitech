#ifndef POUTNAMEDPIPE_HH_
# define POUTNAMEDPIPE_HH_

#include <string>
#include <fstream>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "Error.hpp"
#include "Log.hh"

class	POutNamedPipe {
public:
  explicit POutNamedPipe(const std::string &path);
  ~POutNamedPipe();
  void send(const std::string & msg);
private:
  std::string	m_path;
  std::ofstream	m_file;
};

#endif  /* !POUTNAMEDPIPE_HH_ */
