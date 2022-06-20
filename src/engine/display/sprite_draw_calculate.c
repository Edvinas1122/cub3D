#include "display.h"

/*
	calculates and returns the respective y value for an angle
*/
static int	angle_to_column(double angle)
{
	double	tmp;

	tmp = ((double)SCREEN_WIDTH * tan(angle)) / 2;
	return (SCREEN_WIDTH / 2 + tmp);
}

/*
	Find sprite direction vector
*/
static void	find_sprite_direction_vector(t_vect *vect, t_vect *pos, \
													t_vect *player_pos)
{
	vect->x = pos->x - player_pos->x;
	vect->y = pos->y - player_pos->y;
	normalize_vector(vect);
}

static void	sprite_set_data(t_entity *sprite, t_vect vect, \
											t_data *data, double angle)
{
	sprite->on_screen.x = angle_to_column(angle);
	sprite->distance /= 1 / (cos(get_angle(&data->player.vect, &vect) / \
														(180 / M_PI)));
	sprite->on_screen.y = (double)TILE_SIZE / sprite->distance;
	sprite->on_screen.y = SCREEN_HEIGHT / 2 + \
							(SCREEN_HEIGHT / 2 * sprite->on_screen.y);
}

static int	check_condition(t_entity *sprite, t_texture *images, double angle)
{
	if (sprite->on_screen.x + \
		sprite->scale * images[0].width >= 0 && \
		sprite->on_screen.x - sprite->scale * images[0].width < \
			SCREEN_WIDTH && (angle * 180 / M_PI) > -90 && \
		(angle * 180 / M_PI) < 90)
		return (1);
	else
		return (0);
}

/*
	Calculates and draws each sprite
*/
void	calculate_draw(t_draw_sprite *layer, t_data *data)
{
	int			i;
	double		angle;
	t_texture	image;

	i = 0;
	while (i < layer->obj_count)
	{
		find_sprite_direction_vector(&layer->sprite_vect,
			&(*layer->entety_arr[i]).position, &data->player.pos);
		angle = find_angle_vecotrs(layer->sprite_vect, data->player.vect);
		image = set_sprite_image(layer, data, i);
		sprite_set_data(layer->entety_arr[i], layer->sprite_vect, data, angle);
		if (check_condition(layer->entety_arr[i], &image, angle))
			draw_the_mother_ducking_sprite(data,
				image, (*layer->entety_arr[i]));
		i++;
	}
}
