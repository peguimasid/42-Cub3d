/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:41:50 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/28 16:56:08 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

char	**matrix_replace(char **matrix, int i, char *new_value)
{
	if (!matrix || !matrix[i])
		return (NULL);
	free(matrix[i]);
	matrix[i] = ft_strdup(new_value);
	return (matrix);
}
