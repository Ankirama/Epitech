#ifndef BORG_HH_
# define BORG_HH_

#include "Warpsystem.hh"
#include "Federation.hh"
#include "Destination.hh"

namespace Federation {
  namespace Starfleet {
    class Ship;
  }
  class Ship;
};

namespace Borg {
  class Ship {
  private:
    int _side;
    short _maxWarp;
    WarpSystem::Core *_core;
    Destination _location;
    Destination _home;
    int _shield;
    int _weaponFrequency;
    short _repair;

  public:
    Ship(int weaponFrequency);
    Ship(int weaponFrequency, short repair);
    ~Ship();

    void setupCore(WarpSystem::Core *core);
    void checkCore();
    bool move(int warp, Destination d);
    bool move(int warp);
    bool move(Destination d);
    bool move();
    int getShield();
    void setShield(int);
    int getWeaponFrequency();
    void setWeaponFrequency(int);
    short getRepair();
    void setRepair(short);
    void fire(Federation::Starfleet::Ship *);
    void fire(Federation::Ship *);
    void repair();
  };
}

#endif /* !BORG_HH_ */
