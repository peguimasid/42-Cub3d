/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:47:46 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/31 20:15:10 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	destroy_texture(t_img *img, t_game *game)
{
	if (img && img->i)
		mlx_destroy_image(game->mlx, img->i);
}

int	close_game(t_game *game)
{
	destroy_texture(game->textures.north, game);
	destroy_texture(game->textures.south, game);
	destroy_texture(game->textures.west, game);
	destroy_texture(game->textures.east, game);
	destroy_texture(game->textures.black, game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	free_matrix(game->map.array);
	exit(0);
	return (0);
}

int	throw_error(char *error)
{
	printf("\033[0;31m");
	printf("Error\n%s\n", error);
	printf("\033[0m");
	return (0);
}

int	exit_app(char *message, t_game *game)
{
	if (message)
		throw_error(message);
	return (close_game(game));
}
