/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_char_in_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:11:53 by gmasid            #+#    #+#             */
/*   Updated: 2023/04/17 14:21:16 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	count_char_in_string(char *string, char to_find)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (string && string[i])
	{
		if (string[i] == to_find)
			result++;
		i++;
	}
	return (result);
}
