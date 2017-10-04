/*
** map.c for helloworldz in /home/mar_b/rendu/piscine_cpp_d02a/ex05
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu Jan  8 21:43:50 2015 Fabien Martinez
** Last update Fri Jan  9 08:34:59 2015 Fabien Martinez
*/

#include <stdlib.h>
#include <stdio.h>
#include "map.h"

unsigned int map_get_size(t_map map)
{
  if (map == NULL)
    return (0);
  else
    return (1 + map_get_size(map->next));
}

t_bool map_is_empty(t_map map)
{
  if (map == NULL)
    return (TRUE);
  else
    return (FALSE);
}

t_key_comparator key_cmp_container(t_bool store, t_key_comparator new_key_cmp)
{
  static t_key_comparator	key_cmp = NULL;
  if (store == TRUE)
    key_cmp = new_key_cmp;
  return (key_cmp);
}

int pair_comparator(void *first, void *second)
{
  t_key_comparator	key_cmp;

  key_cmp = key_cmp_container(FALSE, NULL);
  return (key_cmp(((t_pair *)first)->key, ((t_pair *)second)->key));
}

t_bool map_add_elem(t_map *map_ptr, void *key, void *value, t_key_comparator key_cmp)
{
  t_map	head;
  t_map	elt;
  t_pair *pair;

  head = *map_ptr;
  if ((elt = malloc(sizeof(elt))) == NULL)
    return (FALSE);
  if ((pair = malloc(sizeof(t_pair *))) == NULL)
    return (FALSE);
  pair->key = key;
  pair->value = value;
  elt->value = pair;
  elt->next = NULL;
  if (head == NULL)
    {
      *map_ptr = elt;
      return (TRUE);
    }
  while (head != NULL && head->next != NULL && key_cmp(key, ((t_pair *)(head->next->value))->key) != 0)
    head = head->next;
  if (head != NULL && head->next != NULL)
    ((t_pair *)(head->next)->value)->value = value;
  else
    head->next = elt;
  return (TRUE);
}

t_bool map_del_elem(t_map *map_ptr, void *key, t_key_comparator key_cmp)
{
  t_map head;

  head = *map_ptr;
  while (head != NULL && key_cmp(((t_pair *)(head->value))->key, key))
    head = head->next;
  return (list_del_node(map_ptr, head));
}

void *map_get_elem(t_map map, void *key, t_key_comparator key_cmp)
{
  t_map head;

  head = map;
  while (head != NULL && key_cmp(key, ((t_pair *)(head->value))->key) != 0)
    head = head->next;
  if (head == NULL)
    return (NULL);
  return (((t_pair *)(head->value))->value);
}
