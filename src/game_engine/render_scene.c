/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:11:07 by gmasid            #+#    #+#             */
/*   Updated: 2023/04/14 15:21:15 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	render_wall_column_pixel(int x, int y, int wall_height, t_game *game)
{
	float	wall_start;
	float	wall_end;

	wall_start = (WINDOW_HEIGHT / 2) - wall_height;
	wall_end = (WINDOW_HEIGHT / 2) + wall_height;
	if (y < wall_start)
		return (set_pixel_color(x, y, game->textures.ceiling, game));
	if (y >= wall_end)
		return (set_pixel_color(x, y, game->textures.floor, game));
	return (handle_texture(x, y, wall_height, game));
}

void	render_wall_column(t_game *game, int x, float dis)
{
	int	wall_height;
	int	y;

	wall_height = WINDOW_HEIGHT / (1.5 * dis);
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		render_wall_column_pixel(x, y, wall_height, game);
		y++;
	}
}

float	calculate_wall_distance(t_game *game, float ray_angle)
{
	float	distance;
	float	x;
	float	y;
	float	delta_x;
	float	delta_y;

	game->ray.cos = cos(degree_to_radians(ray_angle)) / game->ray.precision;
	game->ray.sin = sin(degree_to_radians(ray_angle)) / game->ray.precision;
	x = game->player.x_pos + 0.5;
	y = game->player.y_pos + 0.5;
	while (!is_wall(x, y, game) && is_within_ray_limit(x, y, game))
	{
		x += game->ray.cos;
		y += game->ray.sin;
	}
	delta_x = x - game->player.x_pos - 0.5;
	delta_y = y - game->player.y_pos - 0.5;
	distance = sqrt(powf(delta_x, 2.) + powf(delta_y, 2.));
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
		render_wall_column(game, ray_count, distance);
		ray_angle += game->ray.increment_angle;
		ray_count++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->window_image.i, 0, 0);
}
