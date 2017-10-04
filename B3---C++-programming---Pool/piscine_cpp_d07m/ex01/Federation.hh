#ifndef FEDERATION_HH_
# define FEDERATION_HH_

#include <iostream>
# include <string>
# include "Warpsystem.hh"

namespace Federation {
  namespace Starfleet {
    class Ship {
    public:
      Ship (int length, int width, std::string name, short maxWarp);
      ~Ship ();
      void setupCore(WarpSystem::Core *core);
      void checkCore();
      void promote(class Captain *captain);

      protected: /* data */
      WarpSystem::Core *_core;
      int _length;
      int _width;
      std::string _name;
      short _maxWarp;
      Captain *_captain;
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
  private:
    WarpSystem::Core *_core;
    int _length;
    int _width;
    std::string _name;
    static const short _maxWarp = 1;
  };

}

#endif /* !FEDERATION_HH_ */
