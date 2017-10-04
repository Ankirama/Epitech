#ifndef LISTDIR__HH
#define LISTDIR__HH

/**
 * @file ListDir.hh
 * @brief List files in directory
 * @author ankirama
 * @version 1.11
 */

#include <string>
#include <vector>
#include <iostream>
#include <dirent.h>

/**
 * @class ListDir
 * @brief List files in specific directory
 *
 * Allow to list files in specific directory
 */
class ListDir {
public:

  /**
   * @brief ListDir's constructor
   *
   * It will init to default values every variable
   */
  ListDir();

  /**
   * @brief ListDir's destructor
   */
  ~ListDir();

  /**
   * @brief list everyfile in path
   *
   * It will list everyfile in specific path without '.' and '..'
   *
   * @param path we will list file in this path
   * @return Every file stored in string
   */
  std::vector<std::string> getFiles(std::string const& path);
private:
  DIR  *m_dirp; /**< variable to 'load' directory and allow us to travel it*/
  struct dirent *m_files; /**< structure to read into m_dirp */
};

#endif
