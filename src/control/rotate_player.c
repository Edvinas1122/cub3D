/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:04:36 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/20 23:04:37 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void	rotate_player_left(t_data *data)
{
	rotate_vector(&data->player.vect, -3);
}

void	rotate_player_right(t_data *data)
{
	rotate_vector(&data->player.vect, 3);
}

void	rotate_player(t_data *data, int x)
{
	double	strenght;

	strenght = x;
	strenght /= MOUSE_SENSITIVITY;
	rotate_vector(&data->player.vect, strenght);
	rotate_vector(&data->player.movement, strenght);
}

int	red_x_win(t_data *data)
{
	close_win(data);
	return (0);
}
