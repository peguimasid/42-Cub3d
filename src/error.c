/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:50:00 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/16 17:59:11 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	throw_error(char *error)
{
	printf("\033[0;31m");
	printf("Error\n%s\n", error);
	printf("\033[0m");
	return (1);
}
