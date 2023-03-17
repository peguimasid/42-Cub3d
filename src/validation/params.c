/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:46:51 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/17 13:50:13 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	send_valid_params(int argc, char **argv)
{
	if (!send_valid_file(argc, argv))
		return (0);
	if (!send_valid_map(argv))
		return (0);
	return (1);
}
