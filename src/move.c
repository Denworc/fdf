/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:22:56 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/11 20:41:36 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		ft_inmap_check(t_line *line, int axis, int ordinate)
{
	if (axis < 0)
		return (0);
	if (!axis_check(line, axis))
		return (0);
	ordinate++;
	return (1);
}

void	rot_im(int keycode, t_mlx *i)
{
	if (keycode == 0)
		i->rot[1] += 6;
	else if (keycode == 2)
		i->rot[1] -= 6;
	else if (keycode == 13)
		i->rot[0] -= 6;
	else if (keycode == 1)
		i->rot[0] += 6;
	else if (keycode == 12)
		i->rot[2] -= 6;
	else if (keycode == 14)
		i->rot[2] += 6;
	else if ((keycode == 69) && (i->zoom[0] < 50))
		i->zoom[0] += 0.1;
	else if ((keycode == 78) && (i->zoom[0] > 0.1))
		i->zoom[0] -= 0.1;
	else if ((keycode == 8) && (*i->c_mode == 3))
		*i->c_mode = 1;
	else if ((keycode == 8) && (*i->c_mode != 3))
		(*i->c_mode)++;
	else if ((keycode == 35) && (*i->proj == 2))
		*i->proj = 1;
	else if ((keycode == 35) && (*i->proj != 2))
		(*i->proj)++;
}

void	move_im(int keycode, t_mlx *i)
{
	if (keycode == 123)
		i->mov[0] -= 0.5;
	else if (keycode == 124)
		i->mov[0] += 0.5;
	else if (keycode == 126)
		i->mov[1] -= 0.5;
	else if (keycode == 125)
		i->mov[1] += 0.5;
}

void	remake_im(t_mlx *i)
{
	float	m[4][4];

	mlx_destroy_image(i->mlx, i->img2);
	i->img2 = mlx_new_image(i->mlx, i->im_w, i->im_h);
	i->tab = mlx_get_data_addr(i->img2, &i->bpp, &i->sl, &i->e);
	make_global(m, i);
	draw(i, m, (-1), (-1));
	mlx_put_image_to_window(i->mlx, i->win, i->img2, 232, 1);
}

int		key_hook(int keycode, t_mlx *info)
{
	if (keycode == 53)
	{
		mlx_clear_window(info->mlx, info->win);
		mlx_destroy_window(info->mlx, info->win);
		exit(0);
	}
	else if (keycode > 120)
		move_im(keycode, info);
	else if (keycode < 120)
		rot_im(keycode, info);
	remake_im(info);
	return (0);
}
