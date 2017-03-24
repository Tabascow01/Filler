NAME = mchemakh.filler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/main.c srcs/parser.c

OBJS = main.o parser.o

LIB_PATH = -L./ft_printf/
LIB = -lftprintf

LIBINC_PATH = ./ft_printf/includes/
INC = ./includes/

all: $(NAME)

$(NAME):
	@make -C ./ft_printf/
	@echo "[libftprintf.a Ok]"
	@$(CC) $(CFLAGS) $(LIB_PATH) $(LIB) $(SRCS) -I $(LIBINC_PATH) -I $(INC) -o $(NAME)
	@echo "$(NAME) Ok"

clean:
	@rm -rf *.o
	@make clean -C ./ft_printf/
	@echo "all *.o deleted"

fclean : clean
	@rm -rf $(NAME)
	@make fclean -C ./ft_printf/
	@echo "exec + lib deleted"

re: fclean all

.PHONY: all, clean, fclean, re
