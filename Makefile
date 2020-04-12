##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## ROOT
##

NAME 		= 	root_makefile

LIB_PATH	=	./lib/
SRC_PATH	=	./sources/
TST_PATH	=	./tests/

CLEAN		=	clean
FCLEAN		=	fclean

$(NAME):
	@$(MAKE) -C $(LIB_PATH)
	@$(MAKE) -C $(SRC_PATH)

all: $(NAME)

clean:
	@$(MAKE) $(CLEAN) -C $(LIB_PATH)
	@$(MAKE) $(CLEAN) -C $(SRC_PATH)
	@$(MAKE) $(CLEAN) -C $(TST_PATH)

fclean:
	@$(MAKE) $(FCLEAN) -C $(LIB_PATH)
	@$(MAKE) $(FCLEAN) -C $(SRC_PATH)
	@$(MAKE) $(FCLEAN) -C $(TST_PATH)

re: fclean all

tests_run: all
	@$(MAKE) -C $(TST_PATH)

.PHONY: all clean fclean re tests_run
