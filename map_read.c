/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 08:24:49 by mbond             #+#    #+#             */
/*   Updated: 2018/08/16 08:24:51 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			freesplit(void **split)
{
	int n;

	n = 0;
	while (split[n] != NULL)
	{
		free(split[n]);
		n++;
	}
	free(split);
}

static t_map	*createint(int x, int y, char *z)
{
	t_map *new_node;

	new_node = list_malloc();
	new_node->orig.x = x;
	new_node->orig.y = y;
	new_node->orig.z = ft_atoi(z);
	return (new_node);
}

static t_map	*appendint(t_map *head, int x, int y, char *z)
{
	t_map *cursor;

	if (head == NULL)
		head = createint(x, y, z);
	else
	{
		cursor = head;
		while (cursor->next != NULL)
			cursor = cursor->next;
		cursor->next = createint(x, y, z);
	}
	return (head);
}

t_map			*map_read(char *file)
{
	t_map	*head;
	t_read	run;

	run.py = 0;
	head = NULL;
	run.fd = map_check(file);
	while ((run.ret = get_next_line(run.fd, &run.line)) > 0)
	{
		run.px = 0;
		run.split = ft_strsplit(run.line, ' ');
		while (run.split[run.px] != NULL)
		{
			head = appendint(head, run.px, run.py, run.split[run.px]);
			run.px += 1;
		}
		run.py += 1;
		freesplit((void **)run.split);
		free(run.line);
	}
	close(run.fd);
	empty_check(head);
	head->rows = run.py;
	head->cols = run.px;
	return (head);
}
