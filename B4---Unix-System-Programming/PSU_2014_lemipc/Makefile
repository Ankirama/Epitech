##
## Makefile for Makefile in /home/ankirama
## 
## Made by Fabien martinez
## Login   <ankirama@epitech.net>
## 
## Started on  Sun Feb 22 10:48:37 2015 Fabien martinez
## Last update Sun Mar  8 15:25:25 2015 CHARLES VITERBO
##

CC = gcc

RM = rm -f

CFLAGS = -W -Wall -Werror -Wextra

LDFLAGS	= -lSDL2

NAME = lemipc

SRCS =	main.c\
	utils.c\
	utils2.c\
	utils3.c\
	team.c\
	position.c\
	sdl.c\
	ai.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

%.o:	%.c
	$(CC) $(LDFLAGS) -c -o $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
