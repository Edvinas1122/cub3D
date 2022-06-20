/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigger_area.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:05:48 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/20 23:05:49 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mechanics.h"

static int	enter_area_check(t_vect player,
						t_vect position, int radius)
{
	if ((player.x - position.x) < radius)
		if ((player.y - position.y) < radius)
			return (1);
	return (0);
}

void	trigger_area(t_data *data)
{
	if (enter_area_check(data->player.pos, data->potion.position, 10)
		&& data->potion.status != 1)
	{
		play_audio("./audio/drink.mp3", 4);
		data->potion.status = 1;
	}
}
