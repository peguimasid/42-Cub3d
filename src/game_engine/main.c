/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:02:59 by gmasid            #+#    #+#             */
/*   Updated: 2023/04/04 19:21:43 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	initialize_window(t_game *game)
{
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	game->window_image.i = mlx_new_image(game->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	game->window_image.addr = mlx_get_data_addr(game->window_image.i,
			&game->window_image.bpp, &game->window_image.line_len,
			&game->window_image.endian);
}

void	initialize_ray(t_game *game)
{
	if (game->player.dir == 'N')
		game->ray.angle = 270;
	if (game->player.dir == 'W')
		game->ray.angle = 180;
	if (game->player.dir == 'S')
		game->ray.angle = 90;
	if (game->player.dir == 'E')
		game->ray.angle = 0;
}

void	start_game(t_game *game)
{
	initialize_window(game);
	initialize_ray(game);
	mlx_hook(game->win, 2, 1L << 0, handle_key_down, game);
	mlx_hook(game->win, 3, 1L << 1, handle_key_up, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
}
