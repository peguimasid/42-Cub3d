/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:53:12 by gmasid            #+#    #+#             */
/*   Updated: 2023/04/02 12:03:53 by gmasid           ###   ########.fr       */
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
	game->textures.black = NULL;
	game->textures.floor = -1;
	game->textures.ceiling = -1;
	game->textures.black = load_img_from_path("textures/black.xpm", game);
	if (!game->textures.black || !game->textures.black->i)
		exit_app("Run cub3d from the root of the project", game);
}

void	init_frame(t_game *game)
{
	game->frame.count = 0;
	game->frame.rate = 30;
}
