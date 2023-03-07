/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:45:21 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/07 17:43:17 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"
# include "../mlx/mlx.h"
# include "constants.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_pressed
{
	int			is_w_pressed;
	int			is_a_pressed;
	int			is_s_pressed;
	int			is_d_pressed;
}				t_pressed;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_pressed	keys;
}				t_game;

void			init_config(t_game *game);

int				handle_keydown(int key, t_game *game);
int				handle_keyup(int key, t_game *game);

#endif
