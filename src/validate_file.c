/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:50:06 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/17 17:38:17 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_valid_ext(char *path)
{
	int	length;

	length = ft_strlen(path);
	if (ft_strncmp(path + length - 4, ".cub", 4) != 0)
		return (0);
	return (1);
}

int	can_open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	close(fd);
	return (fd > 0);
}

int	send_valid_file(int argc, char **argv)
{
	if (argc != 2)
		return (throw_error("Usage: ./cub3D maps/<map>.cub"));
	if (!is_valid_ext(argv[1]))
		return (throw_error("Invalid file extension"));
	if (!can_open_file(argv[1]))
		return (throw_error("Cannot open file"));
	return (1);
}
