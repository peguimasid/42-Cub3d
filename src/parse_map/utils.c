/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:19:23 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/29 18:32:52 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*get_next_line_trimmed(int fd)
{
	char	*tmp;
	char	*line;

	tmp = get_next_line(fd);
	line = ft_strtrim(tmp, "\n");
	free(tmp);
	return (line);
}

int	is_map_line(int count)
{
	return (count > 6);
}

char	*get_texture_key(char *line, t_game *game)
{
	char	**split;
	char	*result;

	split = ft_split(line, ' ');
	if (matrix_len(split) != 2)
	{
		free_matrix(split);
		exit_app("Exactly two positions in texture line", game);
	}
	result = ft_strdup(split[0]);
	free_matrix(split);
	return (result);
}

char	*get_texture_value(char *line, t_game *game)
{
	char	**split;
	char	*result;

	split = ft_split(line, ' ');
	if (matrix_len(split) != 2)
	{
		free_matrix(split);
		exit_app("Exactly two positions in texture line", game);
	}
	result = ft_strdup(split[1]);
	free_matrix(split);
	return (result);
}
