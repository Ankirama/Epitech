#include "ListDir.hh"

int main() {
  ListDir *test;

  test = new ListDir();
  std::vector<std::string> files = test->getFiles(".");
  for (size_t i = 0; i < files.size(); i++) {
    std::cout << files[i] << std::endl;
  }
  return (0);
}
