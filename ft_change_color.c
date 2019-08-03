/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabakhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 22:51:44 by yabakhar          #+#    #+#             */
/*   Updated: 2019/07/29 23:01:31 by yabakhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_change_color(int keycode, t_coor *coor)
{
	if (keycode == 6)
	{
		mlx_clear_window(coor->mlx.ptr, coor->mlx.win);
		coor->rgb1 = 0x00F4E9;
		coor->rgb2 = 0xFFC817;
		coor->rgb3 = 0xFFFBFE;
		ft_print(coor);
	}
	if (keycode == 7)
	{
		mlx_clear_window(coor->mlx.ptr, coor->mlx.win);
		coor->rgb1 = 0x00fffff;
		coor->rgb2 = 0xF70000;
		coor->rgb3 = 0xFFFBFE;
		ft_print(coor);
	}
	if (keycode == 8)
	{
		mlx_clear_window(coor->mlx.ptr, coor->mlx.win);
		coor->rgb1 = 0xEE00FF;
		coor->rgb2 = 0x00FF87;
		coor->rgb3 = 0xFFFBFE;
		ft_print(coor);
	}
}
