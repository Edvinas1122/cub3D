#include "constructor.h"

static void	destroy_textures(t_data *data)
{
	if (data->map.north.matx)
		destroy_mtrx_image(data, data->map.north);
	if (data->map.east.matx)
		destroy_mtrx_image(data, data->map.east);
	if (data->map.west.matx)
		destroy_mtrx_image(data, data->map.west);
	if (data->map.south.matx)
		destroy_mtrx_image(data, data->map.south);
	if (data->util.bigmap_background.matx)
		destroy_mtrx_image(data, data->util.bigmap_background);
	if (data->util.minimap_frame.matx)
		destroy_mtrx_image(data, data->util.minimap_frame);
	if (data->map.door.matx)
		destroy_mtrx_image(data, data->map.door);
}

void	destructor(t_data *data)
{
	if (data->map.bit_map)
		delocate_arr(data->map.bit_map);
	if (data->video.img)
		destroy_mtrx_video(data, data->video);
	destroy_textures(data);
	if (data->doors)
		free(data->doors);
	if (data->map.doormap)
		delocate_door(data->map.doormap);
	if (data->sprite_images)
		delocate_texture_array(data, data->sprite_images);
	if (data->sprite_anim)
		delocate_sprite_animation(data);
	if (data->entity)
		free(data->entity);
	if (data->entity_arr)
		free(data->entity_arr);
	if (data->util.soundtrack)
		free(data->util.soundtrack);
	if (data->mlx.win)
		mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	// if (data->mlx.ptr)
	// 	free(data->mlx.ptr);
	end_audio();
	exit(0);
}
