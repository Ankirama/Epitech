//
// LittlePony.hh for  in /home/viterb_c/rendu/cpp_santa
// 
// Made by CHARLES VITERBO
// Login   <viterb_c@epitech.net>
// 
// Started on  Sat Jan 17 11:02:39 2015 CHARLES VITERBO
// Last update Sat Jan 17 13:53:26 2015 Alexandre Chenevier
//

#ifndef _LITTLEPONY_HH__
# define _LITTLEPONY_HH__

#include "Toy.hh"
#include <iostream>

class LittlePony : public Toy
{
private:
  bool	m_shitrainbow;

public:
  // Constructor
  LittlePony();
  LittlePony(int, t_type, std::string const, std::string const, std::string const, bool);
  LittlePony(LittlePony const &);
  LittlePony& operator=(LittlePony const &);

  // Destructor
  virtual ~LittlePony();

  // Getter
  bool	getShitRainbow() const;
  std::string const getTitle() const;

  //Functions
  void	isTaken();
    
    virtual bool operator!=(LittlePony const&) const;
};

std::ostream&	operator<<(std::ostream&, LittlePony const &);

#endif /* !_TEDDY_HH__ */
