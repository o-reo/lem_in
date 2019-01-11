# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 0017/12/28 15:26:42 by uaud         #+#   ##    ##    #+#        #
#    Updated: 2019/01/11 16:01:43 by eruaud      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = lem-in
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FUNC = parsing_tools debug utils heuristic moves
OBJ_MAIN = build/main.o
SRC = $(addprefix src/, $(addsuffix .c, $(FUNC) main)) includes/lem_in.h
OBJ = $(addprefix build/, $(addsuffix .o, $(FUNC)))
RED = \033[1;31m
GREEN = \033[1;92m
BLUE = \033[34;1m
YELLOW = \033[0;33m
HEADER = -I includes/ -I libft/includes/
LDLIBS = -lft
LDFLAGS = -L libft/

# UNIT TEST - CHECK
CHECK_NAME = check
OBJ_CHECK = build/test.o
CHECK_HEADER = -I ~/.brew/include/
CHECK_LIBS = -L ~/.brew/lib/
CHECK_FLAGS = -lcheck

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN) lib
	@echo "\033[1;31mCompiling project..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(HEADER) $(LDLIBS) $(LDFLAGS)
	@echo "\033[1;92mSuccess !"

./build/%.o: ./src/%.c
	@echo "     $(YELLOW) → Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADER)
	@echo "     $(GREEN)   OK"

lib :
	@make -C libft

norm :
	@norminette $(SRC) $()

check : cclean
	@$(CC) $(CFLAGS) -o build/test.o -c src/test.c $(HEADER) $(CHECK_HEADER)
	@$(CC) -Wall -o $(CHECK_NAME) $(OBJ) $(OBJ_CHECK) $(HEADER) $(CHECK_HEADER) $(LDLIBS) $(LDFLAGS) $(CHECK_FLAGS) $(CHECK_LIBS)
	@echo "$(YELLOW)"
	./$(CHECK_NAME)

cclean:
	@/bin/rm -f $(OBJ_CHECK) $(CHECK_NAME)

clean:
	@/bin/rm -f $(OBJ)
	@echo "  $(YELLOW)OBJ files have been deleted."

fclean:
	@/bin/rm -f $(OBJ) $(NAME)
	@echo "  $(YELLOW)$(NAME) and OBJ files have been deleted."

re: fclean $(NAME)

.PHONY = all clean fclean re norm lib
