#include "display.h"

// static void	set_wall_data(t_wall *wall, t_raycast *raycast)
// {
// 	wall->offset = 0;
// 	wall->size = SCREEN_HEIGHT/(raycast->distance/TILE_SIZE);
// 	wall->y = 0;
// 	wall->start = SCREEN_HEIGHT/2.0 - (wall->size)/2;
// 	if (wall->start < 0)
// 	{
// 		wall->offset = wall->start * -1;
// 		wall->start = 0;
// 	}
// 	wall->end = wall->size + wall->start;
// 	if (wall->end >= SCREEN_HEIGHT)
// 		wall->end = SCREEN_HEIGHT - 1;
// }

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
/*
	Draws vertical pixel line using raycast data
	top portion - ceiling , middle - wall, bottom - floor
*/
// void	old_draw_vertical_line(t_data *data, t_raycast *raycast)
// {
// 	t_wall	wall;

// 	set_wall_data(&wall, raycast);
// 	wall.y = wall.start;
// 	draw_wall_line(data, raycast, &wall);
// }

t_texture	choose_texture(t_data *data, int direction)
{
	if (direction == 1)
		return (data->map.north);
	if (direction == 2)
		return (data->map.south);
	if (direction == 3)
		return (data->map.west);
	if (direction == 4)
		return (data->map.east);
	return (data->map.north);
}

int	get_texture_x(t_texture texture, t_raycast *raycast)
{
	double d_x;

	if (raycast->cardinal_direction == 1)
		d_x = fmod(raycast->impact.x, TILE_SIZE);
	if (raycast->cardinal_direction == 2)
		d_x = TILE_SIZE - fmod(raycast->impact.x, TILE_SIZE);
	if (raycast->cardinal_direction == 3)
		d_x = fmod(raycast->impact.y, TILE_SIZE);
	if (raycast->cardinal_direction == 4)
		d_x = TILE_SIZE - fmod(raycast->impact.y, TILE_SIZE);
	d_x *= (double)(texture.width - 1)/100;
	return ((int)floor(d_x));
}

void	draw_vertical_line(t_data *data, t_raycast *raycast)
{
	t_texture	texture;
	int			textureX;
	int			textureY;
	double		wallsize;
	int			wallstart;
	int			wally;
	double		d_y;
	t_color		color;
	double		dimfactor;
	//get correct texture
	texture = choose_texture(data, raycast->cardinal_direction);
	//get textureX;
	textureX = get_texture_x(texture, raycast);
	//get wallsize
	wallsize = (double)SCREEN_HEIGHT/(raycast->distance/TILE_SIZE);
	wally = 0;
	dimfactor = get_dim_factor(raycast->distance);
	wallstart = (int)(SCREEN_HEIGHT/2 - wallsize/2);
	while (wally < wallsize)
	{
		d_y = (double)((texture.height - 1) * wally)/wallsize;
		textureY = (int)floor(d_y);
		color = *texture.matx[textureX][textureY];
		color = dim_color(color, dimfactor);
		if (wally+wallstart>=0 && wally+wallstart<SCREEN_HEIGHT)
			pixel_put(data->video.img_matrix, color, raycast->v_line_ct, wally + wallstart);
		wally++;
	}
	//get textureY
}