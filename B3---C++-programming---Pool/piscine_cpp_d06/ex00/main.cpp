//
// main.cpp for meow in /home/mar_b/rendu/piscine_cpp_d06/ex00
//
// Made by Fabien Martinez
// Login   <mar_b@epitech.net>
//
// Started on  Mon Jan 12 10:28:36 2015 Fabien Martinez
// Last update Mon Jan 12 16:47:26 2015 Fabien Martinez
//

#include <iostream>
#include <fstream>

char	error_msg(char *file)
{
  if (!file)
    {
      std::cout << "my_cat: Usage : ./my_cat file [...]" << std::endl;
      return (0);
    }
  else
    {
      std::cerr << "my_cat: " << file << ": No such file or directory" << std::endl;
      return (1);
    }
}

void		read_file(char *filename)
{
  std::ifstream	file(filename, std::ios::in);
  std::string	s;

  if (file)
    {
      while (getline(file, s, '\0'));
      std::cout << s;
      file.close();
    }
  else
    (void)error_msg(filename);
}

int	main(int argc, char **argv)
{
  int	i;

  if (argc == 1)
    return (error_msg(NULL));
  i = 0;
  while (++i < argc)
    read_file(argv[i]);
  return (0);
}
