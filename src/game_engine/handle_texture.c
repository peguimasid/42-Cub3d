/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:15:37 by gmasid            #+#    #+#             */
/*   Updated: 2023/04/25 13:59:23 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_img	*get_wall_texture(t_game *game)
{
	float	cos;
	float	sin;

	cos = fabs(game->ray.cos);
	sin = fabs(game->ray.sin);
	if (!is_wall(game->ray.x_pos, game->ray.y_pos - sin, game))
		return (game->textures.east);
	if (!is_wall(game->ray.x_pos, game->ray.y_pos + sin, game))
		return (game->textures.west);
	if (!is_wall(game->ray.x_pos + cos, game->ray.y_pos, game))
		return (game->textures.north);
	if (!is_wall(game->ray.x_pos - cos, game->ray.y_pos, game))
		return (game->textures.south);
	return (game->textures.black);
}

int	get_texture_color(t_img *texture, int texture_y, t_game *game)
{
	float	x;
	float	y;
	int		texture_x;

	x = game->ray.x_pos;
	y = game->ray.y_pos;
	if (!is_wall(x, y, game))
		return (0x00000000);
	texture_x = (int)(texture->width * (x + y)) % texture->width;
	return (get_texture_pixel_color(texture_x, texture_y, texture));
}

float	get_wall_start(int wall_height)
{
	return (WINDOW_HEIGHT / 2 - wall_height);
}

void	handle_texture(int ray_count, int wall_height, t_game *game)
{
	float	v[3];
	int		y;
	int		color;
	t_img	*texture;

	texture = get_wall_texture(game);
	v[0] = ((float)wall_height * 2) / (float)texture->height;
	v[1] = get_wall_start(wall_height);
	y = 0;
	while (y < texture->height)
	{
		color = get_texture_color(texture, y, game);
		v[2] = v[1] + v[0];
		while (v[1] < v[2])
		{
			if (v[1] >= 0 && v[1] < (float)WINDOW_HEIGHT)
				set_pixel_color(ray_count, v[1], color, game);
			v[1]++;
		}
		v[1] = v[2];
		y++;
	}
}
