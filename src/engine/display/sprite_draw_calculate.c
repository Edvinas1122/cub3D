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
		
		//select_spriteif animation

		if ((*layer->sprite_arr[i]).on_screen.x + 
			(*layer->sprite_arr[i]).scale * layer->sprite_images[(*layer->sprite_arr[i]).id].width >= 0 &&
			(*layer->sprite_arr[i]).on_screen.x - (*layer->sprite_arr[i]).scale * layer->sprite_images[(*layer->sprite_arr[i]).id].width <
				SCREEN_WIDTH && (angle*180/M_PI) > -90 && (angle*180/M_PI) < 90)
			draw_the_mother_ducking_sprite(data, layer->sprite_images[(*layer->sprite_arr[i]).id],(*layer->sprite_arr[i]));
		i++;
	}
}