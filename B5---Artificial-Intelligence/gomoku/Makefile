CXX	= g++

RM	= rm -f

NAME	= plazza

LDFLAGS	= -lpthread -lQtCore -lQtGui -std=c++11

CXXFLAGS = -W -Wall -Werror -I./includes -I/usr/include/Qt -I/usr/include/QtGui -g3
CXXFLAGS+= -I/usr/include/QtCore -I/usr/share/qt4/mkspecs/default -I.

DIR	= src

CORE	= $(DIR)/core

GRAPHIC	= $(DIR)/graphic

SRCS	= $(DIR)/main.cpp \
$(CORE)/GameEngine.cpp \
$(CORE)/IntroState.cpp

OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS) $(LDFLAGS)

$(CORE)/moc_Graphic.cpp: includes/Graphic.h

$(CORE)/moc_Graphic.cpp: includes/Graphic.h
	moc -o $(CORE)/moc_Graphic.cpp includes/Graphic.h

$(CORE)/moc_IntroState.cpp: includes/IntroState.h

$(CORE)/moc_IntroState.cpp: includes/IntroState.h
	moc -o $(CORE)/moc_IntroState.cpp includes/IntroState.h

clean:
	$(RM) $(OBJS)
	$(RM) $(CORE)/moc_Graphic.cpp
	$(RM) $(CORE)/moc_IntroState.cpp

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re all clean fclean
