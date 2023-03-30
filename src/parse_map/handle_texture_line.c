/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_texture_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:12:19 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/30 16:47:49 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	load_texture_from_path(char *key, char *path, t_game *game)
{
	(void)game;
	printf("texture >> %s = %s\n", key, path);
}

void	load_color_from_string(char *key, char *string, t_game *game)
{
	(void)game;
	printf("color >> %s = %s\n", key, string);
}

void	handle_texture_line(char *line, t_game *game)
{
	char	*key;
	char	*value;

	key = get_texture_key(line, game);
	value = get_texture_value(line, game);
	if (is_cardinal_direction(key))
		return (load_texture_from_path(key, value, game));
	return (load_color_from_string(key, value, game));
}
