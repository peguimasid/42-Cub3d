/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:56:04 by gmasid            #+#    #+#             */
/*   Updated: 2023/04/03 18:56:55 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	validate_map(t_game *game)
{
	verify_player_existence(game);
	if (contains_invalid_char(game))
		exit_app("You provide invalid char in map", game);
}
