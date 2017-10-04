##
## Makefile for Makefile in /home/user/rendu/colle4_
##
## Made by 
## Login   
##
## Started on  Tue Sep 16 19:00:57 2014 
## Last update Tue Sep 16 22:15:57 2014 
##

CC	= gcc

RM	= rm -f

CFLAGS	= -W -Wall -Wextra

NAME	= game_of_life

SRCS	= main.c\
	  nbr.c\
	  fun.c\
	  life.c\
	  my_tab.c\
	  my_aff_tab.c

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
