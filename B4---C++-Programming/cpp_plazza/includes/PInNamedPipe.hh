#ifndef PINNAMEDPIPE_HH_
# define PINNAMEDPIPE_HH_

#include <string>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "Error.hpp"
#include "Log.hh"

class	PInNamedPipe {
public:
  explicit PInNamedPipe(const std::string &path);
  ~PInNamedPipe();
  std::string receive();
private:
  std::string	m_path;
  std::ifstream	m_file;
};

#endif  /* !PINNAMEDPIPE_HH_ */
