/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_player_existance.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:55:37 by gmasid            #+#    #+#             */
/*   Updated: 2023/04/03 19:11:30 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_player_props(t_game *game, int x, int y, char player_dir)
{
	game->player.dir = player_dir;
	game->player.x_pos = x;
	game->player.y_pos = y;
}

void	check_player_existence(t_game *game)
{
	int	players_count;
	int	i;
	int	j;

	players_count = 0;
	i = 0;
	while (game->map.array[i])
	{
		j = 0;
		while (game->map.array[i][j])
		{
			if (is_player_cell(game->map.array[i][j]))
			{
				set_player_props(game, i, j, game->map.array[i][j]);
				players_count++;
			}
			j++;
		}
		i++;
	}
	if (players_count != 1)
		exit_app("Send exactly one player", game);
}
