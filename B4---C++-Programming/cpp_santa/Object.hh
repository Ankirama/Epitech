//
// Object.hh for  in /home/viterb_c/rendu/cpp_santa
// 
// Made by CHARLES VITERBO
// Login   <viterb_c@epitech.net>
// 
// Started on  Fri Jan 16 23:46:22 2015 CHARLES VITERBO
// Last update Sat Jan 17 15:52:30 2015 Alexandre Chenevier
//

#ifndef _OBJECT_HH__
# define _OBJECT_HH__

#include <iostream>
#include <string>

typedef enum    e_type {
    LITTLE_PONY,
    TEDDY,
    BOX,
    GIFT_PAPER,
    UNKNOWN
}               t_type;

class Object
{
protected:
    int     m_weight;
    bool    m_isTaken;
    t_type    m_type;

public:
  // Constructor
  Object();
  Object(int, t_type);
  Object(Object const &);
  Object& operator=(Object const &);

  // Destructor
  virtual ~Object();

  // Getter
    int             getWeight() const;
    t_type            getType() const;
    virtual void    isTaken() = 0;
    virtual std::string const getTitle() const = 0;

    //operator
    virtual bool operator!=(Object const&) const;
};

#endif /* !_OBJECT_HH__ */
