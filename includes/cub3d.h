/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:45:21 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/04 16:14:23 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/constants.h"
#include "../mlx/mlx.h"

typedef struct s_game {
  void *mlx;
  void *win;
} t_game;

enum e_event_code {
  E_KEYPRESS = 2,
  E_CLOSE_WINDOW = 17
};

#endif
