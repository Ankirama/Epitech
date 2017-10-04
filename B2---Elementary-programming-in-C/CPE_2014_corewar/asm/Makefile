##
## Makefile for makefile in /home/chenev_d/rendu/CPE_2014_corewar
##
## Made by chenev_d chenev_d
## Login   <chenev_d@epitech.net>
##
## Started on  Tue Jul 15 14:13:19 2014 chenev_d chenev_d
## Last update Fri Aug 29 21:01:35 2014 mar_b mar_b
##

ROOT	= ../.

CC	= gcc

RM	= rm -f

CFLAGS	= -Wextra -Wall -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -I. -I../utils -I./parsing -I./utils -I./write_file

NAME	= asm

SRCS	= main.c\
	  ./parsing/parser.c\
	  ./parsing/check_command.c\
	  ./utils/str_asm.c\
	  ./utils/nbr.c\
	  ./utils/error.c\
	  ./utils/str_to_wordtab.c\
	  ./utils/list.c\
	  ./write_file/check_instru.c\
	  ./write_file/header.c\
	  ./write_file/write.c\
	  ./write_file/check_type.c\
	  ./write_file/write_file.c\
	  ./write_file/label.c\
	  ./write_file/write_commands.c\
	  ../utils/error.c\
	  ../utils/arr.c\
	  ../utils/conv.c\
	  ../utils/op.c\
	  ../utils/get_next_line.c\
	  ../utils/str.c\
	  ../utils/fun.c\
	  ../utils/nbr.c\
	  ../utils/print.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS)

%.o:	%.c
	$(DOT_O_S)
	@$(CC) $(CFLAGS) -c -o $@ $^
	$(DOT_O_E)

clean:
	@$(RM) $(OBJS)
	$(CLEAN_R)

fclean: clean
	@$(RM) $(NAME)
	$(FCLEAN_R)


re: fclean all

debug: CFLAGS += -g3
debug: re

.PHONY: all clean fclean re debug

define DOT_O_S
	@tput setaf 3
	@tput bold
	@printf "Compiling \t"
	@tput setaf 4
	@printf "%s\n" $(patsubst $(RACINE)/%,%,$^)
endef

define DOT_O_E
	@tput sgr0
	@tput cuf 68
	@tput cuu1
	@printf "[ "
	@tput setf 2
	@tput bold
	@printf "√"
	@tput sgr0
	@printf " ]\n"
endef

define CLEAN_R
	@tput setaf 1
	@tput bold
	@printf "Removing  \t"
	@tput setaf 4
	@printf "File [.o]...\n"
	@tput sgr0
	@tput cuf 68
	@tput cuu1
	@printf "[ "
	@tput setaf 1
	@tput bold
	@printf "√"
	@tput sgr0
	@printf " ]\n"
endef

define FCLEAN_R
	@tput setaf 1
	@tput bold
	@printf "Removing  \t"
	@tput setaf 4
	@printf "File %s...\n", $(NAME)
	@tput sgr0
	@tput cuf 67
	@tput cuu1
	@printf "[ "
	@tput setaf 1
	@tput bold
	@printf "√"
	@tput sgr0
	@printf " ]\n"

endef
