/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabakhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 02:05:18 by yabakhar          #+#    #+#             */
/*   Updated: 2019/07/28 01:44:52 by yabakhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		close_press(t_coor *coor)
{
	mlx_destroy_window(coor->mlx.ptr, coor->mlx.win);
	exit(0);
}

void	key_press2(int keycode, t_coor *coor)
{
	if (keycode == 35)
	{
		mlx_clear_window(coor->mlx.ptr, coor->mlx.win);
		coor->mv.p = &ft_para;
		ft_print(coor);
	}
	if (keycode == 34)
	{
		mlx_clear_window(coor->mlx.ptr, coor->mlx.win);
		coor->mv.p = &ft_iso;
		ft_print(coor);
	}
	if (keycode == 69)
	{
		mlx_clear_window(coor->mlx.ptr, coor->mlx.win);
		coor->mv.rs += 0.0075 / 4;
		ft_print(coor);
	}
	if (keycode == 78)
	{
		mlx_clear_window(coor->mlx.ptr, coor->mlx.win);
		coor->mv.rs -= 0.0075 / 4;
		ft_print(coor);
	}
}

void	key_press1(int keycode, t_coor *coor)
{
	if (keycode == 53)
	{
		mlx_destroy_window(coor->mlx.ptr, coor->mlx.win);
		exit(0);
	}
	if (keycode == 124)
	{
		mlx_clear_window(coor->mlx.ptr, coor->mlx.win);
		coor->mv.x_move += 10;
		ft_print(coor);
	}
	if (keycode == 123)
	{
		mlx_clear_window(coor->mlx.ptr, coor->mlx.win);
		coor->mv.x_move -= 10;
		ft_print(coor);
	}
	if (keycode == 126)
	{
		mlx_clear_window(coor->mlx.ptr, coor->mlx.win);
		coor->mv.y_move -= 10;
		ft_print(coor);
	}
}

int		key_press(int keycode, t_coor *coor)
{
	if (keycode == 125)
	{
		mlx_clear_window(coor->mlx.ptr, coor->mlx.win);
		coor->mv.y_move += 10;
		ft_print(coor);
	}
	if (keycode == 49)
	{
		mlx_clear_window(coor->mlx.ptr, coor->mlx.win);
		coor->rgb1 = coor->rgb1 * 5;
		coor->rgb2 = coor->rgb2 * 5;
		coor->rgb3 = coor->rgb2 * 5;
		ft_print(coor);
	}
	key_press1(keycode, coor);
	key_press2(keycode, coor);
	ft_change_color(keycode, coor);
	return (0);
}

int		mouse_press(int button, int x, int y, t_coor *coor)
{
	x = 0;
	y = 0;
	if (button == 4)
	{
		mlx_clear_window(coor->mlx.ptr, coor->mlx.win);
		coor->mv.zm += 0.5;
		ft_print(coor);
	}
	if (button == 5)
	{
		if (coor->mv.zm <= 1)
			return (0);
		mlx_clear_window(coor->mlx.ptr, coor->mlx.win);
		coor->mv.zm -= 0.5;
		ft_print(coor);
	}
	return (0);
}
