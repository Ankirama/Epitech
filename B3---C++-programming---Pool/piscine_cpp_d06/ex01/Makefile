##
## Makefile<2> for meow in /home/mar_b/rendu/piscine_cpp_d06/ex00
##
## Made by Fabien Martinez
## Login   <mar_b@epitech.net>
##
## Started on  Mon Jan 12 10:28:58 2015 Fabien Martinez
## Last update Mon Jan 12 12:25:02 2015 Fabien Martinez
##

CXX =	g++

RM =	rm -f

CXXFLAGS = -Wall -W -Werror

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = my_convert_temp

all:	$(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
