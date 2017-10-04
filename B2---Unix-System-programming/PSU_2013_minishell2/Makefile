##
## Makefile for MAKEFILE in /home/mar_b/minishell
##
## Made by mar_b mar_b
## Login   <mar_b@epitech.net>
##
## Started on  Tue Jun 24 08:52:45 2014 mar_b mar_b
## Last update Sun Aug  3 13:55:01 2014
##

ROOT	= ./

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Werror -Wextra

CFLAGS	+= -I. -I./parser -I./builtin -I./list -I./utils

NAME	= mysh

SRCS	= main.c\
	  my_check.c\
	  my_exec.c\
	  redirection.c\
	  pipe.c\
	  builtin/my_builtin.c\
	  builtin/my_cd.c\
	  builtin/my_env.c\
	  builtin/my_pwd.c\
	  list/list.c\
	  parser/parser.c\
	  parser/pre_parser.c\
	  parser/my_str_to_wordtab.c\
	  utils/my_error.c\
	  utils/my_free.c\
	  utils/my_str.c\
	  utils/my_set.c\
	  utils/my_write.c\
	  utils/my_nbr.c\
	  utils/my_conv.c\
	  utils/my_fun.c

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
	@printf "Removing \t"
	@tput setaf 4
	@printf "Files [.o]\n"
	@tput sgr0
	@tput cuf 68
	@tput cuu1
	@printf "[ "
	@tput setf 2
	@tput bold
	@printf "ok"
	@tput sgr0
	@printf " ]\n"

fclean: clean
	@$(RM) $(NAME)
	@tput setaf 3
	@tput bold
	@printf "Removing \t"
	@tput setaf 4
	@printf "%s\n" $(NAME)
	@tput sgr0
	@tput cuf 68
	@tput cuu1
	@printf "[ "
	@tput setf 2
	@tput bold
	@printf "ok"
	@tput sgr0
	@printf " ]\n"

re: fclean all

debug: CFLAGS	+= -g3
debug: re

.PHONY: all clean fclean re
