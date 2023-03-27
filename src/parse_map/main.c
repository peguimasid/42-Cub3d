/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:19:23 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/27 19:07:20 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parse_map(char *path, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line_trimmed(fd);
	if (!line)
		exit_app("You provide an empty file", game);
	while (line)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line_trimmed(fd);
	}
	close(fd);
}
