#ifndef BORG_HH_
# define BORG_HH_

#include "Warpsystem.hh"
#include "Destination.hh"

namespace Borg {
  class Ship {
  private:
    int _side;
    short _maxWarp;
    WarpSystem::Core *_core;
    Destination _location;
    Destination _home;

  public:
    Ship();
    ~Ship();

    void setupCore(WarpSystem::Core *core);
    void checkCore();
    bool move(int warp, Destination d);
    bool move(int warp);
    bool move(Destination d);
    bool move();
  };
}

#endif /* !BORG_HH_ */
