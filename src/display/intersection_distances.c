#include "display.h"

static void	find_factor(t_intersect *data, t_vect *pos, t_vect *dir)
{
	if (dir->x >= 0)
		data->vert_factor = 100 - (pos->x - ((int)(pos->x/100)*100));
	else
		data->vert_factor = pos->x - ((int)(pos->x/100)*100);
	if (dir->y >= 0)
		data->hor_factor = 100 - (pos->y - ((int)(pos->y/100)*100));
	else
		data->hor_factor = pos->y - ((int)(pos->y/100)*100);
}

static void find_angle_quadrant(t_intersect *data, t_vect *dir)
{
	data->angle = atan2(dir->y*-1, dir->x);
	if (dir->x >= 0 && dir->y >= 0)
		data->angle *= -1;
	if (dir->x < 0 && dir->y >= 0)
		data->angle = ((-1) * M_PI - data->angle) * (-1);
	if (dir->x < 0 && dir->y < 0)
		data->angle = M_PI - data->angle;
}

// short coment here 
double	intersection_distances(t_vect *pos, t_vect *dir)
{
	t_intersect	data;

	find_angle_quadrant(&data, dir);
	find_factor(&data, pos, dir);
	data.dist_to_vert = 100/(cos(data.angle));
	data.dist_to_hor = 100/(cos(M_PI/2 - data.angle));
	data.vert_factor /= 100;
	data.hor_factor /= 100;
	data.dist_to_vert = fabs(data.dist_to_vert * data.vert_factor);
	data.dist_to_hor = fabs(data.dist_to_hor * data.hor_factor);
	if (data.dist_to_vert < data.dist_to_hor)
		return (data.dist_to_vert);
	else
		return (data.dist_to_hor);
}