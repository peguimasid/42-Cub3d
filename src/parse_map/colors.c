/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:15:22 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/31 14:42:16 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	invalid_color(char *string, char **parts, t_game *game)
{
	free(string);
	free_matrix(parts);
	return (exit_app("Invalid color", game));
}

int	is_valid(char **parts)
{
	if (!parts || matrix_len(parts) != 3)
		return (0);
	print_matrix(parts);
	printf("----\n");
	return (1);
}

int	get_color_from_string(char *string, t_game *game)
{
	char	**parts;
	int		r;
	int		g;
	int		b;
	int		color;

	parts = ft_split(string, ',');
	if (!is_valid(parts))
		return (invalid_color(string, parts, game));
	r = ft_atoi(parts[0]);
	g = ft_atoi(parts[1]);
	b = ft_atoi(parts[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (invalid_color(string, parts, game));
	color = (r << 16) | (g << 8) | b;
	free_matrix(parts);
	return (color);
}
