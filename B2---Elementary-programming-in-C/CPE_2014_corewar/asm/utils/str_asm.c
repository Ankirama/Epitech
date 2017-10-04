/*
** str_asm.c for str_asm in /home/mar_b/rendu/CPE_2014_corewar/asm
**
** Made by mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Wed Jul 23 00:24:19 2014 mar_b
** Last update Sun Aug 24 01:18:36 2014
*/

/*
** brief: it will compar s1 and s2, and ignore space and tabulation
** @s1: our first string
** @s2: our second one
** return : return 1 if s2[j] is the end, 0 else or return 2 if s1[i] is the end
*/
char	my_strcmp_pre_asm(const char *s1, const char *s2)
{
  int	i;
  int	j;

  i = 0;
  while (s1[i] != '\0' && (s1[i] == ' ' || s1[i] == '\t'))
    ++i;
  if (s1[i] == '\0')
    return (-1);
  j = -1;
  while (s2[++j] != '\0' && s1[i] != '\0' && s1[i] == s2[j])
    ++i;
  return (s2[j] == '\0');
}
