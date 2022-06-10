#include "utils.h"

/*
	Sets aRGB colors values to t_color struct
*/
t_color	set_color(int a, int r, int g, int b)
{
	t_color	color;

	color.a = (char)a;
	color.r = (char)r;
	color.g = (char)g;
	color.b = (char)b;
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
