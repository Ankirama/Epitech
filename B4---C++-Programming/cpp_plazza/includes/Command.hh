//
// Command.hh for  in /home/teyssa_r/rendu/cpp_plazza
// 
// Made by Raphael Teyssandier
// Login   <teyssa_r@epitech.net>
// 
// Started on  Thu Apr 23 17:10:34 2015 Raphael Teyssandier
// Last update Sun Apr 26 13:33:35 2015 Raphael Teyssandier
//

#ifndef COMMAND_HH_
# define COMMAND_HH_

# include <iostream>

typedef enum	e_TaillePizza {
  S = 1,
  M = 2,
  L = 4,
  XL = 8,
  XXL = 16
}		t_TaillePizza;

typedef enum	e_status_cmd {
  WAIT_CMD,
  LOADING,
  FINISH_CMD
}		t_status_cmd;

class	Command {
private:
  int		m_quantite;
  std::string	m_pizza;
  std::string  	m_taille;
  t_status_cmd	m_status;
  int		m_nCommand;

public:
  Command(const std::string &, const int, std::string const &, const t_status_cmd, const int);
  ~Command();

  std::string		getPizza() const;
  int			getQuantite() const;
  std::string			getTall() const;
  t_status_cmd		getStatus() const;
  int			getNbCommand() const;
  void			setStatus(t_status_cmd const);
};

#endif /* !COMMAND_HH_ */
