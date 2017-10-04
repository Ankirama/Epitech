##
## Makefile for Makefile in /home/mar_b/rendu/MUL_2013_rtv1
##
## Made by mar_b mar_b
## Login   <mar_b@epitech.net>
##
## Started on  Fri Jul 11 16:55:53 2014 mar_b mar_b
## Last update Thu Jul 24 23:47:34 2014 mar_b
##

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Werror -Wextra
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -DM_PI=3.14159265358979323846
CFLAGS	+= -I. -I./calc -I./img -I./objects -I./parser -I./utils
CFLAGS	+= -I/usr/X11/include

LDFLAGS	= -L/usr/X11/lib -lmlx -lXext -lX11 -lm

NAME	= rtv1

SRCS	= main.c\
	  key.c\
	  calc/calc.c\
	  calc/light.c\
	  calc/vec_calc.c\
	  img/img.c\
	  img/pixel.c\
	  objects/cone.c\
	  objects/cylinder.c\
	  objects/free.c\
	  objects/plane.c\
	  objects/objects.c\
	  objects/sphere.c\
	  parser/get_next_line.c\
	  parser/parser_scene.c\
	  utils/free.c\
	  utils/str.c\
	  utils/error.c\
	  utils/conv.c

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

%.o:	%.c
	@tput setaf 3
	@tput bold
	@printf "Compiling "
	@tput setaf 4
	@printf "%s\n" $(patsubst $(RACINE)/%,%,$^)
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

.PHONY: all clean fclean re
