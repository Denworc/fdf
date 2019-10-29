/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:53:03 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/11 22:03:53 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	zero_col(t_mlx *i)
{
	if (*i->c_mode == 2)
	{
		i->cur_c.r = i->vert[0][0]->col_f->r;
		i->cur_c.g = i->vert[0][0]->col_f->g;
		i->cur_c.b = i->vert[0][0]->col_f->b;
	}
	else
	{
		i->cur_c.r = i->vert[0][0]->col_h->r;
		i->cur_c.g = i->vert[0][0]->col_h->g;
		i->cur_c.b = i->vert[0][0]->col_h->b;
	}
}

void	draw_3(t_mlx *i, int y, int x)
{
	y = -1;
	while (++y < (i->ordinate + 1))
	{
		while (++x < (i->axis + 1))
		{
			i->vert[y][x]->screen = (t_2d *)ft_memalloc(sizeof(t_2d));
			project(i->vert[y][x], i);
		}
		x = -1;
	}
	put_img(i, (-1), (-1));
}

void	take_col_2(t_vert *v)
{
	v->col_f->r = 255;
	v->col_f->g = 255;
	v->col_f->b = 255;
}

int		map_out(t_line *line, char *t, int axis, int ordinate)
{
	t_mlx	info;

	info.mlx = mlx_init();
	init_info(&info, line, axis, ordinate);
	init_elem(&info, ordinate + 1, axis + 1);
	get_coord(&info, ordinate + 1, axis + 1);
	get_param(&info, 0, 0, 0);
	info.win = mlx_new_window(info.mlx, 230 + info.im_w, info.im_h, t);
	add_ui(&info);
	make_l(&info);
	make_im(&info);
	mlx_hook(info.win, 2, 0, key_hook, &info);
	mlx_hook(info.win, 17, 0, exit_hook, &info);
	mlx_loop(info.mlx);
	return (1);
}

int		main(int ac, char **av)
{
	int		fd;
	t_line	*first;

	if (ac != 2)
		return (ft_error_check(1));
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (ft_error_check(2));
	if (!(first = ft_put_line(fd)))
		return (ft_error_check(2));
	if (!ft_inmap_check(first, take_axis(first), take_or(first)))
		return (ft_error_check(2));
	if (!map_out(first, av[1], take_axis(first), take_or(first)))
		return (ft_error_check(2));
	ft_delall(&first);
	close(fd);
	return (0);
}
