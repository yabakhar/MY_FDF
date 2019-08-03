/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabakhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 20:51:01 by yabakhar          #+#    #+#             */
/*   Updated: 2019/07/21 15:32:37 by yabakhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_sign(int x)
{
	if (x > 0)
		return (1);
	else if (x < 0)
		return (-1);
	else
		return (0);
}

void		ft_line(t_node p1, t_node p2, t_coor *coor, int color)
{
	t_line	line;

	line.diffx = 0;
	line.diffy = 0;
	while (p1.x != p2.x || p1.y != p2.y)
	{
		mlx_pixel_put(coor->mlx.ptr, coor->mlx.win, p1.x, p1.y, color);
		line.dx = abs(p2.x - p1.x);
		line.dy = abs(p2.y - p1.y);
		line.sx = ft_sign(p2.x - p1.x);
		line.sy = ft_sign(p2.y - p1.y);
		line.diffx = line.diffx + (line.dx / line.dy);
		line.diffy = line.diffy + (line.dy / line.dx);
		p1.x += (line.dx < line.dy ? line.diffx >= 1 : line.dx != 0) * line.sx;
		p1.y += (line.dx > line.dy ? line.diffy >= 1 : line.dy != 0) * line.sy;
		line.diffx -= line.diffx >= 1;
		line.diffy -= line.diffy >= 1;
	}
}
