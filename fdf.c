/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabakhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:37:53 by yabakhar          #+#    #+#             */
/*   Updated: 2019/07/29 23:42:30 by yabakhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_coor	fdf_init(t_coor *coor)
{
	coor->mlx.ptr = mlx_init();
	coor->h = 700;
	coor->w = 1280;
	coor->mv.zm = coor->h / coor->x;
	coor->mv.x_move = (coor->w - coor->x * coor->mv.zm) / 2;
	coor->mv.y_move = (coor->h - coor->y * coor->mv.zm) / 2;
	coor->mv.rs = 0.025;
	coor->rgb1 = 0x00F4E9;
	coor->rgb2 = 0xFFC817;
	coor->rgb3 = 0xFFFBFE;
	coor->mv.p = ft_para;
	return (*coor);
}

void	texts(t_coor *c)
{
	mlx_string_put(c->mlx.ptr, c->mlx.win, 10, 12, 0xf3f8ff, "+/-: RISE");
	mlx_string_put(c->mlx.ptr, c->mlx.win, 150, 12, 0xf3f8ff, "ARROWS: MOVE");
	mlx_string_put(c->mlx.ptr, c->mlx.win, 380, 12, 0xf3f8ff, "Z X C: RGB");
	mlx_string_put(c->mlx.ptr, c->mlx.win, 540, 12, 0xf3f8ff, "P: PAR");
	mlx_string_put(c->mlx.ptr, c->mlx.win, 700, 12, 0xf3f8ff, "ESPACE: DISCO");
	mlx_string_put(c->mlx.ptr, c->mlx.win, 900, 12, 0xf3f8ff, "I: ISO");
	mlx_string_put(c->mlx.ptr, c->mlx.win, 1130, 12, 0xf3f8ff, "MOUSE: WHEEL");
}

int		main(int argc, char **argv)
{
	t_coor	coor;

	if (argc != 2)
	{
		ft_putstr("Usage: ./fdf <filename>\n");
		return (1);
	}
	coor = ft_read(argv[1]);
	if (coor.rd == -1 || coor.m == -1)
	{
		ft_putstr("error");
		return (1);
	}
	fdf_init(&coor);
	coor.mlx.win = mlx_new_window(coor.mlx.ptr, coor.w, coor.h, argv[1]);
	ft_print(&coor);
	texts(&coor);
	mlx_hook(coor.mlx.win, 17, 0, close_press, &coor);
	mlx_hook(coor.mlx.win, 2, 0, key_press, &coor);
	mlx_hook(coor.mlx.win, 4, 0, mouse_press, &coor);
	mlx_loop(coor.mlx.ptr);
	return (0);
}
