/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:13:15 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/28 16:56:05 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

char	**matrix_remove(char **matrix, int to_remove)
{
	char	**result;
	int		i;
	int		j;
	int		len;

	if (!matrix || !matrix[to_remove])
		return (matrix);
	i = 0;
	j = 0;
	len = matrix_len(matrix);
	result = malloc(sizeof(char *) * (len));
	result[len] = NULL;
	if (!result)
		return (matrix);
	while (i < len)
	{
		if (i != to_remove)
			result[j++] = ft_strdup(matrix[i]);
		i++;
	}
	free_matrix(matrix);
	return (result);
}
