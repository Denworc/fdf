/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:38:09 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/11 21:35:03 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	take_c2(int d[3], int c[2], t_mlx *i)
{
	if (c[0] < c[1])
	{
		i->cur_c.r = i->v->col_h->r * (d[2] - (c[0] - (c[1] - d[2]))) /
			d[2] + i->v2->col_h->r * (c[0] - (c[1] - d[2])) / d[2];
		i->cur_c.g = i->v->col_h->g * (d[2] - (c[0] - (c[1] - d[2]))) /
			d[2] + i->v2->col_h->g * (c[0] - (c[1] - d[2])) / d[2];
		i->cur_c.b = i->v->col_h->b * (d[2] - (c[0] - (c[1] - d[2]))) /
			d[2] + i->v2->col_h->b * (c[0] - (c[1] - d[2])) / d[2];
	}
	else
	{
		i->cur_c.r = i->v->col_h->r * (d[2] - (c[1] - (c[0] - d[2]))) /
			d[2] + i->v2->col_h->r * ((c[1]) - (c[0] - d[2])) / d[2];
		i->cur_c.g = i->v->col_h->g * (d[2] - (c[1] - (c[0] - d[2]))) /
			d[2] + i->v2->col_h->g * ((c[1]) - (c[0] - d[2])) / d[2];
		i->cur_c.b = i->v->col_h->b * (d[2] - (c[1] - (c[0] - d[2]))) /
			d[2] + i->v2->col_h->b * ((c[1]) - (c[0] - d[2])) / d[2];
	}
}

void	drawline(t_mlx *i, int x[2], int y[2])
{
	int		d[5];
	int		err[2];

	fill_line(d, x, y, err);
	make_pix(i, x[1], y[1]);
	while (x[0] != x[1] || y[0] != y[1])
	{
		if (*i->c_mode == 2)
			if (d[0] > d[1])
				take_c(d, x, i);
			else
				take_c(d, y, i);
		else
		{
			if (d[0] > d[1])
				take_c2(d, x, i);
			else
				take_c2(d, y, i);
		}
		make_pix(i, x[0], y[0]);
		calc_line(d, x, y, err);
	}
}

void	rev_coord(t_mlx *i, t_vert *v, t_vert *v2)
{
	int		x[2];
	int		y[2];

	i->v = v;
	i->v2 = v2;
	x[0] = v->screen->x;
	x[1] = v2->screen->x;
	y[0] = v->screen->y;
	y[1] = v2->screen->y;
	drawline(i, x, y);
}

void	put_img(t_mlx *i, int y, int x)
{
	int		z;

	z = 0;
	zero_col(i);
	if ((i->ordinate == 0) && (i->axis == 0))
		make_pix(i, i->vert[0][0]->screen->x, i->vert[0][0]->screen->y);
	if (i->ordinate == 0)
		while (++z <= i->axis)
			rev_coord(i, i->vert[y + 1][z - 1], i->vert[y + 1][z]);
	while (++y < i->ordinate)
	{
		if (i->vert[y + 1][i->axis])
			rev_coord(i, i->vert[y][i->axis], i->vert[y + 1][i->axis]);
		while (++x < i->axis)
		{
			rev_coord(i, i->vert[y][x], i->vert[y][x + 1]);
			rev_coord(i, i->vert[y][x], i->vert[y + 1][x]);
			if ((i->vert[i->ordinate][x + 1]) && (y == 0))
				rev_coord(i, i->vert[i->ordinate][x],
							i->vert[i->ordinate][x + 1]);
		}
		x = -1;
	}
}

void	project(t_vert *v, t_mlx *i)
{
	if (*i->proj == 1)
	{
		if (v->aligned->z >= 100)
			v->aligned->z = 99;
		v->screen->x = v->aligned->x * (i->im_w / (200 - v->aligned->z)) +
			(i->im_w / 2);
		v->screen->y = v->aligned->y * (i->im_w / (200 - v->aligned->z)) +
			(i->im_h / 2);
	}
	else if (*i->proj == 2)
	{
		v->screen->x = v->aligned->x * (i->im_w / (200)) + (i->im_w / 2);
		v->screen->y = v->aligned->y * (i->im_w / (200)) + (i->im_h / 2);
	}
}
