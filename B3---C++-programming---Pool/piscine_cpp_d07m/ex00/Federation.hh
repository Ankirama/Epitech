#ifndef FEDERATION_HH_
# define FEDERATION_HH_

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

      protected: /* data */
      WarpSystem::Core *_core;
      int _length;
      int _width;
      std::string _name;
      short _maxWarp;
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
