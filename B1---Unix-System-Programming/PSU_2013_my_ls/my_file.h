/*
** my_file.h for my_file.h in /home/mar_b/rendu/PSU_2013_my_ls
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Apr 23 20:48:48 2014 Fabien Martinez
** Last update Tue Apr 29 17:10:49 2014 Fabien Martinez
*/

#ifndef MY_FILE_H_
# define MY_FILE_H_

typedef struct		s_my_file
{
  unsigned char		type;
  char			*name;
  char			*path;
  struct s_my_file	*next;
}			t_my_file;

t_my_file	*my_add_file(t_my_file *files, char *curr, char *path,
			     unsigned char type);

#endif /* !MY_FILE_H_ */
