/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:11:07 by gmasid            #+#    #+#             */
/*   Updated: 2023/04/08 21:51:02 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	cub_draw(t_game *g, int ray_count, float dis)
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
			my_mlx_pixel_put(&g->window_image, ray_count, j,
					g->textures.ceiling);
		else if (j >= (WINDOW_HEIGHT / 2) + wall_height)
			my_mlx_pixel_put(&g->window_image, ray_count, j, g->textures.floor);
		else
			my_mlx_pixel_put(&g->window_image, ray_count, j, 0xFFFF00);
	}
}

float	distance_to_wall(t_game *game, float ray_angle)
{
	float	d;
	float	x;
	float	y;

	game->ray.cos = cos(degree_to_radians(ray_angle)) / game->ray.precision;
	game->ray.sin = sin(degree_to_radians(ray_angle)) / game->ray.precision;
	x = game->player.x_pos + 0.5;
	y = game->player.y_pos + 0.5;
	while (game->map.array[(int)x][(int)y] != '1' &&
			sqrt(powf(x - game->player.x_pos - 0.5, 2.) +
				powf(y - game->player.y_pos - 0.5, 2.)) < game->ray.limit)
	{
		x += game->ray.cos;
		y += game->ray.sin;
	}
	d = sqrt(powf(x - game->player.x_pos - 0.5, 2.) + powf(y
				- game->player.y_pos - 0.5, 2.));
	return (d * cos(degree_to_radians(ray_angle - game->ray.angle)));
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
