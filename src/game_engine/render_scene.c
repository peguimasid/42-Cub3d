/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:11:07 by gmasid            #+#    #+#             */
/*   Updated: 2023/04/08 22:41:29 by gmasid           ###   ########.fr       */
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
	float	wall_start;
	float	wall_end;
	int		i;

	wall_height = (int)(WINDOW_HEIGHT / (1.5 * dis));
	wall_start = (float)((WINDOW_HEIGHT / 2) - wall_height);
	wall_end = (float)((WINDOW_HEIGHT / 2) + wall_height);
	i = -1;
	while (++i < WINDOW_HEIGHT)
	{
		if (i < wall_start)
			set_pixel_color(ray_count, i, game->textures.ceiling, game);
		else if (i >= wall_end)
			set_pixel_color(ray_count, i, game->textures.floor, game);
		else
			set_pixel_color(ray_count, i, 0xFFFF00, game);
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

float	calculate_wall_distance(t_game *game, float ray_angle)
{
	float	distance;
	float	x;
	float	y;
	float	x_diff;
	float	y_diff;

	game->ray.cos = cos(degree_to_radians(ray_angle)) / game->ray.precision;
	game->ray.sin = sin(degree_to_radians(ray_angle)) / game->ray.precision;
	x = game->player.x_pos + 0.5;
	y = game->player.y_pos + 0.5;
	while (!is_wall(x, y, game) && is_within_ray_limit(x, y, game))
	{
		x += game->ray.cos;
		y += game->ray.sin;
	}
	x_diff = x - game->player.x_pos - 0.5;
	y_diff = y - game->player.y_pos - 0.5;
	distance = sqrt(powf(x_diff, 2.) + powf(y_diff, 2.));
	return (distance * cos(degree_to_radians(ray_angle - game->ray.angle)));
}

void	render_scene(t_game *game)
{
	float	ray_angle;
	int		ray_count;
	float	distance;

	ray_angle = game->ray.angle - game->ray.hfov;
	ray_count = 0;
	while (ray_count < WINDOW_WIDTH)
	{
		distance = calculate_wall_distance(game, ray_angle);
		cub_draw(game, ray_count, distance);
		ray_angle += game->ray.increment_angle;
		ray_count++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->window_image.i, 0, 0);
}
