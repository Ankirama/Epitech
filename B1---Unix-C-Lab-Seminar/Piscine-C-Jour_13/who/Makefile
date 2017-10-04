##
## Makefile for Makefile in /home/user/rendu/Piscine-C-Jour_13/cat
##
## Made by 
## Login   
##
## Started on  Wed Mar 26 10:17:21 2014 
## Last update Wed Mar 26 22:11:18 2014 
##

CC	= gcc

RM	= rm -f

CFLAGS 	+= -ansi -pedantic
CFLAGS	+= -lmy -L../../Piscine-C-lib/
CFLAGS	+= -I../../Piscine-C-include/

NAME	= who

SRCS	= who.c \
	  my_perror.c \
	  my_perror2.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
