/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:25:36 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/31 20:39:39 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_map(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
	{
		printf("'%s'\n", matrix[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (!send_valid_file(argc, argv))
		return (1);
	init_cub(&game);
	parse_map(argv[1], &game);
	print_map(game.map.array);
	// TODO: Remove this 'close_game' function from here
	close_game(&game);
}
