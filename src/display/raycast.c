#include "display.h"

static double	intersection_distances(t_vect *pos, t_vect *dir)
{
	double	angle;
	double	dist_to_vert;
	double	dist_to_hor;
	double	vert_factor;
	double	hor_factor;

	angle = atan2(dir->y*-1, dir->x);
	if (dir->x >= 0 && dir->y >= 0)
		angle *= -1;
	if (dir->x < 0 && dir->y >= 0)
		angle = ((-1) * M_PI - angle) * (-1);
	if (dir->x < 0 && dir->y < 0)
		angle = M_PI - angle;

	if (dir->x >= 0)
		vert_factor = 100 - (pos->x - ((int)(pos->x/100)*100));	//fixed rough edges here, by changing modulo to more precise stuff
	else
		vert_factor = pos->x - ((int)(pos->x/100)*100);
	if (dir->y >= 0)
		hor_factor = 100 - (pos->y - ((int)(pos->y/100)*100));
	else
		hor_factor = pos->y - ((int)(pos->y/100)*100);
	dist_to_vert = 100/(cos(angle));
	dist_to_hor = 100/(cos(M_PI/2 - angle));
	vert_factor /= 100;
	hor_factor /= 100;
	dist_to_vert = fabs(dist_to_vert * vert_factor);
	dist_to_hor = fabs(dist_to_hor * hor_factor);
	if (dist_to_vert < dist_to_hor)
		return (dist_to_vert);
	else
		return (dist_to_hor);
}

static void	draw_ray_3D(t_color ***img, double distance, int x)
{
	int	i;
	t_color	ceilingcolour;
	t_color	wallcolour;
	t_color floorcolour;
	double wallsize;


	// printf("RAY #%d with distance %f\n", x, distance);
	ceilingcolour = set_color(0, 20, 20, 80);
	wallcolour = set_color(0, 100, 100, 100);
	floorcolour = set_color(0, 20, 80, 20);
	wallsize = (double)SCREEN_HEIGHT/(distance/100.0);
	i = 0;
	double start;
	double end;
	start = ((-1)*wallsize)/2 + (double)SCREEN_HEIGHT/2.0;
	if (start < 0)
		start = 0;
	end = wallsize/2.0 + (double)SCREEN_HEIGHT/2.0;
	if (end >= (double)SCREEN_HEIGHT)
		end = (double)SCREEN_HEIGHT - 1;
	// printf("start %f end %f\n", start, end);
	while (i < SCREEN_HEIGHT)
	{
		if (i < start)
			pixel_put(img, ceilingcolour, x, i);
		else if (i < end)
			pixel_put(img, wallcolour, x, i);
		else
			pixel_put(img, floorcolour, x, i);
		i++;
	}
}

static t_vect	*find_intersections(t_data *data, t_vect *dir)
{
	t_vect	*tmp;
	double	tmpdist;

	tmp = malloc(sizeof(t_vect));
	tmp->x = data->player.pos.x;
	tmp->y = data->player.pos.y;
	while (42)
	{
		tmpdist = intersection_distances(tmp, dir);
		tmp->x += (tmpdist * dir->x);
		tmp->y += (tmpdist * dir->y);
		tmp->x += dir->x;
		tmp->y += dir->y;
		if (check_if_wall(tmp, data->map.bit_map))
			break ;
	}
	return (tmp);
}

/*
	Ussing raycast technique draws a display image of "walls" in FOV
	
*/
// void	old_render_fov_view(t_data *data)
// {
// 	t_vect		ray_dir;
// 	t_vect		*impact;
// 	double		step;
// 	int			i;
// 	t_vect		ray_dir_old;
// 	double		distance;
// 	i = 0;
// 	ray_dir.x = data->player.vect.x;
// 	ray_dir.y = data->player.vect.y;
// 	step = FOV;
// 	step /= SCREEN_WIDTH;
// 	rotate_vector(&ray_dir, (-1)*(FOV/2));
// 	while ((i * step) < FOV)
// 	{
// 		impact = find_intersections(data, &ray_dir);
// 		distance = point_distance(&data->player.pos, impact);		//removing fisheye
// 		distance /= 1/(cos(get_angle(&data->player.vect, &ray_dir) / (180/M_PI)));
// 		draw_ray_3D(data->video.img_matrix,
// 					point_distance(&data->player.pos, impact), i);
// 		free(impact);
// 		ray_dir_old.x = ray_dir.x;
// 		ray_dir_old.y = ray_dir.y;
// 		rotate_vector(&ray_dir, step);
// 		i++;
// 	}
// }

void	render_fov_view(t_data *data)
{
	t_vect	ray_dir;
	t_vect	target;
	t_vect	perp;
	t_vect	*impact;
	int		i;
	double	distance;
	// printf("HELLO\n");
	i = 0;
	ray_dir.x = data->player.vect.x;
	ray_dir.y = data->player.vect.y;
	rotate_vector(&ray_dir, (-1)*(FOV/2));
	target.x = data->player.pos.x + ray_dir.x * SCREEN_WIDTH/sqrt(2);
	target.y = data->player.pos.y + ray_dir.y * SCREEN_WIDTH/sqrt(2);
	perp.x = data->player.vect.x;
	perp.y = data->player.vect.y;
	rotate_vector(&perp, 90);
	while (i < SCREEN_WIDTH)
	{
		impact = find_intersections(data, &ray_dir);
		distance = point_distance(&data->player.pos, impact);		//removing fisheye
		// printf("distance1: %f angle %f\n", distance, get_angle(&data->player.vect, &ray_dir));
		distance /= 1/(cos(get_angle(&data->player.vect, &ray_dir) / (180/M_PI)));
		// printf("distance2: %f\n", distance);
		draw_ray_3D(data->video.img_matrix, distance, i);
		free(impact);
		target.x += perp.x;
		target.y += perp.y;
		ray_dir.x = target.x - data->player.pos.x;
		ray_dir.y = target.y - data->player.pos.y;
		normalize_vector(&ray_dir);
		i++;
	}
	// printf("%f\n", get_angle(&data->player.vect, &ray_dir));
}