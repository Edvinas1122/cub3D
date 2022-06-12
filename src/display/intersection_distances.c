#include "display.h"

static void	find_factor(t_intersect *data, t_vect *pos, t_vect *dir)
{
	if (dir->x >= 0)
		data->vert_factor = TILE_SIZE - (pos->x - ((int)(pos->x/TILE_SIZE)*TILE_SIZE));
	else
		data->vert_factor = pos->x - ((int)(pos->x/TILE_SIZE)*TILE_SIZE);
	if (dir->y >= 0)
		data->hor_factor = TILE_SIZE - (pos->y - ((int)(pos->y/TILE_SIZE)*TILE_SIZE));
	else
		data->hor_factor = pos->y - ((int)(pos->y/TILE_SIZE)*TILE_SIZE);
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
double	intersection_distances(t_vect *pos, t_vect *dir, t_raycast *raycast)
{
	t_intersect	data;

	find_angle_quadrant(&data, dir);
	find_factor(&data, pos, dir);
	data.dist_to_vert = TILE_SIZE/(cos(data.angle));
	data.dist_to_hor = TILE_SIZE/(cos(M_PI/2 - data.angle));
	data.vert_factor /= TILE_SIZE;
	data.hor_factor /= TILE_SIZE;
	data.dist_to_vert = fabs(data.dist_to_vert * data.vert_factor);
	data.dist_to_hor = fabs(data.dist_to_hor * data.hor_factor);
	if (data.dist_to_vert < data.dist_to_hor)
	{
		raycast->plane_dir = 1;
		return (data.dist_to_vert);
	}
	else
	{
		raycast->plane_dir = 0;
		return (data.dist_to_hor);
	}
}
