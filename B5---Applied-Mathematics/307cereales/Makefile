CXX             =   g++
RM              =   rm -f
DIR             =   src
NAME            =   307cereales

SRCS            =   $(DIR)/main.cpp \
                    $(DIR)/RegexIsFunny.cpp \
			$(DIR)/Simplex.cpp

CXXFLAGS        =   -I./includes

OBJS            =   $(SRCS:.cpp=.o)

all:                $(NAME)

$(NAME):	$(OBJS)
		$(CXX) -o $(NAME) $(OBJS) -std=c++11

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:                 fclean all

.PHONY:             all clean fclean re
