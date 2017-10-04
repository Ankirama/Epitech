CXX	= g++

RM	= rm -f

TEST_1	= test1

TEST_2	= test2

SRCS_TEST1	= main_test1.cpp

SRCS_TEST2	= tinyxml2.cpp \
		  main_test2.cpp

OBJS_T1		= $(SRCS_TEST1:.cpp=.o)

OBJS_T2		= $(SRCS_TEST2:.cpp=.o)

CXXFLAGS	= -W -Wall -Werror -Wextra

all: $(TEST_1) $(TEST_2)

$(TEST_1): $(OBJS_T1)
	$(CXX) -o $(TEST_1) $(OBJS_T1)

$(TEST_2): $(OBJS_T2)
	$(CXX) -o $(TEST_2) $(OBJS_T2)

clean:
	$(RM) $(OBJS_T1) $(OBJS_T2)

fclean: clean
	$(RM) $(TEST_1) $(TEST_2)

re: fclean all

.PHONY: all clean fclean re