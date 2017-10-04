##
## Makefile for makefile in /home/chenev_d/rendu/CPE_2014_corewar
##
## Made by chenev_d chenev_d
## Login   <chenev_d@epitech.net>
##
## Started on  Tue Jul 15 14:13:19 2014 chenev_d chenev_d
## Last update Sun Oct 12 16:25:59 2014 charles viterbo
## Last update Tue Oct  7 21:58:08 2014 mar_b mar_b
##

ROOT	= ../.

DIR	= ./src

CC	= gcc

RM	= rm -f

CFLAGS	= -Wextra -Wall -Werror
CFLAGS	+= -I$(DIR) -I$(DIR)/parser -I$(DIR)/utils -I$(DIR)/objects
CFLAGS	+= -I$(DIR)/rotation -I$(DIR)/intersection -I$(DIR)/luminosite
CFLAGS	+= -I$(DIR)/utils/equation
CFLAGS	+= -I$(DIR)/shadow -I$(DIR)/noise -I$(DIR)/save
CFLAGS	+= -DM_PI=3.14159265358979323846

LDFLAGS	= -L/usr/lib64 -lmlx -L/usr/X11/lib -lXext -lX11 -lm

NAME	= rt

SRCS	= $(DIR)/main.c\
	  $(DIR)/expose.c\
	  $(DIR)/keyboard.c\
	  $(DIR)/picture.c\
	  $(DIR)/rotation/rotation.c \
	  $(DIR)/parser/parser.c\
	  $(DIR)/objects/cone.c\
	  $(DIR)/objects/eye.c\
	  $(DIR)/objects/cylinder.c\
	  $(DIR)/objects/orb.c\
	  $(DIR)/objects/plan.c\
	  $(DIR)/objects/light.c\
	  $(DIR)/objects/para.c\
	  $(DIR)/noise/noise.c\
	  $(DIR)/noise/fun.c\
	  $(DIR)/noise/color.c\
	  $(DIR)/luminosite/orb.c\
	  $(DIR)/luminosite/calc.c\
	  $(DIR)/luminosite/cylinder.c\
	  $(DIR)/luminosite/cone.c\
	  $(DIR)/luminosite/plan.c\
	  $(DIR)/luminosite/paraboloide.c\
	  $(DIR)/parser/str_to_wordtab.c\
	  $(DIR)/shadow/shadow.c\
	  $(DIR)/shadow/cone.c\
	  $(DIR)/shadow/plan.c\
	  $(DIR)/shadow/orb.c\
	  $(DIR)/shadow/cylinder.c\
	  $(DIR)/shadow/paraboloide.c\
	  $(DIR)/save/header.c\
	  $(DIR)/save/save_file.c\
	  $(DIR)/utils/error.c\
	  $(DIR)/utils/get_next_line.c\
	  $(DIR)/utils/create_struct.c\
	  $(DIR)/utils/fun.c\
	  $(DIR)/utils/conv_color.c\
	  $(DIR)/utils/free.c\
	  $(DIR)/utils/str.c\
	  $(DIR)/utils/color.c\
	  $(DIR)/utils/vect.c\
	  $(DIR)/utils/nbr.c\
	  $(DIR)/utils/mv_position.c\
	  $(DIR)/utils/limite.c\
	  $(DIR)/intersection/all_objects.c\
	  $(DIR)/intersection/cone.c\
	  $(DIR)/intersection/cylinder.c\
	  $(DIR)/intersection/orb.c\
	  $(DIR)/intersection/plan.c \
	  $(DIR)/intersection/paraboloide.c



OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)
	$(COMPIL_ING)

%.o:	%.c
	$(DOT_O_S)
	@$(CC) $(CFLAGS) -c -o $@ $^
	$(DOT_O_E)

clean:
	@$(RM) $(OBJS)
	@$(CLEAN_R)

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
	@printf "#              "
	@tput setaf 7
	@printf "\e[5mRTracer\e[0m"
	@tput setaf 6
	@tput bold
	@printf "               #\n"
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
