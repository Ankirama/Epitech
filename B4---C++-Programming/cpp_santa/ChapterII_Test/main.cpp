//
// main.cpp for main in /home/chenev_d/rendu/cpp_santa/ChapterII_Test
// 
// Made by Alexandre Chenevier
// Login   <chenev_d@epitech.net>
// 
// Started on  Fri Jan 16 23:47:00 2015 Alexandre Chenevier
// Last update Sat Jan 17 11:18:36 2015 CHARLES VITERBO
//

#include "Object.hh"
#include "Toy.hh"
#include "LittlePony.hh"
#include "Teddy.hh"

#include <iostream>

Object	**MyUnitTests()
{
  Object	*tab = new array(2);
  Object	*Bears = new Teddy("20", "brown", "MagicBear", "HappyTeddy", false);
  Object	*Marc = new LittlePony("50", "pink", "UnicorOfDrug", "gay pony", true);

  std::cout << Bears << std::endl;
  std::cout << Marc << std::endl;
  Marc.isTaken();
  Bears.isTaken();
  std::cout << "The BIG  pony weight: " << Bears.getWeight() << " and it's only " << Marc.getWeight() << " for Teddy." << std::endl;
  Bears.isTaken();
  Bears.isTaken();
  std::cout << "Is it " << Marc.getBrand() << " which transforms Teddy on " << Bears.getTitle() << "." << std::endl;
  std::cout << "When " << Bears.getTitle() << "saw the " << Marc.getColor() << " color of the pony, he said: HA!... GAAAAAAAAAYYYYYY! because he is " << Bears.getColor()  << std::endl;
  Marc.isTaken();
  std::cout << Bears << std::endl;
  return (*Object);
}

int	main()
{
  Object	*tab[2];
  Toy		Fun(42, "white", "Atari", "Pong");

  std::cout << Fun << std::endl;
  std::cout << "This Toy is called " << Toy.getTitle() << " developped by  " << Toy.getBrand() << " with one ball and two line " << Toy.getColor() << ". And I don't know why but " << getWeight() << std::endl;
  tab = MyUnitTests();
  (Teddy)tab[0];
  (Pony)tab[1];
  std::cout << "All information by tab of Bears "  << tab[0] << std::endl;
  std::cout << "All information by tab of Pony "  << tab[1] << std::endl;
  std::cout << "The BIG  pony weight: " << tab[0].getWeight() << " and it's only " << tab[1].getWeight() << " for Teddy." << std::endl;
  tab[1].isTaken();
}
