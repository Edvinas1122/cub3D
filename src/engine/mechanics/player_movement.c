/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:05:45 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/20 23:05:46 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

/*
	Controls colision
*/
static void	collisios_slide(t_data *data)
{
	t_vect	destination;

	destination.x = data->player.pos.x
		+ data->player.movement.x * data->util.move_factor;
	destination.y = data->player.pos.y;
	if (!check_if_solid_around(data, destination))
	{
		data->player.pos.x = destination.x;
		data->player.pos.y = destination.y;
	}
	else
	{
		destination.x = data->player.pos.x;
		destination.y = data->player.pos.y
			+ data->player.movement.y * data->util.move_factor;
		if (!check_if_solid_around(data, destination))
		{
			data->player.pos.x = destination.x;
			data->player.pos.y = destination.y;
		}
	}
}

static void	dash(t_data *data)
{
	static int	dash_dif;

	if (data->keys.key_space[0] == 1 && data->keys.key_space[1] == 0)
	{
		play_audio("./audio/jump.mp3", 1);
		data->keys.key_space[1] = 1;
		data->player.dash_cooldown = 30 * data->util.move_factor
			/ MOVE_DISTANCE;
		dash_dif = data->player.dash_cooldown - 5
			* data->util.move_factor / MOVE_DISTANCE;
	}
	if (data->player.dash_cooldown > dash_dif)
		data->util.move_factor *= DASH;
	if (data->player.dash_cooldown)
		data->player.dash_cooldown--;
	if (data->util.move_factor > TILE_SIZE / 3)
		data->util.move_factor = TILE_SIZE / 3;
}

void	player_movement(t_data *data)
{
	t_vect	destination;

	dash(data);
	set_movement_vector(data);
	unset_movement_vector(data);
	destination.x = data->player.pos.x
		+ data->player.movement.x * data->util.move_factor;
	destination.y = data->player.pos.y
		+ data->player.movement.y * data->util.move_factor;
	if (check_if_solid_around(data, destination))
		collisios_slide(data);
	else
	{
		data->player.pos.x = destination.x;
		data->player.pos.y = destination.y;
	}
}
