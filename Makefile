NAME = cub3D

CC = cc
CPPFLAGS = -Wall -Werror -Wextra

SRCS = main.c

all: $(NAME)

$(NAME):
	$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: fclean, all, re
