//
// Teddy.hh for  in /home/viterb_c/rendu/cpp_santa
// 
// Made by CHARLES VITERBO
// Login   <viterb_c@epitech.net>
// 
// Started on  Sat Jan 17 00:59:55 2015 CHARLES VITERBO
// Last update Sat Jan 17 11:14:17 2015 CHARLES VITERBO
//

#ifndef _TEDDY_HH__
# define _TEDDY_HH__

#include "Toy.hh"
#include <iostream>

class Teddy : public Toy
{
private:
  bool	m_ted;

public:
  // Constructor
  Teddy();
  Teddy(int, t_type, std::string const, std::string const, std::string const, bool);
  Teddy(Teddy const &);
  Teddy& operator=(Teddy const &);

  // Destructor
  virtual ~Teddy();

  // Getter
  bool	getTed() const;
    virtual std::string const getTitle() const;

  //Functions
  void	isTaken();
    
    virtual bool operator!=(Teddy const&) const;
};

std::ostream&	operator<<(std::ostream&, Teddy const &);

#endif /* !_TEDDY_HH__ */
