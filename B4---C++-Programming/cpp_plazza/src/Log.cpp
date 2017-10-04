//
// Log.cpp for Log in /home/chenev_d/rendu/cpp_plazza/src
// 
// Made by Alexandre Chenevier
// Login   <chenev_d@epitech.net>
// 
// Started on  Sun Apr 26 21:24:47 2015 Alexandre Chenevier
// Last update Sun Apr 26 21:24:47 2015 Alexandre Chenevier
//

#include "Log.hh"

Log	Log::m_instance = Log();

Log::Log() {
  this->m_mutex = new PMutex();
  this->m_file.open("plazza.log", std::ios::in | std::ios::out | std::ios::app);
  this->m_mutex->lock();
  if (!this->m_file.is_open()) {
    std::cerr << "Unable to open plazza.log file" << std::endl;
  }
  else {
    this->m_file << "_________________START LOG_________________" << std::endl;
  }
  this->m_mutex->unlock();
}

Log::~Log() {
  this->m_mutex->lock();
  if (this->m_file.is_open()) {
    this->m_file << "__________________END LOG__________________" << std::endl;
    this->m_file.close();
  }
  this->m_mutex->unlock();
  delete this->m_mutex;
}

Log&	Log::getInstance() {
  return m_instance;
}

void	Log::writeLog(std::string const &message, std::string const &component) {
  this->m_mutex->lock();
  if (this->m_file.is_open()) {
    this->m_file << "LOG: [" << component << "]: " << message << std::endl;
  }
  std::clog << "LOG: [" << component << "]: " << message << std::endl;
  this->m_mutex->unlock();
}

void	Log::writeError(std::string const &message, std::string const &component) {
  this->m_mutex->lock();
  if (this->m_file.is_open()) {
    this->m_file << "ERROR: [" << component << "]: " << message << std::endl;
  }
  std::cerr << "ERROR: [" << component << "]: " << message << std::endl;
  this->m_mutex->unlock();
}
