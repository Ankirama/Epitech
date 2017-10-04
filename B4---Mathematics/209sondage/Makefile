OCAML_DIR = ocaml
C_DIR = C

all:
		make -C $(OCAML_DIR)
		make -C $(C_DIR)

clean:
		make -C $(OCAML_DIR) clean
		make -C $(C_DIR) clean

fclean:
		make -C $(OCAML_DIR) fclean
		make -C $(C_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
