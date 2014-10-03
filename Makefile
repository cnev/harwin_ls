NAME = ft_ls
CC = gcc -I $(HEADERFOLDER)
CFLAGS = -Wall -Wextra -Werror -O3
SRCFOLDER = srcs
HEADERFOLDER = includes/
SRC += $(SRCFOLDER)/bsq.c

OBJ = $(SRC:%.c=%.o)
LIB = libft/

all: $(NAME)

$(NAME): $(OBJ) lib
	@$(CC) $(CFLAGS) -Llibft/ -lft -g -o $(NAME) $(OBJ)

%.o: %.c
	@echo "Building $@"
	@$(CC) $(CFLAGS) -I. -o $@ -c $^

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

$(LIB): lib

lib:
	@make -C libft/
