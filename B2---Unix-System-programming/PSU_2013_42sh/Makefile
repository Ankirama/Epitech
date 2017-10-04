##
## Makefile for makefile in /home/chenev_d/rendu/CPE_2014_corewar
##
## Made by chenev_d chenev_d
## Login   <chenev_d@epitech.net>
##
## Started on  Tue Jul 15 14:13:19 2014 chenev_d chenev_d
## Last update Thu Oct  2 23:36:21 2014 mar_b mar_b
##

ROOT	= ../.

CC	= gcc

RM	= rm -f

CFLAGS	= -Wextra -Wall -Werror -g3
CFLAGS	+= -I./src/utils -I./src/bonus -I./src/parser -I./src/list -I./src/
CFLAGS	+= -I./src/lexer -I./src/execution

NAME	= zero

SRCS	= ./src/main.c\
	  ./src/signal.c\
	  ./src/list/list.c\
	  ./src/lexer/lexer.c\
	  ./src/lexer/my_str_to_wordtab.c\
	  ./src/lexer/fun.c\
	  ./src/lexer/ast.c\
	  ./src/parser/parser.c\
	  ./src/utils/error.c\
	  ./src/utils/fun.c\
	  ./src/utils/free.c\
	  ./src/utils/str.c\
	  ./src/utils/nbr.c\
	  ./src/utils/duparray.c

BONUS_FILE = ./src/true_main.c\
	  ./src/list/list.c\
	  ./src/signal.c\
	  ./src/lexer/lexer.c\
	  ./src/lexer/my_str_to_wordtab.c\
	  ./src/lexer/fun.c\
	  ./src/lexer/ast.c\
	  ./src/parser/parser.c\
	  ./src/utils/error.c\
	  ./src/utils/fun.c\
	  ./src/utils/free.c\
	  ./src/utils/str.c\
	  ./src/utils/nbr.c\
	  ./src/bonus/function_key.c\
	  ./src/bonus/function_side.c\
	  ./src/bonus/function_delete.c\
	  ./src/bonus/function_hst.c\
	  ./src/bonus/tab_fct.c\
	  ./src/bonus/history.c\
	  ./src/bonus/function_init.c\
	  ./src/bonus/function_enter.c\
	  ./src/bonus/function_fast.c\
	  ./src/bonus/free.c\
	  ./src/bonus/field_str.c\
	  ./src/utils/duparray.c

BONUS_OBJ = $(BONUS_FILE:.c=.o)

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS)
	$(COMPIL_ING)

bonus: $(BONUS_OBJ)
	@$(CC) -o $(NAME) $(BONUS_OBJ) -lncurses
	$(COMPIL_ING)

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

clean_bonus:
	@$(RM) $(BONUS_OBJ)
	$(CLEAN_R)

fclean_bonus: clean_bonus
	@$(RM) $(NAME)
	$(FCLEAN_R)

re: fclean all

re_bonus: fclean_bonus bonus

debug: CFLAGS += -g3
debug: re

.PHONY: all clean fclean re debug bonus clean_bonus fclean_bonus re_bonus

define DOT_O_S
	@tput setaf 3
	@tput bold
	@printf "Compiling \t"
	@tput setaf 4
	@printf "%s\n" $(patsubst $(RACINE)/%,%,$^)
endef

define COMPIL_ING
	@tput setaf 7
	@tput bold
	@tput cuf 26
	@printf "\e[3mCompiling Done\e[0m"
	@tput setaf 1
	@tput bold
	@tput cuf 25
	@printf "\e[3mAstek <3\e[0m\n"
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
	@tput clear
	@tput cuf 16
	@tput bold
	@tput setaf 6
	@printf "######################################\n"
	@tput cuf 16
	@printf "#                                    #\n"
	@tput cuf 16
	@printf "#                "
	@tput setaf 7
	@printf "\e[5m42sh\e[0m"
	@tput setaf 6
	@tput bold
	@printf "                #\n"
	@tput cuf 16
	@printf "#       "
	@tput setaf 1
	@tput smul
	@tput bold
	@printf "\e[3mMakefile to the Futur"
	@tput rmul
	@tput setaf 6
	@tput bold
	@printf "        #\n"
	@tput cuf 16
	@printf "#                                    #\n"
	@tput cuf 16
	@printf "######################################\n"
	@tput setaf 7
	@tput bold
	@tput smul
	@printf "\e[3mRemoving Binary\e[0m\n"
	@tput rmul
	@tput setaf 1
	@tput bold
	@tput rmul
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
	@tput setaf 7
	@tput bold
	@tput smul
	@printf "\e[3mRemoving File\e[0m\n"
	@tput rmul
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
