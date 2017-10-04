CXX		= g++

RM		= rm -f

DIR		= src

OTHER		= $(DIR)/others

STATE		= $(DIR)/state

SAVE		= $(DIR)/save

NAME		= bomberman

SRCS		= $(DIR)/main.cpp \
	  	  $(DIR)/GameEngine.cpp \
		  $(DIR)/Button.cpp \
		  $(DIR)/Object2D.cpp \
		  $(DIR)/GenerateText.cpp \
		  $(DIR)/Object3D.cpp \
		  $(DIR)/Camera.cpp \
		  $(DIR)/Animation.cpp \
		  $(DIR)/botme/Lua.cpp \
		  $(DIR)/Bomb.cpp \
		  $(DIR)/Maze.cpp \
		  $(DIR)/player/ACharacter.cpp \
		  $(DIR)/player/Player.cpp \
		  $(DIR)/player/IA.cpp \
		  $(OTHER)/Score.cpp \
		  $(OTHER)/GenerateMaze.cpp \
		  $(OTHER)/ListDir.cpp \
		  $(OTHER)/tinyxml2.cpp \
		  $(STATE)/ScoreState.cpp \
		  $(STATE)/IntroState.cpp \
		  $(STATE)/GameState.cpp \
		  $(STATE)/MenuState.cpp \
		  $(STATE)/OptionState.cpp \
		  $(STATE)/PlayState.cpp \
		  $(STATE)/LoadState.cpp \
		  $(STATE)/SaveState.cpp \
		  $(STATE)/SoloState.cpp \
		  $(STATE)/MultState.cpp \
		  $(STATE)/ConfState.cpp \
		  $(SAVE)/XmlSave.cpp \
		  $(SAVE)/XmlLoad.cpp \

DIRTUTO		= annexes/tutoriel

NAMETUTO	= tuto

SRCSTUTO	= $(DIRTUTO)/main.cpp \

CXXFLAGS	= -I./lib/gdl/includes -I./include -I./lib/sfe/include/
CXXFLAGS	+= -W -Wall -Werror  -std=c++11 -I./lib/sfe/include/sfeMovie/
LIB		= -L./lib/gdl/libs/ -lgdl_gl -lGL -lGLU -lGLEW  -lrt -lfbxsdk -lswresample
LIB		+= -lsfml-window -lsfml-graphics -lavdevice -lavformat -lavcodec
LIB		+= -lavutil -lswscale -lGLEW -lavfilter
LIB		+= -lSDL2 -lSDL_image -lsfml-audio -lsfml-system -lsfeMovie
LIB		+= -llua -lpthread -ldl
OBJS		= $(SRCS:.cpp=.o)

OBJSTUTO	= $(SRCSTUTO:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) -o $(NAME) $(OBJS) $(LIB)
	$(COMPIL_ING)

%.o:	%.cpp
	$(DOT_O_S)
	@$(CXX) $(CXXFLAGS) $(LIB) -c -o $@ $^
	$(DOT_O_E)

tuto: $(NAMETUTO)

$(NAMETUTO): $(OBJSTUTO)
	$(CXX) -o $(NAMETUTO) $(OBJSTUTO) $(LIB)

clean:
	@$(RM) $(OBJS)
	$(CLEAN_R)

clean_tuto:
	$(RM) $(OBJSTUTO)

fclean: clean
	@$(RM) $(NAME)
	$(FCLEAN_R)

fclean_tuto: clean_tuto
	$(RM) $(NAMETUTO)

re: fclean all

re_tuto: fclean_tuto tuto

.PHONY: re all fclean clean tuto clean_tuto fclean_tuto

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
	@printf "\e[3mKoala <3\e[0m\n"
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
	@printf "\e[5mBomberman\e[0m"
	@tput setaf 6
	@tput bold
	@printf "             #\n"
	@tput cuf 16
	@printf "#	 "
	@tput setaf 1
	@tput smul
	@tput bold
	@printf "\e[3mMakefile to the Futur"
	@tput rmul
	@tput setaf 6
	@tput bold
	@printf "       #\n"
	@tput cuf 16
	@printf "#                                    #\n"
	@tput cuf 16
	@printf "######################################\n"
	@tput setaf 7
	@tput bold
	@tput smul
	@printf "\e[3mRemoving Files\e[0m\n"
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
