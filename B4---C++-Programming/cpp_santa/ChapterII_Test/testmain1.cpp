//
// main.cpp for main in /home/chenev_d/rendu/cpp_santa/ChapterII_Test
// 
// Made by Alexandre Chenevier
// Login   <chenev_d@epitech.net>
// 
// Started on  Fri Jan 16 23:47:00 2015 Alexandre Chenevier
// Last update Sat Jan 17 15:59:55 2015 Alexandre Chenevier
//

#include "../Object.hh"
#include "../Toy.hh"
#include "../LittlePony.hh"
#include "../Teddy.hh"

#include <iostream>

Object	**MyUnitTests()
{
  Object	**tab = new Object*[2];

  Object	*Bears = new Teddy(20, TEDDY, "brown", "MagicBear", "HappyTeddy", true);
  Object	*Marc = new LittlePony(50, LITTLE_PONY, "pink", "UnicorOfDrug", "gay pony", true);

  Object	*Ted = new Teddy(20, TEDDY, "brown", "Magic", "TED", true);

  tab[0] = Bears;
  tab[1] = Marc;
  std::cout << "LOL" << std::endl;
  std::cout << *(Teddy *)Bears << std::endl;
  std::cout << *(LittlePony *)Marc << std::endl;
  Marc->isTaken();
  Bears->isTaken();
  std::cout << "The BIG  pony weight: " << Bears->getWeight() << " and it's only " << Marc->getWeight() << " for Teddy." << std::endl;
  Bears->isTaken();
  Bears->isTaken();
  std::cout << "Is it " << ((LittlePony *)Marc)->getBrand() << " which transforms Teddy on " << ((LittlePony *)Bears)->getTitle() << "." << std::endl;
  std::cout << "When " << ((Teddy *)Bears)->getTitle() << " saw the " << ((Teddy *)Marc)->getColor() << " color of the pony, he said: HA!... GAAAAAAAAAYYYYYY! because he is " << ((Teddy *)Bears)->getColor()  << std::endl;
  Marc->isTaken();
  std::cout << *(Teddy *)Ted << std::endl;
  return (tab);
}

int	main()
{
  int	i;
  Teddy	Ted;
  LittlePony	Pony;

  i = 0;
  Object	**tab;

   tab = MyUnitTests();
  std::cout << "----------------BY TAB---------------" << std::endl;
  std::cout << "All information by tab of Bears "  << *(Teddy *)tab[0] << std::endl;
  std::cout << "All information by tab of Pony "  << *(LittlePony *)tab[1] << std::endl;
  while (i < 2)	{
    if (tab[i]->getType() == LITTLE_PONY)	{
      Pony = *(LittlePony *)tab[i];
      std::cout << "It 's a poney !!" << std::endl;
      std::cout << Pony << std::endl;
    }
    else if (tab[i]->getType() == TEDDY)	{
      Ted = *(Teddy *)tab[i];
      std::cout << "It's a bear !!" << std::endl;
      std::cout << Ted << std::endl;
    }
    else
      std::cout << "Dafuck ?" << std::endl;
    i++;
  }
  return (0);
}
