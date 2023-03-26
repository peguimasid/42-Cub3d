/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:42:52 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/26 10:49:41 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
}

void	init_map(t_game *game)
{
	game->map.array = NULL;
	game->map.height = 0;
	game->map.width = 0;
}

void	init_player(t_game *game)
{
	game->player.dir = 0;
	game->player.speed = 0.10;
	game->player.x_pos = -1;
	game->player.y_pos = -1;
}

void	init_cub(t_game *game)
{
	init_mlx(game);
	init_map(game);
	init_ray(game);
	init_keys(game);
	init_textures(game);
	init_player(game);
	init_frame(game);
}
