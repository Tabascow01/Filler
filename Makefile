NAME = mchemakh.filler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/main.c srcs/parser.c

OBJS = main.o parser.o

LIB_PATH = ./ft_printf/
LIB = ftprintf

LIBINC_PATH = ./ft_printf/includes/
INC = ./includes/

all: $(NAME)

$(NAME):
	@make -C $(LIB_PATH)
	@echo "libftprintf.a Ok"
	@$(CC) $(CFLAGS) $(SRCS) -I $(LIBINC_PATH) -I $(INC) -o $(NAME)
	@echo "$(NAME) Ok"

clean:
	@rm -rf *.o
	@make clean -C $(LIB_PATH)
	@echo "all *.o deleted"

fclean : clean
	@rm -rf $(NAME)
	@make fclean -C $(LIB_PATH)
	@echo "exec + lib deleted"

re: fclean all
	@make re -C $(LIB_PATH)

.PHONY: all, clean, fclean, re
