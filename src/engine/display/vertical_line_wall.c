#include "display.h"

/*
	Returns pixel compencated for vertical offset and strech_factor
*/
static t_color	sample_texture_pixel(t_color ***texture, t_line line, int y)
{
	y = (int)roundf(y * line.strech_factor);
	return (*(texture[y + line.horizontal_offset][line.vertical_offset]));
}

static int	vertical_offset_cal(t_vect impact, int texture_width, int plane, int height)
{
	double	ratio_factor;
	int 	vertical_offset;

	height++;
	ratio_factor = (double)texture_width / TILE_SIZE;
	if (plane < 3)
	{
		vertical_offset = (int)(impact.x * ratio_factor) % texture_width;
	}
	else
	{
		vertical_offset = (int)(impact.y * ratio_factor) % texture_width;
	}
	return (vertical_offset);
}

static double	get_dim_factor(double distance)
{
	double factor;

	factor = (distance / TILE_SIZE) / 10;
	if (factor > 1)
		factor = 1;
	factor = 1 - factor;
	if (factor < 0.25)
		factor = 0.25;
	return (factor);
}

static void	construct_line(t_line *line, t_data *data, t_raycast *raycast, t_wall *wall)
{
	if (raycast->cardinal_direction == 1)
		line->texture = data->map.north;
	else if (raycast->cardinal_direction == 2)
		line->texture = data->map.south;
	else if (raycast->cardinal_direction == 3)
		line->texture = data->map.west;
	else if (raycast->cardinal_direction == 4)
		line->texture = data->map.east;
	line->strech_factor = (double)(line->texture.height - 1)/wall->size;
	line->vertical_offset = vertical_offset_cal(raycast->impact, line->texture.width, raycast->cardinal_direction, line->texture.height);
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
	double	dimfactor;

	construct_line(&line, data, raycast, wall);
	dimfactor = get_dim_factor(raycast->distance);
	y = 0;
	while (wall->y < wall->end)
	{
		color = sample_texture_pixel(line.texture.matx, line, y);
		color = dim_color(color, dimfactor);
		pixel_put(data->video.img_matrix, color, raycast->v_line_ct, wall->y);
		wall->y++;
		y++;
	}
}