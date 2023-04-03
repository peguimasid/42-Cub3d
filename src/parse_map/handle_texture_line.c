/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_texture_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:12:19 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/31 14:41:37 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	load_texture_from_path(char *key, char *path, t_game *game)
{
	if (is_north(key))
		game->textures.north = load_img_from_path(path, game);
	if (is_south(key))
		game->textures.south = load_img_from_path(path, game);
	if (is_west(key))
		game->textures.west = load_img_from_path(path, game);
	if (is_east(key))
		game->textures.east = load_img_from_path(path, game);
	free(key);
	free(path);
}

void	load_color_from_string(char *key, char *string, t_game *game)
{
	if (is_floor(key))
		game->textures.floor = get_color_from_string(string, game);
	if (is_ceiling(key))
		game->textures.ceiling = get_color_from_string(string, game);
	free(key);
	free(string);
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
