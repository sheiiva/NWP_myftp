##
## EPITECH PROJECT, 2019
## SOURCES MAKEFILE
## File description:
## STEP4
##

NAME	=	../mulclients

INCLUDE_PATH		=	include/
SOURCES_PATH		=	sources/

override CFLAGS 	+=	-W -Wall -Werror -Wextra -I./$(INCLUDE_PATH)
override LDFLAGS 	+=
override LDLIBS 	+=

SRC		=	$(SOURCES_PATH)socket_manager.c		\
			$(SOURCES_PATH)main.c

OBJ 	= 	$(SRC:.c=.o)

LD			=	gcc
PRINT		=	@echo -e
RM          =   @rm -f

$(NAME): $(OBJ)
	$(PRINT) "\n------->\tCOMPILED SRC DEPENDENCIES.\n\nLET'S LINK IT ALL:\n"
	$(LD) $(CFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@
	$(PRINT) "\n------->\tCONGRATS !\n"

all: $(NAME)

clean:
	$(PRINT) "\n------->\tREMOVE TMP FILES\n"
	$(RM) $(OBJ)

fclean: clean
	$(PRINT) "------->\tREMOVE BINARY\n"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re