#include "utils.h"

// t_color	set_color_fstr(void *bin)
// {
// 	t_color	color;

// 	color.a = *(char *)bin;
// 	color.r = *(char *)bin + 1;
// 	color.g = *(char *)bin + 2;
// 	color.b = *(char *)bin + 3;
// 	return (color);
// }

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
	free(colors[0]);
	free(colors[1]);
	free(colors[2]);
	free(colors);
	return (item);
}

t_color	dim_color(t_color color, double factor)
{
	t_color dimmed;

	dimmed.a = 0;
	dimmed.r = color.r * factor;
	dimmed.g = color.g * factor;
	dimmed.b = color.b * factor;
	return (dimmed);
}