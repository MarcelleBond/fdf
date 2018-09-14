/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:18:32 by mbond             #+#    #+#             */
/*   Updated: 2018/09/14 09:39:49 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	empty_check(t_map *head)
{
	if (head == NULL)
	{
		ft_putendl("Error: Empty File");
		exit(1);
	}
}

int		map_check(char *file)
{
	int		fd;
	char	*check;

	check = ft_strrchr(file, '.');
	if (check == NULL)
	{
		ft_putendl("Error: Invalid file");
		exit(1);
	}
	if ((ft_strcmp(check, ".fdf") != 0))
	{
		ft_putendl("Error: Invalid file");
		exit(1);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error on file opening");
		exit(1);
	}
	return (fd);
}

t_map	*list_malloc(void)
{
	t_map *new_node;

	new_node = (t_map *)malloc(sizeof(t_map));
	if (new_node == NULL)
	{
		perror("Error on malloc");
		exit(1);
	}
	new_node->next = NULL;
	return (new_node);
}

void	valid_map(t_map *head)
{
	int		i;
	int		totlines;
	t_map	*check;

	i = 0;
	check = head;
	while (check != NULL)
	{
		i++;
		check = check->next;
	}
	totlines = head->rows * head->cols;
	if (head->rows < 2)
	{
		ft_putendl("File with bad line length");
		exit(1);
	}
	if (i == totlines)
		return ;
	else
	{
		ft_putendl("File with bad line length");
		exit(1);
	}
}
