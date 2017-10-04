//
// BorgQueen.hh for borg in /home/user/rendu/piscine_cpp_d07m/ex04
//
// Made by 
// Login   
//
// Started on  Tue Jan 13 16:59:58 2015 
// Last update Tue Jan 13 23:47:27 2015 
//

#ifndef BORGQUEEN_HH_
# define BORGQUEEN_HH_

#include "Borg.hh"
#include "Destination.hh"

namespace Borg {
  class BorgQueen
  {
  public:
    BorgQueen();
    ~BorgQueen();
    bool (Borg::Ship::*movePtr) (Destination);
    void (Borg::Ship::*firePtr) (Federation::Starfleet::Ship *);
    void (Borg::Ship::*destroyPtr) (Federation::Ship *);
    bool move(Borg::Ship*, Destination);
    void fire(Borg::Ship*, Federation::Starfleet::Ship*);
    void destroy(Borg::Ship*, Federation::Ship*);
  };
}

#endif /* !BORGQUEEN_HH_ */
