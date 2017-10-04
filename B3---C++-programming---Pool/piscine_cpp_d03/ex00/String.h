/*
** String.h for string_meow in /home/mar_b/rendu/piscine_cpp_d03/ex00
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Fri Jan  9 09:17:53 2015 Fabien Martinez
** Last update Fri Jan  9 11:12:58 2015 Fabien Martinez
*/

#ifndef STRING_H_
#define STRING_H_

typedef struct	s_string
{
  char		*str;
}		String;

void	StringInit(String* this, char const * s);
void	StringDestroy(String* this);

#endif /* !STRING_H_ */
