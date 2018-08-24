/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 08:25:49 by mbond             #+#    #+#             */
/*   Updated: 2018/08/16 08:25:50 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*ft_drop(char *file, t_map *head)
{
	char *ft;

	ft = ft_strrchr(file, '.');
	ft = ft - 2;
	if ((ft_strcmp(ft, "42.fdf")) == 0)
		head->ft = 8;
	else
		head->ft = 1;
	return (head);
}

t_map	*preset(t_map *head)
{
	t_map		*p;
	t_preset	d;
	float		angle;

	d.ft = head->ft;
	p = head;
	d.width = (WIDTH / head->cols) / 2;
	d.height = (HEIGHT / head->rows) / 2;
	while (p != NULL)
	{
		angle = 30 * (M_PI / 180);
		p->mod.y = (cos(angle) * p->orig.y) + (-sin(angle) * p->orig.z / d.ft);
		p->mod.z = (sin(angle) * p->orig.y) + (cos(angle) * p->orig.z / d.ft);
		angle = -20 * (M_PI / 180);
		p->mod.x = (cos(angle) * p->orig.x) + (sin(angle) * p->orig.z / d.ft);
		p->mod.z = (-sin(angle) * p->orig.y) + (cos(angle) * p->orig.z / d.ft);
		angle = 25 * (M_PI / 180);
		p->mod.x = (cos(angle) * p->mod.x) + (-sin(angle) * p->mod.y);
		p->mod.y = (sin(angle) * p->mod.x) + (cos(angle) * p->mod.y);
		p->mod.x = d.width * p->mod.x;
		p->mod.y = d.height * p->mod.y;
		p = p->next;
	}
	return (head);
}
