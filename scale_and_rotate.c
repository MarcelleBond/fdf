/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_and_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 08:25:41 by mbond             #+#    #+#             */
/*   Updated: 2018/08/16 08:25:43 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*scale_up(t_map *head, float scale)
{
	t_map *points;

	points = head;
	while (points != NULL)
	{
		points->mod.x = points->mod.x * scale;
		points->mod.y = points->mod.y * scale;
		points->mod.z = points->mod.z * scale;
		points = points->next;
	}
	mlx_clear_window(head->inter.mxl, head->inter.win);
	line_draw_x(head);
	return (head);
}

t_map	*scale_down(t_map *head, float scale)
{
	t_map *points;

	points = head;
	while (points != NULL)
	{
		points->mod.x = points->mod.x / scale;
		points->mod.y = points->mod.y / scale;
		points->mod.z = points->mod.z / scale;
		points = points->next;
	}
	mlx_clear_window(head->inter.mxl, head->inter.win);
	line_draw_x(head);
	return (head);
}
