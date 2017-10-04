CXX             =   g++
RM              =   rm -f
DIR             =   src
NAME            =   309pollution

SRCS            =   $(DIR)/main.cpp \
                    $(DIR)/Parsing.cpp \
		    $(DIR)/Bezier.cpp \
		    $(DIR)/Points.cpp

CXXFLAGS        =   -std=c++11 -I./includes

OBJS            =   $(SRCS:.cpp=.o)

all:                $(NAME)

$(NAME):	$(OBJS)
		$(CXX) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:                 fclean all

.PHONY:             all clean fclean re
