/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:14:41 by gmasid            #+#    #+#             */
/*   Updated: 2023/04/05 14:52:12 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	game_loop(t_game *game)
{
	if (game->frame.count % game->frame.rate == 0)
	{
		printf("count = %ld\n", game->frame.count);
	}
	game->frame.count++;
	return (1);
}
