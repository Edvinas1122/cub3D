#include "display.h"

static t_vect	*find_intersections(t_data *data, t_vect *dir, t_raycast *raycast)
{
	t_vect	*tmp;
	double	tmpdist;

	tmp = malloc(sizeof(t_vect));
	tmp->x = data->player.pos.x;
	tmp->y = data->player.pos.y;
	while (42)
	{
		tmpdist = intersection_distances(tmp, dir, raycast);
		tmp->x += (tmpdist * dir->x);
		tmp->y += (tmpdist * dir->y);
		if (check_if_wall(tmp, data->map.bit_map))
			break ;
	}
	return (tmp);
}

/*
	Sets next ray
*/
static void	set_next_ray(t_data *data, t_raycast *raycast)
{
		raycast->target.x += raycast->perp.x;	//find target for next ray
		raycast->target.y += raycast->perp.y;
		raycast->ray_dir.x = raycast->target.x - data->player.pos.x;	//adjust direction vector for next ray
		raycast->ray_dir.y = raycast->target.y - data->player.pos.y;
		normalize_vector(&raycast->ray_dir);
}


/*
	Sets variables for first ray
*/
static void	raycast_constructor(t_raycast *raycast, t_data *data)
{
	raycast->v_line_ct = 0;
	raycast->ray_dir.x = data->player.vect.x;
	raycast->ray_dir.y = data->player.vect.y;
	rotate_vector(&raycast->ray_dir, (-1)*(FOV/2));
	raycast->target.x = data->player.pos.x + raycast->ray_dir.x * SCREEN_WIDTH/sqrt(2);
	raycast->target.y = data->player.pos.y + raycast->ray_dir.y * SCREEN_WIDTH/sqrt(2);
	raycast->perp.x = data->player.vect.x;
	raycast->perp.y = data->player.vect.y;
	rotate_vector(&raycast->perp, 90);
}

/*
	Ussing raycast technique draws a display image of "walls" "ceiling" "floor" in FOV
	loop iterates for every vertical line in screen width plane
*/
void	render_fov_view(t_data *data)
{
	t_raycast	raycast;

	raycast_constructor(&raycast, data);
	while (raycast.v_line_ct < SCREEN_WIDTH)
	{
		raycast.impact = find_intersections(data, &raycast.ray_dir, &raycast);
		raycast.distance = point_distance(&data->player.pos, raycast.impact);		//removing fisheye
		raycast.distance /= 1/(cos(get_angle(&data->player.vect, &raycast.ray_dir) / (180/M_PI)));
		draw_vertical_line(data, &raycast);
		free(raycast.impact);
		set_next_ray(data, &raycast);
		raycast.v_line_ct++;
	}
}