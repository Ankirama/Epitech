//
// Command.cpp for  in /home/teyssa_r/rendu/cpp_plazza
// 
// Made by Raphael Teyssandier
// Login   <teyssa_r@epitech.net>
// 
// Started on  Thu Apr 23 17:28:45 2015 Raphael Teyssandier
// Last update Sun Apr 26 13:32:49 2015 Raphael Teyssandier
//

#include "Command.hh"

Command::Command(const std::string &name, const int quantite, const std::string &tall,
		 const t_status_cmd status, const int nb) : m_quantite(quantite),
					      m_pizza(name),
					      m_taille(tall),
					      m_status(status),
					      m_nCommand(nb) {
}

Command::~Command(){
}

std::string		Command::getPizza() const{
  return (this->m_pizza);
}

int			Command::getQuantite() const{
  return (this->m_quantite);
}

std::string    		Command::getTall() const{
  return (this->m_taille);
}

t_status_cmd		Command::getStatus() const{
  return (this->m_status);
}

int			Command::getNbCommand() const{
  return (this->m_nCommand);
}

void			Command::setStatus(t_status_cmd const status) {
  this->m_status = status;
}
