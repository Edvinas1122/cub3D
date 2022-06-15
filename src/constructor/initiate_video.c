#include "constructor.h"

/*
	initiates video struct - sets image color to black, puts it on screen
*/
t_video	set_video_window(t_mlx mlx)
{
	t_video		video;
	t_tmp_video	tmp;

	video.img = mlx_new_image(mlx.ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	tmp.img_data = mlx_get_data_addr(video.img, &tmp.img_bp, &tmp.img_sl, &tmp.img_e);
	video.img_matrix = create_pixel_matrix(tmp.img_data, SCREEN_WIDTH, SCREEN_HEIGHT);
	//color_the_matrix(video.img_matrix);
	return (video);
}
