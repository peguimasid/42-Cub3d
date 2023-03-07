/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:25:36 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/07 17:36:32 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main_loop(t_game *game)
{
	printf("is w pressed = %d\n", game->keys.is_w_pressed);
	printf("is a pressed = %d\n", game->keys.is_a_pressed);
	printf("is s pressed = %d\n", game->keys.is_s_pressed);
	printf("is d pressed = %d\n", game->keys.is_d_pressed);
	return (0);
}

int	key_down(int key, t_game *game)
{
	if (key == KEY_W)
		game->keys.is_w_pressed = 1;
	if (key == KEY_A)
		game->keys.is_a_pressed = 1;
	if (key == KEY_S)
		game->keys.is_s_pressed = 1;
	if (key == KEY_D)
		game->keys.is_d_pressed = 1;
	return (0);
}

int	key_up(int key, t_game *game)
{
	if (key == KEY_W)
		game->keys.is_w_pressed = 0;
	if (key == KEY_A)
		game->keys.is_a_pressed = 0;
	if (key == KEY_S)
		game->keys.is_s_pressed = 0;
	if (key == KEY_D)
		game->keys.is_d_pressed = 0;
	return (0);
}

void	init_config(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	game->keys.is_w_pressed = 0;
	game->keys.is_a_pressed = 0;
	game->keys.is_s_pressed = 0;
	game->keys.is_d_pressed = 0;
}

int	main(void)
{
	t_game	game;

	init_config(&game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_hook(game.win, ON_KEYDOWN, 0, &key_down, &game);
	mlx_hook(game.win, ON_KEYUP, 0, &key_up, &game);
	mlx_loop(game.mlx);
}
