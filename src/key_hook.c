/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:53:22 by groberto          #+#    #+#             */
/*   Updated: 2019/02/25 15:03:07 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		move(int key, t_config *param)
{
	if (key >= 123 && key <= 126)
	{
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		if (key == 123)
			param->move.x -= 10;
		else if (key == 124)
			param->move.x += 10;
		else if (key == 125)
			param->move.y += 10;
		else if (key == 126)
			param->move.y -= 10;
		make_draw(param);
	}
}

void		projection(int key, t_config *param)
{
	if (key == 121 || key == 116)
	{
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		if (key == 121)
			param->move.z += 1;
		else if (key == 116)
			param->move.z -= 1;
		make_draw(param);
	}
}

void		color(int key, t_config *param)
{
	if (key == 15 || key == 5 || key == 11)
	{
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		param->color = param->color == 0xFFFFFF ? 0x000000 : param->color;
		if (key == 15)
			param->color = (param->color | 0xFF0000) == param->color ?
				param->color & 0x00FFFF : param->color | 0xFF0000;
		else if (key == 5)
			param->color = (param->color | 0x00FF00) == param->color ?
				param->color & 0xFF00FF : param->color | 0x00FF00;
		else if (key == 11)
			param->color = (param->color | 0x0000FF) == param->color ?
				param->color & 0xFFFF00 : param->color | 0x0000FF;
		param->color = param->color == 0x000000 ? 0xFFFFFF : param->color;
		make_draw(param);
	}
}

void		iso_paral(int key, t_config *param)
{
	if (key == 34 || key == 35)
	{
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		if (key == 35)
			param->proj = param->proj == 0 ? 1 : 0;
		make_draw(param);
	}
}

void		zoom(int key, t_config *param)
{
	if (key == 69 && param->grid.width && param->grid.height)
	{
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		param->move.blancks += 1;
		if (param->move.blancks > 80)
			param->move.blancks = 80;
		make_draw(param);
	}
	else if (key == 78 && param->grid.width && param->grid.height)
	{
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		param->move.blancks -= 1;
		if (param->move.blancks <= 1)
			param->move.blancks = 1;
		make_draw(param);
	}
}
