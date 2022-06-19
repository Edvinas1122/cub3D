#include "display.h"

static void	find_factor(t_intersect *data, t_vect pos, t_vect *dir)
{
	double	tmpx;
	double	tmpy;

	tmpx = fmod(pos.x, (double)TILE_SIZE);
	tmpy = fmod(pos.y, (double)TILE_SIZE);
	if (dir->x > 0)
		data->vert_factor = TILE_SIZE - tmpx;
	else if (dir->x < 0)
		data->vert_factor = tmpx + 0.0001;
	else
		data->vert_factor = 2e30;
	if (dir->y > 0)
		data->hor_factor = TILE_SIZE - tmpy;
	else if (dir->y < 0)
		data->hor_factor = tmpy + 0.0001;
	else
		data->hor_factor = 2e30;
}

static void	find_angle_quadrant(t_intersect *data, t_vect *dir)
{
	data->angle = atan2(dir->y * -1, dir->x);
	if (dir->x >= 0 && dir->y >= 0)
		data->angle *= -1;
	if (dir->x < 0 && dir->y >= 0)
		data->angle = ((-1) * M_PI - data->angle) * (-1);
	if (dir->x < 0 && dir->y < 0)
		data->angle = M_PI - data->angle;
}

/*
	Provides raycaster information by calculating next intersection
	distance.
*/
static double	intersection_distances(t_vect pos, t_vect *dir,
										t_raycast *raycast, int doorflag)
{
	t_intersect	data;

	find_angle_quadrant(&data, dir);
	find_factor(&data, pos, dir);
	data.dist_to_vert = TILE_SIZE / (cos(data.angle));
	data.dist_to_hor = TILE_SIZE / (cos(M_PI / 2 - data.angle));
	if (doorflag && raycast->cardinal_direction == 1)
		data.dist_to_hor /= 2;
	if (doorflag && raycast->cardinal_direction == 3)
		data.dist_to_vert /= 2;
	data.vert_factor /= TILE_SIZE;
	data.hor_factor /= TILE_SIZE;
	data.dist_to_vert = fabs(data.dist_to_vert * data.vert_factor);
	data.dist_to_hor = fabs(data.dist_to_hor * data.hor_factor);
	if (data.dist_to_vert < data.dist_to_hor)
	{
		raycast->cardinal_direction = 3;
		return (data.dist_to_vert);
	}
	else
	{
		raycast->cardinal_direction = 1;
		return (data.dist_to_hor);
	}
}

static int	itterate_intersection(t_data *data, t_vect *dir,
									t_raycast *raycast, t_hit *in)
{
	in->tmpdist = intersection_distances(in->tmp, dir, raycast, 0);
	in->tmp.x += (in->tmpdist * dir->x);
	in->tmp.y += (in->tmpdist * dir->y);
	in->hit_wall = check_if_wall(data, in->tmp);
	if (in->hit_wall == 2)
	{
		in->tmpdist = intersection_distances(in->tmp, dir, raycast, 1);
		in->tmp.x += (in->tmpdist * dir->x);
		in->tmp.y += (in->tmpdist * dir->y);
		in->hit_wall = check_if_wall(data, in->tmp);
		if (in->hit_wall == 2 && check_door(data, in->tmp,
				raycast->cardinal_direction))
		{
			raycast->isdoor = 1;
			return (0);
		}
	}
	if (in->hit_wall == 1)
	{
		raycast->isdoor = 0;
		return (0);
	}
	return (1);
}

t_vect	find_intersections(t_data *data, t_vect *dir, t_raycast *raycast)
{
	t_hit	in;

	in.hit_door = 0;
	in.tmp.x = data->player.pos.x;
	in.tmp.y = data->player.pos.y;
	while (42)
	{
		if (!itterate_intersection(data, dir, raycast, &in))
			break ;
	}
	if (raycast->cardinal_direction == 1 && data->player.pos.y < in.tmp.y)
		raycast->cardinal_direction = 2;
	if (raycast->cardinal_direction == 3 && data->player.pos.x < in.tmp.x)
		raycast->cardinal_direction = 4;
	return (in.tmp);
}
