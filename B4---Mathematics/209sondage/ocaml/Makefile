CAMLC	= ocamlc

CAMLOPT	= ocamlopt

CAMLDEP	= ocamldep

RM	= rm -f

# LIBS=$(WITHGRAPHICS) $(WITHUNIX) $(WITHSTR) $(WITHNUMS) $(WITHTHREADS)

LIBS = $(WITHSTR)

WITHSTR = str.cma

SRCS	= main.ml

NAME	= 209sondage

OPTOBJS	= $(SRCS:.ml=.cmx)
OBJS	= $(SRCS:.ml=.cmo)

all:	depend $(NAME)

opt:	$(NAME).opt

$(NAME): $(OBJS)
	$(CAMLC) -o $(NAME) $(LIBS) $(OBJS)

$(NAME).opt: $(OPTOBJS)
	$(CAMLOPT) -o $(EXEC) $(LIBS:.cma=.cmxa) $(OPTOBJS)

.ml.cmo:
	$(CAMLC) -c $<
.mli.cmi:
	$(CAMLC) -c $<
.ml.cmx:
	$(CAMLOPT) -c $<

clean:
	$(RM) *.cm[iox] $(NAME).opt

fclean: clean
	$(RM) $(NAME)

depend: $(SRCS)
	$(CAMLDEP) $(SRCS) > .depend

re: fclean all

-include .depend

.PHONY: all clean fclean depend

.SUFFIXES: .ml .mli .cmo .cmi .cmx
