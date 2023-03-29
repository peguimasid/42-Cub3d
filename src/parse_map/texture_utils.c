/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:12:19 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/29 18:53:43 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_valid_key(char *key)
{
	if (ft_strncmp(key, "NO", 2) == 0 && ft_strlen(key) == 2)
		return (1);
	if (ft_strncmp(key, "SO", 2) == 0 && ft_strlen(key) == 2)
		return (1);
	if (ft_strncmp(key, "WE", 2) == 0 && ft_strlen(key) == 2)
		return (1);
	if (ft_strncmp(key, "EA", 2) == 0 && ft_strlen(key) == 2)
		return (1);
	if (ft_strncmp(key, "F", 1) == 0 && ft_strlen(key) == 1)
		return (1);
	if (ft_strncmp(key, "C", 1) == 0 && ft_strlen(key) == 1)
		return (1);
	return (0);
}

int	is_duplicate_key(char *key, t_game *game)
{
	if (ft_strncmp(key, "NO", 2) == 0 && game->textures.north)
		return (1);
	if (ft_strncmp(key, "SO", 2) == 0 && game->textures.south)
		return (1);
	if (ft_strncmp(key, "WE", 2) == 0 && game->textures.west)
		return (1);
	if (ft_strncmp(key, "EA", 2) == 0 && game->textures.east)
		return (1);
	if (ft_strncmp(key, "F", 1) == 0 && game->textures.floor != -1)
		return (1);
	if (ft_strncmp(key, "C", 1) == 0 && game->textures.ceiling != -1)
		return (1);
	return (0);
}
