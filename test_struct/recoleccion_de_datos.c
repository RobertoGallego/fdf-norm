/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recoleccion_de_datos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:07:27 by groberto          #+#    #+#             */
/*   Updated: 2019/02/11 12:16:53 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct		s_people
{
	char	*name;
	int		number;
	char	*direccion;
}					t_people;

t_people	*first_person(t_people *fp)
{
	fp->name = "Roberto";
	fp->number = 56354;
	fp->direccion = "por aca";
	return (fp);
}

int		main()
{
	t_people *lst;
	lst = first_person(lst);

	printf("%s\n", lst->name);
	return (0);
}
