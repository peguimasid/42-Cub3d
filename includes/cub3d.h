/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:45:21 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/06 15:03:12 by gmasid           ###   ########.fr       */
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

typedef struct s_pressed {
  int is_w_pressed;
  int is_a_pressed;
  int is_s_pressed;
  int is_d_pressed;
} t_pressed;

typedef struct s_game {
  void *mlx;
  void *win;
  double posX;
  double posY;
  double dirX;
  double dirY;
  double planeX;
  double planeY;
  double moveSpeed;
  double rotationSpeed;
  t_pressed keys;
} t_game;

enum e_event_code {
  E_KEYPRESS = 2,
  E_CLOSE_WINDOW = 17
};

#endif
