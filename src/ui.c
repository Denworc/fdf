/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:26:17 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/11 21:38:06 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		exit_hook(t_mlx *info)
{
	mlx_clear_window(info->mlx, info->win);
	mlx_destroy_window(info->mlx, info->win);
	exit(0);
	return (0);
}

void	add_ui(t_mlx *i)
{
	mlx_string_put(i->mlx, i->win, 70, 35, 0xE89000, "Controls");
	mlx_string_put(i->mlx, i->win, 35, 80, 0xE89000, "Move = ^ v < >");
	mlx_string_put(i->mlx, i->win, 35, 110, 0xE89000, "Zoom = + or -");
	mlx_string_put(i->mlx, i->win, 35, 140, 0xE89000, "Rotate Y = W S");
	mlx_string_put(i->mlx, i->win, 35, 170, 0xE89000, "Rotate X = A D");
	mlx_string_put(i->mlx, i->win, 35, 200, 0xE89000, "Rotate Z = Q E");
	mlx_string_put(i->mlx, i->win, 35, 230, 0xE89000, "Quit = Esc");
	mlx_string_put(i->mlx, i->win, 35, 290, 0xE89000, "Projection (p):");
	mlx_string_put(i->mlx, i->win, 65, 320, 0xE89000, "1.perspective");
	mlx_string_put(i->mlx, i->win, 65, 350, 0xE89000, "2.isometric");
	mlx_string_put(i->mlx, i->win, 35, 420, 0xE89000, "Color (c):");
	mlx_string_put(i->mlx, i->win, 65, 450, 0xE89000, "1.classic");
	mlx_string_put(i->mlx, i->win, 65, 480, 0xE89000, "2.file_mode");
	mlx_string_put(i->mlx, i->win, 65, 510, 0xE89000, "3.height_mode");
}

void	init_info(t_mlx *i, t_line *line, int axis, int ordinate)
{
	i->axis = axis;
	i->ordinate = ordinate;
	i->list = line;
	i->mov = (float *)malloc(sizeof(float) * 2);
	i->rot = (float *)malloc(sizeof(float) * 3);
	*(i->mov) = 0;
	*((i->mov) + 1) = 0;
	*(i->rot) = 6.0;
	*((i->rot) + 1) = -6.0;
	*((i->rot) + 2) = 0.0;
	i->zoom = (float *)malloc(sizeof(float));
	*(i->zoom) = 10.0;
	i->z_min = 999999;
	i->z_max = -999999;
	i->proj = (int *)malloc(sizeof(int));
	*i->proj = 1;
	i->c_mode = (int *)malloc(sizeof(int));
	*i->c_mode = 1;
}

void	get_param_(t_mlx *i, int y, int z)
{
	if (y > 1300)
	{
		i->im_h = 1300;
		while ((y > 1300) && (*(i->zoom) > 0.3))
		{
			*(i->zoom) -= 0.1;
			y = (i->ordinate * *(i->zoom) * 10) + 200;
		}
	}
	else
		i->im_h = y;
	while ((z > i->im_h) && (*(i->zoom) > 0.3))
	{
		*(i->zoom) -= 0.1;
		z = (i->z_max - i->z_min) * (*(i->zoom)) + 400;
	}
}

void	get_param(t_mlx *i, int x, int y, int z)
{
	x = (i->axis * 30) + 400;
	y = (i->ordinate * 30) + 550;
	z = ((i->z_max - i->z_min) * 30) + 40;
	if (x > 2330)
	{
		i->im_w = 2330;
		while ((x > 2330) && (*(i->zoom) > 0.3))
		{
			*(i->zoom) -= 0.1;
			x = (i->axis * *(i->zoom) * 10) + 200;
		}
	}
	else
		i->im_w = x;
	get_param_(i, y, z);
}
