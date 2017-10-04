#ifndef FEDERATION_HH_
# define FEDERATION_HH_

#include <iostream>
# include <string>
# include "Warpsystem.hh"
# include "Destination.hh"
# include "Borg.hh"

namespace Borg {
  class Ship;
};

namespace Federation {
  namespace Starfleet {
    class Ship {
    public:
      Ship (int length, int width, std::string name, short maxWarp, int torpedo);
      Ship();
      ~Ship ();
      void setupCore(WarpSystem::Core *core);
      void checkCore();
      void promote(class Captain *captain);
      bool move(int warp, Destination d);
      bool move(int warp);
      bool move(Destination d);
      bool move();
      int getShield();
      void setShield(int);
      int getTorpedo();
      void setTorpedo(int);
      void fire(Borg::Ship*);
      void fire(int torpedoes, Borg::Ship*);

      private: /* data */
      WarpSystem::Core *_core;
      int _length;
      int _width;
      std::string _name;
      short _maxWarp;
      Captain *_captain;
      Destination _location;
      Destination _home;
      int _shield;
      int _photonTorpedo;
    };
    class Captain {
    public:
      Captain(std::string name);
      ~Captain();
      int getAge();
      void setAge(int age);

      std::string _name;

    private:
      int _age;
    };

    class Ensign {
    public:
      explicit Ensign(std::string name);
      ~Ensign();

    private:
      std::string _name;
    };
  }
  class Ship {
  public:
    Ship (int length, int width, std::string name);
    ~Ship();
    void setupCore(WarpSystem::Core *core);
    void checkCore();
    WarpSystem::Core *getCore();

    bool move(int warp, Destination d);
    bool move(int warp);
    bool move(Destination d);
    bool move();

  private:
    WarpSystem::Core *_core;
    int _length;
    int _width;
    std::string _name;
    static const short _maxWarp = 1;
    Destination _location;
    Destination _home;
  };

}

#endif /* !FEDERATION_HH_ */
