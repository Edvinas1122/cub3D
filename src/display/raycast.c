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
		vert_factor = (100 - ((int)(pos->x)%100));
	else
		vert_factor = ((int)(pos->x)%100);
	if (dir->y >= 0)
		hor_factor = (100 - ((int)(pos->y)%100));
	else
		hor_factor = ((int)(pos->y)%100);
	
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

	ceilingcolour = set_color(0, 20, 20, 80);
	wallcolour = set_color(0, 100, 100, 100);
	floorcolour = set_color(0, 20, 80, 20);
	wallsize = SCREEN_HEIGHT/(distance/100);
	i = 0;
	int start;
	int end;
	start = ((-1)*wallsize)/2 + SCREEN_HEIGHT/2;
	if (start < 0)
		start = 0;
	end = wallsize/2 + SCREEN_HEIGHT/2;
	if (end >= SCREEN_HEIGHT)
		end = SCREEN_HEIGHT - 1;
	
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
void	render_fov_view(t_data *data)
{
	t_vect		ray_dir;
	t_vect		*impact;
	double		step;
	int			i;

	i = 0;
	ray_dir.x = data->player.vect.x;
	ray_dir.y = data->player.vect.y;
	step = FOV;
	step /= SCREEN_WIDTH;
	rotate_vector(&ray_dir, (-1)*(FOV/2));
	while ((i * step) < FOV)
	{
		impact = find_intersections(data, &ray_dir);
		draw_ray_3D(data->video.img_matrix,
					point_distance(&data->player.pos, impact), i);
		free(impact);
		rotate_vector(&ray_dir, step);
		i++;
	}
}