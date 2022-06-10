#include "display.h"

/*
	checks if the given point belongs to a wall
*/
static int	check_if_wall(t_vect *point, char **bitmap)
{
	int x = point->x / 100;
	int y = point->y / 100;

	if (bitmap[y][x] == '1')
		return (1);
	else
		return (0);
}


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

static t_vect	*find_and_draw_intersections(t_data *data, t_vect *dir)
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
		//my_mlx_pixel_put(&mlx->img, tmp->x, tmp->y, 0x0000FF00);
		tmp->x += dir->x;
		tmp->y += dir->y;
		if (check_if_wall(tmp, data->map.bit_map))
			break ;
	}
	return (tmp);
}

/*
	casts lots of rays and calls draw_ray_3D for each
*/
void	cast_cone(t_data *data)
{
	t_vect		tmpdir;
	t_vect		*impact;
	double		step;
	int	i;

	i = 0;
	tmpdir.x = data->player.vect.x;
	tmpdir.y = data->player.vect.y;
	step = FOV;
	step /= SCREEN_WIDTH;
	rotate_vector(&tmpdir, (-1)*(FOV/2));
	while ((i * step) < FOV)
	{
		impact = find_and_draw_intersections(data, &tmpdir);
		draw_ray_3D(data->video.img_matrix, point_distance(&data->player.pos, impact), i);
		free(impact);
		rotate_vector(&tmpdir, step);
		i++;
	}
}