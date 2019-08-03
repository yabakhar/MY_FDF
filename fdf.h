/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabakhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:11:32 by yabakhar          #+#    #+#             */
/*   Updated: 2019/08/01 01:59:12 by yabakhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFF_SIZE 1000000

typedef	struct			s_mlx
{
	void	*ptr;
	void	*win;
}						t_mlx;

typedef	struct			s_node
{
	int x;
	int y;
	int z;
}						t_node;

typedef	struct			s_move
{
	double				zm;
	int					x_move;
	int					y_move;
	double				rs;
	void				(*p)(int *, int *, int);
}						t_move;

typedef	struct			s_coor
{
	int					x;
	int					y;
	t_node				**arr;
	t_move				mv;
	t_mlx				mlx;
	int					rgb1;
	int					rgb2;
	int					rgb3;
	int					h;
	int					w;
	int					a;
	int					i;
	int					j;
	char				**splitx;
	char				**splity;
	char				*line;
	char				*tmp;
	int					fd;
	int					rd;
	int					k;
	int					u;
	int					m;
}						t_coor;

typedef	struct			s_line
{
	double				dx;
	double				dy;
	int					sx;
	int					sy;
	double				diffx;
	double				diffy;
}						t_line;

void					texts(t_coor *coor);
int						ft_get_color_y(t_coor *co, int i, int j);
int						ft_get_color_x(t_coor *co, int i, int j);
t_coor					fdf_init(t_coor *coor);
t_coor					ft_continue(char *arg);
t_coor					ft_continue1(t_coor *coor);
int						close_press(t_coor *p);
void					ft_print(t_coor *coor);
void					ft_print1(t_coor *coor);
void					ft_print2(t_coor *coor);
void					key_press1(int keycode, t_coor *coor);
void					key_press2(int keycode, t_coor *coor);
void					ft_change_color(int keycode, t_coor *coor);
int						key_press(int keycode, t_coor *coor);
void					ft_line(t_node p1, t_node p2, t_coor *coor, int color);
int						main(int argc, char **argv);
void					ft_iso(int *x, int *y, int z);
void					ft_para(int *x, int *y, int z);
t_coor					ft_read(char *arg);
int						ft_sign(int x);
int						mouse_press(int button, int x, int y, t_coor *coor);
void					del_2d(char ***tab);
#endif
