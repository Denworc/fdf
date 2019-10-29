/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 19:19:18 by smaksymy          #+#    #+#             */
/*   Updated: 2017/03/29 18:30:03 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	change_position(char *prev, int i)
{
	char	*buff;

	buff = ft_strdup(prev + i + 1);
	ft_bzero(prev, ft_strlen(prev));
	ft_strcpy(prev, buff);
	free(buff);
}

int		check_line(char *prev, char *str, char **line, int i)
{
	while (prev[i] && prev[i] != '\n')
		i++;
	if (*line)
	{
		str = ft_strnew(ft_strlen(*line) + i);
		ft_strcpy(str, *line);
		ft_strncat(str, prev, i);
		free(*line);
		*line = str;
	}
	else
	{
		*line = ft_strnew(i);
		*line = ft_strncpy(*line, prev, i);
	}
	if (!prev[i])
	{
		ft_bzero(prev, ft_strlen(prev));
		return (0);
	}
	change_position(prev, i);
	return (1);
}

int		take_prev(char *prev, char **line)
{
	int		i;
	char	c;

	i = 0;
	while (prev[i] != '\n' && prev[i])
		i++;
	*line = ft_strnew(i);
	*line = ft_strncpy(*line, prev, i);
	c = prev[i];
	change_position(prev, i);
	if (c == '\n')
		return (1);
	return (0);
}

t_file	*get_list(int fd, t_file *list_elem)
{
	t_file	*tmp;

	if ((!list_elem) && (list_elem = (t_file *)malloc(sizeof(t_file))))
	{
		list_elem->fd = fd;
		list_elem->next = NULL;
		ft_bzero(list_elem->prev, BUFF_SIZE + 1);
		return (list_elem);
	}
	while (list_elem)
	{
		if (list_elem->fd == fd)
			return (list_elem);
		tmp = list_elem;
		list_elem = list_elem->next;
	}
	if ((tmp->next = (t_file *)malloc(sizeof(t_file))))
	{
		list_elem = tmp->next;
		list_elem->fd = fd;
		ft_bzero(list_elem->prev, BUFF_SIZE + 1);
		list_elem->next = NULL;
	}
	return (list_elem);
}

int		get_next_line(const int fd, char **line)
{
	static	t_file	*begin_list;
	t_file			*list_elem;

	if ((fd < 0) || (!line) || (BUFF_SIZE < 1))
		return (-1);
	*line = NULL;
	if (!begin_list)
		begin_list = get_list(fd, begin_list);
	list_elem = get_list(fd, begin_list);
	if (read(fd, list_elem->prev, 0) < 0)
		return (-1);
	if ((*list_elem->prev) && (take_prev(list_elem->prev, line)))
		return (1);
	while (read(fd, list_elem->prev, BUFF_SIZE))
	{
		if (check_line(list_elem->prev, list_elem->str, line, 0))
			return (1);
	}
	if (*line != NULL)
		return (1);
	return (0);
}
