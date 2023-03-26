/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:53:12 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/26 11:01:35 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_ray(t_game *game)
{
	game->ray.angle = 0;
	game->ray.cos = 0;
	game->ray.hfov = 30;
	game->ray.increment_angle = 2 * game->ray.hfov / WINDOW_WIDTH;
	game->ray.limit = 11;
	game->ray.precision = 50;
	game->ray.sin = 0;
	game->ray.x_pos = 0;
	game->ray.y_pos = 0;
}

void	init_keys(t_game *game)
{
	game->keys.is_w_pressed = 0;
	game->keys.is_a_pressed = 0;
	game->keys.is_s_pressed = 0;
	game->keys.is_d_pressed = 0;
	game->keys.is_arrow_left_pressed = 0;
	game->keys.is_arrow_right_pressed = 0;
}

void	init_textures(t_game *game)
{
	game->window_image.i = NULL;
	game->textures.north = NULL;
	game->textures.south = NULL;
	game->textures.east = NULL;
	game->textures.west = NULL;
	// TODO: Create function to open image and assign to t_img struct
	// game->textures.black = load_image(game->mlx, "textures/black.xpm");
}

void	init_frame(t_game *game)
{
	game->frame.count = 0;
	game->frame.rate = 30;
}
