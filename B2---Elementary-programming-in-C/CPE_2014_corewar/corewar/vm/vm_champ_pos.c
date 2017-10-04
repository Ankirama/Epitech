/*
** vm_champ_pos.c for  in /home/viterb_c/rendu/CPE_2014_corewar/corewar
** 
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
** 
** Started on  Tue Aug 26 18:57:13 2014 charles viterbo
** Last update Sun Aug 31 23:26:33 2014 chenev_d chenev_d
*/

#include <stdlib.h>
#include <struct.h>
#include "vm.h"
#include "utils.h"
#include "struct.h"
#include "op.h"

/*
** brief : this function will swap 4 int, 2 in my_a_adress and 2 in my_n_number
** @max : the index of the max (relative to adress);
** @min : the index of the min (relative to adress);
** @option : my struct option
*/
static	void	swap_int_char(const int max, const int min, t_option *option)
{
  int		tmp;
  char		*cor;

  tmp = option->my_a_adress[max];
  option->my_a_adress[max] = option->my_a_adress[min];
  option->my_a_adress[min] = tmp;
  tmp = option->my_n_number[max];
  option->my_n_number[max] = option->my_n_number[min];
  option->my_n_number[min] = tmp;
  cor = option->my_cor[max];
  option->my_cor[max] = option->my_cor[min];
  option->my_cor[min] = cor;
}

/*
** brief : this function will sort the int** my_a_adress, so we can compare
** the size of our champions
** @option : my struct option
*/
void	sort_adress(t_option *option)
{
  int	i;
  int	swap;

  swap = 1;
  if (option->my_a_adress != NULL)
    {
      while (swap == 1)
	{
	  i = 0;
	  swap = 0;
	  while (option->my_a_adress[i + 1] != -1)
	    {
	      if (option->my_a_adress[i] > option->my_a_adress[i + 1])
		{
		  swap_int_char(i, i + 1, option);
		  swap = 1;
		}
	      i++;
	    }
	}
    }
}

/*
** brief : this function will compare the size between two -a, the closest,
** and the size of a champion. If it's too small there is an error
** @option : the struct that will contain our -a
** @root_chp : the list that will contain our champions and their size
*/
void		good_size(t_option *option, t_list *root_chp)
{
  int		i;
  int		space;
  t_list	*champ;

  i = 0;
  if (option->my_a_adress != NULL)
    {
      while (option->my_a_adress[i + 1] != -1)
	{
	  champ = root_chp->next;
	  space = option->my_a_adress[i + 1] - option->my_a_adress[i];
	  while (champ != root_chp && champ->reg[0] != option->my_n_number[i])
	    champ = champ->next;
	  if (champ->chpm->prog_size > space)
	    my_puterror(ERR_SIZE);
	  i++;
	}
    }
  champ = root_chp->next;
  while (champ != root_chp)
    {
      if (champ->chpm->prog_size > (MEM_SIZE / 4))
	my_puterror(ERR_SIZE);
      champ = champ->next;
    }
}

/*
** brief : this function will place our champions in the memory
** it will depend if my_a_adress exist. If it exist we use it otherwise
** we place them to 0, 1/4, 1/2 and 3/4
** @option : the struct that contains all the informations about
** the number of champion and their adress
** @mem : our VM's memory
*/
void		place_champ(t_option *option, t_list *root,
			    unsigned char *mem)
{
  int		i;
  t_list	*champion;

  i = -1;
  champion = root->next;
  if (option->my_a_adress != NULL)
    {
      while (option->my_a_adress[++i] != -1)
	{
	  write_code_in_mem(mem, option->my_cor[i], option->my_a_adress[i]);
	  while (champion->reg[0] != option->my_n_number[i])
	    champion = champion->next;
	  champion->init_pos = option->my_a_adress[i];
	  champion->pc = option->my_a_adress[i];
	}
    }
  while (++i < option->number_cor)
    {
      write_code_in_mem(mem, option->my_cor[i], MEM_SIZE *
			i / option->number_cor);
      champion->init_pos = MEM_SIZE * i / option->number_cor;
      champion->pc = MEM_SIZE * i / option->number_cor;
      champion = champion->next;
    }
}
