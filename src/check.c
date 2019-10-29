/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:19:24 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/11 22:08:56 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_line	*ft_put_line(int fd)
{
	char	*line;
	t_line	*begin_list;

	begin_list = NULL;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		if (line == NULL)
		{
			ft_error_check(2);
			exit(1);
		}
		if (!add_elem(line, &begin_list))
			return (ft_delall(&begin_list));
	}
	return (begin_list);
}

int		ft_error_check(int n)
{
	if (n == 1)
		ft_putstr("usage: ./fdf source_file\n");
	else if (n == 2)
		ft_putstr("file error\n");
	else if (n == 3)
		ft_putstr("line error\n");
	else if (n == 4)
		ft_putstr("map error\n");
	else if (n == 5)
		ft_putstr("map_out error\n");
	return (0);
}

int		take_axis(t_line *line)
{
	int		i;
	char	**x;

	x = line->line;
	i = -1;
	while (*(x))
	{
		i += 1;
		(x)++;
	}
	return (i);
}

int		take_or(t_line *line)
{
	while (line->next)
		line = line->next;
	return (line->ordinate);
}

int		axis_check(t_line *line, int axis)
{
	int		i;
	char	**z;

	i = -1;
	while (line->next)
	{
		line = line->next;
		z = line->line;
		while (*(z))
		{
			i++;
			(z)++;
		}
		if (axis > i)
			return (0);
		i = -1;
	}
	return (1);
}
