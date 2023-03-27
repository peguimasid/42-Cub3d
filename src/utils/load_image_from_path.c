/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image_from_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:41:26 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/27 13:01:25 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	has_xpm_extension(char *path)
{
	int	length;

	length = ft_strlen(path);
	if (ft_strncmp(path + length - 4, ".xpm", 4) != 0)
		return (0);
	return (1);
}

t_img	*load_img_from_path(char *path, t_game *game)
{
	t_img	*i;

	i = malloc(sizeof(t_img));
	i->i = NULL;
	if (!path || !has_xpm_extension(path) || !can_open_file(path))
		return (i);
	i->i = mlx_xpm_file_to_image(game->mlx, path, &i->width, &i->height);
	i->addr = mlx_get_data_addr(i->i, &i->bpp, &i->line_len, &i->endian);
	return (i);
}
