#include "display.h"

/*
	calculates and returns the respective y value for an angle
*/
static int	angle_to_column(double angle)
{
	double	tmp;

	tmp = ((double)SCREEN_WIDTH * tan(angle))/2;
	return (SCREEN_WIDTH/2 + tmp);
}

/*
	Find sprite direction vector
*/
static void	find_sprite_direction_vector(t_vect *vect, t_vect *position, t_vect *player_pos)
{
	vect->x = position->x - player_pos->x;
	vect->y = position->y - player_pos->y;
	normalize_vector(vect);
}

static void	sprite_set_data(t_sprite *sprite, t_vect vect, t_data *data, double angle)
{
	sprite->on_screen.x = angle_to_column(angle);
	sprite->distance /= 1/(cos(get_angle(&data->player.vect, &vect) / (180/M_PI)));
	sprite->on_screen.y = (double)TILE_SIZE / sprite->distance;
	sprite->on_screen.y = SCREEN_HEIGHT / 2 + (SCREEN_HEIGHT / 2 * sprite->on_screen.y);
}

static int check_condition(t_sprite *sprite, t_sprite_data *images, double angle)
{
	if (sprite->on_screen.x + 
		sprite->scale * images[sprite->id].width >= 0 &&
		sprite->on_screen.x - sprite->scale * images[sprite->id].width <
			SCREEN_WIDTH && (angle*180/M_PI) > -90 && (angle*180/M_PI) < 90)
		return (1);
	else
		return (0);
}

/*
	Calculates and draws each sprite
*/
void calculate_draw(t_draw_sprite *layer, t_data *data)
{
	int	i;
	double angle;

	i = 0;
	while (i < layer->obj_count)
	{
		find_sprite_direction_vector(&layer->sprite_vect,
			&(*layer->sprite_arr[i]).position, &data->player.pos);
		angle = find_angle_vecotrs(layer->sprite_vect, data->player.vect);
		sprite_set_data(layer->sprite_arr[i], layer->sprite_vect, data, angle);
		//select_spriteif animation
		if (check_condition(layer->sprite_arr[i], layer->sprite_images, angle))
			draw_the_mother_ducking_sprite(data,
					layer->sprite_images[(*layer->sprite_arr[i]).id],
					(*layer->sprite_arr[i]));
		i++;
	}
}
