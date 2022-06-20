/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:06:11 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/20 23:06:12 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_color	rotate_color(t_data *data, t_color color, double angle)
{
	t_color	dimmed;

	if (data->potion.status == 0)
		return (color);
	angle *= 0.1;
	dimmed.a = 150;
	dimmed.r = color.r * (cos(angle) + 1) / 2;
	dimmed.g = color.g * ((cos(120) - cos(angle + 120)) + 1) / 2;
	dimmed.b = color.b * ((cos(240) - cos(angle + 240)) + 1) / 2;
	return (dimmed);
}
