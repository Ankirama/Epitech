##
## Makefile for Makefile in /root/rendu/PSU_2013_minitalk
##
## Made by mar_b mar_b
## Login   <mar_b@epitech.net>
##
## Started on  Mon Aug  4 23:28:41 2014 mar_b mar_b
## Last update Wed Aug  6 00:56:31 2014
##

ROOT= ../.

CC	= gcc

RM	= rm -f

CFLAGS	= -Wextra -Wall -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -I. -I../utils
CFLAGS	+= -D _POSIX_C_SOURCE -D _BSD_SOURCE

NAME	= server

SRCS	= main.c\
	  ../utils/str.c\
	  ../utils/error.c\
	  ../utils/nbr.c\
	  ../utils/signal.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS)

%.o:	%.c
	@tput setaf 3
	@tput bold
	@printf "Compiling "
	@tput setaf 4
	@printf "%s\n" $(patsubst $(ROOT)/%,%,$^)
	@$(CC) $(CFLAGS) -c -o $@ $^
	@tput sgr0
	@tput cuf 68
	@tput cuu1
	@printf "[ "
	@tput setf 2
	@tput bold
	@printf "ok"
	@tput sgr0
	@printf " ]\n"

clean:
	@$(RM) $(OBJS)
	@tput setaf 3
	@tput bold
	@printf "Removing \t "
	@tput setaf 4
	@printf " File [.o]...\n"
	@tput sgr0
	@tput cuf 68
	@tput cuu1
	@printf "[ "
	@tput setaf 2
	@tput bold
	@printf "ok"
	@tput sgr0
	@printf " ]\n"

fclean: clean
	@$(RM) $(NAME)
	@tput setaf 3
	@tput bold
	@printf "Removing \t "
	@tput setaf 4
	@printf " File %s...\n", $(NAME)
	@tput sgr0
	@tput cuf 67
	@tput cuu1
	@printf "[ "
	@tput setaf 2
	@tput bold
	@printf "ok"
	@tput sgr0
	@printf " ]\n"


re: fclean all

debug: CFLAGS += -g3
debug: re

.PHONY: all clean fclean re debug
