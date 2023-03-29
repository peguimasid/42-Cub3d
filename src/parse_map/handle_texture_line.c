/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_texture_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:12:19 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/29 19:30:56 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	handle_texture_line(char *line, t_game *game)
{
	char	*key;
	char	*value;

	key = get_texture_key(line, game);
	value = get_texture_value(line, game);
	(void)key;
	(void)value;
}
