/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:45:21 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/16 19:03:44 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"
# include "../mlx/mlx.h"
# include "constants.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_player
{
	float		x;
	float		y;
	char		dir;
	float		speed;
}				t_player;

typedef struct s_ray
{
	float		increment_angle;
	float		angle;
	float		cos;
	float		sin;
	float		hfov;
	float		limit;
	int			precision;
}				t_ray;

typedef struct s_pressed
{
	int			is_w_pressed;
	int			is_a_pressed;
	int			is_s_pressed;
	int			is_d_pressed;
	int			is_arrow_left_pressed;
	int			is_arrow_right_pressed;
}				t_pressed;

typedef struct s_map
{
	char		**array;
	int			width;
	int			height;
}				t_map;

typedef struct s_frame
{
	long		count;
	int			rate;
}				t_frame;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_ray		ray;
	t_pressed	keys;
	t_frame		frame;
	t_player	player;
}				t_game;

// General
void			init_game(t_game *game);
int				close_game(t_game *game);

int				handle_keydown(int key, t_game *game);
int				handle_keyup(int key, t_game *game);

// Validation
int				send_valid_params(int argc, char **argv);

// Error
int				throw_error(char *error);

#endif
