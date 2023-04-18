NAME=cub3D

SRCS=src/common.c \
src/validate_file.c \
src/start/utils.c \
src/start/main.c \
src/utils/max.c \
src/utils/can_open_file.c \
src/utils/load_image_from_path.c \
src/utils/min.c \
src/utils/degree_to_radians.c \
src/utils/count_char_in_string.c \
src/utils/matrix/matrix_replace.c \
src/utils/matrix/matrix_remove.c \
src/utils/matrix/matrix_push.c \
src/utils/matrix/matrix_dup.c \
src/utils/matrix/matrix_print.c \
src/utils/matrix/matrix_len.c \
src/utils/matrix/matrix_free.c \
src/main.c \
src/validate_map/check_invalid_char.c \
src/validate_map/check_for_open_walls.c \
src/validate_map/utils.c \
src/validate_map/main.c \
src/validate_map/check_player_existance.c \
src/game_engine/game_loop.c \
src/game_engine/handle_player_move.c \
src/game_engine/render_scene_utils.c \
src/game_engine/main.c \
src/game_engine/handle_texture.c \
src/game_engine/handle_keys.c \
src/game_engine/render_scene.c \
src/parse_map/handle_map_line.c \
src/parse_map/utils.c \
src/parse_map/main.c \
src/parse_map/normalize.c \
src/parse_map/texture_utils.c \
src/parse_map/texture_utils2.c \
src/parse_map/handle_texture_line.c \
src/parse_map/colors.c \
lib/get_next_line/get_next_line_utils.c \
lib/get_next_line/get_next_line.c \

LIBFT=lib/libft/libft.a

OBJ=$(SRCS:.c=.o)

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
