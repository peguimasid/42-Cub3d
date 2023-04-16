/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:15:37 by gmasid            #+#    #+#             */
/*   Updated: 2023/04/16 16:39:16 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_tex_color(t_game *game, t_img *i, int texture_y)
{
	float	x;
	float	y;
	int		texture_x;

	x = game->ray.x_pos;
	y = game->ray.y_pos;
	(void)x;
	(void)y;
	if (game->map.array[(int)x][(int)y] != '1')
		return (0x00000000);
	texture_x = (int)(i->width * (x + y)) % i->width;
	return (get_texture_pixel_color(texture_x, texture_y, i));
}

void	handle_texture(int ray_count, int wall_height, t_game *game)
{
	float	delta_y;
	float	wall_top;
	float	current_y;
	float	current_y_end;
	int		tex_y;
	int		color;
	t_img	*i;

	i = game->textures.east;
	delta_y = ((float)wall_height * 2) / (float)i->height;
	wall_top = ((float)WINDOW_HEIGHT / 2) - (float)wall_height;
	current_y = wall_top;
	tex_y = 0;
	while (tex_y < i->height)
	{
		color = get_tex_color(game, i, tex_y);
		current_y_end = current_y + delta_y;
		while (current_y < current_y_end)
		{
			if (current_y >= 0 && current_y < (float)WINDOW_HEIGHT)
				set_pixel_color(ray_count, current_y, color, game);
			current_y++;
		}
		current_y = current_y_end;
		tex_y++;
	}
}
