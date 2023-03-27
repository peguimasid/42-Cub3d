/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:19:23 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/27 18:41:12 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parse_map(char *path, t_game *game)
{
	int		fd;
	char	*line;

	(void)game;
	fd = open(path, O_RDONLY);
	line = get_next_line_trimmed(fd);
	while (line)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line_trimmed(fd);
	}
	close(fd);
}
