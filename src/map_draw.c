/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 10:21:02 by groberto          #+#    #+#             */
/*   Updated: 2019/02/25 14:51:26 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		vertical(t_config *fdf, int *x, int *y, int *xy)
{
	int		i;
	int		e;

	i = 0;
	e = y[0] / 2;
	while (i < y[0])
	{
		xy[1] += y[1];
		e += x[0];
		if (e >= y[0])
		{
			e -= y[0];
			xy[0] += x[1];
		}
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, xy[0], xy[1], fdf->color);
		i++;
	}
}

void		horizontal(t_config *fdf, int *x, int *y, int *xy)
{
	int		i;
	int		e;

	i = 0;
	e = x[0] / 2;
	while (i < x[0])
	{
		xy[0] += x[1];
		e += y[0];
		if (e >= x[0])
		{
			e -= x[0];
			xy[1] += y[1];
		}
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, xy[0], xy[1], fdf->color);
		i++;
	}
}

void		bresenham(t_config *fdf, int *tabxy, int x2, int y2)
{
	int		xy[2];
	int		x[2];
	int		y[2];

	xy[0] = tabxy[0];
	xy[1] = tabxy[1];
	x[0] = ft_abs(x2 - xy[0]);
	y[0] = ft_abs(y2 - xy[1]);
	x[1] = xy[0] < x2 ? 1 : -1;
	y[1] = xy[1] < y2 ? 1 : -1;
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, xy[0], xy[1], fdf->color);
	if (x[0] > y[0])
		horizontal(fdf, x, y, xy);
	else
		vertical(fdf, x, y, xy);
}

void		draw(t_config *fdf)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < fdf->grid.width || y < fdf->grid.height - 1)
	{
		if (x == fdf->grid.width)
		{
			x = 0;
			y++;
		}
		draw_bresenham(fdf, x, y);
		x++;
	}
}

void		make_draw(t_config *fdf)
{
	fdf->size.dx = (fdf->move.x + (WIDTH / 2)
	- ((fdf->grid.width * fdf->move.blancks) / 2));
	fdf->size.dy = (fdf->move.y + (HEIGHT / 2)
	- ((fdf->grid.height * fdf->move.blancks) / 2));
	fdf->size.px = (fdf->move.x + (WIDTH / 2)
	- (((fdf->grid.width / fdf->grid.height) * fdf->move.blancks) / 2) / 2);
	fdf->size.py = (fdf->move.y + (HEIGHT / 2)
	- ((fdf->grid.height * fdf->move.blancks) / 2));
	if (fdf->start == 1)
	{
		fdf->color = 0xFFFFFF;
		fdf->move.z = -1;
	}
	fdf->start = 0;
	draw(fdf);
	if (WIDTH >= 190 && HEIGHT >= 190)
		info(fdf);
}
