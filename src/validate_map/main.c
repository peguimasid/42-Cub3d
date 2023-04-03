/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:56:04 by gmasid            #+#    #+#             */
/*   Updated: 2023/04/03 18:33:28 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
			if (!ft_strchr("NSEW 01", game->map.array[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	validate_map(t_game *game)
{
	if (contains_invalid_char(game))
		exit_app("You provide invalid char in map", game);
}
