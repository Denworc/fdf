/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:14:01 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/11 20:41:25 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	m_rotate(float m[4][4], float ax, float ay, float az)
{
	rot_z(m, az);
	rot_x(m, ax);
	rot_y(m, ay);
}

void	make_global(float m[4][4], t_mlx *i)
{
	make_zero_m(m);
	make_id_m(m);
	m_translate(m, ((float)i->axis) / 2, ((float)i->ordinate) / 2,
				((float)(i->z_max + i->z_min)) / 2);
}

t_line	*ft_delall(t_line **begin_list)
{
	t_line	*tmp;
	t_line	*next;

	if (begin_list && *begin_list)
	{
		tmp = *begin_list;
		while (tmp)
		{
			next = tmp->next;
			tmp->next = NULL;
			free(tmp);
			tmp = next;
		}
		*begin_list = NULL;
	}
	return (NULL);
}

void	add_to_list(t_line **begin_list, t_line *new)
{
	t_line	*tmp;
	int		i;

	i = 1;
	if (*begin_list)
	{
		tmp = *begin_list;
		while (tmp->next)
		{
			i++;
			tmp = tmp->next;
		}
		tmp->next = new;
		new->ordinate = i;
	}
	else
	{
		*begin_list = new;
		new->ordinate = 0;
		new->next = NULL;
	}
}

int		add_elem(char *ln, t_line **begin_list)
{
	t_line	*new;

	if (!(new = (t_line *)malloc(sizeof(t_line))))
		return (0);
	new->next = NULL;
	new->line = ft_strsplit(ln, ' ');
	add_to_list(begin_list, new);
	return (1);
}
