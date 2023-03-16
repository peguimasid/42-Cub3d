/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:27:10 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/16 19:27:10 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_img
{
	int		height;
	int		width;
	void	*i;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_textures
{
	t_img	*north;
	t_img	*south;
	t_img	*east;
	t_img	*west;
	t_img	*black;
	int		floor;
	int		ceiling;
}			t_textures;

typedef struct s_player
{
	float	x_pos;
	float	y_pos;
	char	dir;
	float	speed;
}			t_player;

typedef struct s_ray
{
	float	increment_angle;
	float	angle;
	float	cos;
	float	sin;
	float	hfov;
	float	limit;
	int		precision;
	float	x_pos;
	float	y_pos;
}			t_ray;

typedef struct s_pressed
{
	int		is_w_pressed;
	int		is_a_pressed;
	int		is_s_pressed;
	int		is_d_pressed;
	int		is_arrow_left_pressed;
	int		is_arrow_right_pressed;
}			t_pressed;

typedef struct s_map
{
	char	**array;
	int		width;
	int		height;
}			t_map;

typedef struct s_frame
{
	long	count;
	int		rate;
}			t_frame;

#endif
