#include "display.h"

static void	set_wall_data(t_wall *wall, t_raycast *raycast)
{
	wall->offset = 0;
	wall->color = set_color(0, 100, 100, 100);
	wall->size = SCREEN_HEIGHT/(raycast->distance/TILE_SIZE);
	wall->y = 0;
	wall->start = SCREEN_HEIGHT/2.0 - (wall->size)/2;
	if (wall->start < 0)
	{
		wall->offset = wall->start * -1;
		wall->start = 0;
	}
	wall->end = wall->size + wall->start;
	if (wall->end >= SCREEN_HEIGHT)
		wall->end = SCREEN_HEIGHT - 1;
}


static int	vertical_offset_cal(t_vect *impact, int texture_width, int plane)
{
	int vertical_offset;
	if (plane == 0)
	{
		vertical_offset = (int)(impact->x) % texture_width;
	}
	else
	{
		vertical_offset = (int)(impact->y) % texture_width;
	}
	return (vertical_offset);
}

void	dim_color_on_distance(t_color *color, double distance)
{
	double	factor;

	factor = distance/1000;
	if (factor > 1)
		factor = 1;
	factor = 1 - factor;
	if (factor < 0.25)
		factor = 0.25;
	color->r = color->r * factor;
	color->g = color->g * factor;
	color->b = color->b * factor;
}
/*
	Draws wall - samples color for each wall pixel from texture using 
	sample_texture_pixel object.
*/
static void	draw_wall_line(t_data *data, t_raycast *raycast, t_wall *wall)
{
	t_color	color;
	double	i;
	double	factor;
	int		offset;
	int		vertical_offset;

	vertical_offset = vertical_offset_cal(raycast->impact, data->map.east.width, raycast->plane_dir);
	factor = (double)data->map.east.height/wall->size;
	i = 0;
	offset = roundf((double)wall->offset * factor);
	while (wall->y < wall->end)
	{
		color = sample_texture_pixel(data, raycast, wall, (int)roundf(i * factor), offset, vertical_offset);
		dim_color_on_distance(&color, raycast->distance);
		//color = set_color(0, 140, 140, 140);
		pixel_put(data->video.img_matrix, color, raycast->v_line_ct, wall->y);
		wall->y++;
		i++;
	}
}


/*
	Draws vertical pixel line using raycast data
	top portion - ceiling , middle - wall, bottom - floor
*/
void	draw_vertical_line(t_data *data, t_raycast *raycast)
{
	t_wall	wall;

	set_wall_data(&wall, raycast);
	while (wall.y < wall.start)
	{
		pixel_put(data->video.img_matrix, data->map.ceiling, raycast->v_line_ct, wall.y);
		wall.y++;
	}
	draw_wall_line(data, raycast, &wall);
	while (wall.y < SCREEN_HEIGHT)
	{
		pixel_put(data->video.img_matrix, data->map.floor, raycast->v_line_ct, wall.y);
		wall.y++;
	}
}
