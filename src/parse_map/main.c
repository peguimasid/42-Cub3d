/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:19:23 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/31 20:46:52 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	handle_line(char *line, int count, t_game *game)
{
	if (count < 6)
		return (handle_texture_line(line, game));
	return (handle_map_line(line, game));
}

void	parse_map_file_and_set_textures(char *path, t_game *game)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(path, O_RDONLY);
	count = 0;
	line = get_next_line_trimmed(fd);
	if (!line)
		exit_app("You provide an empty file", game);
	while (line)
	{
		if (is_map_line(count) && !ft_strlen(line))
			exit_app("Empty line inside map", game);
		if (ft_strlen(line))
			handle_line(line, count++, game);
		free(line);
		line = get_next_line_trimmed(fd);
	}
	close(fd);
}

void	normalize_map(t_game *game)
{
	(void)game;
}

void	parse_map(char *path, t_game *game)
{
	parse_map_file_and_set_textures(path, game);
	normalize_map(game);
}
