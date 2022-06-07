#include "utils.h"

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
