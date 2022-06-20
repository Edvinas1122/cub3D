/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:04:58 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/20 23:04:59 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

/*
	Selects texture acording to facing dirrection
*/
t_texture	choose_texture(t_data *data, t_raycast *raycast)
{
	if (raycast->isdoor == 1)
		return (data->map.door);
	if (raycast->cardinal_direction == 1)
		return (data->map.north);
	if (raycast->cardinal_direction == 2)
		return (data->map.south);
	if (raycast->cardinal_direction == 3)
		return (data->map.west);
	if (raycast->cardinal_direction == 4)
		return (data->map.east);
	return (data->map.north);
}

static int	get_texture_x_door(t_data *data, t_texture texture,
								t_raycast *raycast)
{
	double	d_x;
	int		x;
	int		y;
	t_door	door;

	x = raycast->impact.x / TILE_SIZE;
	y = raycast->impact.y / TILE_SIZE;
	door = data->map.doormap[y][x];
	if (raycast->cardinal_direction == 1 || raycast->cardinal_direction == 2)
		d_x = fmod(raycast->impact.x, TILE_SIZE);
	if (raycast->cardinal_direction == 3 || raycast->cardinal_direction == 4)
		d_x = fmod(raycast->impact.y, TILE_SIZE);
	d_x += (100 - door.closed_percentage);
	d_x *= (double)(texture.width - 1) / 100;
	return ((int)floor(d_x));
}

static int	get_texture_x(t_data *data, t_texture texture, t_raycast *raycast)
{
	double	d_x;

	if (raycast->isdoor == 1)
		return (get_texture_x_door(data, texture, raycast));
	if (raycast->cardinal_direction == 1)
		d_x = fmod(raycast->impact.x, TILE_SIZE);
	if (raycast->cardinal_direction == 2)
		d_x = TILE_SIZE - fmod(raycast->impact.x, TILE_SIZE);
	if (raycast->cardinal_direction == 3)
		d_x = fmod(raycast->impact.y, TILE_SIZE);
	if (raycast->cardinal_direction == 4)
		d_x = TILE_SIZE - fmod(raycast->impact.y, TILE_SIZE);
	d_x *= (double)(texture.width - 1) / 100;
	return ((int)floor(d_x));
}

void	draw_vertical_line(t_data *data, t_raycast *raycast)
{
	t_wall		wall;
	t_texture	texture;

	texture = choose_texture(data, raycast);
	wall.txt_x = get_texture_x(data, texture, raycast);
	wall.size = (double)SCREEN_HEIGHT / (raycast->distance / TILE_SIZE);
	wall.start = (int)(SCREEN_HEIGHT - wall.size) / 2;
	wall.end = (int)(SCREEN_HEIGHT + wall.size) / 2;
	if (wall.size < SCREEN_HEIGHT)
		wall.iterator = wall.start;
	else
		wall.iterator = 0;
	wall.dim = get_dim_factor(raycast->distance);
	while (wall.iterator < SCREEN_HEIGHT - 1 && wall.iterator < wall.end)
	{
		wall.y = (double)(wall.iterator - wall.start) / wall.size;
		wall.txt_y = (int)(((double)texture.height - 1) * wall.y);
		wall.color = *texture.matx[wall.txt_x][wall.txt_y];
		wall.color = dim_color(wall.color, wall.dim);
		wall.color = rotate_color(data, wall.color, data->count);
		pixel_put(data->video.img_matrix, wall.color, \
							raycast->v_line_ct, wall.iterator);
		(wall.iterator)++;
	}
}
