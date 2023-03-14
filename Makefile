NAME=cub3D

SRCS=$(shell find src lib/get_next_line -name '*.c')

LIBFT=lib/libft/libft.a

$(NAME):
	make -s -C mlx
	make -s -C lib/libft
	cc -Lmlx -lmlx -framework OpenGL -framework AppKit $(SRCS) -o $(NAME) $(LIBFT)

all: $(NAME)

clean:
	make clean -s -C mlx
	make clean -s -C lib/libft

fclean: clean
	make fclean -s -C lib/libft
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
