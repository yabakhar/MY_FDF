/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabakhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:55:23 by yabakhar          #+#    #+#             */
/*   Updated: 2019/07/29 16:53:02 by yabakhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_get_color_x(t_coor *co, int i, int j)
{
	co->u = ((co->arr[i][j].z) * co->rgb3 > 0 ? (co->arr[i][j].z)
	* co->rgb3 : co->rgb3);
	if (((co->arr[i][j].z) != 0 && (co->arr[i][j + 1].z) != 0))
		return (co->u);
	else if ((co->arr[i][j].z) != 0 || (co->arr[i][j + 1].z) != 0)
		return (co->rgb2);
	return (co->rgb1);
}

int		ft_get_color_y(t_coor *co, int i, int j)
{
	co->u = ((co->arr[i][j].z) * co->rgb3 > 0 ? (co->arr[i][j].z)
	* co->rgb3 : co->rgb3);
	if ((co->arr[i][j].z) != 0 && (co->arr[i + 1][j].z) != 0)
		return (co->u);
	else if ((co->arr[i][j].z) != 0 || (co->arr[i + 1][j].z) != 0)
		return (co->rgb2);
	return (co->rgb1);
}

void	ft_print1(t_coor *co)
{
	int		i;
	int		j;
	t_node	p1;
	t_node	p2;

	i = -1;
	while (++i < co->y && (j = -1))
	{
		while (++j < co->x - 1)
		{
			co->k = co->mv.zm;
			p1.x = co->arr[i][j].x * co->k;
			p1.y = co->arr[i][j].y * co->k;
			co->mv.p(&(p1.x), &(p1.y), ((co->arr[i][j].z) * co->mv.rs) * co->k);
			p1.x += co->mv.x_move;
			p1.y += co->mv.y_move;
			p2.x = co->arr[i][j + 1].x * co->k;
			p2.y = co->arr[i][j + 1].y * co->k;
			co->mv.p(&(p2.x), &(p2.y),
			((co->arr[i][j + 1].z) * co->mv.rs) * co->k);
			p2.x += co->mv.x_move;
			p2.y += co->mv.y_move;
			ft_line(p1, p2, co, ft_get_color_x(co, i, j));
		}
	}
}

void	ft_print2(t_coor *co)
{
	int		i;
	int		j;
	t_node	p1;
	t_node	p2;

	i = -1;
	while (++i < co->y - 1 && (j = -1))
	{
		while (++j < co->x)
		{
			co->k = co->mv.zm;
			p1.x = co->arr[i][j].x * co->k;
			p1.y = co->arr[i][j].y * co->k;
			co->mv.p(&(p1.x), &(p1.y), ((co->arr[i][j].z) * co->mv.rs) * co->k);
			p1.x += co->mv.x_move;
			p1.y += co->mv.y_move;
			p2.x = co->arr[i + 1][j].x * co->k;
			p2.y = co->arr[i + 1][j].y * co->k;
			co->mv.p(&(p2.x), &(p2.y),
			((co->arr[i + 1][j].z) * co->mv.rs) * co->k);
			p2.x += co->mv.x_move;
			p2.y += co->mv.y_move;
			ft_line(p1, p2, co, ft_get_color_y(co, i, j));
		}
	}
}

void	ft_print(t_coor *co)
{
	ft_print1(co);
	ft_print2(co);
	texts(co);
}
