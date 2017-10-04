##
## Makefile for Makefile in /home/ankirama
## 
## Made by Fabien martinez
## Login   <ankirama@epitech.net>
## 
## Started on  Sun Feb 22 10:48:37 2015 Fabien martinez
## Last update Wed Feb 25 13:08:07 2015 CHARLES VITERBO
##

CC = gcc

RM = rm -f

CFLAGS = -W -Wall -Werror -Wextra

LDFLAGS = -pthread

NAME = philo

SRCS =	main.c\
	state.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
