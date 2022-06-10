/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   experimenting.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:10:07 by kmeixner          #+#    #+#             */
/*   Updated: 2022/06/10 14:06:29 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPERIMENTING_H
# define EXPERIMENTING_H
#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOVE_DISTANCE 25
#define ROTATION_ANGLE 1
#define FOV 90
#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 2180
#define _USE_MATH_DEFINES

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_point
{
	double	x;
	double	y;
}			t_point;

typedef struct s_vector
{
	double	x;
	double	y;
}			t_vector;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_data		img;
	t_data		img_3D;
	t_point		*player;
	t_vector	*dir;
}			t_mlx;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		keys(int keycode, t_mlx *mlx);
void	move_player(t_mlx *mlx, int keycode);
void	normalize_vector(t_vector *vector);
int		check_if_wall(t_point *point);
void	rotate_vector(t_vector *vector, double angle);
void	rotate_player(t_mlx *mlx, int keycode, double angle);
double	vector_length(t_vector *vector);
double	intersection_distances(t_mlx *mlx, t_point *pos, t_vector *dir);
double	point_distance(t_point *v1, t_point *v2);

#endif