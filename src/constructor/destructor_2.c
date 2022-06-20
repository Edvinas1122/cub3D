/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:03:16 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/20 23:03:17 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constructor.h"

void	destroy_mtrx_image(t_data *data, t_texture texture)
{
	int		y;
	t_color	***matrix;

	y = 0;
	matrix = texture.matx;
	while (matrix[y])
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
	mlx_destroy_image(data->mlx.ptr, texture.img_header);
}

void	destroy_mtrx_video(t_data *data, t_video texture)
{
	int		y;
	t_color	***matrix;

	y = 0;
	matrix = texture.img_matrix;
	while (matrix[y])
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
	mlx_destroy_image(data->mlx.ptr, texture.img);
}

void	delocate_texture_array(t_data *data, t_texture *arr)
{
	int	i;

	i = 0;
	while (arr[i].matx)
	{
		destroy_mtrx_image(data, arr[i]);
		i++;
	}
	free(arr);
}

void	delocate_sprite_animation(t_data *data)
{
	delocate_texture_array(data, data->sprite_anim->img_arr);
	free(data->sprite_anim);
}
