/*
** parse_vm.c for  in /home/teyssa_r/rendu/CPE_2014_corewar
** 
** Made by teyssa_r teyssa_r
** Login   <teyssa_r@epitech.net>
** 
** Started on  Mon Jul 21 15:06:58 2014 teyssa_r teyssa_r
** Last update Sun Aug 31 23:25:40 2014 chenev_d chenev_d
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "parser.h"
#include "parse.h"
#include "utils.h"
#include "op.h"
#include "vm.h"

int	my_strlen_arr(char **my_cor)
{
  int	i;

  i = 0;
  while (my_cor[i])
    i++;
  return (i);
}

/*
** brief: for read the header and the size
** @fd: our file descriptor
*/
int		header_or_not(int fd)
{
  int		nbr;
  int		i;
  unsigned char	car[4];

  i = 0;
  nbr = 0;
  my_read(fd, car, 4);
  while (i < 4)
    nbr = (nbr << 8) + car[i++];
  return (nbr);
}

/*
** brief: for parse_vm
** @my_cor: our file .cor
*/
t_list		*parse_vm(t_option *opt, unsigned char *mem)
{
  char		**my_cor;
  int		i;
  int		fd;
  t_list	*champ;

  champ = make_list();
  i = 0;
  my_cor = opt->my_cor;
  while (i < my_strlen_arr(my_cor))
    {
      fd = my_open(my_cor[i], O_RDONLY, 0);
      add_before(&champ, fd, i, opt->my_n_number[i]);
      i++;
    }
  sort_adress(opt);
  good_size(opt, champ);
  place_champ(opt, champ, mem);
  champ->nb_tour = opt->dump;
  champ->root = opt->number_cor;
  return (champ);
}
