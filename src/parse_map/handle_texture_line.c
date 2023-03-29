/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_texture_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:12:19 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/29 18:52:32 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	handle_texture_line(char *line, t_game *game)
{
	char	*key;
	char	*value;

	key = get_texture_key(line, game);
	if (!is_valid_key(key) || is_duplicate_key(key, game))
	{
		free(key);
		exit_app("You send either invalid or duplicated keys", game);
	}
	value = get_texture_value(line, game);
	(void)value;
}
