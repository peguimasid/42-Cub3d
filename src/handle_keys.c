/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:39:47 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/31 20:17:14 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	handle_key_down(int key, t_game *game)
{
	if (key == KEY_W)
		game->keys.is_w_pressed = 1;
	if (key == KEY_A)
		game->keys.is_a_pressed = 1;
	if (key == KEY_S)
		game->keys.is_s_pressed = 1;
	if (key == KEY_D)
		game->keys.is_d_pressed = 1;
	if (key == ARROW_LEFT)
		game->keys.is_arrow_left_pressed = 1;
	if (key == ARROW_RIGHT)
		game->keys.is_arrow_right_pressed = 1;
	if (key == KEY_ESC)
		close_game(game);
	return (0);
}

int	handle_key_up(int key, t_game *game)
{
	if (key == KEY_W)
		game->keys.is_w_pressed = 0;
	if (key == KEY_A)
		game->keys.is_a_pressed = 0;
	if (key == KEY_S)
		game->keys.is_s_pressed = 0;
	if (key == KEY_D)
		game->keys.is_d_pressed = 0;
	if (key == ARROW_LEFT)
		game->keys.is_arrow_left_pressed = 0;
	if (key == ARROW_RIGHT)
		game->keys.is_arrow_right_pressed = 0;
	return (0);
}
