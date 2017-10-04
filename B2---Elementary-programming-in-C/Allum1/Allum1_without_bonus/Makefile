##
## Makefile for Makefile in /home/mar_b/rendu/PSU_2013_minishell1
##
## Made by mar_b mar_b
## Login   <mar_b@epitech.net>
##
## Started on  Mon Jun 16 02:53:30 2014 mar_b mar_b
## Last update Thu Jul  3 15:54:16 2014 mar_b mar_b
##

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

NAME	= allum1

SRCS	= main.c\
	  game.c\
	  ia.c\
	  list.c\
	  calc.c\
	  utils.c\
	  message.c\
	  str.c

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
