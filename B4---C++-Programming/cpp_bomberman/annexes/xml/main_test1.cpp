#include <fstream>
#include "XmlWrite.hpp"

int main() {
  std::ofstream of("test.xml");
  XmlWrite  xml(of);

  xml << tag("save")
        << tag("players")
          << attribute("number") << 1
          << tag("player")
            << attribute("id") << 1
            << attribute("type") << "player"
            << attribute("state") << true
            << tag("name")
              << data() << "ankirama"
            << endtag()
            << tag("position")
              << data() << 24
            << endtag("")
            << tag("direction")
              << data() << 2
            << endtag()
            << tag("speed")
              << data() << 42
            << endtag()
            << tag("texture")
              << tag("color")
                << tag("r")
                  << data() << 230
                << endtag()
                << tag("g")
                  << data() << 210
                << endtag()
                << tag("b")
                  << data() << 130
              << endtag("color")
              << tag("path")
                << data() << "/home/tamaman/marvin.suce"
            << endtag("texture")
            << tag("score")
              << data() << 4224
            << endtag()
            << tag("keys")
              << tag("left")
              << data() << 2
              << endtag()
              << tag("right")
                << data() << 3
              << endtag()
              << tag("up")
                << data() << 4
              << endtag()
              << tag("down")
                << data() << 1
              << endtag()
              << tag("bomb")
                << data() << 0
            << endtag("keys")
            << tag("bombs")
              << attribute("number") << 1
              << tag("bomb")
                << attribute("id") << 1
                << tag("texture")
                  << data() << "/home/tamaman/bomb.sucepatro"
                << endtag()
                << tag("time")
                    << data() << 3
                << endtag()
                << tag("range")
                  << data() << 2
                << endtag()
                << tag("position")
                  << tag("x")
                    << data() << 42
                  << endtag()
                  << tag("y")
                    << data() << 23
                  << endtag()
                << endtag()
              << endtag()
            << endtag()
          << endtag()
        << endtag()
        << tag("maze")
          << tag("size")
            << tag("width")
              << data() << 10
            << endtag()
            << tag("height")
              << data() << 10
          << endtag("size")
      << tag("maze") << data() << "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
        << endtag();

  return (0);
}
