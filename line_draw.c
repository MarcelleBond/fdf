/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 08:24:33 by mbond             #+#    #+#             */
/*   Updated: 2018/08/16 08:24:37 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		colour(t_map *current, t_map *next)
{
	if ((current->orig.z >= 3 && current->orig.z < 6) ||
		(next->orig.z >= 3 && next->orig.z < 6))
		return (0xFFFF00);
	else if ((current->orig.z >= 6 && current->orig.z < 7) ||
			(next->orig.z >= 6 && next->orig.z < 7))
		return (0xFF00FF);
	else if (current->orig.z >= 7 || next->orig.z >= 7)
		return (0x00FF00);
	else
		return (0xFFFFFF);
}

void	line_draw_y(t_map *head)
{
	t_draw	draw;
	t_map	*current;
	t_map	*next;

	current = head;
	next = current->next;
	while (next->orig.x != current->orig.x)
		next = next->next;
	while (current != NULL && next != NULL)
	{
		draw = draw_setup(draw, current, next);
		draw = swap(draw);
		draw.p = 2 * draw.dy - draw.dx;
		while (draw.i < draw.dx)
		{
			mlx_pixel_put(head->inter.mxl, head->inter.win,
				draw.x + WIDTH / 3, draw.y + HEIGHT / 4,
				colour(current, next));
			draw = nextstep(draw);
			draw.i++;
		}
		current = current->next;
		next = next->next;
	}
}

void	line_draw_x(t_map *head)
{
	t_draw	draw;
	t_map	*current;
	t_map	*next;

	current = head;
	next = current->next;
	while (current != NULL && next != NULL)
	{
		draw = draw_setup(draw, current, next);
		draw = swap(draw);
		draw.p = 2 * draw.dy - draw.dx;
		while (draw.i < draw.dx)
		{
			if (next->mod.x < current->mod.x)
				break ;
			mlx_pixel_put(head->inter.mxl, head->inter.win,
				draw.x + WIDTH / 3, draw.y + HEIGHT / 4,
				colour(current, next));
			draw = nextstep(draw);
			draw.i++;
		}
		current = current->next;
		next = next->next;
	}
	line_draw_y(head);
}
