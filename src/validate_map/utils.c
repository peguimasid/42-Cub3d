/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:55:37 by gmasid            #+#    #+#             */
/*   Updated: 2023/04/03 18:57:22 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_player_cell(char map_cell)
{
	return (ft_strchr("NSEW", map_cell) != 0);
}

int	is_valid_cell(char map_cell)
{
	return (ft_strchr("NSEW 01", map_cell) != 0);
}
