/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:33:08 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/11 20:44:46 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	make_l(t_mlx *i)
{
	int		h;
	int		x;
	int		z;

	z = -1;
	h = i->im_h;
	i->img = mlx_new_image(i->mlx, 2, i->im_h);
	i->tab = mlx_get_data_addr(i->img, &i->bpp, &i->sl, &i->e);
	while (h > 0)
	{
		x = 2;
		while (x > 0)
		{
			i->tab[++z] = 0x00;
			i->tab[++z] = 0x90;
			i->tab[++z] = 0xE8;
			i->tab[++z] = 0;
			x--;
		}
		z = z - 8;
		z = z + (i->sl);
		h--;
	}
	mlx_put_image_to_window(i->mlx, i->win, i->img, 230, 1);
}

void	make_pix(t_mlx *i, int x, int y)
{
	long long	z;

	if (((x > 0) && (x < i->im_w)) && ((y > 0) && (y < i->im_h)))
	{
		z = (i->sl) * (y) + 4 * x;
		if (*i->c_mode == 1)
		{
			i->tab[z] = 0xff;
			i->tab[++z] = 0xff;
			i->tab[++z] = 0xff;
			i->tab[++z] = 0;
		}
		else
		{
			i->tab[z] = i->cur_c.b;
			i->tab[++z] = i->cur_c.g;
			i->tab[++z] = i->cur_c.r;
			i->tab[++z] = 0;
		}
	}
	else
		return ;
}

void	calc_line(int d[5], int x[2], int y[2], int s[2])
{
	d[4] = d[3] * 2;
	if (d[4] > -d[1])
	{
		d[3] -= d[1];
		x[0] += s[0];
	}
	if (d[4] < d[0])
	{
		d[3] += d[0];
		y[0] += s[1];
	}
}

void	fill_line(int d[5], int x[2], int y[2], int s[2])
{
	d[0] = abs(x[1] - x[0]);
	d[1] = abs(y[1] - y[0]);
	s[0] = x[0] < x[1] ? 1 : -1;
	s[1] = y[0] < y[1] ? 1 : -1;
	d[3] = d[0] - d[1];
	if (d[0] > d[1])
		d[2] = d[0];
	else
		d[2] = d[1];
}

void	take_c(int d[3], int c[2], t_mlx *i)
{
	if (c[0] < c[1])
	{
		i->cur_c.r = i->v->col_f->r * (d[2] - (c[0] - (c[1] - d[2]))) / d[2] +
			i->v2->col_f->r * (c[0] - (c[1] - d[2])) / d[2];
		i->cur_c.g = i->v->col_f->g * (d[2] - (c[0] - (c[1] - d[2]))) / d[2] +
			i->v2->col_f->g * (c[0] - (c[1] - d[2])) / d[2];
		i->cur_c.b = i->v->col_f->b * (d[2] - (c[0] - (c[1] - d[2]))) / d[2] +
			i->v2->col_f->b * (c[0] - (c[1] - d[2])) / d[2];
	}
	else
	{
		i->cur_c.r = i->v->col_f->r * (d[2] - (c[1] - (c[0] - d[2]))) / d[2] +
			i->v2->col_f->r * ((c[1]) - (c[0] - d[2])) / d[2];
		i->cur_c.g = i->v->col_f->g * (d[2] - (c[1] - (c[0] - d[2]))) / d[2] +
			i->v2->col_f->g * ((c[1]) - (c[0] - d[2])) / d[2];
		i->cur_c.b = i->v->col_f->b * (d[2] - (c[1] - (c[0] - d[2]))) / d[2] +
			i->v2->col_f->b * ((c[1]) - (c[0] - d[2])) / d[2];
	}
}
