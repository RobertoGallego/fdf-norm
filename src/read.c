/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:42:35 by groberto          #+#    #+#             */
/*   Updated: 2019/02/25 14:16:19 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_count_words(char const *str)
{
	int		count;
	int		sw;
	char	s;

	sw = 0;
	count = 0;
	s = ' ';
	while (*str != '\0')
	{
		if (sw == 1 && *str == s)
			sw = 0;
		if (sw == 0 && *str != s)
		{
			sw = 1;
			count++;
		}
		str++;
	}
	return (count);
}

void	ft_temp(t_config *read, char *line)
{
	char	**tmp;
	int		i;

	tmp = ft_strsplit(line, ' ');
	i = 0;
	while (tmp[i])
	{
		read->grid.grip[read->move.p] = ft_atoi(tmp[i]);
		read->move.p++;
		i++;
	}
	read->grid.height++;
	ft_free_splited_str(tmp);
	free(line);
}

int		ft_check_lines(t_config *read, char *line)
{
	int		fd;
	int		word;
	int		i;
	int		flag;

	i = 0;
	read->move.p = 0;
	flag = 0;
	line = "\0";
	fd = open(read->name, O_RDONLY);
	read->grid.height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (flag == 0)
		{
			word = ft_count_words(line);
			flag = 1;
			read->grid.width = word;
		}
		if (word != ft_count_words(line))
			return (ft_error("Found wrong line length."));
		ft_temp(read, line);
	}
	close(fd);
	return (0);
}

int		ft_check_files(t_config *read, char *line)
{
	int fd;

	line = NULL;
	fd = open(read->name, O_RDONLY);
	if (get_next_line(fd, &line) <= 0)
		return (ft_error("No data found."));
	close(fd);
	free(line);
	return (0);
}

int		ft_check(t_config *read)
{
	char *line;

	line = NULL;
	if (ft_check_lines(read, line) == -1)
		return (-1);
	if (ft_check_files(read, line) == -1)
		return (-1);
	return (0);
}
