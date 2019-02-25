/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_splited_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:04:08 by groberto          #+#    #+#             */
/*   Updated: 2019/02/25 13:12:20 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_splited_str(char **str)
{
	int i;

	i = 0;
	while (str[i])
		ft_memdel((void **)&str[i++]);
	ft_memdel((void **)&str);
}
