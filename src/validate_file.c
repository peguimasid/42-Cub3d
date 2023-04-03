/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:50:06 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/27 13:02:47 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	has_cub_extension(char *path)
{
	int	length;

	length = ft_strlen(path);
	if (ft_strncmp(path + length - 4, ".cub", 4) != 0)
		return (0);
	return (1);
}

int	send_valid_file(int argc, char **argv)
{
	if (argc != 2)
		return (throw_error("Usage: ./cub3D maps/<map>.cub"));
	if (!has_cub_extension(argv[1]))
		return (throw_error("Invalid file extension"));
	if (!can_open_file(argv[1]))
		return (throw_error("Cannot open file"));
	return (1);
}
