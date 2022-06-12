#include "display.h"

static void	set_wall_data(t_wall *wall, t_raycast *raycast)
{
	wall->offset = 0;
	wall->color = set_color(0, 100, 100, 100);
	wall->size = SCREEN_HEIGHT/(raycast->distance/100.0);
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

static void	draw_walls(t_data *data, t_raycast *raycast, t_wall *wall)
{
	t_color	color;

	while (wall->y < wall->end)
	{
		color = sample_texture_pixel(data, raycast, wall);
		//color = set_color(0, 140, 140, 140);
		pixel_put(data->video.img_matrix, color, raycast->v_line_ct, wall->y);
		wall->y++;
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
	draw_walls(data, raycast, &wall);
	while (wall.y < SCREEN_HEIGHT)
	{
		pixel_put(data->video.img_matrix, data->map.floor, raycast->v_line_ct, wall.y);
		wall.y++;
	}
}
