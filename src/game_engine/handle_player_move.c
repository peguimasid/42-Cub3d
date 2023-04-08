/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:08:15 by gmasid            #+#    #+#             */
/*   Updated: 2023/04/08 13:20:05 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	handle_player_move(t_game *game)
{
	if (game->keys.is_arrow_left_pressed)
		game->ray.angle -= 3;
	if (game->keys.is_arrow_right_pressed)
		game->ray.angle += 3;
	if (game->keys.is_w_pressed)
		printf("User is pressing W\n");
	if (game->keys.is_a_pressed)
		printf("User is pressing A\n");
	if (game->keys.is_s_pressed)
		printf("User is pressing S\n");
	if (game->keys.is_d_pressed)
		printf("User is pressing D\n");
}
