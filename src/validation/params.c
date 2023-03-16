/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:46:51 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/16 18:53:49 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_valid_ext(char *path)
{
	int	length;

	length = ft_strlen(path);
	if (ft_strncmp(path + length - 4, ".cub", 4) != 0)
		return (0);
	return (1);
}

int	send_valid_params(int argc, char **argv)
{
	if (argc != 2)
		return (throw_error("Usage: ./cub3D maps/<map>.cub"));
	if (!is_valid_ext(argv[1]))
		return (throw_error("Invalid file extension"));
	return (1);
}
