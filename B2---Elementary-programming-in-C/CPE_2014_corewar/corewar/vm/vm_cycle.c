/*
** vm_cycle.c for  in /home/viterb_c/rendu/CPE_2014_corewar/corewar/vm
** 
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
** 
** Started on  Sat Aug 30 23:23:16 2014 charles viterbo
** Last update Sun Aug 31 23:20:23 2014 charles viterbo
*/

#include "struct.h"
#include "op.h"


/*
** brief : this function will returns the number of champion who are alive
** @root : the list that contain all our champions
*/
static	int	nbr_champ_live(const t_list *root)
{
  t_list	*champion;
  int		nbr_champ;

  nbr_champ = 0;
  champion = root->next;
  while (champion != root)
    {
      if (champion->live == 1)
	++nbr_champ;
      champion->live = 0;
      champion = champion->next;
    }
  return (nbr_champ);
}

int	action_champion(t_list *champ, unsigned char *mem, int cycle)
{
  int	i;

  i = 0;
  (void)mem;
  if (cycle != champ->nb_tour && cycle != champ->nb_tour + 1)
    return (1);
  else if (cycle == champ->nb_tour + 1)
    {
      while (i < 16 && op_tab[i].code != mem[champ->pc])
	i++;
      if (i == 16)
	{
	  champ->nb_tour = cycle + 1;
	  champ->pc = champ->pc + 1;
	}
      else
	champ->nb_tour = cycle + op_tab[i].nbr_cycles - 1;
    }
  return (0);
}

/*
** brief : this function is our main cycle
** @root : our list with champ
** @mem : our memory
** limit : 0 (if just 1 champ) or 1 (if > 1 champ)
*/
int		main_cycle(t_list *root, unsigned char *mem, int limit)
{
  int		cycle;
  int		nb_champ;
  int		cycle_to_die;
  t_list	*champion;

  cycle = 1;
  cycle_to_die = CYCLE_TO_DIE;
  while (((cycle % cycle_to_die != 0 && nbr_champ_live(root) > limit) ||
	  (cycle % cycle_to_die != 0)) && (cycle < root->nb_tour ||
					   root->nb_tour == -1))
    {
      nb_champ = 0;
      while (++nb_champ <= 4)
	{
	  champion = root->next;
	  while (champion != root && champion->reg[0] != nb_champ)
	    champion = champion->next;
	  action_champion(champion, mem, cycle);
	}
      if (cycle % cycle_to_die * NBR_LIVE == 0)
	cycle_to_die = cycle_to_die - CYCLE_DELTA;
      ++cycle;
    }
  return (0);
}
