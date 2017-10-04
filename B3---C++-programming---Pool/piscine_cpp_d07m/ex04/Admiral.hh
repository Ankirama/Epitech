//
// Admiral.hh for hall in /home/user/rendu/piscine_cpp_d07m/ex04
//
// Made by 
// Login   
//
// Started on  Tue Jan 13 16:22:03 2015 
// Last update Tue Jan 13 16:59:44 2015 
//

#ifndef ADMIRAL_HH_
# define ADMIRAL_HH_

# include <string>
# include "Federation.hh"
# include "Destination.hh"

namespace Federation {
  namespace Starfleet {
    class Admiral
    {
    private:
      std::string _name;

    public:
      Admiral(std::string name);
      ~Admiral();

      bool (Federation::Starfleet::Ship::*movePtr) (Destination);
      void (Federation::Starfleet::Ship::*firePtr) (Borg::Ship *);
      void fire(Federation::Starfleet::Ship*, Borg::Ship*);
      bool move(Federation::Starfleet::Ship*, Destination);
    };
  }
}

#endif /* !ADMIRAL_HH_ */
