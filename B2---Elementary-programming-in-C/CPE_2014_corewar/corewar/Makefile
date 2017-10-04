##
## Makefile for makefile in /root/rendu/CPE_2014_corewar
##
## Made by
## Login   <-n@epitech.net>
##
## Started on  Mon Aug 25 16:31:02 2014
## Last update Sun Aug 31 22:10:51 2014 charles viterbo
##

ROOT	= ../.

CC	= gcc

RM	= rm -f

CFLAGS	= -Wextra -Wall -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -I../utils/ -I./parser/ -I./vm/ -I./

NAME	= corewar

SRCS	= ./parser/parse_vm.c \
          ./parser/list_cham.c \
	  ./parser/mainparser.c \
          ./parser/my_adress.c \
          ./parser/my_cor.c \
          ./parser/my_dump.c \
          ./parser/my_number_good.c \
          ./parser/my_precheck.c \
	  ./vm/vm_memory.c \
	  ./vm/vm_main.c \
	  ./vm/vm_champ_pos.c \
	  ./vm/vm_cycle.c \
	  ../utils/error.c \
	  ../utils/str.c \
	  ../utils/get_next_line.c \
	  ../utils/fun.c \
	  ../utils/fun_2.c \
	  ../utils/nbr.c \
	  ../utils/conv.c \
	  ../utils/print.c \
	  ../utils/op.c \
#	  ./function/function_arg.c
#	  ./function/function_one.c \
#	  ./function/function_two.c \
#	  ./function/function_three.c \
#	  ./function/function_four.c \

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
