/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:56:04 by gmasid            #+#    #+#             */
/*   Updated: 2023/04/03 18:54:01 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_player_cell(char map_cell)
{
	return (ft_strchr("NSEW", map_cell) != 0);
}

int	is_valid_cell(char map_cell)
{
	return (ft_strchr("NSEW 01", map_cell) != 0);
}

void	set_player_props(t_game *game, int x, int y, char player_dir)
{
	game->player.dir = player_dir;
	game->player.x_pos = x;
	game->player.y_pos = y;
}

void	verify_player_existence(t_game *game)
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

int	contains_invalid_char(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.array[i])
	{
		j = 0;
		while (game->map.array[i][j])
		{
			if (!is_valid_cell(game->map.array[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	validate_map(t_game *game)
{
	verify_player_existence(game);
	if (contains_invalid_char(game))
		exit_app("You provide invalid char in map", game);
}
