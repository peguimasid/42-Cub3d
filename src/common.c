/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:47:46 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/26 11:24:13 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_game(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(0);
	return (0);
}

int	exit_app(char *message, t_game *game)
{
	if (message)
		throw_error(message);
	return (close_game(game));
}
