/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:25:36 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/17 17:28:16 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main_loop(t_game *game)
{
	printf("is w pressed = %d\n", game->keys.is_w_pressed);
	printf("is a pressed = %d\n", game->keys.is_a_pressed);
	printf("is s pressed = %d\n", game->keys.is_s_pressed);
	printf("is d pressed = %d\n", game->keys.is_d_pressed);
	printf("is <- pressed = %d\n", game->keys.is_arrow_left_pressed);
	printf("is -> pressed = %d\n", game->keys.is_arrow_right_pressed);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (!send_valid_file(argc, argv))
		return (1);
	init_game(&game);
	mlx_loop_hook(game.mlx, main_loop, &game);
	mlx_hook(game.win, ON_KEYDOWN, 0, handle_keydown, &game);
	mlx_hook(game.win, ON_KEYUP, 0, handle_keyup, &game);
	mlx_hook(game.win, ON_CLOSE_WINDOW, 0, close_game, &game);
	mlx_loop(game.mlx);
}
