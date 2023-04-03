/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_open_walls.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:22:45 by gmasid            #+#    #+#             */
/*   Updated: 2023/04/03 19:59:38 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_valid_position(char **map, int x, int y)
{
	if (!map[x] || !map[x][y])
		return (0);
	return (map[x][y] == '1' || map[x][y] == '0');
}

void	check_for_open_wall(char **map, int px, int py, t_game *game)
{
	if (!is_valid_position(map, px, py))
	{
		free_matrix(map);
		exit_app("Invalid map", game);
	}
	if (map[px][py] == '1')
		return ;
	map[px][py] = '1';
	check_for_open_wall(map, px + 1, py, game);
	check_for_open_wall(map, px - 1, py, game);
	check_for_open_wall(map, px, py + 1, game);
	check_for_open_wall(map, px, py - 1, game);
}

void	check_for_open_walls(t_game *game)
{
	char	**map;
	int		px;
	int		py;

	px = game->player.x_pos;
	py = game->player.y_pos;
	map = dup_matrix(game->map.array);
	map[px][py] = '0';
	check_for_open_wall(map, px, py, game);
	free_matrix(map);
}
