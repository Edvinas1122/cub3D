#include "display.h"

/*
	finds the sprite with the next highest distance.
	Meant to be initiated with very high last_distance
	and have it loop through number of sprites
	returns pointer to the sprite object
*/
static void *next_highest(t_sprite sprites[6], double *last_distance)
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
