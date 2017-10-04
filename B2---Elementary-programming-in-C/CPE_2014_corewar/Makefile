##
## Makefile for makefile in /home/chenev_d/rendu/CPE_2014_corewar
##
## Made by chenev_d chenev_d
## Login   <chenev_d@epitech.net>
##
## Started on  Tue Jul 15 14:13:19 2014 chenev_d chenev_d
## Last update Thu Aug 21 17:21:51 2014 teyssa_r teyssa_r
## Last update Tue Jul 15 15:11:01 2014 teyssa_r teyssa_r
##

ASM_DIR = asm
COR_DIR	= corewar

ASM_NAM = $(ASM_DIR)/asm
COR_NAM = $(COR_DIR)/corewar

I	= 0

all:
	$(ASM_DIRECTORY)
	@make -s -C $(ASM_DIR)
	$(COR_DIRECTORY)
	@make -s -C $(COR_DIR)
	@tput setaf 8
	@tput sgr0

clean:
	$(CLEAN_R)
	@(cd $(ASM_DIR) && $(MAKE) -s clean)
	@(cd $(COR_DIR) && $(MAKE) -s clean)
	@tput setaf 8
	@tput sgr0

fclean: clean
	@($(RM) $(ASM_NAM))
	@($(RM) $(COR_NAM))
	$(FCLEAN_R)

re: fclean all

.PHONY: all clean fclean re

define FCLEAN_R
	$(DIS_MAKE)
	@tput smul
	@printf "Removing File\n"
	@tput rmul
	$(DIS_FCLEAN)
	@printf "File %s...\n" $(ASM_NAM)
	$(DIS_RACINE)
	$(DIS_FCLEAN)
	@printf "File %s...\n" $(COR_NAM)
	$(DIS_RACINE)
	@tput setaf 8
	@tput sgr0
endef

define DIS_FCLEAN
	@tput setaf 1
	@tput bold
	@printf "Removing \t"
	@tput setaf 4
	@tput bold
endef

define DIS_RACINE
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

define DIS_MAKE
	@tput setaf 7
	@tput bold
endef

define CLEAN_R
	@tput setaf 7
	@tput bold
	@tput smul
	@printf "Removing Binary\n"
	@tput rmul
endef

define ASM_DIRECTORY
	$(DIS_MAKE)
	@tput smul
	@printf "Asm Directory\n"
	@tput rmul
endef

define COR_DIRECTORY
	$(DIS_MAKE)
	@tput smul
	@printf "Corewar Directory\n"
	@tput rmul
endef
