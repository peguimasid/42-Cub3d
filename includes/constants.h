/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:40:13 by gmasid          #+#    #+#             */
/*   Updated: 2023/03/03 15:19:55 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define WINDOW_WIDTH 900
# define WINDOW_HEIGHT 500

enum	e_keyboard_letters
{
	KEY_A = 0,
	KEY_D = 2,
	KEY_S = 1,
	KEY_W = 13,
};

enum	e_keyboard_arrows
{
	ARROW_LEFT = 123,
	ARROW_RIGHT = 124,
};

enum	e_keyboard_utils
{
	KEY_ESC = 53,
};

enum	e_event_codes
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_CLOSE_WINDOW = 17
};

#endif
