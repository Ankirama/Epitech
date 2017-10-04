/*
** algo.c for let it go in /home/mar_b/rendu/colle5_mar_b
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Sep 23 19:02:19 2014 mar_b mar_b
** Last update Tue Sep 23 22:35:13 2014 mar_b mar_b
*/

#include <stdio.h>
#include <stdlib.h>
#include "algo.h"
#include "utils.h"

/*
** left = 1000
** right = 100
** bot = 10
** top = 1
*/
int	next_is_ok(t_boogle *boogle, char letter, int x, int y)
{
  int	left;
  int	right;
  int	top;
  int	bot;
  int	nbr_pos;

  nbr_pos = 0;
  left = x + y * boogle->sizeline - 1;
  right = x + y * boogle->sizeline + 1;
  bot = x + (y - 1) * boogle->sizeline;
  top = x + (y + 1) * boogle->sizeline;
  if (left >= 0 && boogle->tab[left] == letter)
    nbr_pos += 1000;
  if (right < (boogle->sizeline * boogle->sizeline) &&
      boogle->tab[right] == letter)
    nbr_pos += 100;
  if (bot >= 0 && boogle->tab[bot] == letter)
    nbr_pos += 10;
  if (top < (boogle->sizeline * boogle->sizeline) &&
      boogle->tab[top] == letter)
    nbr_pos += 1;
  return (nbr_pos);
}

static char	_my_new_pos(t_boogle *boogle, char *word, int x, int y)
{
  int		dir;
  int		left;
  int		right;
  int		top;
  int		bot;

  left = x + y * boogle->sizeline - 1;
  right = x + y * boogle->sizeline + 1;
  bot = x + (y - 1) * boogle->sizeline;
  top = x + (y + 1) * boogle->sizeline;
  dir = next_is_ok(boogle, word[0], x, y);
  if (dir / 1000 != 0 && my_find_word(boogle, word, left % boogle->sizeline,
						  left / boogle->sizeline))
    return (1);
  if (dir / 100 != 0 && my_find_word(boogle, word, right % boogle->sizeline,
						 right / boogle->sizeline))
    return (1);
  if (dir / 10 != 0 && my_find_word(boogle, word, bot % boogle->sizeline,
						bot / boogle->sizeline))
    return (1);
  if (dir % 10 == 1 && my_find_word(boogle, word, top % boogle->sizeline,
						top / boogle->sizeline))
    return (1);
  return (0);
}

static char	_my_next_find(t_boogle *boogle, char *word, int x, int y)
{
  if (x == boogle->sizeline - 1)
    return (my_find_word(boogle, word, 0, y + 1));
  else
    return (my_find_word(boogle, word, x + 1, y));
}

char	my_find_word(t_boogle *boogle, char *word, int x, int y)
{
  int	pos;

  pos = x + y * boogle->sizeline;
  if (word[0] == '\0')
    return (1);
  else if (pos >= boogle->sizeline * boogle->sizeline)
    return (0);
  else
    {
      if (boogle->tab[pos] == word[0])
	{
	  boogle->tab[pos] -= 32;
	  printf("POSITION : %d, letter : %c, word : %s\n", pos, boogle->tab[pos], word);
	  if (word[1] == '\0')
	    return (1);
	  if (next_is_ok(boogle, word[1], x, y) == 0)
	    {
	      printf("next-is-ok = 0\n");
	      boogle->tab[pos] += 32;
	      if (!my_strcmp(word, boogle->word))
		return (_my_next_find(boogle, word, x, y));
	      else
		return (0);
	    }
	  else
	    {
	      if (_my_new_pos(boogle, &word[1], x, y))
		{
		  printf("my_new_pos = 1\n");
		  return (1);
		}
	      else
		{
		  printf("my_new_pos != 1\n");
		  boogle->tab[pos] += 32;
		  return (_my_next_find(boogle, word, x, y));
		}
	    }
	}
      else
	return (_my_next_find(boogle, word, x, y));
    }
  return (0);
}
