/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:05:27 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/11 20:41:10 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	make_zero_m(float src[4][4])
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < 4)
	{
		while (++j < 4)
			src[i][j] = 0;
		j = -1;
	}
}

void	make_id_m(float src[4][4])
{
	int		i;

	i = -1;
	while (++i < 4)
		src[i][i] = 1;
	src[3][3] = -1;
}

void	m_copy(float src[4][4], float dst[4][4])
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < 4)
	{
		while (++j < 4)
			dst[i][j] = src[i][j];
		j = -1;
	}
}

void	m_mult(float m1[4][4], float m2[4][4], float dst[4][4])
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < 4)
	{
		while (++j < 4)
			dst[i][j] = m1[i][0] * m2[0][j] +
				m1[i][1] * m2[1][j] +
				m1[i][2] * m2[2][j] +
				m1[i][3] * m2[3][j];
		j = -1;
	}
}

void	v_mult_m(t_3d *src, float m[4][4], t_3d *dst)
{
	dst->x = src->x * m[0][0] +
		src->y * m[1][0] +
		src->z * m[2][0] +
		m[3][0];
	dst->y = src->x * m[0][1] +
		src->y * m[1][1] +
		src->z * m[2][1] +
		m[3][1];
	dst->z = src->x * m[0][2] +
		src->y * m[1][2] +
		src->z * m[2][2] +
		m[3][2];
}
