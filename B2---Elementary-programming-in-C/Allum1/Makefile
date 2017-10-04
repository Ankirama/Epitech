##
## Makefile for Makefile in /home/mar_b/rendu/PSU_2013_minishell1
##
## Made by mar_b mar_b
## Login   <mar_b@epitech.net>
##
## Started on  Mon Jun 16 02:53:30 2014 mar_b mar_b
## Last update Wed Jul  9 21:52:33 2014 mar_b mar_b
##

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

CFLAGS	+= -I. -I./graph

LDFLAGS	= -lSDL -lSDL_ttf -lSDL_image

NAME	= allum1

SRCS	= main.c\
	  ia.c\
	  list.c\
	  calc.c\
	  utils.c\
	  message.c\
	  str.c\
	  graph/draw.c\
	  graph/font.c\
	  graph/init.c\
	  graph/input.c\
	  graph/graph.c\
	  graph/start.c\
	  graph/game.c

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
