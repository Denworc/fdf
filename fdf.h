/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 20:24:38 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/16 03:30:44 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H
# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# define COLOR 0xFFFFFF

typedef	struct s_line	t_line;
typedef	struct s_mlx	t_mlx;
typedef	struct s_coord	t_coord;
typedef	struct s_2d		t_2d;
typedef	struct s_3d		t_3d;
typedef	struct s_vert	t_vert;
typedef struct s_col	t_col;

struct		s_col
{
	int		r;
	int		g;
	int		b;
};
struct		s_2d
{
	int		x;
	int		y;
};
struct		s_3d
{
	float	x;
	float	y;
	float	z;
};
struct		s_vert
{
	t_3d	*local;
	t_3d	*world;
	t_3d	*aligned;
	t_2d	*screen;
	t_col	*col_f;
	t_col	*col_h;
};
struct		s_coord
{
	t_coord	*next;
	int		*color;
	int		*z;
};
struct		s_line
{
	t_line	*next;
	char	**line;
	int		ordinate;
};
struct		s_mlx
{
	int		*proj;
	int		*c_mode;
	void	*mlx;
	void	*win;
	t_line	*list;
	t_coord	*coord;
	char	***color;
	t_vert	***vert;
	int		axis;
	int		ordinate;
	float	*mov;
	float	*rot;
	float	*zoom;
	int		im_h;
	int		im_w;
	void	*img;
	char	*tab;
	int		bpp;
	int		sl;
	int		e;
	int		bpp2;
	int		sl2;
	int		e2;
	void	*img2;
	char	*tab2;
	int		z_max;
	int		z_min;
	t_col	cur_c;
	t_vert	*v;
	t_vert	*v2;
};

void		make_zero_m(float src[4][4]);
void		make_id_m(float src[4][4]);
void		m_copy(float src[4][4], float dst[4][4]);
void		m_mult(float m1[4][4], float m2[4][4], float dst[4][4]);
void		v_mult_m(t_3d *src, float m[4][4], t_3d *dst);
void		m_translate(float m[4][4], float tx, float ty, float tz);
void		m_scale(float m[4][4], float sx, float sy, float sz);
void		rot_x(float m[4][4], int ax);
void		rot_y(float m[4][4], int ay);
void		rot_z(float m[4][4], int az);
void		m_rotate(float m[4][4], float ax, float ay, float az);
void		make_global(float m[4][4], t_mlx *i);
t_line		*ft_delall(t_line **begin_list);
void		add_to_list(t_line **begin_list, t_line *new);
int			add_elem(char *ln, t_line **begin_list);
t_line		*ft_put_line(int fd);
int			ft_error_check(int n);
int			take_axis(t_line *line);
int			take_or(t_line *line);
int			axis_check(t_line *line, int axis);
int			ft_inmap_check(t_line *line, int axis, int ordinate);
void		rot_im(int keycode, t_mlx *i);
void		move_im(int keycode, t_mlx *i);
void		remake_im(t_mlx *i);
int			key_hook(int keycode, t_mlx *info);
int			exit_hook(t_mlx *info);
void		add_ui(t_mlx *i);
void		init_info(t_mlx *i, t_line *line, int axis, int ordinate);
void		get_param(t_mlx *i, int x, int y, int z);
void		make_l(t_mlx *i);
void		make_pix(t_mlx *i, int x, int y);
void		calc_line(int d[3], int x[2], int y[2], int s[2]);
void		fill_line(int d[3], int x[2], int y[2], int s[2]);
void		take_c(int d[3], int c[2], t_mlx *i);
void		take_c2(int d[3], int c[2], t_mlx *i);
void		drawline(t_mlx *i, int x[2], int y[2]);
void		rev_coord(t_mlx *i, t_vert *v, t_vert *v2);
void		put_img(t_mlx *i, int y, int x);
void		project(t_vert *v, t_mlx *i);
void		draw_2(t_mlx *i, float m[4][4], int y, int x);
int			trans_col(char s);
void		take_col(t_vert *v, t_mlx *i, int y, int x);
void		take_col2(t_vert *v, t_mlx *i);
void		draw(t_mlx *i, float m[4][4], int y, int x);
void		make_im(t_mlx *i);
void		get_coord2(t_mlx *t, int i, int j, t_line *l);
void		get_coord(t_mlx *t, int i2, int j2);
void		init_elem(t_mlx *t, int i2, int j2);
int			map_out(t_line *line, char *t, int axis, int ordinate);
void		take_col_(t_vert *v, t_mlx *i, int y, int x);
void		get_param_(t_mlx *i, int y, int z);
void		take_col_2(t_vert *v);
void		draw_3(t_mlx *i, int y, int x);
void		zero_col(t_mlx *i);

#endif
