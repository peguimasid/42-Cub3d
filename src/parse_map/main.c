/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:19:23 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/28 17:39:59 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	handle_line(char *line, int count)
{
	if (count < 6)
		return (handle_texture_line(line));
	return (handle_map_line(line));
}

void	parse_map(char *path, t_game *game)
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
			handle_line(line, count++);
		free(line);
		line = get_next_line_trimmed(fd);
	}
	close(fd);
}
