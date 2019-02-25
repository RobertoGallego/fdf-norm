/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:02:55 by groberto          #+#    #+#             */
/*   Updated: 2019/02/25 15:05:22 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		info_box(t_config *param)
{
	int		x;
	int		y;

	x = 10;
	y = 10;
	while (x <= 190)
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, x++, y, 0xFFFFFF);
	while (y <= 150)
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, x, y++, 0xFFFFFF);
	while (x >= 10)
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, x--, y, 0xFFFFFF);
	while (y >= 10)
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, x, y--, 0xFFFFFF);
}

void		info(t_config *param)
{
	{
		info_box(param);
		mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 20, 0xFFFFFF,
				"MOVE = ^ v < >");
		mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 40, 0xFFFFFF,
				"HEIGHT = up down");
		mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 60, 0xFFFFFF,
				"ZOOM = + -");
		mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 80, 0xFFFFFF,
				"COLOR = R G B");
		mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 100, 0xFFFFFF,
				"PROJECTION = p");
		mlx_string_put(param->mlx_ptr, param->win_ptr, 20, 120, 0xFFFFFF,
				"QUIT = esc");
	}
}
