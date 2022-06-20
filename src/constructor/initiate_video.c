/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_video.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:03:24 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/20 23:03:25 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constructor.h"

/*
	initiates video struct - sets image color to black, puts it on screen
*/
t_video	set_video_window(t_mlx mlx)
{
	t_video		video;
	t_tmp_video	tmp;

	video.img = mlx_new_image(mlx.ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	tmp.img_data = mlx_get_data_addr(video.img, \
							&tmp.img_bp, &tmp.img_sl, &tmp.img_e);
	video.img_matrix = create_pixel_matrix(tmp.img_data, \
									SCREEN_WIDTH, SCREEN_HEIGHT);
	return (video);
}
