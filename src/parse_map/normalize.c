/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:39:32 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/31 21:51:13 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	normalize_row(char *row, int row_index, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.width)
	{
		if (i >= (int)ft_strlen(game->map.array[row_index]))
			row[i] = ' ';
		else
			row[i] = game->map.array[row_index][i];
		i++;
	}
	row[i] = '\0';
}

void	normalize_map(t_game *game)
{
	char	**temp;
	int		i;

	temp = malloc(sizeof(char *) * (game->map.height + 1));
	i = 0;
	while (i < game->map.height)
	{
		temp[i] = malloc(sizeof(char) * (game->map.width + 1));
		normalize_row(temp[i], i, game);
		i++;
	}
	temp[i] = NULL;
	free_matrix(game->map.array);
	game->map.array = temp;
}
