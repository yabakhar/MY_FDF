/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabakhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 23:11:08 by yabakhar          #+#    #+#             */
/*   Updated: 2019/08/01 15:07:35 by yabakhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coor		ft_continue(char *arg)
{
	t_coor	coor;
	char	buff[BUFF_SIZE + 1];

	coor.x = 0;
	coor.y = 0;
	coor.fd = open(arg, O_RDONLY);
	if (!(coor.line = ft_strnew(0))
		&& (coor.m = -1))
		return (coor);
	while ((coor.rd = read(coor.fd, buff, BUFF_SIZE)) > 0)
	{
		buff[coor.rd] = '\0';
		coor.tmp = coor.line;
		if (!(coor.line = ft_strjoin(coor.line, buff))
			&& (coor.m = -1))
			return (coor);
		ft_strdel(&(coor.tmp));
	}
	close(coor.fd);
	return (coor);
}

void		del_2d(char ***t)
{
	char	**tab;
	int		i;

	tab = *t;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

t_coor		ft_read(char *arg)
{
	t_coor	coor;

	coor.m = 0;
	coor = ft_continue(arg);
	if (!(coor.splity = ft_strsplit(coor.line, '\n'))
		&& (coor.m = -1))
		return (coor);
	ft_strdel(&coor.line);
	while (coor.splity[coor.y])
		coor.y++;
	if (!(coor.arr = (t_node **)malloc(sizeof(t_node*) * coor.y))
		&& (coor.m = -1))
		return (coor);
	coor.i = -1;
	while (coor.splity[++coor.i])
	{
		if (!(coor.splitx = ft_strsplit(coor.splity[coor.i], ' '))
		&& (coor.m = -1))
			return (coor);
		coor.j = 0;
		ft_continue1(&coor);
		del_2d(&coor.splitx);
	}
	del_2d(&coor.splity);
	return (coor);
}

t_coor		ft_continue1(t_coor *coor)
{
	while (coor->splitx[coor->j])
		coor->j++;
	if (coor->m == 0)
	{
		coor->x = coor->j;
		coor->m = 1;
	}
	if (coor->x != coor->j)
	{
		coor->m = -1;
		return (*coor);
	}
	if (!(coor->arr[coor->i] = (t_node *)malloc(sizeof(t_node) * coor->x))
	&& (coor->m = -1))
		return (*coor);
	coor->a = -1;
	while (++coor->a < coor->x)
	{
		coor->arr[coor->i][coor->a].z = ft_atoi(coor->splitx[coor->a]);
		coor->arr[coor->i][coor->a].x = coor->a;
		coor->arr[coor->i][coor->a].y = coor->i;
		ft_strdel(&coor->splitx[coor->a]);
	}
	ft_strdel(coor->splitx);
	return (*coor);
}
