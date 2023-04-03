/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:12:19 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/30 16:59:35 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_north(char *key)
{
	return (ft_strncmp(key, "NO", 2) == 0 && ft_strlen(key) == 2);
}

int	is_south(char *key)
{
	return (ft_strncmp(key, "SO", 2) == 0 && ft_strlen(key) == 2);
}

int	is_west(char *key)
{
	return (ft_strncmp(key, "WE", 2) == 0 && ft_strlen(key) == 2);
}

int	is_east(char *key)
{
	return (ft_strncmp(key, "EA", 2) == 0 && ft_strlen(key) == 2);
}

int	is_duplicate_key(char *key, t_game *game)
{
	if (is_north(key) && game->textures.north)
		return (1);
	if (is_south(key) && game->textures.south)
		return (1);
	if (is_west(key) && game->textures.west)
		return (1);
	if (is_east(key) && game->textures.east)
		return (1);
	if (is_floor(key) && game->textures.floor != -1)
		return (1);
	if (is_ceiling(key) && game->textures.ceiling != -1)
		return (1);
	return (0);
}
