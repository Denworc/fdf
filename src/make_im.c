/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_im.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:48:04 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/11 20:40:58 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw(t_mlx *i, float m[4][4], int y, int x)
{
	while (++y < (i->ordinate + 1))
	{
		while (++x < (i->axis + 1))
		{
			i->vert[y][x]->col_f =
				(t_col *)ft_memalloc(sizeof(t_col));
			take_col(i->vert[y][x], i, y, x);
			i->vert[y][x]->col_h =
				(t_col *)ft_memalloc(sizeof(t_col));
			take_col2(i->vert[y][x], i);
			i->vert[y][x]->world =
				(t_3d *)ft_memalloc(sizeof(t_3d));
			v_mult_m(i->vert[y][x]->local, m, i->vert[y][x]->world);
		}
		x = -1;
	}
	draw_2(i, m, (-1), (-1));
}

void	make_im(t_mlx *i)
{
	int		h;
	int		z;
	float	m[4][4];

	z = -1;
	h = i->im_h;
	mlx_destroy_image(i->mlx, i->img);
	i->img2 = mlx_new_image(i->mlx, i->im_w, i->im_h);
	i->tab = mlx_get_data_addr(i->img2, &i->bpp, &i->sl, &i->e);
	make_global(m, i);
	draw(i, m, (-1), (-1));
	mlx_put_image_to_window(i->mlx, i->win, i->img2, 232, 1);
}

void	get_coord2(t_mlx *t, int i, int j, t_line *l)
{
	char	*s;

	s = l->line[j];
	t->vert[i][j]->local =
		(t_3d *)ft_memalloc(sizeof(t_3d));
	t->vert[i][j]->local->z = ft_atoi(s);
	if (t->vert[i][j]->local->z > 2000)
		t->vert[i][j]->local->z = 2000;
	if (t->vert[i][j]->local->z < -2000)
		t->vert[i][j]->local->z = -2000;
	if (t->vert[i][j]->local->z > t->z_max)
		t->z_max = t->vert[i][j]->local->z;
	if (t->vert[i][j]->local->z < t->z_min)
		t->z_min = t->vert[i][j]->local->z;
	t->vert[i][j]->local->x = j;
	t->vert[i][j]->local->y = i;
	while (*s)
		if (*s == ',')
			ft_strncpy(t->color[i][j], ++s, 8);
		else
			s++;
}

void	get_coord(t_mlx *t, int i2, int j2)
{
	int		i;
	int		j;
	t_line	*l;

	i = -1;
	j = -1;
	l = t->list;
	while (++i < i2)
	{
		while (++j < j2)
			get_coord2(t, i, j, l);
		l = l->next;
		j = -1;
	}
}

void	init_elem(t_mlx *t, int i2, int j2)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	t->vert = (t_vert ***)ft_memalloc(sizeof(t_vert **) * (i2));
	t->color = (char ***)ft_memalloc(sizeof(char **) * (i2 + 1));
	t->color[i2] = NULL;
	while (++i < i2)
	{
		t->vert[i] = (t_vert **)ft_memalloc(sizeof(t_vert *) * (j2));
		t->color[i] = (char **)ft_memalloc(sizeof(char *) * (j2 + 1));
		t->color[i][j2] = NULL;
		while (++j < j2)
		{
			t->color[i][j] = (char *)ft_memalloc(sizeof(char) * (9));
			t->vert[i][j] = (t_vert *)ft_memalloc(sizeof(t_vert));
		}
		j = -1;
	}
}
