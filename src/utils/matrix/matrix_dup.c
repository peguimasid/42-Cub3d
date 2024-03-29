/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:46:02 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/28 16:55:29 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

char	**dup_matrix(char **matrix)
{
	char	**result;
	int		i;

	i = 0;
	result = malloc(sizeof(char *) * (matrix_len(matrix) + 1));
	if (!result)
		return (NULL);
	while (matrix && matrix[i])
	{
		result[i] = ft_strdup(matrix[i]);
		if (!result[i])
		{
			free_matrix(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
