##
## EPITECH PROJECT, 2019
## SERVER
## File description:
## Makefile
##

NAME 		= 	../myftp
SRC_LIB 	= 	libsrc/libserver.a

ROOT_PATH			=	../
SRC_PATH			=	sources/
INCLUDE_PATH		=	include/
LIBSRC_PATH         =   libsrc/

override CFLAGS 	+=	-W -Wall -Werror -Wextra -I./$(INCLUDE_PATH)
override LDFLAGS 	+=
override LDLIBS 	+=

SRC		=	$(SRC_PATH)clients_handler.c	\
			$(SRC_PATH)execute.c			\
			$(SRC_PATH)fd_handler.c			\
			$(SRC_PATH)main.c				\
			$(SRC_PATH)server.c				\
			$(SRC_PATH)socket_manager.c


OBJ 	= 	$(SRC:.c=.o)

CC		= 	gcc
LD		=	$(CC)
PRINT		=	@echo -e
RM          =   @rm -f

$(NAME): $(OBJ)
	$(PRINT) "\n------->\tCOMPILED SERVER SRC DEPENDENCIES.\n\nLET'S LINK IT ALL:\n"
	$(LD) $(CFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@ 
	$(PRINT) "\n------->\tCONGRATS !\n"

$(SRC_LIB): $(OBJ)
	$(PRINT) "\n------->\tCOMPILED SERVER SRC DEPENDENCIES.\n\nLET'S PACK SERVER LIB:\n"
	@mkdir $(LIBSRC_PATH)
	$(AR) rc $@ $^
	$(PRINT) "\n------->\tCONGRATS ! YOUR SERVER LIB HAS BEEN CREATED.\n"

all: $(NAME)

lib: $(SRC_LIB)

clean:
	$(PRINT) "\n------->\tREMOVE TMP FILES\n"
	$(RM) $(OBJ) $(OBJ:.o=.gcno) $(OBJ:.o=.gcda)

fclean: clean
	$(PRINT) "------->\tREMOVE BINARY\n"
	$(RM) $(NAME)
	$(PRINT) "------->\tREMOVE SERVER'S LIBRARY\n"
	$(RM) $(SRC_LIB)
	$(RM) -r $(LIBSRC_PATH)

re: fclean all

.PHONY: all clean fclean re