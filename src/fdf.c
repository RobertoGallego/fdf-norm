/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 10:19:23 by groberto          #+#    #+#             */
/*   Updated: 2019/02/25 15:07:00 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		deal_key(int key, t_config *param)
{
	if (key == 53)
		exit(0);
	move(key, param);
	color(key, param);
	iso_paral(key, param);
	zoom(key, param);
	projection(key, param);
	return (0);
}

int		ft_construct_mlx(t_config *first)
{
	first->start = 1;
	first->proj = 0;
	first->mlx_ptr = mlx_init();
	first->win_ptr = mlx_new_window(first->mlx_ptr, WIDTH, HEIGHT, first->name);
	make_draw(first);
	mlx_key_hook(first->win_ptr, deal_key, first);
	mlx_loop(first->mlx_ptr);
	return (0);
}
