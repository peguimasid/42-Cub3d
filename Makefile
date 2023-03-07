NAME=cub3D

SRCS	= lib/get_next_line/get_next_line.c	\
				lib/get_next_line/get_next_line_utils.c	\
				src/main.c \
				src/handle_keys.c \

LIBFT = lib/libft/libft.a

OBJ	= $(SRCS:.c=.o)

%.o: %.c
	cc -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	make -s -C mlx
	make -s -C lib/libft
	cc $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT)

all: $(NAME)

clean:
	make clean -s -C mlx
	make clean -s -C lib/libft
	rm -f $(OBJ)

fclean: clean
	make fclean -s -C lib/libft
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
