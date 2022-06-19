#include "display.h"

t_texture	set_sprite_image(t_draw_sprite *layer, t_data *data, int i)
{
	t_texture	img;
	int			frame;

	(void) data;
	if (!layer->entety_arr[i]->anim_info)
		return (layer->sprite_images[(*layer->entety_arr[i]).id]);
	else
	{
		frame = (data->count / ANIMATION_SPEED) % 4;
		img.height = data->sprite_anim[0].height;
		img.width = data->sprite_anim[0].width;
		img.matx = data->sprite_anim[0].img_matrix[frame];
	}
	return (img);
}
