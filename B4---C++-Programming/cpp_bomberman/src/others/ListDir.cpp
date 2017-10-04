#include "ListDir.hh"

ListDir::ListDir() {
  this->m_dirp = 0;
  this->m_files = 0;
}

ListDir::~ListDir() {

}

std::vector<std::string>ListDir::getFiles(std::string const &path) {
  std::vector<std::string>files;
  std::string		tmp;
  std::size_t		pos;

  if (!(this->m_dirp = opendir(path.c_str())))
    std::cerr << "ERROR: unable to open the directory" << std::endl;
  else {
    while ((this->m_files = readdir(this->m_dirp))) {
      if (this->m_files->d_type == DT_REG && this->m_files->d_name[0] != '.'){
	tmp = std::string(this->m_files->d_name);
	pos = tmp.find('.');
	if (pos != std::string::npos)
	  tmp = tmp.substr(0, pos);
        files.push_back(tmp);
      }
    }
    if (closedir(this->m_dirp) == -1)
      std::cerr << "Error: unable to close the directory" << std::endl;
  }
  this->m_dirp = 0;
  this->m_files = 0;
  return files;
}
