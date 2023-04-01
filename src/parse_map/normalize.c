/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:39:32 by gmasid            #+#    #+#             */
/*   Updated: 2023/04/01 20:10:28 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*normalize_row(char *original_map_row, t_game *game)
{
	char	*result;
	int		i;
	int		row_length;

	row_length = ft_strlen(original_map_row);
	result = malloc(sizeof(char) * (game->map.width + 1));
	i = 0;
	while (i < game->map.width)
	{
		if (i >= row_length)
			result[i] = ' ';
		else
			result[i] = original_map_row[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	normalize_map(t_game *game)
{
	char	**normalized_map;
	int		i;

	normalized_map = malloc(sizeof(char *) * (game->map.height + 1));
	i = 0;
	while (i < game->map.height)
	{
		normalized_map[i] = normalize_row(game->map.array[i], game);
		i++;
	}
	normalized_map[i] = NULL;
	free_matrix(game->map.array);
	game->map.array = normalized_map;
}
