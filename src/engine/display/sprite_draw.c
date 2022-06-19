#include "display.h"

/*
	finds the sprite with the next highest distance.
	Meant to be initiated with very high last_distance
	and have it loop through number of sprites
	returns pointer to the sprite object
*/
static void	*next_highest(t_draw_sprite *layer, double *last_dist)
{
	double		tmpdist;
	void		*ptr;
	int			i;

	i = 0;
	tmpdist = -1.0;
	while (i < layer->obj_count)
	{
		if (layer->objects[i].distance > tmpdist && \
			layer->objects[i].distance < *last_dist)
		{
			ptr = &layer->objects[i];
			tmpdist = layer->objects[i].distance;
		}
		i++;
	}
	*last_dist = tmpdist;
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
		layer->entety_arr[i] = (t_entity *)next_highest(layer, &layer->tmpdbl);
		i++;
	}
}

/*
	calculating the distance to each sprite
*/
static void	sprites_calculate_distances(t_draw_sprite *layer, t_vect pos)
{
	int	i;

	i = 0;
	while (i < layer->obj_count)
	{
		layer->sprite_vect.x = layer->objects[i].position.x - pos.x;
		layer->sprite_vect.y = layer->objects[i].position.y - pos.y;
		normalize_vector(&layer->sprite_vect);
		layer->objects[i].distance = point_distance(pos, \
										layer->objects[i].position);
		i++;
	}
}

static void	sprite_constructor(t_draw_sprite *layer, t_data *data)
{
	layer->sprite_images = data->sprite_images;
	layer->objects = data->entity;
	layer->obj_count = data->entity->obj_count;
	layer->entety_arr = data->entity_arr;
}

/*
	The big one: does everything there is to be done for sprites
*/
void	sprite_draw(t_data *data)
{
	t_draw_sprite	layer;

	sprite_constructor(&layer, data);
	sprites_calculate_distances(&layer, data->player.pos);
	sort_sprites_by_distances(&layer);
	calculate_draw(&layer, data);
}
