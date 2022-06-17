#include "display.h"
void	draw_the_mother_fucking_sprite(t_data *data, t_sprite_data sprite_data, t_sprite sprite);

/*
	freeing the sprite memory again - again just for testing (something is wrong here btw)
*/
void	free_img_matrix(t_sprite_data *sprite_data)
{
	int i, j;

	i = 0;
	while (sprite_data->img_matrix[i])
	{
		j = 0;
		while (sprite_data->img_matrix[j])
		{
			free(sprite_data->img_matrix[i][j]);
			j++;
		}
		free(sprite_data->img_matrix[i][j]);
		free(sprite_data->img_matrix[i]);
		i++;
	}
	free(sprite_data->img_matrix[i]);
	free(sprite_data->img_matrix);
}

/*
	finds the sprite with the next highest distance.
	Meant to be initiated with very high last_distance
	and have it loop through number of sprites
	returns pointer to the sprite object
*/
void *next_highest(t_sprite sprites[6], double *last_distance)
{
	double		tmpdist;
	void	*ptr;

	tmpdist = -1.0;
	for (int i = 0; i < 6; i++)
	{
		if (sprites[i].distance > tmpdist && sprites[i].distance < *last_distance)
		{
			ptr = &sprites[i];
			tmpdist = sprites[i].distance;
		}
	}
	*last_distance = tmpdist;
	return (ptr);
}

/*
	calculates and returns the respective y value for an angle
*/
int	angle_to_column(double angle)
{
	double	tmp;

	tmp = ((double)SCREEN_WIDTH * tan(angle))/2;
	return (SCREEN_WIDTH/2 + tmp);
}

/*
	sorting the sprites by distance
*/
static void	sort_sprites_by_distances(t_draw_sprite *layer)
{
	int	i;

	i = 0;
	layer->tmpdbl = 2e30;
	while (i < layer->obj_count)
	{
		layer->sprite_arr[i] = (t_sprite *)next_highest(layer->objects, &layer->tmpdbl);
		i++;
	}
}

/*
	calculating the distance to each sprite
*/
static void	sprites_calculate_distances(t_draw_sprite *layer, t_data *data)
{
	int	i;

	i = 0;
	while (i < layer->obj_count)
	{
		layer->sprite_vect.x = layer->objects[i].position.x - data->player.pos.x;
		layer->sprite_vect.y = layer->objects[i].position.y - data->player.pos.y;
		normalize_vector(&layer->sprite_vect);
		layer->objects[i].distance = point_distance(data->player.pos, layer->objects[i].position);
		i++;
	}
}
static void	sprite_constructor(t_draw_sprite *layer, t_data *data)
{
	layer->sprite_images = data->sprite_images;
	layer->objects = data->sprite_objects;
	layer->obj_count = *(data->sprite_objects->obj_count);
	layer->sprite_arr = data->sprite_arr;
}


/*
	Calculates and draws each sprite
*/
static void calculate_draw(t_draw_sprite *layer, t_data *data)
{
	int	i;
	double angle;

	i = 0;
	while (i < layer->obj_count)
	{
		//find sprite direction vector
		layer->sprite_vect.x = (*layer->sprite_arr[i]).position.x - data->player.pos.x;
		layer->sprite_vect.y = (*layer->sprite_arr[i]).position.y - data->player.pos.y;
		normalize_vector(&layer->sprite_vect);

		//find angle between player direction and sprite
		angle = atan2(layer->sprite_vect.y, layer->sprite_vect.x) - atan2(data->player.vect.y, data->player.vect.x);
		if (angle > M_PI)
			angle -= 2*M_PI;
		else if (angle < -M_PI)
			angle += 2*M_PI;
		(*layer->sprite_arr[i]).on_screen.x = angle_to_column(angle);
		(*layer->sprite_arr[i]).distance /= 1/(cos(get_angle(&data->player.vect, &layer->sprite_vect) / (180/M_PI)));
		(*layer->sprite_arr[i]).on_screen.y = (double)TILE_SIZE/(*layer->sprite_arr[i]).distance;
		(*layer->sprite_arr[i]).on_screen.y = SCREEN_HEIGHT/2 + (SCREEN_HEIGHT/2 * (*layer->sprite_arr[i]).on_screen.y);
		if ((*layer->sprite_arr[i]).on_screen.x + 
			(*layer->sprite_arr[i]).scale * layer->sprite_images[(*layer->sprite_arr[i]).id].width >= 0 &&
			(*layer->sprite_arr[i]).on_screen.x - (*layer->sprite_arr[i]).scale * layer->sprite_images[(*layer->sprite_arr[i]).id].width <
				SCREEN_WIDTH && (angle*180/M_PI) > -90 && (angle*180/M_PI) < 90)
			draw_the_mother_fucking_sprite(data, layer->sprite_images[(*layer->sprite_arr[i]).id],(*layer->sprite_arr[i]));
		i++;
	}
}

/*
	The big one: does everything there is to be done for sprites
*/
void	sprite_draw(t_data *data)
{
	t_draw_sprite	layer;

	sprite_constructor(&layer, data);
	sprites_calculate_distances(&layer, data);
	sort_sprites_by_distances(&layer);
	calculate_draw(&layer, data);
}

static double	get_dim_factor(double distance)
{
	double factor;

	factor = distance/1000;
	if (factor > 1)
		factor = 1;
	factor = 1 - factor;
	if (factor < 0.25)
		factor = 0.25;
	return (factor);
}

void	draw_the_mother_fucking_sprite(t_data *data, t_sprite_data sprite_data, t_sprite sprite)
{
	double	scalefactor;
	int		scaledwidth;
	int		scaledheight;
	int		xstart;
	int		ystart;

	scalefactor = sprite.scale / (sprite.distance / TILE_SIZE);
	scaledwidth = (int)(sprite_data.width * scalefactor);
	scaledheight = (int)(sprite_data.height * scalefactor);
	xstart = (int)sprite.on_screen.x - scaledwidth/2;
	ystart = (int)sprite.on_screen.y - scaledheight;
	for (int x = 0; x < scaledwidth; x++)
	{
		if  (xstart + x >= 0 && xstart + x < SCREEN_WIDTH && data->map.z_buffer[xstart + x] > sprite.distance) //checking if wall at this column is closer, and if it's offscreen
		{
			for (int j = 0; j < scaledheight; j++)
				if (ystart + j >= 0 &&ystart + j < SCREEN_HEIGHT)	//checking if y val is offscreen
				{
					double dimfactor;
					if ((*sprite_data.img_matrix[(int)(x/scalefactor)][(int)(j/scalefactor)]).a == 0) //not drawing if transparency value isn't 0
					{
						t_color dimmed;
						dimfactor = get_dim_factor(sprite.distance);
						dimmed = dim_color(*sprite_data.img_matrix[(int)(x/scalefactor)][(int)(j/scalefactor)], dimfactor);
						pixel_put(data->video.img_matrix, dimmed, xstart + x, ystart + j);
					}
				}
		}
	}
}