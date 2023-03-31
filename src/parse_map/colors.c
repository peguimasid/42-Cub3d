/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:15:22 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/31 15:20:16 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	invalid_color(char *string, char **parts, t_game *game)
{
	free(string);
	free_matrix(parts);
	return (exit_app("Invalid color", game));
}

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

int	is_string_numeric(char *string)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(string);
	while (i < len)
	{
		if (!ft_isdigit(string[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_color_parts_valid(char **parts)
{
	int	i;

	if (!parts || matrix_len(parts) != 3)
		return (0);
	i = 0;
	while (i < matrix_len(parts))
	{
		if (!is_string_numeric(parts[i]))
			return (0);
		i++;
	}
	return (1);
}

int	get_color_from_string(char *string, t_game *game)
{
	char	**parts;
	int		r;
	int		g;
	int		b;

	parts = ft_split(string, ',');
	if (!is_color_parts_valid(parts))
		return (invalid_color(string, parts, game));
	r = ft_atoi(parts[0]);
	g = ft_atoi(parts[1]);
	b = ft_atoi(parts[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (invalid_color(string, parts, game));
	free_matrix(parts);
	return (rgb_to_int(r, g, b));
}
