#include "display.h"

/*
	Returns pixel compencated for vertical offset and strech_factor
*/
static t_color	sample_texture_pixel(t_color ***texture, t_line line, int y)
{
	y = (int)roundf(y * line.strech_factor);
	return (*(texture[y + line.horizontal_offset][line.vertical_offset]));
}

static int	vertical_offset_cal(t_vect impact, int texture_width, int plane)
{
	int vertical_offset;
	if (plane == 0)
	{
		vertical_offset = (int)(impact.x) % texture_width;
	}
	else
	{
		vertical_offset = (int)(impact.y) % texture_width;
	}
	return (vertical_offset);
}

static void	dim_color_on_distance(t_color *color, double distance)
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

static void	construct_line(t_line *line, t_data *data, t_raycast *raycast, t_wall *wall)
{
	//Based on ray data should select appropriate texture
	line->texture = data->map.north;
	//Based on ray data should select appropriate texture
	line->strech_factor = (double)data->map.east.height/wall->size;
	line->vertical_offset = vertical_offset_cal(raycast->impact, line->texture.width, raycast->plane_dir);
	line->horizontal_offset = roundf((double)wall->offset * line->strech_factor);
}

/*
	Draws wall - samples color for each wall pixel from texture using 
	sample_texture_pixel object.
*/
void	draw_wall_line(t_data *data, t_raycast *raycast, t_wall *wall)
{
	t_line	line;
	t_color	color;
	double	y;

	construct_line(&line, data, raycast, wall);
	y = 0;
	while (wall->y < wall->end)
	{
		color = sample_texture_pixel(line.texture.matx, line, y);
		dim_color_on_distance(&color, raycast->distance);
		pixel_put(data->video.img_matrix, color, raycast->v_line_ct, wall->y);
		wall->y++;
		y++;
	}
}