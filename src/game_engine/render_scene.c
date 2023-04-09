/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:11:07 by gmasid            #+#    #+#             */
/*   Updated: 2023/04/08 22:24:58 by gmasid           ###   ########.fr       */
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

void	cub_draw(t_game *game, int ray_count, float dis)
{
	int		wall_height;
	float	ds;
	int		j;

	wall_height = (int)(WINDOW_HEIGHT / (1.5 * dis));
	ds = ((float)WINDOW_HEIGHT / 2) - (float)wall_height;
	j = -1;
	while (++j < WINDOW_HEIGHT)
	{
		if (j < ds)
			set_pixel_color(ray_count, j, game->textures.ceiling, game);
		else if (j >= (WINDOW_HEIGHT / 2) + wall_height)
			set_pixel_color(ray_count, j, game->textures.floor, game);
		else
			set_pixel_color(ray_count, j, 0xFFFF00, game);
	}
}

int	is_within_ray_limit(int x, int y, t_game *game)
{
	float	dx;
	float	dy;
	float	distance;

	dx = x - game->player.x_pos - 0.5;
	dy = y - game->player.y_pos - 0.5;
	distance = sqrt(powf(dx, 2.) + powf(dy, 2.));
	return (distance < game->ray.limit);
}

int	is_wall(int x, int y, t_game *game)
{
	return (game->map.array[x][y] == '1');
}

float	distance_to_wall(t_game *game, float ray_angle)
{
	float	distance;
	float	x;
	float	y;

	game->ray.cos = cos(degree_to_radians(ray_angle)) / game->ray.precision;
	game->ray.sin = sin(degree_to_radians(ray_angle)) / game->ray.precision;
	x = game->player.x_pos + 0.5;
	y = game->player.y_pos + 0.5;
	while (!is_wall(x, y, game) && is_within_ray_limit(x, y, game))
	{
		x += game->ray.cos;
		y += game->ray.sin;
	}
	distance = sqrt(powf(x - game->player.x_pos - 0.5, 2.) + powf(y
				- game->player.y_pos - 0.5, 2.));
	return (distance * cos(degree_to_radians(ray_angle - game->ray.angle)));
}

void	render_scene(t_game *game)
{
	float	ray_angle;
	int		ray_count;
	float	dist;

	ray_angle = game->ray.angle - game->ray.hfov;
	ray_count = -1;
	while (++ray_count < WINDOW_WIDTH)
	{
		dist = distance_to_wall(game, ray_angle);
		cub_draw(game, ray_count, dist);
		ray_angle += game->ray.increment_angle;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->window_image.i, 0, 0);
}
