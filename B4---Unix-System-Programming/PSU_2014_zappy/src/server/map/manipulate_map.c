/*
** manipulate_map.c for  in /home/viterb_c/rendu/PSU_2014_zappy/src/server
** 
** Made by CHARLES VITERBO
** Login   <viterb_c@epitech.net>
** 
** Started on  Thu Jun 18 09:20:35 2015 CHARLES VITERBO
** Last update Sun Jul  5 17:25:03 2015 CHARLES VITERBO
*/

# include "manipulate_map.h"
# include "actions.h"

/*
** @brief initialize our map
**
** @param map our game's map
** @param size our map's size
**
** @return 1
*/
static int	init_map(t_map *map, unsigned int size)
{
  unsigned int	i;

  i = -1;
  while (++i < size)
    {
      map->map[i].food = 0;
      map->map[i].stones[ID_LINEMATE] = 0;
      map->map[i].stones[ID_DERAUMERE] = 0;
      map->map[i].stones[ID_SIBUR] = 0;
      map->map[i].stones[ID_MENDIANE] = 0;
      map->map[i].stones[ID_PHIRAS] = 0;
      map->map[i].stones[ID_THYSTAME] = 0;
      if ((map->map[i].players = create_root()) == NULL)
	return (-1);
    }
  return (0);
}

/*
** @brief it will generate food and stones on our map
** at the beginning of the game
**
** @param map struct map, contains our case, width and height
** @param nb_teams number of teams
** @pram client_start number of clients at the start
*/
int		generate_map(t_map *map)
{
  unsigned int	objects;
  unsigned int	size;
  unsigned int	contenu;

  objects = -1;
  size = map->height * map->width;
  if (init_map(map, size) == -1)
    return (-1);
  while (++objects <= ID_THYSTAME)
    {
      if (objects < ID_MENDIANE)
	contenu = size / POURC_COM + 1;
      else
	contenu = size / POURC_RARE + 1;
      while (contenu > 0)
	generate_object(map, size, objects, &contenu);
    }
  contenu = size / POURC_FOOD + 1;
  while (contenu > 0)
    generate_object(map, size, ID_MEAT, &contenu);
  return (0);
}

/*
**
** @brief it will randomly find a case, in our map, empty for the type
** of stones
**
** @param map struct map, contains our case, width and height
** @param map_size the size of our map
** @param type the type of stones / food
** @param tack stack of objects
*/
int	generate_object(t_map *map, int map_size,
			unsigned int type, unsigned int *stack)
{
  int	case_map;

  case_map = random_number(map_size);
  if (type <= ID_THYSTAME)
    map->map[case_map].stones[type]++;
  else
    map->map[case_map].food++;
  *stack = *stack - 1;
  return (case_map);
}

/*
** @brief drop an object on case number position
**
** @param map struct map, contains cases, width and height
** @param position the case's number
** @param type type of stones / food
*/
void	drop_object(t_map *map, unsigned int position, int type)
{
  if (type <= ID_THYSTAME)
    map->map[position].stones[type]++;
  else if (type == ID_MEAT)
    map->map[position].food++;
}

/*
** @brief take an object on the floor
**
** @param map struct map, contains cases, width and height
** @param position the case's number
** @param type type of stones or food
**
** @return : 0 if failed (no such type on case) else 1
*/
int	take_object(t_map *map, unsigned int pos, int type)
{
  if (type <= ID_THYSTAME)
    {
      if (map->map[pos].stones[type] == 0)
	return (0);
      else
	map->map[pos].stones[type] = map->map[pos].stones[type] - 1;
    }
  else
    {
      if (map->map[pos].food == 0)
	return (0);
      else
	map->map[pos].food = map->map[pos].food - 1;
    }
  return (1);
}
