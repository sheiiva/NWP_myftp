##
## EPITECH PROJECT, 2019
## LIB
## File description:
## Makefile
##

NAME 	= 	libmy.a

INCLUDE			=	include/
LIB_PATH		=	my/
LIB_I_PATH		=	$(LIB_PATH)$(INCLUDE)

override CFLAGS 	+= 	-W -Wall -Wextra -Werror -I./$(LIB_I_PATH)
override LDFLAGS	+= 	-L./
override LDLIBS		+=	-lmy

RM			=	@rm -f
PRINT		=	@echo -e

SRC 	=	$(LIB_PATH)my_counter.c				\
			$(LIB_PATH)my_freetab.c				\
			$(LIB_PATH)my_getnbr.c				\
			$(LIB_PATH)my_putchar.c 			\
			$(LIB_PATH)my_putstr.c 				\
			$(LIB_PATH)my_realloc.c				\
			$(LIB_PATH)my_revstr.c 				\
			$(LIB_PATH)my_str_alloc.c			\
			$(LIB_PATH)my_str_concat.c			\
			$(LIB_PATH)my_str_isletter.c		\
			$(LIB_PATH)my_str_to_wordarray.c	\
			$(LIB_PATH)my_strcmp.c 				\
			$(LIB_PATH)my_strncmp.c				\
			$(LIB_PATH)my_strcpy.c				\
			$(LIB_PATH)my_strlen.c				\
			$(LIB_PATH)my_tab_alloc.c			\
			$(LIB_PATH)my_tabcpy.c				\
			$(LIB_PATH)my_tablen.c				\

OBJ 	= 	$(SRC:.c=.o)

$(NAME): $(OBJ)
	$(PRINT) "\n------->\tCOMPILED LIB DEPENDENCIES.\n\nLET'S PACK THE LIBRARY:\n"
	$(AR) rc $@ $^
	$(PRINT) "\n------->\tCONGRATS ! YOUR LIBRARY HAS BEEN CREATED.\n"

all: $(NAME)

clean:
	$(PRINT) "\n------->\tREMOVE LIBRARY TMP FILES\n"
	$(RM) $(OBJ) $(OBJ:.o=.gcno) $(OBJ:.o=.gcda)

fclean: clean
	$(PRINT) "------->\tREMOVE LIBRARY\n"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
