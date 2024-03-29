/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_open_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:01:06 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/27 13:01:42 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	can_open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	close(fd);
	return (fd > 0);
}
