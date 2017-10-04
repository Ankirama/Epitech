/*
** main.c for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Wed Apr  1 11:40:32 2015 Fabien Martinez
*/

/*
** @file check_params.c
** @brief check / set param from command line args
**
** For each option the next arg is for the option ex:
** -p -s : -s is the -p's argument
**
** @author ankirama
** @version 0.1
*/

#include "check_params.h"

static t_opt_pos	g_fct_opt[NB_OPT] = {
  {"-p", 0, 0, MAX_VAL_PORT},
  {"-x", 0, 0, MAX_VAL_WIDTH},
  {"-y", 0, 0, MAX_VAL_HEIGHT},
  {"-n", 0, 0, MAX_VAL_TEAMS},
  {"-c", 0, 0, MAX_VAL_CLIENTS},
  {"-t", 0, 0, MAX_VAL_TIME},
  {"--debug", 0, 0, MAX_VAL_DEBUG}};

/*
** @brief Set an option
**
** It will set the option's position and check / add arguments
**
** @param argc size argv
** @param idx option index
** @param pos pointer to current pos in argv
** @param argv array given to our binary
** @return error id
*/
static int	_set_option(int argc, int idx, int *pos, char **argv)
{
  int		i;
  int		j;

  if (g_fct_opt[idx].pos != 0)
    return (ID_ERR_ALRD_USED);
  if ((g_fct_opt[idx].max_val == NO_LIMITS && argc - *pos < 1) ||
      (argc - *pos < g_fct_opt[idx].max_val))
    return (ID_ERR_NOT_ENG_ARG);
  g_fct_opt[idx].pos = *pos - 1;
  g_fct_opt[idx].nbr_val = g_fct_opt[idx].max_val != 0 ? 1 : 0;
  j = *pos;
  if (g_fct_opt[idx].max_val == NO_LIMITS)
    {
      while (++j < argc)
	{
	  i = 0;
	  while (i < NB_OPT && (i == idx || strcmp(g_fct_opt[i].opt, argv[j])))
	    ++i;
	  if (i < NB_OPT)
	    break;
	  ++g_fct_opt[idx].nbr_val;
	}
    }
  *pos = j + (g_fct_opt[idx].max_val == NO_LIMITS ? 0 : g_fct_opt[idx].nbr_val);
  return (ID_NO_ERR);
}

/*
** @brief display error message
**
** It will display an error message from our id error
**
** @param error id error to display right message
** @param i index for g_fct_opt
** @param j index for argv
** @param argv string array
** @return 0 if error = ID_NO_ERR, else 1
*/
static int	_display_error(int error, int i, int j, char **argv)
{
  if (error == ID_ERR_NO_OPT)
    my_printf(2, "Error [%s]: %s\n", argv[j], ERR_NO_OPT);
  else if (error == ID_ERR_ALRD_USED)
    my_printf(2, "Error [%s]: %s\n", g_fct_opt[i].opt, ERR_ALRD_USED);
  else if (error == ID_ERR_OPT_NOT_SET)
    my_printf(2, "Error [%s]: %s\n", g_fct_opt[i].opt, ERR_OPT_NOT_SET);
  else if (error == ID_ERR_NOT_ENG_ARG)
    my_printf(2, "Error [%s]: %s\n", g_fct_opt[i].opt, ERR_NOT_ENG_ARG);
  return (error != 0 ? 1: 0);
}

/*
** @brief check and set options
**
** It will check every argv and set options if we found it.
** Check errors too (except wrong type like string instead of int etc..)
**
** @param argc argv's size
** @param argv string array
** @param error set to 0 and used to catch error
** @param j set to 1 to ignore binary name from argv (argv[0])
** @return error value (1 -> error, 0 -> no error)
*/
static int	_check_options(int argc, char **argv, int error, int j)
{
  int		i;

  while (j < argc && !error)
    {
      i = 0;
      while (i < NB_OPT && strcmp(g_fct_opt[i].opt, argv[j]))
	++i;
      if (i == NB_OPT)
	error = ID_ERR_NO_OPT;
      else
	{
	  ++j;
	  error = _set_option(argc, i, &j, argv);
	}
    }
  if (error == ID_NO_ERR)
    {
      i = 0;
      while (i < NB_OPT - 1 && g_fct_opt[i].pos != 0)
	++i;
      if (i < NB_OPT - 1)
	error = ID_ERR_OPT_NOT_SET;
    }
  return (_display_error(error, i, j, argv));
}

/*
** @brief free our option struct
**
** @param opt_arg our struct we will free
** @return 0
*/
int	free_options(t_opt_arg *opt_arg)
{
  free(opt_arg->port);
  free_wordtab(opt_arg->teams);
  free(opt_arg);
  return (0);
}

/*
** @brief Set options from arguments line (argv)
**
** It will check every element in argv.
** check if we have all options and their argument(s)
** display error message if any problem.
**
** @param argc argv's size
** @param argv array string
** @return a structure with all informations formated
*/
t_opt_arg	*set_options(int argc, char **argv)
{
  t_opt_arg	*opt_arg;
  int		error;

  if (_check_options(argc, argv, ID_NO_ERR, 1) != 0)
    return (NULL);
  error = 0;
  if (!(opt_arg = my_malloc(sizeof(*opt_arg))) ||
      !(opt_arg->port = my_strdup(argv[g_fct_opt[ID_OPT_PORT].pos + 1])))
    error = 1;
  error = error ? error :
    conv_to_unint(&(opt_arg->x), argv[g_fct_opt[ID_OPT_WIDTH].pos + 1]);
  error = error != 0 ? error :
    conv_to_unint(&(opt_arg->y), argv[g_fct_opt[ID_OPT_HEIGHT].pos + 1]);
  opt_arg->teams = split_array(argv, g_fct_opt[ID_OPT_TEAMS].pos + 1,
			       g_fct_opt[ID_OPT_TEAMS].nbr_val);
  error = error != 0 ? error : (opt_arg->teams == NULL ? 1 : 0);
  error = error != 0 ? error :
    conv_to_unint(&(opt_arg->clients), argv[g_fct_opt[ID_OPT_CLIENTS].pos + 1]);
  error = error != 0 ? error :
    conv_to_unint(&(opt_arg->time), argv[g_fct_opt[ID_OPT_TIME].pos + 1]);
  opt_arg->debug = g_fct_opt[ID_OPT_DEBUG].pos != 0 ? 1 : 0;
  return (error != 0 ? NULL : opt_arg);
}
