##
## Makefile for Makefile in /home/mar_b/rendu/PSU_2013_my_ls
##
## Made by Fabien Martinez
## Login   <mar_b@epitech.net>
##
## Started on  Wed Apr 23 01:28:46 2014 Fabien Martinez
## Last update Fri May  2 16:47:07 2014 Fabien Martinez
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -ansi -pedantic

CFLAGS	+= -lmy -L./lib/

CFLAGS	+= -D_BSD_SOURCE

CFLAGS	+= -I./lib/

SRCS	= my_ls.c \
	  my_date.c \
	  my_read.c \
	  my_check.c \
	  my_color.c \
	  my_path.c \
	  my_display.c \
	  my_display_l.c \
	  my_sort.c \
	  my_file.c \
	  my_options.c \
	  my_fun.c

NAME	= my_ls

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	@(cd ./lib/ && $(MAKE))
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	@(cd ./lib/ && $(MAKE) clean)
	$(RM) $(OBJS)

fclean: clean
	$(RM) ./lib/libmy.a
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
