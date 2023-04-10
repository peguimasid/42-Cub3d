/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:45:21 by gmasid            #+#    #+#             */
/*   Updated: 2023/04/09 15:54:00 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"
# include "../mlx/mlx.h"
# include "constants.h"
# include "structs.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		window_image;
	t_map		map;
	t_ray		ray;
	t_pressed	keys;
	t_frame		frame;
	t_player	player;
	t_textures	textures;
}				t_game;

// General
int				close_game(t_game *game);
int				exit_app(char *message, t_game *game);

// Game Engine
void			start_game(t_game *game);
int				game_loop(t_game *game);
int				handle_key_down(int key, t_game *game);
int				handle_key_up(int key, t_game *game);
void			handle_player_move(t_game *game);
void			render_scene(t_game *game);

void			set_pixel_color(int x, int y, int color, t_game *game);
int				is_within_ray_limit(int x, int y, t_game *game);
int				is_wall(int x, int y, t_game *game);

// Validation
int				send_valid_file(int argc, char **argv);

// Start
void			init_cub(t_game *game);
void			init_ray(t_game *game);
void			init_keys(t_game *game);
void			init_textures(t_game *game);
void			init_frame(t_game *game);

// Parse Map
void			parse_map(char *path, t_game *game);
void			handle_map_line(char *line, t_game *game);
void			handle_texture_line(char *line, t_game *game);
void			normalize_map(t_game *game);
char			*get_next_line_trimmed(int fd);
char			*get_texture_key(char *line, t_game *game);
char			*get_texture_value(char *line, t_game *game);
int				get_color_from_string(char *string, t_game *game);

int				is_map_line(int count);
int				is_valid_key(char *key);
int				is_duplicate_key(char *key, t_game *game);
int				is_color_texture(char *key);
int				is_cardinal_direction(char *key);
int				is_north(char *key);
int				is_south(char *key);
int				is_west(char *key);
int				is_east(char *key);
int				is_floor(char *key);
int				is_ceiling(char *key);

// Validate Map
void			validate_map(t_game *game);

void			check_invalid_char(t_game *game);
void			check_player_existence(t_game *game);
void			check_for_open_walls(t_game *game);
void			set_player_props(t_game *game, int x, int y, char player_dir);

int				is_player_cell(char map_cell);
int				is_valid_cell(char map_cell);

// Error
int				throw_error(char *error);

// Utils
t_img			*load_img_from_path(char *path, t_game *game);
int				can_open_file(char *path);
int				max(int a, int b);
float			degree_to_radians(float degree);

int				matrix_len(char **matrix);
void			free_matrix(char **matrix);
void			print_matrix(char **matrix);
char			**dup_matrix(char **matrix);
char			**matrix_push(char **matrix, char *new);
char			**matrix_remove(char **matrix, int to_remove);
char			**matrix_replace(char **matrix, int i, char *new_value);

#endif
