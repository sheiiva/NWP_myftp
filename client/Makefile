##
## EPITECH PROJECT, 2019
## CLIENT
## File description:
## Makefile
##

NAME	=	../clients
SRC_LIB 	= 	libsrc/libclient.a

INCLUDE_PATH		=	include/
SOURCES_PATH		=	sources/
LIBSRC_PATH         =   libsrc/

override CFLAGS 	+=	-W -Wall -Werror -Wextra -I./$(INCLUDE_PATH)
override LDFLAGS 	+=
override LDLIBS 	+=

SRC		=	$(SOURCES_PATH)socket_manager.c		\
			$(SOURCES_PATH)main.c

OBJ 	= 	$(SRC:.c=.o)

CC		= 	gcc
LD		=	$(CC)
PRINT		=	@echo -e
RM          =   @rm -f

$(NAME): $(OBJ)
	$(PRINT) "\n------->\tCOMPILED CLIENT SRC DEPENDENCIES.\n\nLET'S LINK IT ALL:\n"
	$(LD) $(CFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@
	$(PRINT) "\n------->\tCONGRATS !\n"

$(SRC_LIB): $(OBJ)
	$(PRINT) "\n------->\tCOMPILED CLIENT SRC DEPENDENCIES.\n\nLET'S PACK CLIENT LIB:\n"
	@mkdir $(LIBSRC_PATH)
	$(AR) rc $@ $^
	$(PRINT) "\n------->\tCONGRATS ! YOUR CLIENT LIB HAS BEEN CREATED.\n"

all: $(NAME)

lib: $(SRC_LIB)

clean:
	$(PRINT) "\n------->\tREMOVE TMP FILES\n"
	$(RM) $(OBJ) $(OBJ:.o=.gcno) $(OBJ:.o=.gcda)

fclean: clean
	$(PRINT) "------->\tREMOVE BINARY\n"
	$(RM) $(NAME)
	$(PRINT) "------->\tREMOVE CLIENT'S LIBRARY\n"
	$(RM) $(SRC_LIB)
	$(RM) -r $(LIBSRC_PATH)

re: fclean all

.PHONY: all clean fclean re