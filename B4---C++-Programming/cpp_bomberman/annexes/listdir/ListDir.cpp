#include "ListDir.hh"

ListDir::ListDir() {
  this->m_dirp = 0;
  this->m_files = 0;
}

ListDir::~ListDir() {

}

std::vector<std::string>ListDir::getFiles(std::string const &path) {
  std::vector<std::string>files;

  if (!(this->m_dirp = opendir(path.c_str())))
    std::cerr << "ERROR: unable to open the directory" << std::endl;
  else {
    while ((this->m_files = readdir(this->m_dirp))) {
      if (this->m_files->d_type == DT_REG)
        files.push_back(std::string(this->m_files->d_name));
    }
    if (closedir(this->m_dirp) == -1)
      std::cerr << "Error: unable to close the directory" << std::endl;
  }
  this->m_dirp = 0;
  this->m_files = 0;
  return files;
}
