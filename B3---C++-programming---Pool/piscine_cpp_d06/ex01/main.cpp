//
// main.cpp<2> for meow in /home/mar_b/rendu/piscine_cpp_d06/ex00
//
// Made by Fabien Martinez
// Login   <mar_b@epitech.net>
//
// Started on  Mon Jan 12 10:28:53 2015 Fabien Martinez
// Last update Mon Jan 12 13:21:34 2015 Fabien Martinez
//

#include <iostream>
#include <string>
#include <iomanip>

void	celsius_to_fahrenheit(float celsius)
{
  std::cout << std::setw(16) << std::right << std::fixed << std::setprecision(3) << celsius / 5.0 * 9.0 + 32 << std::setw(16) << std::right << "Fahrenheit" << std::endl;
}

void	fahrenheit_to_celsius(float fahrenheit)
{
  std::cout << std::setw(16) << std::right << std::fixed << std::setprecision(3) << 5.0 / 9.0 * ( fahrenheit - 32 ) << std::setw(16) << std::right << "Celsius" << std::endl;
}

int	main()
{
  float	temperature;
  std::string type;

  std::cin >> temperature;
  std::cin >> type;
  if (type == "Celsius")
    celsius_to_fahrenheit(temperature);
  else if (type == "Fahrenheit")
    fahrenheit_to_celsius(temperature);
  return (0);
}
