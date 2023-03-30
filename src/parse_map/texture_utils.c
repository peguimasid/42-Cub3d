/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:12:19 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/30 16:58:29 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_floor(char *key)
{
	return (ft_strncmp(key, "F", 1) == 0 && ft_strlen(key) == 1);
}

int	is_ceiling(char *key)
{
	return (ft_strncmp(key, "C", 1) == 0 && ft_strlen(key) == 1);
}

int	is_color_texture(char *key)
{
	return (is_floor(key) || is_ceiling(key));
}

int	is_cardinal_direction(char *key)
{
	return (is_north(key) || is_south(key) || is_west(key) || is_east(key));
}

int	is_valid_key(char *key)
{
	return (is_cardinal_direction(key) || is_color_texture(key));
}
