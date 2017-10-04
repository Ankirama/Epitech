/*
** String.h for string_meow in /home/mar_b/rendu/piscine_cpp_d03/ex00
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Fri Jan  9 09:17:53 2015 Fabien Martinez
** Last update Fri Jan  9 14:04:26 2015 Fabien Martinez
*/

#ifndef STRING_H_
#define STRING_H_

#include <sys/types.h>

typedef struct	s_string
{
  char		*str;
  void		(*assign_s)(struct s_string *this, struct s_string const *str);
  void		(*assign_c)(struct s_string *this, char const *s);
  char		(*at)(struct s_string *this, size_t pos);
  void		(*append_s)(struct s_string *this, struct s_string const* ap);
  void		(*append_c)(struct s_string *this, char const* ap);
  void		(*clear)(struct s_string* this);
  int		(*compare_s)(struct s_string *this, const struct s_string* str);
  int		(*compare_c)(struct s_string *this, char const* str);
  int		(*size)(struct s_string* this);
  size_t	(*copy)(struct s_string* this, char* s, size_t n, size_t pos);
  char const*	(*c_str)(struct s_string* this);
  int		(*empty)(struct s_string* this);
  int		(*find_s)(struct s_string* this, const struct s_string *str, size_t pos);
  int		(*find_c)(struct s_string* this, char const* str, size_t pos);
  void		(*insert_c)(struct s_string * this, size_t pos, char const* str);
  void		(*insert_s)(struct s_string * this, size_t pos, struct s_string const* str);
  int		(*to_int)(struct s_string * this);
}		String;

void	StringInit(String* this, char const * s);
void	StringDestroy(String* this);

#endif /* !STRING_H_ */
