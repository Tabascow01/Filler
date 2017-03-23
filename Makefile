NAME = mchemakh
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_PATH = ./srcs/
SRCS = main.c

LIB_PATH = ./ft_printf/
LIB = ftprintf

LIBINC_PATH = ./ft_printf/includes/
INC = ./includes/

all: $(NAME)

$(NAME):
	@make -C $(LIB_PATH)
	@echo "libftprintf.a utilisable"
	@$(CC) $(CFLAGS) -I $(LIBINC_PATH) -o $(NAME) -c $(SRCS_PATH)$(SRCS)
	@echo "$(NAME) Ok"

clean:
	@rm -rf *.o
	@echo "*.o deleted"

fclean : clean
	@rm -rf $(NAME)
	@echo "exec deleted"

re: fclean all
	@make re -C $(LIB_PATH)

.PHONY: all, clean, fclean, re
