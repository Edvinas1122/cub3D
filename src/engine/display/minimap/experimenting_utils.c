/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   experimenting_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:45:04 by kmeixner          #+#    #+#             */
/*   Updated: 2022/06/09 20:49:13 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "experimenting.h"

int	closew(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}

int	keys(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		closew(mlx);
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13 || keycode == 125 || keycode ==126)
		move_player(mlx, keycode);
	if (keycode == 123 || keycode == 124)
		rotate_player(mlx, keycode, 5);
	return (0);
}
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	normalize_vector(t_vector *vector)
{
	double len;
	
	len = sqrt((vector->x * vector->x) + (vector->y * vector->y));
	if (len > 0)
	{
		vector->x /= len;
		vector->y /= len;
	}
}

void	rotate_vector(t_vector *vector, double angle)
{
	double	tmpx = vector->x;
	double	tmpy = vector->y;
	vector->x = cos(angle * M_PI/180) * tmpx - sin(angle * M_PI/180) * tmpy;
	vector->y = sin(angle * M_PI/180) * tmpx + cos(angle * M_PI/180) * tmpy;
}

double	vector_length(t_vector *vector)
{
	return (sqrt(vector->x*vector->x + vector->y*vector->y));
}

double	point_distance(t_point *v1, t_point *v2)
{
	double x = v1->x - v2->x;
	double y = v1->y - v2->y;
	return (sqrt(x*x+y*y));
}