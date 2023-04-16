/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:53:06 by gmasid            #+#    #+#             */
/*   Updated: 2023/04/16 17:09:03 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_pixel_color(int x, int y, int color, t_game *game)
{
	char	*dst;
	t_img	*img;

	img = &game->window_image;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_texture_pixel_color(int x, int y, t_img *img)
{
	char	*result;

	result = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(unsigned int *)result);
}

int	is_within_ray_limit(int x, int y, t_game *game)
{
	float	delta_x;
	float	delta_y;
	float	distance;

	delta_x = x - game->player.x_pos - 0.5;
	delta_y = y - game->player.y_pos - 0.5;
	distance = sqrt(powf(delta_x, 2.) + powf(delta_y, 2.));
	return (distance < game->ray.limit);
}

int	is_wall(int x, int y, t_game *game)
{
	return (game->map.array[x][y] == '1');
}

int	has_ray_reached_limit(t_game *game)
{
	if (!is_within_ray_limit(game->ray.x_pos, game->ray.y_pos, game))
		return (1);
	return (is_wall(game->ray.x_pos, game->ray.y_pos, game));
}
