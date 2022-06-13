#include "display.h"

static void	set_wall_data(t_wall *wall, t_raycast *raycast)
{
	wall->offset = 0;
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

// static double	get_dim_factor(int y)
// {
// 	double	factor;
// 	int		delta;

// 	delta = abs(y - (SCREEN_HEIGHT / 2));
// 	factor = 1 - ((double)delta / (SCREEN_HEIGHT/2));
// 	factor = factor*factor*factor*factor;
// 	return (1-factor);
// }

/*
	Draws vertical pixel line using raycast data
	top portion - ceiling , middle - wall, bottom - floor
*/
void	draw_vertical_line(t_data *data, t_raycast *raycast)
{
	t_wall	wall;
	// double	dimfactor;

	set_wall_data(&wall, raycast);
	// while (wall.y < wall.start)
	// {
	// 	dimfactor = get_dim_factor(wall.y);
	// 	pixel_put(data->video.img_matrix, dim_color(data->map.ceiling, dimfactor), raycast->v_line_ct, wall.y);
	// 	wall.y++;
	// }
	// t_color tmpcol;
	// tmpcol.a = 0;
	// tmpcol.r = 120;
	// tmpcol.g = 0;
	// tmpcol.b = 0;
	// while (wall.y < wall.end)
	// {
	// 	pixel_put(data->video.img_matrix, tmpcol, raycast->v_line_ct, wall.y);
	// 	wall.y++;
	// }
	wall.y = wall.start;
	draw_wall_line(data, raycast, &wall);
	// while (wall.y < SCREEN_HEIGHT)
	// {
	// 	dimfactor = get_dim_factor(wall.y);
	// 	pixel_put(data->video.img_matrix, dim_color(data->map.floor, dimfactor), raycast->v_line_ct, wall.y);
	// 	wall.y++;
	// }
}
