/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:08:15 by gmasid            #+#    #+#             */
/*   Updated: 2023/04/17 19:19:49 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	get_angle(int key, t_game *game)
{
	if (key == KEY_A)
		return (game->ray.angle + 90);
	if (key == KEY_S)
		return (game->ray.angle - 180);
	if (key == KEY_D)
		return (game->ray.angle - 90);
	return (game->ray.angle);
}

void	update_player_position(float ray_sin, float ray_cos, t_game *game)
{
	int	new_x;
	int	new_y;
	int	curr_x;
	int	curr_y;

	new_x = game->player.x_pos + 0.5 + (3 * ray_cos);
	new_y = game->player.y_pos + 0.5 + (3 * ray_sin);
	curr_x = game->player.x_pos + 0.5;
	curr_y = game->player.y_pos + 0.5;
	if (game->map.array[new_x][curr_y] != '1')
		game->player.x_pos += ray_cos;
	if (game->map.array[curr_x][new_y] != '1')
		game->player.y_pos += ray_sin;
}

void	move_player(int key, t_game *game)
{
	float	angle;
	float	ray_cos;
	float	ray_sin;

	angle = get_angle(key, game);
	ray_cos = cos(degree_to_radians(angle)) * game->player.speed;
	ray_sin = sin(degree_to_radians(angle)) * game->player.speed;
	update_player_position(ray_sin, ray_cos, game);
}

void	handle_player_move(t_game *game)
{
	if (game->keys.is_arrow_left_pressed)
		game->ray.angle += 3;
	if (game->keys.is_arrow_right_pressed)
		game->ray.angle -= 3;
	if (game->keys.is_w_pressed)
		move_player(KEY_W, game);
	if (game->keys.is_a_pressed)
		move_player(KEY_A, game);
	if (game->keys.is_s_pressed)
		move_player(KEY_S, game);
	if (game->keys.is_d_pressed)
		move_player(KEY_D, game);
}
