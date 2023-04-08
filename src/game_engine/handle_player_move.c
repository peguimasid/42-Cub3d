/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:08:15 by gmasid            #+#    #+#             */
/*   Updated: 2023/04/08 13:29:36 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	get_angle(int key, t_game *game)
{
	if (key == KEY_A)
		return (game->ray.angle - 90);
	if (key == KEY_S)
		return (game->ray.angle - 180);
	if (key == KEY_D)
		return (game->ray.angle + 90);
	return (game->ray.angle);
}

void	move_player(int key, t_game *game, float ray_cos, float ray_sin)
{
	float	angle;

	angle = get_angle(key, game);
	ray_cos = cos(degree_to_radians(angle)) * game->player.speed;
	ray_sin = sin(degree_to_radians(angle)) * game->player.speed;
	game->player.y_pos += ray_sin;
	game->player.x_pos += ray_cos;
}

void	handle_player_move(t_game *game)
{
	printf(">>> %f %f\n", game->player.x_pos, game->player.y_pos);
	if (game->keys.is_arrow_left_pressed)
		game->ray.angle -= 3;
	if (game->keys.is_arrow_right_pressed)
		game->ray.angle += 3;
	if (game->keys.is_w_pressed)
		move_player(KEY_W, game, 0, 0);
	if (game->keys.is_a_pressed)
		move_player(KEY_A, game, 0, 0);
	if (game->keys.is_s_pressed)
		move_player(KEY_S, game, 0, 0);
	if (game->keys.is_d_pressed)
		move_player(KEY_D, game, 0, 0);
}
