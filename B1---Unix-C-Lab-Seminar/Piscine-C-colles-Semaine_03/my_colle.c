/*
** my_colle.c for my_colle.c in /home/mar_b/rendu/Piscine-C-colles-Semaine_03
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Sat Mar 29 00:09:34 2014 Fabien Martinez
** Last update Sun Mar 30 09:36:47 2014 Fabien Martinez
*/

#include "my.h"

void	my_display_str(char  *str, int width, int height)
{
  my_putstr(str);
  my_putchar('[');
  my_put_nbr(width);
  my_putchar(']');
  my_putchar(' ');
  my_putchar('[');
  my_put_nbr(height);
  my_putchar(']');
}

void	my_colle_str12345()
{
  my_display_str("[colle1-1] ", 0, 0);
  my_putstr(" || ");
  my_display_str("[colle1-2] ", 0, 0);
  my_putstr(" || ");
  my_display_str("[colle1-3] ", 0, 0);
  my_putstr(" || ");
  my_display_str("[colle1-4] ", 0, 0);
  my_putstr(" || ");
  my_display_str("[colle1-5] ", 0, 0);
}
void	my_colle_str345(int width, int height)
{
  my_display_str("[colle1-3] ", width, height);
  my_putstr(" || ");
  my_display_str("[colle1-4] ", width, height);
  my_putstr(" || ");
  my_display_str("[colle1-5] ", width, height);
}

void	my_colle2(char *my_coin, int width, int height)
{
  if (my_coin[2] == 'C')
    {
      my_display_str("[colle1-4] ", width, height);
    }
  else if (my_coin[2] == 'A')
    {
      my_display_str("[colle1-5] ", width, height);
    }
  else
    my_putstr("aucune");
}

void	my_colle(char *my_coin, int width, int height)
{
  if (my_coin[0] == '\n')
    {
      my_colle_str12345();
    }
  else if (my_coin[0] == 'o')
    {
      my_display_str("[colle1-1] ", width, height);
    }
  else if (my_coin[0] == '/' || my_coin[0] == '*')
    {
      my_display_str("[colle1-2] ", width, height);
    }
  else if (my_coin[0] == 'B')
    {
      my_colle_str345(width, height);
    }
  else if (my_coin[1] == 'A')
    {
      my_display_str("[colle1-3] ", width, height);
    }
  else
    my_colle2(my_coin, width, height);
}
