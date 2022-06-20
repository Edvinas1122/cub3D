/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprite_frame.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:05:22 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/20 23:05:23 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		img.height = data->sprite_anim[0].img_arr[frame].height;
		img.width = data->sprite_anim[0].img_arr[frame].width;
		img.matx = data->sprite_anim[0].img_arr[frame].matx;
	}
	return (img);
}
