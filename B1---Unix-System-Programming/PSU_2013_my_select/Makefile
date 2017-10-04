##
## Makefile<2> for make in /home/mar_b/rendu/CPE_2013_Pushswap
##
## Made by mar_b mar_b
## Login   <mar_b@epitech.net>
##
## Started on  Sat May 17 19:53:37 2014 mar_b mar_b
## Last update Tue May 20 13:49:54 2014 mar_b mar_b
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wall -Werror -Wextra
CFLAGS	+= -ansi -pedantic

LDFLAGS	= -lncurses

NAME	= my_select

SRCS	= my_select.c\
	  my_check.c\
	  my_cursor.c\
	  my_mode.c\
	  my_fun.c\
	  my_list.c\
	  my_list2.c\
	  my_error.c\
	  my_termcaps.c\
	  my_free.c

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
