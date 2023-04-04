/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:02:59 by gmasid            #+#    #+#             */
/*   Updated: 2023/04/04 18:11:59 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	game_loop(t_game *game)
{
	(void)game;
	printf("OK\n");
	return (1);
}

void	initialize_window(t_game *game)
{
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d");
}

void	start_game(t_game *game)
{
	initialize_window(game);
	mlx_hook(game->win, 2, 1L << 0, handle_key_down, game);
	mlx_hook(game->win, 3, 1L << 1, handle_key_up, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
}
