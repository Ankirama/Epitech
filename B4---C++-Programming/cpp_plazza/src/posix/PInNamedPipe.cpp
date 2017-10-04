//
// PInNamedPipe.cpp for PInNamedPipe in /home/chenev_d/rendu/cpp_plazza/src
// 
// Made by Alexandre Chenevier
// Login   <chenev_d@epitech.net>
// 
// Started on  Sat Apr 25 16:03:28 2015 Alexandre Chenevier
// Last update Sun Apr 26 22:29:37 2015 Alexandre Chenevier
//

#include <sstream>
#include "PInNamedPipe.hh"
#include "Log.hh"

PInNamedPipe::PInNamedPipe(const std::string &path)
{
  m_file.open(path.c_str());
  if (mkfifo(path.c_str(), 0777) == -1)
    Log::getInstance().writeError("Error mkfifo", path);
  if (m_file.is_open() == -1)
    Log::getInstance().writeError("Error open", path);
}

PInNamedPipe::~PInNamedPipe()
{
  if (this->m_file.is_open())
    this->m_file.close();
}

std::string	PInNamedPipe::receive()
{
  std::string       str;
  std::string   line;

  str = "";
  while (getline(this->m_file, line)) {
    str += line + '\n';
  }
  return (str);
}
