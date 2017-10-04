/*
** my_proto.h for my_proto in /home/mar_b/rendu/Piscine-C-colles-Semaine_03
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Sat Mar 29 17:13:33 2014 Fabien Martinez
** Last update Sat Mar 29 17:40:33 2014 Fabien Martinez
*/

#ifndef MY_PROTO_H_
# define MY_PROTO_H_
# define BUFF_SIZE (4096)

char	my_width(char *, int *, char *);
int	my_height(char *, int);
void	my_display_str(char *, int, int);
void	my_colle_str12345();
void	my_colle_str345(int, int);
void	my_colle2(char *, int, int);
void	my_colle(char *, int, int);
int	    my_loop(char *, int *, int *);
void	my_init(char *);
int	 init_variables(int *, int *, char *, char *);
void	my_part1(int);
void	my_part2(int);
void	my_part3(int);
void	my_part4(int);
void	my_part5(int);
void	my_part6(int);
void	my_part7(int);
int	my_print_error(int, char *);

#endif /* !MY_PROTO_H_ */
