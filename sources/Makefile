##
## EPITECH PROJECT, 2019
## SOURCES
## File description:
## Makefile
##


ROOT_PATH	=	../
INCLUDE_PATH		=	include/
LIBSRC_PATH         =   libsrc/
I_PATH				=	$(ROOT_PATH)$(INCLUDE_PATH)
LIB_PATH			=	$(ROOT_PATH)lib/
LIB_I_PATH			=	$(LIB_PATH)my/$(INCLUDE_PATH)

CC		= 	gcc
LD		=	$(CC)

PRINT		=	@echo -e
RM          =   @rm -f


NAME 		= 	$(ROOT_PATH)myftp
SRC_LIB 	= 	$(LIBSRC_PATH)libsrc.a


override CFLAGS 	+=	-W -Wall -Werror -Wextra -I./$(I_PATH) -I./$(LIB_I_PATH)
override LDFLAGS 	+= 	-L./$(LIB_PATH)
override LDLIBS 	+=	-lmy

SRC		=	main.c

OBJ 	= 	$(SRC:.c=.o)

$(NAME): $(OBJ)
	$(PRINT) "\n------->\tCOMPILED SRC DEPENDENCIES.\n\nLET'S LINK IT ALL:\n"
	$(LD) $^ -o $@ $(CFLAGS) $(LDFLAGS) $(LDLIBS)
	$(PRINT) "\n------->\tCONGRATS !\n"


all: $(NAME)

$(SRC_LIB): $(OBJ)
	$(PRINT) "\n------->\tCOMPILED SRC DEPENDENCIES.\n\nLET'S PACK SRC LIB:\n"
	@mkdir $(LIBSRC_PATH)
	$(AR) rc $@ $^
	$(PRINT) "\n------->\tCONGRATS ! YOUR SRC LIB HAS BEEN CREATED.\n"

lib: $(SRC_LIB)

clean:
	$(PRINT) "\n------->\tREMOVE TMP FILES\n"
	$(RM) $(OBJ) $(OBJ:.o=.gcno) $(OBJ:.o=.gcda)

fclean: clean
	$(PRINT) "------->\tREMOVE BINARY\n"
	$(RM) $(NAME)
	$(PRINT) "------->\tREMOVE SOURCES' LIBRARY\n"
	$(RM) $(SRC_LIB)
	$(RM) -r $(LIBSRC_PATH)

re: fclean all

.PHONY: all clean fclean re