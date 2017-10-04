/*
** my_date.c for my_date in /home/mar_b/rendu/PSU_2013_my_ls
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Sat Apr 26 19:00:41 2014 Fabien Martinez
** Last update Thu May  1 16:48:25 2014 Fabien Martinez
*/

#include "my_ls.h"

/*
** This function will return the year of the char* or the year of the system
*/
char	*current_year(char *my_date)
{
  char		*curr_y;
  int		i;
  int		j;
  time_t	curr_t;
  char		*my_year;

  if (my_date == NULL)
    {
      if ((curr_t = time(NULL)) == -1)
	my_puterror();
    }
  curr_y = my_date == NULL ? ctime(&curr_t) : my_date;
  i = strlen(curr_y) - 2;
  while (curr_y[i - 1] != ' ')
    i -= 1;
  j = 0;
  if ((my_year = malloc(strlen(curr_y) - i)) == NULL)
    my_puterror();
  while (curr_y[i] && curr_y[i] != '\n')
    my_year[j++] = curr_y[i++];
  my_year[j] = '\0';
  return (my_year);
}

/*
** Will check if file_year == current_year
*/
static char	my_formatdate(char *file_y, char *curr_y)
{
  int	i;

  i = 0;
  while (file_y[i] && curr_y[i] && file_y[i] == curr_y[i])
    i += 1;
  return (curr_y[i] - file_y[i]);
}

/*
** if the file_year != current_year then will display it
*/
static void	my_standard_year(char *str, char *my_year)
{
  int		i;

  i = 4;
  while (str[i + 2] && str[i + 3] != ':')
    my_printf(g_fd, "%c", str[i++]);
  my_printf(g_fd, " %s ", my_year);
}

/*
** if the file_year == current_year then will display the hh:mm format
*/
static void	my_standard_date(char *str)
{
  int		i;
  int		end;

  i = 4;
  end = strlen(str) - 2;
  while (str[end] != ':')
    end -= 1;
  while (i < end)
    {
      my_printf(g_fd, "%c", str[i]);
      i += 1;
    }
  my_printf(g_fd, " ");
}

/*
** Will print date in Apr 23 12:42 format or Apr 23 1942 format
*/
char	my_putdate(char *str, char *curr_year)
{
  char	*my_year;

  if ((my_year = current_year(str)) == NULL)
    my_puterror();
  if (my_formatdate(my_year, curr_year) != 0)
    my_standard_year(str, my_year);
  else
    my_standard_date(str);
  free(my_year);
  free(curr_year);
  return (0);
}
