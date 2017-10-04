/*
** main.c for main in /home/user/rendu/colle3_bob42
**
** Made by 
** Login   
**
** Started on  Tue Sep  9 19:09:23 2014 
** Last update Tue Sep  9 22:35:05 2014 
*/

#include "utils.h"
#include "calc.h"

int	main(int argc, char **argv)
{
  char	*tmp;
  if (argc != 2)
    my_puterror(ERR_MAIN);
  tmp = convert_minus(argv[1]);
  tmp = main_parser(tmp);
  my_write(1, tmp, my_strlen(tmp));
  my_write(1, "\n", 1);
  return (0);
}
