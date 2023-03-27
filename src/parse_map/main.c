/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:19:23 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/27 19:14:30 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	handle_line(char *line, int count)
{
	printf("line = %s || count = %d\n", line, count);
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
		if (ft_strlen(line))
			handle_line(line, count++);
		free(line);
		line = get_next_line_trimmed(fd);
	}
	close(fd);
}
