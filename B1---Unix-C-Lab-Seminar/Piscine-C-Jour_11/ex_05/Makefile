##
## Makefile for Makefile in /home/user/rendu/Piscine-C-Jour_11/ex_05
##
## Made by 
## Login   
##
## Started on  Mon Mar 24 10:01:34 2014 
## Last update Mon Mar 24 16:16:16 2014 
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS 	+= -ansi -pedantic
CFLAGS	+= -I.

NAME	= my_advanced_do-op

SRCS	= doop.c \
	  my_fun.c \
	  my_nbr.c \
	  operations.c \

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
