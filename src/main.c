/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:45:42 by groberto          #+#    #+#             */
/*   Updated: 2019/02/25 15:31:49 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_error(char *text)
{
	ft_putendl(text);
	return (-1);
}

void	init_movements(t_config *env)
{
	env->move.x = 0;
	env->move.y = 0;
	env->move.blancks = SPACE;
}

int		main(int argc, char *argv[])
{
	t_config	start;
	int			fd;

	if (argc == 2)
	{
		init_movements(&start);
		start.name = argv[1];
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (ft_error("error: invalide file"));
		else
		{
			if (ft_check(&start) == -1)
				return (-1);
			ft_construct_mlx(&start);
		}
		close(fd);
	}
	else
		return (ft_error("usage: ./fdf FileName"));
	return (0);
}
