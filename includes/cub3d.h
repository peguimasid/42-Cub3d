/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:45:21 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/27 18:40:55 by gmasid           ###   ########.fr       */
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

int				handle_keydown(int key, t_game *game);
int				handle_keyup(int key, t_game *game);

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
char			*get_next_line_trimmed(int fd);

// Error
int				throw_error(char *error);

// Utils
t_img			*load_img_from_path(char *path, t_game *game);
int				can_open_file(char *path);

#endif
