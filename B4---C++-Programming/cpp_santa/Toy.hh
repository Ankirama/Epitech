//
// Toy.hh for  in /home/viterb_c/rendu/cpp_santa
// 
// Made by CHARLES VITERBO
// Login   <viterb_c@epitech.net>
// 
// Started on  Sat Jan 17 00:03:04 2015 CHARLES VITERBO
// Last update Sat Jan 17 16:17:53 2015 Alexandre Chenevier
//

#ifndef _TOY_HH__
# define _TOY_HH__

#include <string>
#include "Object.hh"

class Toy : public Object
{
protected:
  std::string	m_color;
  std::string	m_brand;
  std::string	m_title;

public:
  // Constructor
  Toy();
  Toy(int, t_type,  std::string const, std::string const, std::string const);
  Toy(Toy const &);
  Toy&	operator=(Toy const &);

  // Destructor
  virtual ~Toy();

  // Getter
  std::string	getColor() const;
  std::string	getBrand() const;
  virtual std::string  const getTitle() const;
  // Functions

  virtual bool operator!=(Toy const&) const;
};

#endif /* !OBJECT_HH__ */
