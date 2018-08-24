/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 08:25:09 by mbond             #+#    #+#             */
/*   Updated: 2018/08/16 08:25:10 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_abs(int value)
{
	if (value < 0)
	{
		value = value * -1;
	}
	return (value);
}

int		sign(int x)
{
	if (x > 0)
		return (1);
	else if (x < 0)
		return (-1);
	else
		return (0);
}

t_draw	draw_setup(t_draw draw, t_map *current, t_map *next)
{
	draw.x = current->mod.x;
	draw.y = current->mod.y;
	draw.dx = ft_abs(next->mod.x - current->mod.x);
	draw.dy = ft_abs(next->mod.y - current->mod.y);
	draw.s1 = sign(next->mod.x - current->mod.x);
	draw.s2 = sign(next->mod.y - current->mod.y);
	draw.swap = 0;
	draw.i = 0;
	return (draw);
}

t_draw	swap(t_draw draw)
{
	if (draw.dy > draw.dx)
	{
		draw.temp = draw.dx;
		draw.dx = draw.dy;
		draw.dy = draw.temp;
		draw.swap = 1;
	}
	return (draw);
}

t_draw	nextstep(t_draw draw)
{
	while (draw.p >= 0)
	{
		draw.p = draw.p - 2 * draw.dx;
		if (draw.swap)
			draw.x += draw.s1;
		else
			draw.y += draw.s2;
	}
	draw.p = draw.p + 2 * draw.dy;
	if (draw.swap)
		draw.y += draw.s2;
	else
		draw.x += draw.s1;
	return (draw);
}
