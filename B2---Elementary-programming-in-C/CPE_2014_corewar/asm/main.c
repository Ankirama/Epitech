/*
** main.c for main in /home/mar_b/rendu/CPE_2014_corewar
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Jul 15 14:50:51 2014 mar_b mar_b
** Last update Thu Aug 28 12:09:06 2014
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "utils.h"
#include "asm_utils.h"
#include "parsing.h"
#include "write_file.h"
#include "op.h"
#include "asm.h"

/*
** brief: this function will create the name .cor
** @file: the file name
** @pos: if == -1 then ther isn't a .s else the .s' position
** return: return the file.cor
*/
static char	*_my_dot_cor(char *file, int pos)
{
  char		*name;
  int		i;

  i = -1;
  if (pos >= 0)
    name = my_malloc(sizeof(char) * (my_strlen(file) + 3));
  else
    name = my_malloc(sizeof(char) * (my_strlen(file) + 5));
  if (pos >= 0)
    {
      while (++i < pos)
	name[i] = file[i];
    }
  else
    {
      while (++i < my_strlen(file))
	name[i] = file[i];
    }
  name[i] = '\0';
  my_strcat(".cor", name);
  return (name);
}

/*
** brief: it will create our name (this one will check if there is .s)
** @file: the file name
** return: return the good name with .cor
*/
static char	*_choose_name(char *file)
{
  int		i;
  char		*name;

  i = my_strlen(file) - 1;
  while (i >= 0 && file[i] != '.')
    --i;
  if (file[i] == '.' && my_strcmp(&file[i], ".s"))
    name = _my_dot_cor(file, i);
  else
    name = _my_dot_cor(file, -1);
  return (name);
}

static void	_check_define()
{
  if (REG_NUMBER < 1)
    my_puterror(ERR_REG_NEG);
  if (IND_SIZE > 4 || REG_SIZE > 4 || IND_SIZE < 1 || REG_SIZE < 1)
    my_puterror(ERR_TOO_BIG);
}

int		main(int argc, char **argv)
{
  int		i;
  int		fd;
  char		*name;
  header_t	header;
  t_asm		*list;

  if (argc < 2)
    my_puterror("usage: ./asm file_name[.s] ...\n");
  _check_define();
  i = 0;
  while (++i < argc)
    {
      fd = my_open(argv[i], O_RDONLY, 0);
      list = my_parser(&header, fd);
      my_close(fd, argv[i]);
      name = _choose_name(argv[i]);
      fd = my_open(name, O_CREAT | O_WRONLY | O_TRUNC, PERM);
      write_file(list, fd, &header, argv[i]);
      my_close(fd, name);
      free(name);
      let_it_go(list);
    }
  return (0);
}
