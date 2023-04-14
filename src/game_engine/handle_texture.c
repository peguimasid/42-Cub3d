/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:15:37 by gmasid            #+#    #+#             */
/*   Updated: 2023/04/14 15:21:04 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	handle_texture(int x, int y, int wall_height, t_game *game)
{
	(void)x;
	(void)y;
	(void)wall_height;
	(void)game;
	return (set_pixel_color(x, y, 0xFFFF00, game));
}
