/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybord_work.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 08:26:06 by mbond             #+#    #+#             */
/*   Updated: 2018/08/16 08:26:08 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		butt(int but, t_map *head)
{
	(void)but;
	(void)head;
	exit(0);
}

void	freemap(t_map *head)
{
	t_map *second;

	while (head != NULL)
	{
		second = head->next;
		free(head);
		head = second;
	}
}

int		keywork(int keycode, t_map *head)
{
	static int limit;

	if (keycode == 53 || keycode == 65307)
	{
		freemap(head);
		exit(0);
	}
	if ((keycode == 105 || keycode == 69) && limit < 5)
	{
		head = scale_up(head, 1.5);
		limit++;
	}
	if ((keycode == 111 || keycode == 78) && limit > -5)
	{
		head = scale_down(head, 1.5);
		limit--;
	}
	return (0);
}
