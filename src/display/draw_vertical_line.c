#include "display.h"

static void	set_wall_data(t_wall *wall, t_raycast *raycast)
{
	wall->offset = 0;
	wall->size = SCREEN_HEIGHT/(raycast->distance/TILE_SIZE);
	wall->y = 0;
	wall->start = SCREEN_HEIGHT/2.0 - (wall->size)/2;
	// printf("wall size: %f, wall->start: %d\n", wall->size, wall->start);
	if (wall->start < 0)
	{
		wall->offset = wall->start * -1;
		wall->start = 0;
	}
	wall->end = wall->size + wall->start;
	if (wall->end >= SCREEN_HEIGHT)
		wall->end = SCREEN_HEIGHT - 1;
}

/*
	Draws vertical pixel line using raycast data
	top portion - ceiling , middle - wall, bottom - floor
*/
void	draw_vertical_line(t_data *data, t_raycast *raycast)
{
	t_wall	wall;

	printf("impactx: %f impacty: %f\n", fmod(raycast->impact.x, TILE_SIZE), fmod(raycast->impact.y);
	set_wall_data(&wall, raycast);
	wall.y = wall.start;
	draw_wall_line(data, raycast, &wall);
}


texture	*choose_texture(t_data *data, int direction)
{
	if (direction == 1)
		return(data->map.north);
	if (direction == 2)
		return(data->map.south);
	if (direction == 3)
		return(data->map.west);
	if (direction == 4)
		return(data->map.east);
}

int	get_texture_x(t_vector impact, int direction, int width)
{
	double d_x;

	if (direction == 1)
		d_x = fmod(impact.x, TILE_SIZE);
	if (direction == 2)
		d_x = TILE_SIZE - fmod(impact.x, TILE_SIZE);
	if (direction == 3)
		d_x = fmod(impact.y, TILE_SIZE);
	if (direction == 4)
		d_x = TILE_SIZE - fmod(impact.y, TILE_SIZE);
	d_x *= width/100;
	return (roundf(d_x));
}

void	draw_wall(t_data *data, t_raycast *raycast)
{
	double		textureX;
	double		wallsize;
	t_vector	fmod_impact;
	t_texture	*texture;

	//get correct texture
	texture = choose_texture(data, raycast->cardinal_direction);
	//get textureX
	textureX = get_texture_x(raycast->impact, raycast->cardinal_direction, texture->width);
	//get wallsize
	wallsize = (double)SCREEN_HEIGHT/(raycast->distance/TILE_SIZE);
	
}