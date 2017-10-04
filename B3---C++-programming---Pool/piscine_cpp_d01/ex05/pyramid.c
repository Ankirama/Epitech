/*
** pyramid.c for pyramid in /home/mar_b/rendu/piscine_cpp_d01/ex05
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Jan  7 16:38:12 2015 Fabien Martinez
** Last update Wed Jan  7 23:06:49 2015 Fabien Martinez
*/

/*
** I love recursion
*/
int	rekt_your_mom(int x, int y, int path, int size, int **map)
{
  int	i;
  int	j;

  path += map[y][x];
  ++y;
  if (y < size)
    {
      i = rekt_your_mom(x, y, path, size, map);
      j = rekt_your_mom(x + 1, y, path, size, map);
      if (i < j)
	return (i);
      return (j);
    }
  return (path);
}

int	pyramid_path(int size, int ** map)
{
  return rekt_your_mom(0, 0, 0, size, map);
}
