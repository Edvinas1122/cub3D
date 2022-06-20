#include "utils.h"

t_color	rotate_color(t_data *data, t_color color, double angle)
{
	t_color	dimmed;

	if (data->potion.status == 0)
		return (color);
	angle *= 0.05;
	dimmed.a = color.a;
	dimmed.r = color.r * (cos(angle) + 1) / 2;
	dimmed.g = color.g * ((cos(120) - cos(angle + 120)) + 1) / 2;
	dimmed.b = color.b * ((cos(240) - cos(angle + 240)) + 1) / 2;
	return (dimmed);
}
