/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:06:13 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/20 23:06:14 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double	get_dim_factor_2(int y)
{
	double	factor;

	factor = 1 - ((double)y / (SCREEN_HEIGHT / 2));
	factor = factor * factor * factor * factor;
	return (1 - factor);
}

/*
	Dim factor for color pixel by ratio - distance
*/
double	get_dim_factor(double distance)
{
	double	factor;

	factor = (distance / TILE_SIZE) / 10;
	if (factor > 1)
		factor = 1;
	factor = 1 - factor;
	if (factor < 0.25)
		factor = 0.25;
	return (factor);
}

/*
	Sets aRGB colors values to t_color struct
*/
t_color	set_color(int a, int r, int g, int b)
{
	t_color	color;

	color.a = (unsigned char)a;
	color.r = (unsigned char)r;
	color.g = (unsigned char)g;
	color.b = (unsigned char)b;
	return (color);
}

/*
	Returns color from string delimited by ,
	example 234,255,255
*/
t_color	string_to_color(char *str)
{
	t_color	item;
	char	**colors;

	colors = ft_split(str, ',');
	item.r = ft_atoi(colors[0]);
	item.g = ft_atoi(colors[1]);
	item.b = ft_atoi(colors[2]);
	delocate_arr(colors);
	return (item);
}

t_color	dim_color(t_color color, double factor)
{
	t_color	dimmed;

	dimmed.a = 0;
	dimmed.r = color.r * factor;
	dimmed.g = color.g * factor;
	dimmed.b = color.b * factor;
	return (dimmed);
}
