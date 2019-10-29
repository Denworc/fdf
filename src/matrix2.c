/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:09:46 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/11 20:41:16 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	m_translate(float m[4][4], float tx, float ty, float tz)
{
	float	m2[4][4];
	float	tab[4][4];

	make_zero_m(m2);
	make_id_m(m2);
	m2[3][0] = tx;
	m2[3][1] = ty;
	m2[3][2] = tz;
	m_mult(m, m2, tab);
	m_copy(tab, m);
}

void	m_scale(float m[4][4], float sx, float sy, float sz)
{
	float	m2[4][4];
	float	tab[4][4];

	make_zero_m(m2);
	m2[0][0] = sx;
	m2[1][1] = sy;
	m2[2][2] = sz;
	m2[3][3] = 1;
	m_mult(m, m2, tab);
	m_copy(tab, m);
}

void	rot_x(float m[4][4], int ax)
{
	float	m2[4][4];
	float	tab[4][4];

	make_zero_m(m2);
	make_id_m(m2);
	m2[1][1] = cos(ax);
	m2[2][1] = -sin(ax);
	m2[1][2] = sin(ax);
	m2[2][2] = cos(ax);
	m_mult(m, m2, tab);
	m_copy(tab, m);
}

void	rot_y(float m[4][4], int ay)
{
	float	m2[4][4];
	float	tab[4][4];

	make_zero_m(m2);
	make_id_m(m2);
	m2[0][0] = cos(ay);
	m2[2][0] = sin(ay);
	m2[0][2] = -sin(ay);
	m2[2][2] = cos(ay);
	m_mult(m, m2, tab);
	m_copy(tab, m);
}

void	rot_z(float m[4][4], int az)
{
	float	m2[4][4];
	float	tab[4][4];

	make_zero_m(m2);
	make_id_m(m2);
	m2[0][0] = cos(az);
	m2[1][0] = -sin(az);
	m2[0][1] = sin(az);
	m2[1][1] = cos(az);
	m_mult(m, m2, tab);
	m_copy(tab, m);
}
