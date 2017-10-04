/*
** utils.c for utils in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Sat Feb 21 08:55:40 2015 Fabien Martinez
** Last update Sat Feb 21 09:06:34 2015 Fabien Martinez
*/

#include <stdlib.h>
#include "my_printf.h"

void	usage(int argc)
{
  if (argc < 3)
    {
      my_printf(2, "Usage : ./client machine port\n");
      exit(EXIT_FAILURE);
    }
}
