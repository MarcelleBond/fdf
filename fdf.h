/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 08:25:29 by mbond             #+#    #+#             */
/*   Updated: 2018/08/16 08:25:31 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# define WIDTH 1000
# define HEIGHT 1000

typedef struct	s_read
{
	int		fd;
	int		ret;
	int		px;
	int		py;
	char	*line;
	char	**split;
}				t_read;

typedef struct	s_mxl
{
	void *mxl;
	void *win;
	void *img;
}				t_mxl;

typedef struct	s_orig
{
	float x;
	float y;
	float z;
}				t_orig;

typedef struct	s_mod
{
	float x;
	float y;
	float z;
}				t_mod;

typedef struct	s_map
{
	t_orig			orig;
	t_mod			mod;
	t_mxl			inter;
	int				rows;
	int				cols;
	int				ft;
	struct s_map	*next;
}				t_map;

typedef struct	s_draw
{
	float x;
	float y;
	float dx;
	float dy;
	float swap;
	float s1;
	float s2;
	float p;
	float i;
	float temp;
}				t_draw;

typedef struct	s_preset
{
	float	width;
	float	height;
	int		ft;
}				t_preset;

t_map			*map_read(char *file);
t_map			*preset(t_map *head);
t_map			*scale_down(t_map *head, float scale);
t_map			*scale_up(t_map *head, float scale);
t_map			*list_malloc(void);
t_map			*ft_drop(char *file, t_map *head);
t_draw			draw_setup(t_draw draw, t_map *current, t_map *next);
t_draw			swap(t_draw draw);
t_draw			nextstep(t_draw draw);
void			empty_check(t_map *head);
void			line_draw_x(t_map *head);
void			freemap(t_map *head);
void			valid_map(t_map *head);
int				ft_abs(int value);
int				sign(int x);
int				keywork(int keycode, t_map *head);
int				map_check(char *file);
int				butt(int but, t_map *head);

#endif
