/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_texture_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:12:19 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/29 18:29:51 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	handle_texture_line(char *line, t_game *game)
{
	char	*key;
	char	*value;

	key = get_texture_key(line, game);
	value = get_texture_value(line, game);
	printf("key = '%s' || value = '%s'\n", key, value);
	free(key);
	free(value);
}
