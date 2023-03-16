/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:45:21 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/16 19:42:19 by gmasid           ###   ########.fr       */
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
	t_map		map;
	t_ray		ray;
	t_pressed	keys;
	t_frame		frame;
	t_player	player;
	t_textures	textures;
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
