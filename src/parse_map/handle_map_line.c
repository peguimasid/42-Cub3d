/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:12:19 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/28 18:31:23 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	handle_map_line(char *line, t_game *game)
{
	game->map.array = matrix_push(game->map.array, line);
	game->map.width = max(game->map.width, ft_strlen(line));
	game->map.height++;
}
