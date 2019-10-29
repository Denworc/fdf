/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:42:39 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/11 20:43:46 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_2(t_mlx *i, float m[4][4], int y, int x)
{
	make_zero_m(m);
	make_id_m(m);
	m_rotate(m, (-i->rot[0]), (-i->rot[1]), (-i->rot[2]));
	m_translate(m, (float)(i->mov[0]), (float)(i->mov[1]),
				-((float)(abs(i->z_max) - abs(i->z_min))) / 2);
	m_scale(m, (float)*i->zoom, (float)*i->zoom, (float)*i->zoom);
	while (++y < (i->ordinate + 1))
	{
		while (++x < (i->axis + 1))
		{
			i->vert[y][x]->aligned = (t_3d *)ft_memalloc(sizeof(t_3d));
			v_mult_m(i->vert[y][x]->world, m, i->vert[y][x]->aligned);
		}
		x = -1;
	}
	draw_3(i, y, x);
}

int		trans_col(char s)
{
	int		res;

	res = 0;
	if (s == 'A' || s == 'a')
		res = 10;
	else if (s == 'B' || s == 'b')
		res = 11;
	else if (s == 'C' || s == 'c')
		res = 12;
	else if (s == 'D' || s == 'd')
		res = 13;
	else if (s == 'E' || s == 'e')
		res = 14;
	else if (s == 'F' || s == 'f')
		res = 15;
	else if ((s >= 48) && (s <= 59))
		res = s - 48;
	else
		return (15);
	return (res);
}

void	take_col_(t_vert *v, t_mlx *i, int y, int x)
{
	int		c;

	if (i->color[y][x][4])
	{
		v->col_f->r = 0;
		c = trans_col(i->color[y][x][2]);
		c = c * 16 + trans_col(i->color[y][x][3]);
		v->col_f->g = c;
		c = trans_col(i->color[y][x][4]);
		c = c * 16 + trans_col(i->color[y][x][5]);
		v->col_f->b = c;
	}
	else if (i->color[y][x][2])
	{
		v->col_f->r = 0;
		v->col_f->g = 0;
		c = trans_col(i->color[y][x][2]);
		c = c * 16 + trans_col(i->color[y][x][3]);
		v->col_f->b = c;
	}
	else
		take_col_2(v);
}

void	take_col(t_vert *v, t_mlx *i, int y, int x)
{
	int		c;

	c = 0;
	if (i->color[y][x][6])
	{
		c = trans_col(i->color[y][x][2]);
		c = c * 16 + trans_col(i->color[y][x][3]);
		v->col_f->r = c;
		c = trans_col(i->color[y][x][4]);
		c = c * 16 + trans_col(i->color[y][x][5]);
		v->col_f->g = c;
		c = trans_col(i->color[y][x][6]);
		c = c * 16 + trans_col(i->color[y][x][7]);
		v->col_f->b = c;
	}
	else
		take_col_(v, i, y, x);
}

void	take_col2(t_vert *v, t_mlx *i)
{
	v->col_h->r = 0;
	if (v->local->z > 0)
	{
		v->col_h->r = 255 * ((int)v->local->z) / (i->z_max);
		v->col_h->g = 255 * (i->z_max - ((int)v->local->z)) / (i->z_max);
		v->col_h->b = 0;
	}
	else if (v->local->z < 0)
	{
		v->col_h->r = 0;
		v->col_h->g = 255 * (abs(i->z_min) - abs((int)v->local->z)) /
			(i->z_max);
		v->col_h->b = 255 * abs((int)v->local->z) / (i->z_max);
	}
	else
	{
		v->col_h->r = 0;
		v->col_h->g = 255;
		v->col_h->b = 0;
	}
}
