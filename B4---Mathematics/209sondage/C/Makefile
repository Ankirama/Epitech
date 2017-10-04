CC	= gcc

RM	= rm -f

CFLAGS = -W -Wall -Werror

NAME	= 209sondage

SRCS	= main.c \
	  utils.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -lm

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
