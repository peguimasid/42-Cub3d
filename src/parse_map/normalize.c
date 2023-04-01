/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:39:32 by gmasid            #+#    #+#             */
/*   Updated: 2023/04/01 20:00:48 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*normalize_row(int row_index, t_game *game)
{
	char	*result;
	int		i;

	result = malloc(sizeof(char) * (game->map.width + 1));
	i = 0;
	while (i < game->map.width)
	{
		if (i >= (int)ft_strlen(game->map.array[row_index]))
			result[i] = ' ';
		else
			result[i] = game->map.array[row_index][i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	normalize_map(t_game *game)
{
	char	**result;
	int		i;

	result = malloc(sizeof(char *) * (game->map.height + 1));
	i = 0;
	while (i < game->map.height)
	{
		result[i] = normalize_row(i, game);
		i++;
	}
	result[i] = NULL;
	free_matrix(game->map.array);
	game->map.array = result;
}
