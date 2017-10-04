//
// POutNamedPipe.cpp for PipeOut in /home/chenev_d/rendu/cpp_plazza/src
// 
// Made by Alexandre Chenevier
// Login   <chenev_d@epitech.net>
// 
// Started on  Sat Apr 25 03:46:47 2015 Alexandre Chenevier
// Last update Sun Apr 26 22:29:50 2015 Alexandre Chenevier
//

#include "POutNamedPipe.hh"
#include "Log.hh"

POutNamedPipe::POutNamedPipe(const std::string &path)
{
  m_file.open(path.c_str());
  if (mkfifo(path.c_str(), 0644) == -1)
    Log::getInstance().writeError("Error mkfifo", path);
  if (m_file.is_open() == -1)
    Log::getInstance().writeError("Error open", path);
}

POutNamedPipe::~POutNamedPipe()
{
  if (this->m_file.is_open())
    this->m_file.close();
}

void	POutNamedPipe::send(const std::string &msg)
{
  m_file << msg;
  if (m_file.fail() == true)
    Log::getInstance().writeError("Error send", msg);
}
