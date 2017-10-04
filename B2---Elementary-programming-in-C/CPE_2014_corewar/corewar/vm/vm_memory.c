/*
** vm_memory.c for  in /home/viterb_c/rendu/CPE_2014_corewar/corewar
** 
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
** 
** Started on  Sat Aug 16 13:07:04 2014 charles viterbo
** Last update Sat Aug 30 23:15:16 2014 charles viterbo
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "op.h"
#include "utils.h"

/*
** brief : initialize the VM's memory
** return : an unsigned char *, our memory
*/
unsigned char	*init_memory(void)
{
  int		i;
  unsigned char	*mem;

  i = -1;
  mem = my_malloc(MEM_SIZE);
  while (++i < MEM_SIZE)
    mem[i] = 0;
  return (mem);
}

/*
** brief : display the VM's memory, usefull for -dump
** @mem : the memory
*/
void	print_memory(unsigned char *mem)
{
  int	i;

  i = 0;
  display_hexa(i, "0123456789ABCDEF", 16, 8);
  my_write(1, " : ", 3);
  while (i < MEM_SIZE)
    {
      if (i % 32 == 0 && i != 0)
	{
	  my_write(1, "\n", 1);
	  display_hexa(i , "0123456789ABCDEF", 16, 8);
	  my_write(1, " : ", 3);
	}
      display_hexa(mem[i], "0123456789ABCDEF", 16, 1);
      my_write(1, " ", 1);
      ++i;
    }
  my_write(1, "\n", 1);
}

/*
** brief : from a file .cor this function reads and
** copies it in the VM's memory
** @mem : VM's memory
** @cor : the file .cor
** @pos : the position of the champion
** @champ : the total number of champion for the VM
*/
void	write_code_in_mem(unsigned char *mem, char *cor,
			  int pos)
{
  char	buff[8];
  int	my_fd;
  int	i;
  int	j;

  j = pos;
  my_fd = my_open(cor, O_RDONLY, 0);
  my_lseek(my_fd, 4 + 4 + PROG_NAME_LENGTH + COMMENT_LENGTH , SEEK_SET);
  while (read(my_fd, buff, 8))
    {
      i = 0;
      while (i < 8)
        mem[j++] = buff[i++];
    }
  my_close(my_fd, cor);
}
