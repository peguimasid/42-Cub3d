/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:15:37 by gmasid            #+#    #+#             */
/*   Updated: 2023/04/17 19:18:49 by gmasid           ###   ########.fr       */
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
	if (game->map.array[(int)x][(int)y] != '1')
		return (0x00000000);
	texture_x = (int)(texture->width * (x + y)) % texture->width;
	return (get_texture_pixel_color(texture_x, texture_y, texture));
}

void	handle_texture(int ray_count, int wall_height, t_game *game)
{
	float	delta_y;
	float	wall_top;
	float	current_y;
	float	current_y_end;
	int		y;
	int		color;
	t_img	*texture;

	texture = get_wall_texture(game);
	delta_y = ((float)wall_height * 2) / (float)texture->height;
	wall_top = ((float)WINDOW_HEIGHT / 2) - (float)wall_height;
	current_y = wall_top;
	y = 0;
	while (y < texture->height)
	{
		color = get_texture_color(texture, y, game);
		current_y_end = current_y + delta_y;
		while (current_y < current_y_end)
		{
			if (current_y >= 0 && current_y < (float)WINDOW_HEIGHT)
				set_pixel_color(ray_count, current_y, color, game);
			current_y++;
		}
		current_y = current_y_end;
		y++;
	}
}
