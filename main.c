/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 08:24:23 by mbond             #+#    #+#             */
/*   Updated: 2018/08/16 08:24:26 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map *head;

	if (argc == 2)
	{
		head = map_read(argv[1]);
		valid_map(head);
		head = ft_drop(argv[1], head);
		head = preset(head);
		head->inter.mxl = mlx_init();
		head->inter.win = mlx_new_window(head->inter.mxl, WIDTH, HEIGHT, "FDF");
		line_draw_x(head);
		mlx_hook(head->inter.win, 2, 0, keywork, head);
		mlx_hook(head->inter.win, 17, 0, butt, head);
		mlx_loop(head->inter.mxl);
	}
	else if (argc < 2)
		ft_putendl("Error: Not enough arguments");
	else if (argc > 2)
		ft_putendl("Error: To many arguments");
	return (0);
}
